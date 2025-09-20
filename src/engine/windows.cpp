#include "engine/windows.hpp"

#include <windows.h>
#include <dwmapi.h>

void registerWindowDarkMode(void* handle, bool value) {
    BOOL useImmersiveDarkMode = value ? TRUE : FALSE;
    HRESULT hr = DwmSetWindowAttribute(
        (HWND)handle,
        DWMWA_USE_IMMERSIVE_DARK_MODE,
        &useImmersiveDarkMode,
        sizeof(useImmersiveDarkMode)
    );
}