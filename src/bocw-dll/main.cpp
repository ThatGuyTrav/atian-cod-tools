#include <dll_includes.hpp>
#include <utils/utils.hpp>
#include <imgui.h>
#include <backends/imgui_impl_dx11.h>
#include <backends/imgui_impl_dx12.h>
#include <backends/imgui_impl_win32.h>
#include <d3d11.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <hook/error.hpp>
#include <hook/memory.hpp>
#include <hook/library.hpp>
#include <hook/process.hpp>
#include <core/system.hpp>
#include "systems/core.hpp"
#include "data/cw.hpp"
#include "callbacks.hpp"

#define EXPORT extern "C" __declspec(dllexport)

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace cw {
    namespace {
        HANDLE mainThread{};
        DWORD mainThreadId{};
        hook::library::Detour ExitProcessDetour;
        hook::library::Detour GetThreadContextDetour;
        hook::library::Detour SetThreadContextDetour;
        hook::library::Detour GetSystemMetricsDetour;
        hook::library::Detour CreateSwapChainDetour;
        hook::library::Detour D3D12ExecuteCommandListsDetour;
        hook::library::Detour PresentDetour;
        hook::library::Detour CreateDXGIFactoryDetour;
        hook::library::Detour CreateDXGIFactory1Detour;
        hook::library::Detour CreateDXGIFactory2Detour;
        hook::library::Detour BaseThreadInitDetour;

        DECLSPEC_NORETURN void ExitProcessStub(UINT uExitCode) {
            if (uExitCode) {
                LOG_ERROR("ExitProcess with {}", uExitCode);
                hook::error::DumpStackTraceFrom(core::logs::LVL_ERROR);
            }
            else {
                LOG_INFO("ExitProcess with {}", uExitCode);
                hook::error::DumpStackTraceFrom(core::logs::LVL_INFO);
            }
            ExitProcessDetour.Call(uExitCode);
        }

        BOOL WINAPI GetThreadContextStub(HANDLE hThread, LPCONTEXT lpContext) {
            // clear debug flags if inside the game
            if (hook::library::GetLibraryInfo(_ReturnAddress()) == hook::process::BaseHandle()) {
                if (lpContext && lpContext->ContextFlags & (CONTEXT_DEBUG_REGISTERS & ~CONTEXT_AMD64)) {
                    lpContext->ContextFlags &= ~(CONTEXT_DEBUG_REGISTERS & ~CONTEXT_AMD64);
                }
                if (hThread && hThread != INVALID_HANDLE_VALUE) {
                    callbacks::ThreadRegister((void*)hThread);
                }
            }

            return GetThreadContextDetour.Call<BOOL>(hThread, lpContext);
        }
        BOOL WINAPI SetThreadContextStub(HANDLE hThread, CONTEXT* lpContext) {
            // clear debug flags if inside the game
            if (hook::library::GetLibraryInfo(_ReturnAddress()) == hook::process::BaseHandle()) {
                if (lpContext && lpContext->ContextFlags & (CONTEXT_DEBUG_REGISTERS & ~CONTEXT_AMD64)) {
                    lpContext->ContextFlags &= ~(CONTEXT_DEBUG_REGISTERS & ~CONTEXT_AMD64);
                }
                if (hThread && hThread != INVALID_HANDLE_VALUE) {
                    callbacks::ThreadRegister((void*)hThread);
                }
            }

            return SetThreadContextDetour.Call<BOOL>(hThread, lpContext);
        }
        int GetSystemMetricsStub(int nIndex) {
            // unpack?

            static std::once_flag of{};

            if (mainThreadId == GetCurrentThreadId()) {
                std::call_once(of, [] {
                    try {
                        core::system::PostInit();
                        hook::library::SaveScanContainer();
                    }
                    catch (std::exception& e) {
                        LOG_ERROR("Error at ACTS DLL post init {}", e.what());
                        MessageBoxA(NULL, utils::va("%s", e.what()), "Error at ACTS DLL post init", MB_ICONERROR);
                        *reinterpret_cast<byte*>(0x123456789) = 2;
                    }
                });
            }
            return GetSystemMetricsDetour.Call<int>(nIndex);
        }

        byte* DecryptSTR(byte* str) {
            return reinterpret_cast<byte * (*)(byte * str)>(hook::process::Relativise(0xc990ad0))(str);
        }

        int DecryptGSCFile(T9GSCOBJ* script) {
            uintptr_t str_location = reinterpret_cast<uintptr_t>(&script->magic[script->string_offset]);

            auto decrypted = 0;
            for (size_t i = 0; i < script->string_count; i++) {

                const auto* str = reinterpret_cast<T8GSCString*>(str_location);

                byte* encryptedString = &script->magic[str->string];

                auto* sd = reinterpret_cast<const char*>(DecryptSTR(encryptedString));

                //LOG_INFO("decrypted: {}", sd);

                decrypted++;

                const auto* strings = reinterpret_cast<const uint32_t*>(&str[1]);

                str_location += sizeof(*str) + sizeof(*strings) * str->num_address;
            }

            return decrypted;
        }

        void DecryptMTBuffer(size_t count) {
            int done = 0;
            std::unordered_set<std::string> strs{};
            auto* mt_buffer = *reinterpret_cast<byte**>(hook::process::Relativise(0xF5EC9C8));
            for (size_t i = 1; i < count; i++) {
                auto* loc = mt_buffer + i * 0x10;
                if (i % 0x100 == 0) {
                    LOG_INFO("decrypting MT: {:x}/{:x}, done={}", i, count, done);
                }
                auto loc2 = reinterpret_cast<char*>(loc)[2];
                if (*reinterpret_cast<int16_t*>(loc) == 0 || loc[3] != 7 || (loc2 & 0x40) != 0 || loc2 >= 0) {
                    continue;
                }

                const byte* v = DecryptSTR(reinterpret_cast<byte*>(loc + 0x18));
                strs.insert(reinterpret_cast<const char*>(v));
                done++;
            }
            std::ofstream outStr{ "scriptbundle_str.txt" };

            if (outStr) {
                for (const auto& st : strs) {
                    outStr << st << "\n";
                }
                outStr.close();
                LOG_INFO("dumped strings to scriptbundle_str.txt");
            }
        }

        void DecryptGSCScripts() {
            LOG_INFO("decrypting gsc scripts...");
            std::filesystem::path spt{ "scriptparsetree_cw" };
            std::filesystem::path sptd{ "scriptparsetree_cw_decrypt" };

            std::filesystem::create_directories(sptd);

            std::vector<std::filesystem::path> files{};
            utils::GetFileRecurse(spt, files, [](const std::filesystem::path& path) {
                auto name = path.string();
                return name.ends_with(".gscc");
                });

            for (const auto& file : files) {
                LOG_INFO("decrypting {}...", file.string());

                void* buffer{};
                void* bufferAlign{};
                size_t size{};
                size_t sizeAlign{};

                if (!utils::ReadFileAlign(file, buffer, bufferAlign, size, sizeAlign)) {

                    LOG_ERROR("Can't read file");
                    return;
                }

                if (sizeAlign >= sizeof(T9GSCOBJ) && *reinterpret_cast<uint64_t*>(bufferAlign) == 0x38000a0d43534780) {

                    auto* s = reinterpret_cast<T9GSCOBJ*>(bufferAlign);

                    auto dec = DecryptGSCFile(s);

                    LOG_INFO("{} string(s) decrypted", dec);

                    std::filesystem::path out = sptd / std::format("script_{:x}.gscc", s->name);

                    if (!utils::WriteFile(out, s, sizeAlign)) {
                        LOG_ERROR("Error when writing back the file");
                    }
                }
                else {
                    LOG_ERROR("BAD MAGIC/SIZE");
                }

                std::free(buffer);
            }
        }

        enum MenuDXType {
            MDT_NONE = 0,
            MDT_D11,
            MDT_D12,
        };
        struct DX12FrameContext {
            ID3D12CommandAllocator* allocator{};
            ID3D12Resource* resource{};
            D3D12_CPU_DESCRIPTOR_HANDLE descriptorHandle{};
        };
        struct MenuData {
            // debug
#ifdef CI_BUILD
            bool useImGui{};
#else
            bool useImGui{ false };
#endif

            // imgui data
            bool init{};
            HWND hwnd{};
            WNDPROC wndProc;
            union {
                struct {
                    ID3D11Device* d3dDevice{};
                    ID3D11DeviceContext* d3dContext{};
                    ID3D11RenderTargetView* render{};
                } dx11;
                struct {
                    ID3D12Device* d3dDevice{};
                    int bufferCount;
                    ID3D12DescriptorHeap* descHeap{};
                    ID3D12DescriptorHeap* descBuffers{};
                    ID3D12GraphicsCommandList* commandList{};
                    DX12FrameContext* frames{};
                    ID3D12CommandQueue* queue{};
                } dx12;
            };
            MenuDXType d3dType;

            // menu config
            bool display{};
            const char* lastNotif{};
        };
        MenuData menuData{};


        void HandleImGuiMenu() {
            ImGui::Begin("Atian Tools", nullptr, 0);

            ImGui::Text("Version %s", core::actsinfo::VERSION);

#ifndef CI_BUILD

            if (ImGui::Button("Decrypt")) {
                DecryptGSCScripts();
                menuData.lastNotif = "decrypted";
            }
#endif

            callbacks::RenderImGui((void*)&menuData.lastNotif);

            if (menuData.lastNotif) {
                ImGui::Text("%s", menuData.lastNotif ? menuData.lastNotif : "");
            }
            ImGui::End();
        }

#pragma region imgui

        LRESULT APIENTRY WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
            if (menuData.display && !ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam)) {
                switch (uMsg) {
                case WM_MOUSEACTIVATE:
                case WM_MBUTTONDOWN:
                case WM_MBUTTONUP:
                case WM_MBUTTONDBLCLK:
                case WM_MOUSEMOVE:
                case WM_NCHITTEST:
                case WM_MOUSEWHEEL:
                case WM_MOUSEHOVER:
                case WM_ACTIVATEAPP:
                case WM_RBUTTONDOWN:
                case WM_RBUTTONUP:
                case WM_RBUTTONDBLCLK:
                case WM_KEYDOWN:
                case WM_KEYUP:
                case WM_CHAR:
                case WM_LBUTTONDOWN:
                case WM_LBUTTONUP:
                case WM_LBUTTONDBLCLK:
                case WM_SETCURSOR:
                    return true;
                }
            }
            return CallWindowProc(menuData.wndProc, hwnd, uMsg, wParam, lParam);
        }

        void InitImGui() {
            if (!menuData.useImGui) {
                return;
            }
            ImGui::CreateContext();

            ImGuiIO& io = ImGui::GetIO();
            io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;

            ImGui_ImplWin32_Init(menuData.hwnd);
            switch (menuData.d3dType) {
            case MDT_D11:
                ImGui_ImplDX11_Init(menuData.dx11.d3dDevice, menuData.dx11.d3dContext);
                ImGui_ImplDX11_CreateDeviceObjects();
                break;
            case MDT_D12:
                ImGui_ImplDX12_Init(
                    menuData.dx12.d3dDevice, menuData.dx12.bufferCount, DXGI_FORMAT_R8G8B8A8_UNORM,
                    menuData.dx12.descHeap,
                    menuData.dx12.descHeap->GetCPUDescriptorHandleForHeapStart(),
                    menuData.dx12.descHeap->GetGPUDescriptorHandleForHeapStart()
                );
                ImGui_ImplDX12_CreateDeviceObjects();
                break;
            }
        }

        void D3D12ExecuteCommandListsStub(ID3D12CommandQueue* queue, UINT list, void* commandLists) {
            if (!menuData.dx12.queue) {
                LOG_DEBUG("Load command queue");
                menuData.dx12.queue = queue;
            }
            D3D12ExecuteCommandListsDetour.Call<HRESULT>(queue, list, commandLists);
        }

        HRESULT PresentStub(IDXGISwapChain* chain, UINT SyncInterval, UINT Flags) {
            auto hresf = [chain, SyncInterval, Flags]() -> HRESULT { return PresentDetour.Call<HRESULT>(chain, SyncInterval, Flags); };
            if (!menuData.init) {
                if (SUCCEEDED(chain->GetDevice(__uuidof(ID3D11Device), (void**)&menuData.dx11.d3dDevice))) {
                    menuData.d3dType = MDT_D11;
                    DXGI_SWAP_CHAIN_DESC sd;
                    chain->GetDesc(&sd);
                    menuData.hwnd = sd.OutputWindow;

                    ID3D11Texture2D* buffer{};
                    if (!SUCCEEDED(chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer)) || !buffer) {
                        LOG_ERROR("Can't get D11 texture2d buffer");
                        return hresf();
                    }
                    menuData.dx11.d3dDevice->CreateRenderTargetView(buffer, NULL, &menuData.dx11.render);
                    buffer->Release();

                    menuData.wndProc = (WNDPROC)SetWindowLongPtr(menuData.hwnd, GWLP_WNDPROC, (LONG_PTR)WndProc);

                    menuData.init = true;
                    InitImGui();
                    LOG_DEBUG("ImGui init (D3D11)");
                }
                else if (SUCCEEDED(chain->GetDevice(__uuidof(ID3D12Device), (void**)&menuData.dx12.d3dDevice))) {
                    if (!menuData.dx12.queue) {
                        if (!D3D12ExecuteCommandListsDetour) {
                            // detour not set, we need to create it
                            D3D12_COMMAND_QUEUE_DESC queueDesc;
                            queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
                            queueDesc.Priority = 0;
                            queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
                            queueDesc.NodeMask = 0;

                            ID3D12CommandQueue* queueTmp{};
                            if (menuData.dx12.d3dDevice->CreateCommandQueue(&queueDesc, __uuidof(ID3D12CommandQueue), (void**)&queueTmp) < 0) {
                                return hresf();
                            }
                            void* D3D12ExecuteCommandListsFunc = reinterpret_cast<void***>(queueTmp)[0][10];

                            D3D12ExecuteCommandListsDetour.Create(D3D12ExecuteCommandListsFunc, D3D12ExecuteCommandListsStub);
                            queueTmp->Release();
                            LOG_DEBUG("detour ExecuteCommandLists defined");
                        }
                        // we need to wait until the queue is defined
                        return hresf();
                    }

                    menuData.d3dType = MDT_D12;
                    DXGI_SWAP_CHAIN_DESC sd;
                    chain->GetDesc(&sd);
                    menuData.hwnd = sd.OutputWindow;
                    menuData.dx12.bufferCount = sd.BufferCount;
                    menuData.dx12.frames = new DX12FrameContext[sd.BufferCount];

                    D3D12_DESCRIPTOR_HEAP_DESC desc{};
                    desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
                    desc.NumDescriptors = sd.BufferCount;
                    desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
                    if (menuData.dx12.d3dDevice->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&menuData.dx12.descHeap)) != S_OK) {
                        LOG_ERROR("Can't create D12 descriptor heap");
                        return hresf();
                    }
                    ID3D12CommandAllocator* alloc{};
                    if (menuData.dx12.d3dDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&alloc)) != S_OK) {
                        return hresf();
                    }

                    for (size_t i = 0; i < sd.BufferCount; i++) {
                        menuData.dx12.frames[i].allocator = alloc;
                    }

                    if (menuData.dx12.d3dDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, alloc, NULL, IID_PPV_ARGS(&menuData.dx12.commandList)) != S_OK ||
                        menuData.dx12.commandList->Close() != S_OK) {
                        return hresf();
                    }

                    D3D12_DESCRIPTOR_HEAP_DESC descBuffs;
                    descBuffs.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
                    descBuffs.NumDescriptors = sd.BufferCount;
                    descBuffs.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
                    descBuffs.NodeMask = 1;

                    if (menuData.dx12.d3dDevice->CreateDescriptorHeap(&descBuffs, IID_PPV_ARGS(&menuData.dx12.descBuffers)) != S_OK) {
                        return hresf();
                    }

                    const UINT RTVDescriptorSize = menuData.dx12.d3dDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
                    D3D12_CPU_DESCRIPTOR_HANDLE rtv = menuData.dx12.descBuffers->GetCPUDescriptorHandleForHeapStart();

                    for (UINT i = 0; i < sd.BufferCount; i++) {
                        ID3D12Resource* pBackBuffer{};
                        menuData.dx12.frames[i].descriptorHandle = rtv;
                        chain->GetBuffer(i, IID_PPV_ARGS(&pBackBuffer));
                        menuData.dx12.d3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, rtv);
                        menuData.dx12.frames[i].resource = pBackBuffer;
                        rtv.ptr += RTVDescriptorSize;
                    }

                    menuData.wndProc = (WNDPROC)SetWindowLongPtr(menuData.hwnd, GWLP_WNDPROC, (LONG_PTR)WndProc);

                    menuData.init = true;
                    InitImGui();
                    LOG_DEBUG("ImGui init (D3D12)");
                }
                else {
                    static std::once_flag of{};
                    std::call_once(of, [] { LOG_ERROR("Can't get device imgui, unknown adapter?"); });
                    return hresf(); // Can't init imgui
                }
            }

            if (!menuData.useImGui) {
                return hresf();
            }

            ImGui_ImplWin32_NewFrame();
            switch (menuData.d3dType) {
            case MDT_D11: ImGui_ImplDX11_NewFrame(); break;
            case MDT_D12: ImGui_ImplDX12_NewFrame(); break;
            }
            ImGui::NewFrame();

            if (GetAsyncKeyState(VK_INSERT) & 1) {
                menuData.display = !menuData.display;
            }
            ImGuiIO& io = ImGui::GetIO();
            io.MouseDrawCursor = menuData.display;

            if (menuData.display) {
                HandleImGuiMenu();
            }
            ImGui::EndFrame();

            switch (menuData.d3dType) {
            case MDT_D11: {
                ImGui::Render();
                menuData.dx11.d3dContext->OMSetRenderTargets(1, &menuData.dx11.render, NULL);
                ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
            }
                break;
            case MDT_D12: {
                auto& ctx = menuData.dx12.frames[reinterpret_cast<IDXGISwapChain3*>(chain)->GetCurrentBackBufferIndex()];
                ctx.allocator->Reset();

                D3D12_RESOURCE_BARRIER barrier;
                barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
                barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
                barrier.Transition.pResource = ctx.resource;
                barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
                barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
                barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;

                menuData.dx12.commandList->Reset(ctx.allocator, NULL);
                menuData.dx12.commandList->ResourceBarrier(1, &barrier);
                menuData.dx12.commandList->OMSetRenderTargets(1, &ctx.descriptorHandle, FALSE, NULL);
                menuData.dx12.commandList->SetDescriptorHeaps(1, &menuData.dx12.descHeap);

                ImGui::Render();
                ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), menuData.dx12.commandList);

                barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
                barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
                menuData.dx12.commandList->ResourceBarrier(1, &barrier);
                menuData.dx12.commandList->Close();
                menuData.dx12.queue->ExecuteCommandLists(1, reinterpret_cast<ID3D12CommandList* const*>(&menuData.dx12.commandList));
            }
                break;
            }


            return hresf();
        }

        HRESULT CreateSwapChainStub(IDXGIFactory* factory, IUnknown* pDevice, DXGI_SWAP_CHAIN_DESC* pDesc, IDXGISwapChain** ppSwapChain) {
            HRESULT res = CreateSwapChainDetour.Call<HRESULT>(factory, pDevice, pDesc, ppSwapChain);

            if (SUCCEEDED(res)) {
                if (!PresentDetour) {
                    void* PresentFunc = (*reinterpret_cast<void***>(*ppSwapChain))[8];
                    LOG_DEBUG("Create swap chain {}", PresentFunc);
                    PresentDetour.Create(PresentFunc, PresentStub);
                }
            }
            else {
                LOG_WARNING("Can't create swap chain {:x}", res);
            }

            return res;
        }

        HRESULT CreateDXGI(const char* type, HRESULT res, void** ppFactory) {
            if (SUCCEEDED(res)) {
                if (!CreateSwapChainDetour) {
                    // add detour to the swap chain create function
                    void* CreateSwapChainFunc = (*reinterpret_cast<void***>(*ppFactory))[10];
                    LOG_DEBUG("Create DXGI with res {}/{} {}", type, (int)res, CreateSwapChainFunc);
                    CreateSwapChainDetour.Create(CreateSwapChainFunc, CreateSwapChainStub);
                }
            }
            else {
                LOG_WARNING("Can't create dxgi {:x}", res);
            }

            return res;
        }

        HRESULT __stdcall CreateDXGIFactoryStub(const IID* const riid, void** ppFactory) {
            return CreateDXGI("CreateDXGIFactory", CreateDXGIFactoryDetour.Call<HRESULT>(riid, ppFactory), ppFactory);
        }

        HRESULT __stdcall CreateDXGIFactory1Stub(const IID* const riid, void** ppFactory) {
            return CreateDXGI("CreateDXGIFactory1", CreateDXGIFactory1Detour.Call<HRESULT>(riid, ppFactory), ppFactory);
        }

        HRESULT __stdcall CreateDXGIFactory2Stub(UINT Flags, const IID* const riid, void** ppFactory) {
            return CreateDXGI("CreateDXGIFactory2", CreateDXGIFactory2Detour.Call<HRESULT>(Flags, riid, ppFactory), ppFactory);
        }
