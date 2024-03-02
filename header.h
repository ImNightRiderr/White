#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <shlobj.h>
#include <cstdlib>
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

void findRecordingSoftware()
{
    vector<string> recordSoftwares = {"obs32.exe", "obs64.exe", "bdcam.exe", "Action.exe", "action_svc.exe", "XSplit.Core.exe", "RadeonSettings.exe", "ShareX.exe", "\"NVIDIA Share.exe\"", "CamRecorder.exe", "Fraps.exe"};
    vector<string> recordSoftwaresFinded(11);
    int nRecordSoftwaresFinded = 0;
    string baseCommand = "tasklist | findstr /i /C:";
    for (int i = 0; i < 11; i++)
    {
        string command = baseCommand + recordSoftwares[i];
        int result = system(command.c_str());
        if (result == 0)
        {
            recordSoftwaresFinded[nRecordSoftwaresFinded] = recordSoftwares[i];
            cout << "\x1B[34mSoftware Finder:\033[0m \x1B[36mTrovato " << recordSoftwaresFinded[nRecordSoftwaresFinded] << "\033[0m" << endl;
            nRecordSoftwaresFinded++;
        }
    }
    bool verifica = true;
    do
    {
        system("CLS");
        cout << "\x1B[34mScegli quale processo terminare o tornare indietro\033[0m" << endl;
        cout << "\x1B[34mNota:\033[0m \x1B[36mLe registrazioni in corso potrebbero venir corrotte o eliminate, scegliere responsabilmetne.\033[0m" << endl
             << endl;
        sleep(2);
        cout << "\x1B[34m[0]\033[0m \x1B[36mIndietro\033[0m" << endl;
        for (int i = 0; i < nRecordSoftwaresFinded; i++)
        {
            cout << "\x1B[34m[" << i + 1 << "]\033[0m \x1B[36m" << recordSoftwaresFinded[i] << "\033[0m" << endl;
        }
        string input;
        cin >> input;
        try
        {
            int correctInput = stoi(input);
            if (correctInput > nRecordSoftwaresFinded || correctInput < 0)
            {
                cout << "\x1B[34mErrore:\033[0m \x1B[36mdevi inserire un numero tra 0 e " << nRecordSoftwaresFinded << "\033[0m" << endl;
                sleep(2);
                verifica = true;
            }
            else
            {
                if (correctInput == 0)
                {
                    return;
                }
                string cmd = "taskkill /F /IM ";
                cmd += recordSoftwaresFinded[correctInput - 1];
                system(cmd.c_str());
                system("CLS");
                cout << "\x1B[34mKiller:\033[0m \x1B[36mprocesso " << recordSoftwaresFinded[correctInput - 1] << " terminato \033[0m" << endl;
                sleep(2);
                verifica = false;
            }
        }
        catch (const exception &e)
        {
            cout << "\x1B[34mErrore:\033[0m \x1B[36mdevi inserire un numero intero\033[0m" << endl;
            sleep(2);
            verifica = true;
        }
    } while (verifica);
    return;
}

bool checkRecordingSoftware()
{
    string command = "tasklist | findstr /i /C:obs32.exe /i /C:obs64.exe /i /C:bdcam.exe /i /C:Action.exe /i /C:action_svc.exe /i /C:XSplit.Core.exe /i /C:RadeonSettings.exe /i /C:ShareX.exe /i /C:\"NVIDIA Share.exe\" /i /C:CamRecorder.exe /i /C:Fraps.exe";
    int result = system(command.c_str());
    if (result != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
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
