#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <shlobj.h>
#include <vector>

using namespace std;

void openBrowser(string urlBrowser)
{
    string command = "start " + urlBrowser;
    system(command.c_str());
}

string password()
{
    string password;
    char ch;
    const int ENTER = 3;

    cout << "Inserisci la password: ";

    for (int i = 0; i < ENTER; i++)
    {
        ch = _getch();
        password += ch;
        cout << '*';
    }
    return password;
}

bool isElevated()
{
    HANDLE token;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token))
    {
        return false;
    }

    TOKEN_ELEVATION elevation;
    DWORD size;
    if (!GetTokenInformation(token, TokenElevation, &elevation, sizeof(elevation), &size))
    {
        CloseHandle(token);
        return false;
    }

    CloseHandle(token);
    return elevation.TokenIsElevated;
}

bool elevate()
{
    if (isElevated())
    {
        return true;
    }

    wchar_t moduleName[MAX_PATH];
    GetModuleFileNameW(nullptr, moduleName, MAX_PATH);
    SHELLEXECUTEINFOW shellExecuteInfo = {0};
    shellExecuteInfo.cbSize = sizeof(SHELLEXECUTEINFOW);
    shellExecuteInfo.lpVerb = L"runas";
    shellExecuteInfo.lpFile = moduleName;
    shellExecuteInfo.hwnd = nullptr;
    shellExecuteInfo.nShow = SW_SHOW;
    return ShellExecuteExW(&shellExecuteInfo);
}
