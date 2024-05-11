#include <includes.hpp>
#include "tools/tools_ui.hpp"
#include "actscli.hpp"

namespace {
	int lookuptool(Process& proc, int argc, const char* argv[]) {
		hashutils::ReadDefaultFile();
		for (int i = 2; i < argc; i++) {
			int64_t v = strtoull(argv[i], nullptr, 0x10);
			const char* extract = hashutils::ExtractPtr(v);
			if (extract) {
				LOG_INFO("{:x}={}", v, extract);
			}
			else {
				LOG_INFO("{:x}=can't be find", v);
			}
		}
		return 0;
	}

	int hash32(Process& proc, int argc, const char* argv[]) {
		for (int i = 2; i < argc; i++) {
			LOG_INFO("{}={:x}", argv[i], hashutils::Hash32(argv[i]));
		}
		return 0;
	}

	int hash64(Process& proc, int argc, const char* argv[]) {
		uint64_t sur;
		int i = 2;
		if (argc >= 3 && !_strcmpi("--iw", argv[2])) {
			sur = 0x47F5817A5EF961BA;
			i++;
			LOG_INFO("(iw)");
		}
		else {
			sur = 0xcbf29ce484222325LL;
		}
		for (; i < argc; i++) {
			LOG_INFO("{}={:x}", argv[i], hashutils::Hash64(argv[i], sur));
		}
		return 0;
	}

	int collisiontool(Process& proc, int argc, const char* argv[]) {
		LOG_INFO("Searching...");
		const char* file = actscli::options().defaultHashFile;

		if (!file) {
			file = hashutils::DEFAULT_HASH_FILE;
		}
		int issues = hashutils::LoadMap(file, false);

		if (issues) {
			LOG_ERROR("Found {} collision(s)", issues);
			return tool::BASIC_ERROR;
		}

		LOG_INFO("No collision.");
		return tool::OK;
	}

    struct {
		std::string hash{};
        HWND hashEdit{};
		HWND hashEditLabel{};

		HWND hash64Edit{};
		HWND hash64EditLabel{};
		HWND hash32Edit{};
		HWND hash32EditLabel{};
		HWND hash64IW2Edit{};
		HWND hash64IW2EditLabel{};
		HWND hash64IW3Edit{};
		HWND hash64IW3EditLabel{};
		HWND hash32IW4Edit{};
		HWND hash32IW4EditLabel{};

		HWND titleLabel{};
    } info{};

	void ComputeHashes() {
		info.hash = utils::WStrToStr(tool::ui::GetWindowTextVal(info.hashEdit));


		std::wstring hash64Val = std::format(L"{:x}", hash::Hash64(info.hash.c_str()));
		std::wstring hash32Val = std::format(L"{:x}", hash::Hash32(info.hash.c_str()));
		std::wstring hash64IW2Val = std::format(L"{:x}", hashutils::HashAIW(info.hash.c_str()));
		std::wstring hash64IW3Val = std::format(L"{:x}", hashutils::HashAIW2(info.hash.c_str()));
		std::wstring hash32IW4Val = std::format(L"{:x}", hashutils::Hash64(info.hash.c_str(), 0x811C9DC5, 0x1000193) & 0xFFFFFFFF);

		Edit_SetText(info.hash64Edit, hash64Val.c_str());
		Edit_SetText(info.hash32Edit, hash32Val.c_str());
		Edit_SetText(info.hash64IW2Edit, hash64IW2Val.c_str());
		Edit_SetText(info.hash64IW3Edit, hash64IW3Val.c_str());
		Edit_SetText(info.hash32IW4Edit, hash32IW4Val.c_str());
	}

