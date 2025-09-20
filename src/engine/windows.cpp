#include "engine/windows.hpp"

#include <windows.h>
#include <dwmapi.h>

namespace WindowsWrappers {
    void applyWindowDarkModeSetting(void* handle) {
        BOOL useImmersiveDarkMode = isDarkModeEnabled() ? TRUE : FALSE;
        DwmSetWindowAttribute(
            (HWND)handle,
            DWMWA_USE_IMMERSIVE_DARK_MODE,
            &useImmersiveDarkMode,
            sizeof(useImmersiveDarkMode)
        );
    }

    bool isDarkModeEnabled(void) {
        DWORD value;
        DWORD valueSize = sizeof(value);
        LONG result = RegGetValue(
            HKEY_CURRENT_USER,
            TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize"),
            TEXT("AppsUseLightTheme"),
            RRF_RT_REG_DWORD,
            nullptr,
            &value,
            &valueSize
        );

        return (result == ERROR_SUCCESS && value == 0); // 0 means dark mode is enabled
    }
}