#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <limits.h>
#include <fstream>
#include <cstdlib>

using namespace std;

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

bool IsUserAdmin()
{
    BOOL isAdmin = FALSE;
    SID_IDENTIFIER_AUTHORITY ntAuth = SECURITY_NT_AUTHORITY;
    PSID adminGroup;
    if (AllocateAndInitializeSid(&ntAuth, 2, SECURITY_BUILTIN_DOMAIN_RID,
                                 DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminGroup))
    {
        if (!CheckTokenMembership(NULL, adminGroup, &isAdmin))
        {
            isAdmin = FALSE;
        }
        FreeSid(adminGroup);
    }
    return isAdmin == TRUE;
}


void downloadFile(string fileUrl, string fileName)
{
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    string saveDirectory(buffer);
    string command = "powershell -ExecutionPolicy Bypass -Command \"Invoke-WebRequest -Uri " + fileUrl + " -OutFile '" + saveDirectory + "\\" + fileName + "'\"";
    system(command.c_str());
}