    int Render(HWND window, HINSTANCE hInstance) {
		std::wstring hashw = utils::StrToWStr(info.hash);

		info.titleLabel = CreateWindowEx(
			0,
			L"STATIC",
			L"Hash",
			SS_CENTER | WS_CHILD | WS_VISIBLE,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hashEdit = CreateWindowExW(
			0,
			L"EDIT",
			hashw.c_str(),
			WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hashEditLabel = CreateWindowEx(
			0,
			L"STATIC",
			L"String : ",
			SS_RIGHT | WS_CHILD | WS_VISIBLE,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hash64Edit = CreateWindowExW(
			0,
			L"EDIT",
			L"",
			WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hash64EditLabel = CreateWindowEx(
			0,
			L"STATIC",
			L"FNV1A : ",
			SS_RIGHT | WS_CHILD | WS_VISIBLE,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hash32Edit = CreateWindowExW(
			0,
			L"EDIT",
			L"",
			WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hash32EditLabel = CreateWindowEx(
			0,
			L"STATIC",
			L"ARC Canon : ",
			SS_RIGHT | WS_CHILD | WS_VISIBLE,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hash64IW2Edit = CreateWindowExW(
			0,
			L"EDIT",
			L"",
			WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hash64IW2EditLabel = CreateWindowEx(
			0,
			L"STATIC",
			L"IW Resource : ",
			SS_RIGHT | WS_CHILD | WS_VISIBLE,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hash64IW3Edit = CreateWindowExW(
			0,
			L"EDIT",
			L"",
			WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hash64IW3EditLabel = CreateWindowEx(
			0,
			L"STATIC",
			L"IW Canon : ",
			SS_RIGHT | WS_CHILD | WS_VISIBLE,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hash32IW4Edit = CreateWindowExW(
			0,
			L"EDIT",
			L"",
			WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

		info.hash32IW4EditLabel = CreateWindowEx(
			0,
			L"STATIC",
			L"IW Tag : ",
			SS_RIGHT | WS_CHILD | WS_VISIBLE,
			0, 0, 0, 0,
			window,
			NULL,
			hInstance,
			NULL
		);

        if (
            info.hashEdit == NULL
			|| info.hashEditLabel == NULL
			|| info.hash64Edit == NULL
			|| info.hash64EditLabel == NULL
			|| info.hash32Edit == NULL
			|| info.hash32EditLabel == NULL
			|| info.hash64IW2Edit == NULL
			|| info.hash64IW2EditLabel == NULL
			|| info.hash64IW3Edit == NULL
			|| info.hash64IW3EditLabel == NULL
			|| info.hash32IW4Edit == NULL
			|| info.hash32IW4EditLabel == NULL
			|| info.titleLabel == NULL
            ) {
            return -1;
        }

		SendMessage(info.hashEdit, EM_SETLIMITTEXT, (WPARAM)MAX_PATH, (LPARAM)0);
		SendMessage(info.hash64Edit, EM_SETLIMITTEXT, (WPARAM)MAX_PATH, (LPARAM)0);
		SendMessage(info.hash32Edit, EM_SETLIMITTEXT, (WPARAM)MAX_PATH, (LPARAM)0);
		SendMessage(info.hash64IW2Edit, EM_SETLIMITTEXT, (WPARAM)MAX_PATH, (LPARAM)0);
		SendMessage(info.hash64IW3Edit, EM_SETLIMITTEXT, (WPARAM)MAX_PATH, (LPARAM)0);
		SendMessage(info.hash32IW4Edit, EM_SETLIMITTEXT, (WPARAM)MAX_PATH, (LPARAM)0);

		Edit_SetReadOnly(info.hash64Edit, true);
		Edit_SetReadOnly(info.hash32Edit, true);
		Edit_SetReadOnly(info.hash64IW2Edit, true);
		Edit_SetReadOnly(info.hash64IW3Edit, true);
		Edit_SetReadOnly(info.hash32IW4Edit, true);

		ComputeHashes();

        return 0;
    }

    LRESULT Update(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        if (uMsg == WM_COMMAND) {
            if (HIWORD(wParam) == EN_CHANGE) {
                if (info.hashEdit == (HWND)lParam) {
					ComputeHashes();
                }
            }
        }
        else if (uMsg == WM_CTLCOLORSTATIC) {
            if (lParam == (LPARAM)info.hashEdit
                || lParam == (LPARAM)info.hashEditLabel
				|| lParam == (LPARAM)info.hash64Edit
				|| lParam == (LPARAM)info.hash64EditLabel
				|| lParam == (LPARAM)info.hash32Edit
				|| lParam == (LPARAM)info.hash32EditLabel
				|| lParam == (LPARAM)info.hash64IW2Edit
				|| lParam == (LPARAM)info.hash64IW2EditLabel
				|| lParam == (LPARAM)info.hash64IW3Edit
				|| lParam == (LPARAM)info.hash64IW3EditLabel
				|| lParam == (LPARAM)info.hash32IW4Edit
				|| lParam == (LPARAM)info.hash32IW4EditLabel
				|| lParam == (LPARAM)info.titleLabel
                ) {
                return 0;
            }
        }
        return 1;
    }
	void Resize(int width, int height) {
		int y{ height / 2 - 28 * 4 };
		SetWindowPos(info.titleLabel, NULL, 0, y - 68, width, 60, SWP_SHOWWINDOW);

		SetWindowPos(info.hashEdit, NULL, width / 2 - 250, y, 500, 24, SWP_SHOWWINDOW);
		SetWindowPos(info.hashEditLabel, NULL, 0, y, width / 2 - 250, 24, SWP_SHOWWINDOW);
		y += 28;
		SetWindowPos(info.hash64Edit, NULL, width / 2 - 250, y, 500, 24, SWP_SHOWWINDOW);
		SetWindowPos(info.hash64EditLabel, NULL, 0, y, width / 2 - 250, 24, SWP_SHOWWINDOW);
		y += 28;
		SetWindowPos(info.hash32Edit, NULL, width / 2 - 250, y, 500, 24, SWP_SHOWWINDOW);
		SetWindowPos(info.hash32EditLabel, NULL, 0, y, width / 2 - 250, 24, SWP_SHOWWINDOW);
		y += 28;
		SetWindowPos(info.hash64IW2Edit, NULL, width / 2 - 250, y, 500, 24, SWP_SHOWWINDOW);
		SetWindowPos(info.hash64IW2EditLabel, NULL, 0, y, width / 2 - 250, 24, SWP_SHOWWINDOW);
		y += 28;
		SetWindowPos(info.hash64IW3Edit, NULL, width / 2 - 250, y, 500, 24, SWP_SHOWWINDOW);
		SetWindowPos(info.hash64IW3EditLabel, NULL, 0, y, width / 2 - 250, 24, SWP_SHOWWINDOW);
		y += 28;
		SetWindowPos(info.hash32IW4Edit, NULL, width / 2 - 250, y, 500, 24, SWP_SHOWWINDOW);
		SetWindowPos(info.hash32IW4EditLabel, NULL, 0, y, width / 2 - 250, 24, SWP_SHOWWINDOW);
		y += 28;

		tool::ui::window().SetTitleFont(info.titleLabel);
	}
}
ADD_TOOL_UI("hash", L"Hash", Render, Update, Resize);

ADD_TOOL("lookup", " (string)*", "lookup strings", nullptr, lookuptool);
ADD_TOOL("h32", " (string)*", "hash strings", nullptr, hash32);
ADD_TOOL("h64", " (string)*", "hash strings", nullptr, hash64);
ADD_TOOL("str", "", "check collisions in the string file", nullptr, collisiontool);