#pragma endregion

        void Empty() {}

        void InitDll() {
            try {
                core::logs::setfile("acts-bocw.log");
                core::logs::setlevel(core::logs::LVL_TRACE);
                hook::library::Library main{};
                std::string_view libname{ main.GetName() };
                if (libname.rfind("CrashHandler") != std::string::npos) {
                    LOG_DEBUG("ignore loading crash handler {}", libname);
                    return; // ignore crash handler
                }
                LOG_INFO("init acts dll pid={} name={}", GetCurrentProcessId(), libname);

                mainThread = GetCurrentThread();
                mainThreadId = GetCurrentThreadId();
                hook::error::EnableHeavyDump();
                hook::error::InstallErrorHooks(true);

                // clear error
                std::filesystem::path exepath{ main.GetPath()};
                std::filesystem::remove(exepath.replace_extension(".start"));
                // patch tls
                auto& tlsDir = main.GetOptHeader()->DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS];

                if (tlsDir.VirtualAddress && tlsDir.Size) {
                    IMAGE_TLS_DIRECTORY& tls = *reinterpret_cast<IMAGE_TLS_DIRECTORY*>(main[tlsDir.VirtualAddress]);
                    void** c = reinterpret_cast<void**>(main[tls.AddressOfCallBacks]);

                    while (c && *c) {
                        hook::memory::RedirectJmp(*c, Empty);
                        c++;
                    }
                }

                // kernel hooks
                hook::library::Library kernel32 = "kernel32.dll";
                hook::library::Library dxgi = "dxgi.dll";
                hook::library::Library user32 = "user32.dll";

                if (!kernel32) {
                    throw std::runtime_error("Can't find kernel32.dll");
                }
                if (!dxgi) {
                    throw std::runtime_error("Can't find dxgi.dll");
                }
                if (!user32) {
                    throw std::runtime_error("Can't find user32.dll");
                }

                // dxgi hooks
                if (menuData.useImGui) {
                    CreateDXGIFactoryDetour.Create(dxgi["CreateDXGIFactory"], CreateDXGIFactoryStub);
                    CreateDXGIFactory1Detour.Create(dxgi["CreateDXGIFactory1"], CreateDXGIFactory1Stub);
                    CreateDXGIFactory2Detour.Create(dxgi["CreateDXGIFactory2"], CreateDXGIFactory2Stub);
                }

                GetSystemMetricsDetour.Create(user32["GetSystemMetrics"], GetSystemMetricsStub);
                //ExitProcessDetour.Create(kernel32["ExitProcess"], ExitProcessStub);
                //GetThreadContextDetour.Create(kernel32["GetThreadContext"], GetThreadContextStub);
                //SetThreadContextDetour.Create(kernel32["SetThreadContext"], SetThreadContextStub);

                hook::library::InitScanContainer("acts");

                core::system::Init();
            }
            catch (std::exception& e) {
                LOG_ERROR("Error at ACTS DLL startup {}", e.what());
                MessageBoxA(NULL, utils::va("%s", e.what()), "Error at ACTS DLL startup", MB_ICONERROR);
                *reinterpret_cast<byte*>(0x123456789) = 2;
            }
        }
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        cw::InitDll();
    }
    return TRUE;
}

EXPORT void DLL_DecryptMTBuffer(size_t count) {
    LOG_INFO("Decrypting MT buffer...");
    cw::DecryptMTBuffer(count ? count : 0x100000);
    LOG_INFO("Done");
}

EXPORT void DLL_DecryptGSCScripts() {
    cw::DecryptGSCScripts();
}

// hook powrprof.dll for auto injection
EXPORT NTSTATUS CallNtPowerInformation(POWER_INFORMATION_LEVEL InformationLevel, PVOID InputBuffer, ULONG InputBufferLength, PVOID OutputBuffer, ULONG OutputBufferLength) {
    static auto func = [] {
        hook::library::Library powrprof{ "powrprof.dll", true };

        if (!powrprof) throw std::runtime_error(utils::va("can't find system powrprof.dll"));

        return reinterpret_cast<decltype(&CallNtPowerInformation)>(powrprof["CallNtPowerInformation"]);
    }();

    return func(InformationLevel, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength);
}
