#pragma once
namespace core::actsinfo {
    // Do not write in this file, it is updated by premake
    constexpr unsigned int DEV_VERSION_ID = 0xFFFFFFFF;
#ifdef CI_BUILD

    // Version used for the release
    constexpr const char* VERSION = "2.10.5";
    constexpr const wchar_t* VERSIONW = L"2.10.5";
    constexpr unsigned int VERSION_ID = 0x200a005;

#else


#ifdef PRERELEASE_BUILD

    // prerelease
    constexpr const char* VERSION = "2.10.5-pre";
    constexpr const wchar_t* VERSIONW = L"2.10.5-pre";

#else

    constexpr const char* VERSION = "Dev";
    constexpr const wchar_t* VERSIONW = L"Dev";

#endif // PRERELEASE_BUILD
    // Disable updater
    constexpr unsigned int VERSION_ID = DEV_VERSION_ID;

#endif // CI_BUILD
}
