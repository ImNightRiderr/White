
/*
 
                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
    By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/
#include "SecurityManager.h"
#include <windows.h>
#include <shellapi.h>
#include <string>
#include <iostream>

bool SecurityManager::isElevated() {
    BOOL fIsElevated = FALSE;
    HANDLE hToken = NULL;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
        TOKEN_ELEVATION elevation;
        DWORD dwSize;
        if (GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &dwSize)) {
            fIsElevated = elevation.TokenIsElevated;
        }
        CloseHandle(hToken);
    }
    return fIsElevated;
}

bool SecurityManager::elevateProcess(const char* extraArgs) {
    if (isElevated()) return true;
    wchar_t moduleName[MAX_PATH];
    GetModuleFileNameW(nullptr, moduleName, MAX_PATH);

    std::wstring params;
    if (extraArgs) {
        int len = MultiByteToWideChar(CP_UTF8, 0, extraArgs, -1, nullptr, 0);
        if (len > 0) {
            std::wstring wparams(len, L'\0');
            MultiByteToWideChar(CP_UTF8, 0, extraArgs, -1, &wparams[0], len);
            params = wparams;
        }
    }

    SHELLEXECUTEINFOW shellExecuteInfo = {0};
    shellExecuteInfo.cbSize = sizeof(SHELLEXECUTEINFOW);
    shellExecuteInfo.lpVerb = L"runas";
    shellExecuteInfo.lpFile = moduleName;
    shellExecuteInfo.lpParameters = params.empty() ? nullptr : params.c_str();
    shellExecuteInfo.hwnd = nullptr;
    shellExecuteInfo.nShow = SW_SHOW;
    return ShellExecuteExW(&shellExecuteInfo);
}

