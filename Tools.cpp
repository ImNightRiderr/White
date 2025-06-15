/* 

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
        By using this software, you accept the terms of service and the licence.
            License: https://github.com/ImNightRiderr/White/blob/main/LICENSE

                ##########################################

*/

#include "Utils.h"
#include "Tools.h"
#include "FileSystem.h"
#include "Config.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <tlhelp32.h>
#include <psapi.h>

void Tools::downloadManualTool(int toolId) {
    try {
        auto loading = LoadingAnimation::start(Language::Current::DOWNLOADING);
        switch (toolId) {
            case 1:  FileSystem::downloadFile(Config::PROCESS_HACKER.url, Config::PROCESS_HACKER.filename); break; 
            case 2:  FileSystem::downloadFile("https://www.nirsoft.net/utils/lastactivityview.zip", "lastactivityview.zip"); break; 
            case 3:  FileSystem::downloadFile("https://www.nirsoft.net/utils/winprefetchview-x64.zip", "winprefetchview-x64.zip"); break; 
            case 4:  FileSystem::downloadFile("https://github.com/deathmarine/Luyten/releases/download/v0.5.4_Rebuilt_with_Latest_depenencies/luyten-0.5.4.exe", "luyten.exe"); break;
            case 5:  FileSystem::downloadFile("https://www.voidtools.com/Everything-1.4.1.1027.x64.zip", "Everything-x64.zip"); break;
            case 6:  FileSystem::downloadFile("https://www.nirsoft.net/utils/alternatestreamview-x64.zip", "alternatestreamview-x64.zip"); break; 
            case 7:  FileSystem::downloadFile("https://www.nirsoft.net/utils/previousfilesrecovery-x64.zip", "previousfilesrecovery-x64.zip"); break; 
            case 8:  FileSystem::downloadFile("https://www.nirsoft.net/utils/regscanner-x64.zip", "regscanner-x64.zip"); break;
            case 9:  FileSystem::downloadFile("https://www.nirsoft.net/utils/usbdeview-x64.zip", "usbdeview-x64.zip"); break; 
            case 10: FileSystem::downloadFile("https://www.nirsoft.net/utils/loadeddllsview-x64.zip", "loadeddllsview-x64.zip"); break; 
            case 11: FileSystem::downloadFile("https://www.nirsoft.net/utils/processactivityview-x64.zip", "processactivityview-x64.zip"); break; 
            case 12: FileSystem::downloadFile("https://www.nirsoft.net/utils/executedprogramslist.zip", "executedprogramslist-x64.zip"); break; 
            case 13: FileSystem::downloadFile("https://www.nirsoft.net/utils/browserdownloadsview-x64.zip", "browserdownloadsview.zip"); break; 
            case 14: FileSystem::downloadFile("https://www.nirsoft.net/utils/browsinghistoryview-x64.zip", "browserhistoryview.zip"); break;
            case 15: FileSystem::downloadFile("https://www.nirsoft.net/utils/shellbagsview.zip", "shellbagsview.zip"); break; 
            case 16: FileSystem::downloadFile("https://www.nirsoft.net/utils/userassistview.zip", "userassistview.zip"); break;
            case 17: FileSystem::downloadFile("https://www.nirsoft.net/utils/myeventviewer-x64.zip", "myeventviewer-x64.zip"); break; 
            case 18: FileSystem::downloadFile("https://www.nirsoft.net/utils/injecteddll.zip", "injecteddll.zip"); break; 
            case 19: FileSystem::downloadFile("https://www.nirsoft.net/utils/ofview-x64.zip", "OpenedFilesView-x64.zip"); break; 
            case 20: FileSystem::downloadFile("https://www.nirsoft.net/utils/recentfilesview.zip", "recentfileview.zip"); break; 
            case 21: FileSystem::downloadFile("https://www.nirsoft.net/utils/muicacheview.zip", "muicacheview.zip"); break;
            case 22: FileSystem::downloadFile("https://www.nirsoft.net/utils/regdllview-x64.zip", "regdllview-x64.zip"); break; 
        }
        loading.reset();
    } catch (const std::exception& e) {
        std::cerr << Config::COLOR_ERROR << Language::Current::ERR << " " << e.what() 
                  << Config::COLOR_RESET << std::endl;
        system("PAUSE");
    }
}

void Tools::downloadAutoTool(int toolId) {
    switch (toolId) {
        case 1: FileSystem::openBrowser("https://dl.avenge.ac"); break;
        case 2: FileSystem::openBrowser("https://dl.echo.ac"); break;
        case 3: FileSystem::openBrowser("https://dl.paladin.ac"); break;
    }
}

void Tools::executeJournalCommand(int commandId) {
    switch (commandId) {
        case 1: 
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00000800\" | findstr /i /C:\".exe\"",
                "\\securityChanges.txt"
            );
            break;
        case 2: 
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00000100\" | findstr /i /C:\"explorer\" /C:\".pf\"",
                "\\restartExplorer.txt"
            );
            break;
        case 3: 
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x80000200\" | findstr /i /C:\".exe\" /C:\".py\" /C:\".jar\" /C:\".dll\" /C:\".com\" /C:\".pif\" /C:\".txt\" /C:\".jpg\" /C:\".jpeg\" /C:\".png\" /C:\".lnk\" /C:\".mp3\" /C:\".mp4\" /C:\".mkv\" /C:\".avi\" /C:\".ico\" /C:\".bat\" /C:\".cmd\" /C:\".reg\" /C:\".zip\" /C:\".rar\" /C:\".7z\" /C:\".ini\" /C:\".html\" /C:\".ppt\" /C:\".docx\" /C:\".xlsx\" /C:\".chm\" /C:\".aspx\" /C:\".app\" /C:\"?\"",
                "\\deletedFiles.txt"
            );
            break;
        case 4: 
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00002020\" /C:\"0x00000020\" /C:\"0x00200000\" | findstr /i /C:\"0x80008000\" /C:\"0x00008006\" /C:\"0x80200120\" | findstr /i /C:\".exe\" /C:\".py\" /C:\".jar\" /C:\".dll\" /C:\".com\" /C:\".pif\" /C:\".txt\" /C:\".jpg\" /C:\".jpeg\" /C:\".png\" /C:\".lnk\" /C:\".mp3\" /C:\".mp4\" /C:\".mkv\" /C:\".avi\" /C:\".ico\" /C:\".bat\" /C:\".cmd\" /C:\".reg\" /C:\".zip\" /C:\".rar\" /C:\".7z\" /C:\".ini\" /C:\".html\" /C:\".ppt\" /C:\".docx\" /C:\".xlsx\" /C:\".chm\" /C:\".aspx\" /C:\".app\" /C:\"?\"",
                "\\renamedfiles.txt"
            );
            break;
        case 5:
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00200120\"",
                "\\fileStreams.txt"
            );
            break;
        case 6: 
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00000004\" /C:\"0x00000102\" | findstr /i /C:\"jar_cache\" /C:\".timestamp\"",
                "\\jarCache.txt"
            );
            break;
        case 7: 
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00000100\" | findstr /i /C:\".exe\" /C:\".dll\" /C:\".sys\"",
                "\\fileCreation.txt"
            );
            break;
        case 8:
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00000002\" | findstr /i /C:\".exe\" /C:\".dll\" /C:\".sys\" /C:\".dat\"",
                "\\dataChange.txt"
            );
            break;
        case 9:
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00001000\" | findstr /i /C:\".exe\" /C:\".dll\" /C:\".dat\" /C:\".tmp\" /C:\".bak\"",
                "\\extensionChange.txt"
            );
            break;
        case 10:
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00000100\" | findstr /i /C:\"\\Windows\\System32\" /C:\"\\Windows\\SysWOW64\"",
                "\\systemFiles.txt"
            );
            break;
        case 11:
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00000100\" | findstr /i /C:\"\\Temp\\\" /C:\"\\AppData\\Local\\Temp\\\"",
                "\\tempFiles.txt"
            );
            break;
        case 12: 
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00000100\" | findstr /i /C:\"\\Downloads\\\"",
                "\\downloads.txt"
            );
            break;
        case 13: 
            FileSystem::executeJournal(
                "fsutil usn readjournal c: csv | findstr /i /C:\"0x00000100\" | findstr /i /C:\"\\services\" /C:\".service\"",
                "\\serviceChanges.txt"
            );
            break;
        default:
            std::cerr << Config::COLOR_ERROR << Language::Current::ERR << Language::Current::INVALID_COMMAND_ID
                      << Config::COLOR_RESET << std::endl;
            return;
    }
}

void Tools::executeRegistryCommand(int commandId) {
    switch (commandId) {
        case 1: 
            FileSystem::openRegedit("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\PrefetchParameters");
            break;
        case 2: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Compatibility Assistant\\Store");
            break;
        case 3: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\SOFTWARE\\WinRAR\\ArcHistory");
            break;
        case 4: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU");
            break;
        case 5: 
            FileSystem::openRegedit("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\bam\\State\\UserSettings");
            break;
        case 6: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\Shell\\MuiCache");
            break;
        case 7: 
            FileSystem::openRegedit("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Enum\\USB");
            break;
        case 8: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\Software\\Microsoft\\DirectInput\\MostRecentApplication");
            break;
        case 9: 
            FileSystem::openRegedit("HKEY_CLASSES_ROOT\\LocalSettings\\Software\\Microsoft\\Windows\\Shell\\MuiCache");
            break;
        case 10: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU\\*");
            break;
        case 11: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\.dll");
            break;
        case 12: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts");
            break;
        case 13: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\LastVisitedPidlMRU");
            break;
        case 14: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32");
            break;
        case 15: 
            FileSystem::openRegedit("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU");
            break;
    }
}

void Tools::executeEventViewerCommand(int commandId) {
    system("CLS");
    auto loading = LoadingAnimation::start(Language::Current::EVENT_VIEWER_LOADING);

    std::string command = "powershell -NoProfile -NonInteractive -Command \"";
    switch (commandId) {
        case 1:
            command += "$ErrorActionPreference = 'SilentlyContinue'; Get-WinEvent -FilterHashtable @{LogName='Security';ID=4616} -MaxEvents 5";
            break;
        case 2:
            command += "$ErrorActionPreference = 'SilentlyContinue'; Get-WinEvent -FilterHashtable @{LogName='Security';ID=1102} -MaxEvents 5";
            break;
        case 3:
            command += "$ErrorActionPreference = 'SilentlyContinue'; Get-WinEvent -FilterHashtable @{LogName='Application';ID=3079} -MaxEvents 5";
            break;
        case 4:
            command += "$ErrorActionPreference = 'SilentlyContinue'; Get-WinEvent -LogName 'Microsoft-Windows-Ntfs/Operational' -FilterXPath '*[System[EventID=501]]' -MaxEvents 5";
            break;
        case 5:
            command += "$ErrorActionPreference = 'SilentlyContinue'; Get-WinEvent -ListLog 'Microsoft-Windows-Ntfs/Operational' | Select-Object IsEnabled";
            break;
        default:
            loading.reset();
            std::cout << Config::COLOR_ERROR << Language::Current::INVALID_COMMAND_ID << Config::COLOR_RESET << std::endl;
            return;
    }
    command += " | Format-Table -AutoSize; exit $LASTEXITCODE\" 2>nul";

    loading.reset();
    system("CLS");
    
    FILE* pipe = _popen(command.c_str(), "r");
    if (pipe) {
        char buffer[128];
        std::string result;
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
        _pclose(pipe);
        
        if (result.empty() || result.find("No events found") != std::string::npos) {
            std::cout << Config::COLOR_CYAN << Language::Current::NO_EVENTS_FOUND << Config::COLOR_RESET << std::endl;
        } else {
            std::cout << Config::COLOR_CYAN << result << Config::COLOR_RESET;
        }
    }
}

void Tools::executeBamAnalysis() {
    system("CLS");
    auto loading = LoadingAnimation::start(Language::Current::BAM_SEARCHING);
    std::string scriptPath = Config::BASE_PATH + "\\script.ps1";
    std::ofstream file(scriptPath);
    if (!file.is_open()) {
        std::cerr << Config::COLOR_ERROR << Language::Current::TEMP_FILE_ERROR
                  << Config::COLOR_RESET << std::endl;
        system("PAUSE");
        return;
    }

    file << Config::BAM_SCRIPT;
    file.close();

    std::string command = "powershell -ExecutionPolicy ByPass -File \"" + scriptPath + "\" 2>&1";
    int result = system(command.c_str());
    
    if (result != 0) {
        std::cout << Config::COLOR_ERROR << Language::Current::BAM_SCRIPT_ERROR 
                  << Config::COLOR_RESET << std::endl;
    }

    if (std::remove(scriptPath.c_str()) != 0) {
        system(("del /F \"" + scriptPath + "\"").c_str());
    }

    std::cout << "\n" << Language::Current::PRESS_KEY << std::endl;
    _getch();
}

void Tools::macroSoftwareFinder() {
    auto loading = LoadingAnimation::start(Language::Current::SEARCHING);

    std::vector<std::string> foundPaths;
    std::string userFolder = FileSystem::getUserDirectory();
    char systemDrive[MAX_PATH] = "C:";
    DWORD size = GetEnvironmentVariableA("SystemDrive", systemDrive, MAX_PATH);

    for (const auto& rawPath : programPaths) {
        std::string path = rawPath;

        size_t pos = path.find("USERNAME");
        if (pos != std::string::npos) {
            char username[256];
            DWORD username_len = 256;
            GetUserNameA(username, &username_len);
            path.replace(pos, 9, username);
        }

        if (path.find("AppData") == 0) {
            path = userFolder + "\\" + path;
        }

        else if (path.find("Users\\") == 0) {
            path = std::string(systemDrive) + "\\" + path;
        }

        else if (path.find("Program Files") == 0 || path.find("ProgramData") == 0) {
            path = std::string(systemDrive) + "\\" + path;
        }

        if (FileSystem::directoryExists(path)) {
            foundPaths.push_back(path);
            std::cout << Config::COLOR_BLUE << Language::Current::FOUND_SOFTWARE << Config::COLOR_RESET 
                      << Config::COLOR_CYAN << " " << path << Config::COLOR_RESET << std::endl;
        }
    }
    if (!foundPaths.empty()) {
        handleMacroPathsSelection(foundPaths);
    }
}

void Tools::handleMacroPathsSelection(const std::vector<std::string>& foundPaths) {
    bool done = false;
    while (!done) {
        system("CLS");
        std::cout << Config::COLOR_BLUE << Language::Current::OPEN_DIR_CHOICE
                  << Config::COLOR_RESET << std::endl;
        std::cout << Config::COLOR_BLUE << "[0]" << Config::COLOR_RESET 
                  << Config::COLOR_CYAN << " " << Language::Current::BACK << Config::COLOR_RESET << std::endl;
        for (size_t i = 0; i < foundPaths.size(); i++) {
            std::cout << Config::COLOR_BLUE << "[" << i + 1 << "]" << Config::COLOR_RESET
                      << Config::COLOR_CYAN << " " << foundPaths[i] << Config::COLOR_RESET << std::endl;
        }
        std::string input;
        std::getline(std::cin, input);
        try {
            int choice = std::stoi(input);
            if (choice == 0) return;
            if (choice > 0 && choice <= static_cast<int>(foundPaths.size())) {
                ShellExecuteA(nullptr, "open", foundPaths[choice-1].c_str(), 
                            nullptr, nullptr, SW_SHOWNORMAL);
                done = true;
            }
        }
        catch (...) {
            std::cout << Config::COLOR_ERROR << Language::Current::ERR << " " << Language::Current::MUST_BE_NUMBER
                      << Config::COLOR_RESET << std::endl;
            Sleep(1000);
        }
    }
}

void Tools::cleanMainDirectory() {
    std::string path = Config::BASE_PATH;
    if (FileSystem::directoryExists(path)) {
        std::string command = "rd /S /Q \"" + path + "\"";
        int result = system(command.c_str());
        if (result != 0) {
            command = "powershell.exe -Command \"Remove-Item -Path '" + path + 
                     "' -Recurse -Force -ErrorAction SilentlyContinue\"";
            system(command.c_str());
        }
    }
}

bool Tools::isProcessRunning(const std::string& processName) {
    HANDLE hProcessSnap;
    PROCESSENTRY32W pe32;
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
        return false;
    pe32.dwSize = sizeof(PROCESSENTRY32W);
    if (!Process32FirstW(hProcessSnap, &pe32)) {
        CloseHandle(hProcessSnap);
        return false;
    }
    std::wstring wProcessName(processName.begin(), processName.end());
    do {
        if (_wcsicmp(pe32.szExeFile, wProcessName.c_str()) == 0) {
            CloseHandle(hProcessSnap);
            return true;
        }
    } while (Process32NextW(hProcessSnap, &pe32));
    CloseHandle(hProcessSnap);
    return false;
}


const std::vector<std::string> programPaths = {
    "Program Files (x86)\\Trust",
    "Program Files\\Trust",
    "Users\\USERNAME\\AppData\\Local\\Trust",
    "Program Files (x86)\\Bloody7",
    "Program Files\\Bloody7",
    "Users\\USERNAME\\AppData\\Local\\Bloody7",
    "Program Files (x86)\\Glorious Core",
    "Program Files\\Glorious Core",
    "Users\\USERNAME\\AppData\\Local\\Glorious Core",
    "Program Files\\SteelSeries",
    "Program Files (x86)\\SteelSeries",
    "Users\\USERNAME\\AppData\\Local\\SteelSeries",
    "ProgramData\\Razer\\Synapse\\Accounts",
    "Program Files\\Razer\\Synapse3",
    "Program Files (x86)\\Razer\\Synapse3",
    "Users\\USERNAME\\AppData\\Local\\Razer\\Synapse3",
    "Users\\USERNAME\\AppData\\Roaming\\Razer\\Synapse3",
    "AppData\\Local\\Logitech\\Logitech Gaming Software\\profiles",
    "Program Files\\Logitech\\Logitech Gaming Software",
    "Program Files (x86)\\Logitech\\Logitech Gaming Software",
    "AppData\\Local\\LGHUB",
    "Program Files\\LGHUB",
    "Program Files (x86)\\LGHUB",
    "AppData\\Local\\Razer\\Synapse3\\Settings",
    "AppData\\Roaming\\Corsair\\Cue",
    "Program Files\\Corsair\\Cue",
    "Program Files (x86)\\Corsair\\Cue",
    "Program Files\\Corsair\\Corsair Utility Engine",
    "Program Files (x86)\\Corsair\\Corsair Utility Engine",
    "Users\\USERNAME\\AppData\\Roaming\\Corsair",
    "AppData\\Local\\BY-COMBO2",
    "Program Files\\BY-COMBO2",
    "Program Files (x86)\\BY-COMBO2",
    "AppData\\Local\\JM01",
    "Program Files\\JM01",
    "Program Files (x86)\\JM01",
    "Program Files\\AutoHotkey",
    "Program Files (x86)\\AutoHotkey",
    "AppData\\Roaming\\AutoHotkey",
    "Users\\USERNAME\\AppData\\Local\\AutoHotkey",
    "Users\\USERNAME\\AppData\\Roaming\\AutoHotkey",
    "Program Files\\X-Mouse Button Control",
    "Program Files (x86)\\X-Mouse Button Control",
    "Users\\USERNAME\\AppData\\Local\\Highresolution Enterprises\\X-Mouse Button Control",
    "Program Files\\Macro Recorder",
    "Program Files (x86)\\Macro Recorder",
    "Users\\USERNAME\\AppData\\Local\\Macro Recorder",
    "Program Files\\Pulover's Macro Creator",
    "Program Files (x86)\\Pulover's Macro Creator",
    "Users\\USERNAME\\AppData\\Local\\Pulover's Macro Creator",
    "Program Files\\Keyran",
    "Program Files (x86)\\Keyran",
    "Users\\USERNAME\\AppData\\Local\\Keyran",
    "Program Files\\GS Auto Clicker",
    "Program Files (x86)\\GS Auto Clicker",
    "Users\\USERNAME\\AppData\\Local\\GS Auto Clicker",
    "Program Files\\TinyTask",
    "Program Files (x86)\\TinyTask",
    "Users\\USERNAME\\AppData\\Local\\TinyTask",
    "Program Files\\OP Auto Clicker",
    "Program Files (x86)\\OP Auto Clicker",
    "Users\\USERNAME\\AppData\\Local\\OP Auto Clicker",
    "Program Files\\Razer\\Razer Synapse",
    "Program Files (x86)\\Razer\\Razer Synapse",
    "Users\\USERNAME\\AppData\\Local\\Razer\\Razer Synapse",
    "Program Files\\Corsair\\Corsair Utility Engine",
    "Program Files (x86)\\Corsair\\Corsair Utility Engine",
    "Program Files\\Logitech Gaming Software",
    "Program Files (x86)\\Logitech Gaming Software",
    "Program Files\\Logitech\\G HUB",
    "Program Files (x86)\\Logitech\\G HUB",
    "Users\\USERNAME\\AppData\\Local\\Logitech\\G HUB",
    "Program Files\\Bloody5",
    "Program Files (x86)\\Bloody5",
    "Program Files\\Bloody6",
    "Program Files (x86)\\Bloody6",
    "Users\\USERNAME\\AppData\\Local\\Bloody5",
    "Users\\USERNAME\\AppData\\Local\\Bloody6",
    "Program Files\\A4Tech",
    "Program Files (x86)\\A4Tech",
    "Users\\USERNAME\\AppData\\Local\\A4Tech",
    "Program Files\\Redragon",
    "Program Files (x86)\\Redragon",
    "Users\\USERNAME\\AppData\\Local\\Redragon",
    "Program Files\\Ducky",
    "Program Files (x86)\\Ducky",
    "Users\\USERNAME\\AppData\\Local\\Ducky",
    "Program Files\\ROCCAT",
    "Program Files (x86)\\ROCCAT",
    "Users\\USERNAME\\AppData\\Local\\ROCCAT",
    "Program Files\\HyperX NGenuity",
    "Program Files (x86)\\HyperX NGenuity",
    "Users\\USERNAME\\AppData\\Local\\HyperX NGenuity",
    "Program Files\\Cooler Master",
    "Program Files (x86)\\Cooler Master",
    "Users\\USERNAME\\AppData\\Local\\Cooler Master",
    "Program Files\\Mad Catz",
    "Program Files (x86)\\Mad Catz",
    "Users\\USERNAME\\AppData\\Local\\Mad Catz",
    "Program Files\\AutoIt3",
    "Program Files (x86)\\AutoIt3",
    "Program Files\\Auto Key Presser",
    "Program Files (x86)\\Auto Key Presser",
    "Program Files\\Auto Keyboard",
    "Program Files (x86)\\Auto Keyboard",
    "Program Files\\Auto Mouse Click",
    "Program Files (x86)\\Auto Mouse Click",
    "Program Files\\Perfect Automation",
    "Program Files (x86)\\Perfect Automation",
    "Program Files\\Jitbit Macro Recorder",
    "Program Files (x86)\\Jitbit Macro Recorder",
    "Program Files\\GhostMouse",
    "Program Files (x86)\\GhostMouse",
    "Program Files\\Mini Mouse Macro",
    "Program Files (x86)\\Mini Mouse Macro",
    "Program Files\\Auto Macro Recorder",
    "Program Files (x86)\\Auto Macro Recorder",
    "Program Files\\PhraseExpress",
    "Program Files (x86)\\PhraseExpress",
    "Users\\USERNAME\\AppData\\Roaming\\PhraseExpress",
    "Program Files\\MacroGamer",
    "Program Files (x86)\\MacroGamer",
    "Users\\USERNAME\\AppData\\Local\\MacroGamer",
    "Program Files\\AutoClickExtreme",
    "Program Files (x86)\\AutoClickExtreme",
    "Users\\USERNAME\\AppData\\Local\\AutoClickExtreme",
    "Program Files\\AutoMate",
    "Program Files (x86)\\AutoMate",
    "Users\\USERNAME\\AppData\\Local\\AutoMate",
    "Program Files\\WinMacro",
    "Program Files (x86)\\WinMacro",
    "Users\\USERNAME\\AppData\\Local\\WinMacro",
    "Program Files\\Easy Macro Recorder",
    "Program Files (x86)\\Easy Macro Recorder",
    "Users\\USERNAME\\AppData\\Local\\Easy Macro Recorder",
    "Program Files\\Mouse Recorder Pro",
    "Program Files (x86)\\Mouse Recorder Pro",
    "Users\\USERNAME\\AppData\\Local\\Mouse Recorder Pro",
    "Program Files\\RobotSoft",
    "Program Files (x86)\\RobotSoft",
    "Users\\USERNAME\\AppData\\Local\\RobotSoft",
    "Program Files\\Auto Mouse",
    "Program Files (x86)\\Auto Mouse",
    "Users\\USERNAME\\AppData\\Local\\Auto Mouse",
    "Program Files\\Auto Mouse Mover",
    "Program Files (x86)\\Auto Mouse Mover",
    "Users\\USERNAME\\AppData\\Local\\Auto Mouse Mover",
    "Program Files\\Mouse Recorder Premium",
    "Program Files (x86)\\Mouse Recorder Premium",
    "Users\\USERNAME\\AppData\\Local\\Mouse Recorder Premium",
    "Program Files\\Ghost Control",
    "Program Files (x86)\\Ghost Control",
    "Users\\USERNAME\\AppData\\Local\\Ghost Control",
    "Program Files\\Auto Macro Recorder",
    "Program Files (x86)\\Auto Macro Recorder",
    "Users\\USERNAME\\AppData\\Local\\Auto Macro Recorder",
    "Program Files\\Hot Keyboard Pro",
    "Program Files (x86)\\Hot Keyboard Pro",
    "Users\\USERNAME\\AppData\\Local\\Hot Keyboard Pro",
    "Program Files\\Macro Express",
    "Program Files (x86)\\Macro Express",
    "Users\\USERNAME\\AppData\\Local\\Macro Express",
    "Program Files\\Pitrinec Software",
    "Program Files (x86)\\Pitrinec Software",
    "Users\\USERNAME\\AppData\\Local\\Pitrinec Software",
    "Program Files\\AutoMate Pro",
    "Program Files (x86)\\AutoMate Pro",
    "Users\\USERNAME\\AppData\\Local\\AutoMate Pro",
    "Program Files\\Auto Mouse Clicker",
    "Program Files (x86)\\Auto Mouse Clicker",
    "Users\\USERNAME\\AppData\\Local\\Auto Mouse Clicker",
    "Program Files\\Auto Mouse and Keyboard",
    "Program Files (x86)\\Auto Mouse and Keyboard",
    "Users\\USERNAME\\AppData\\Local\\Auto Mouse and Keyboard",
    "Program Files\\Auto Click Typer",
    "Program Files (x86)\\Auto Click Typer",
    "Users\\USERNAME\\AppData\\Local\\Auto Click Typer",
    "Program Files\\Auto Presser",
    "Program Files (x86)\\Auto Presser",
    "Users\\USERNAME\\AppData\\Local\\Auto Presser",
    "Program Files\\Auto Typer",
    "Program Files (x86)\\Auto Typer",
    "Users\\USERNAME\\AppData\\Local\\Auto Typer",
    "Program Files\\Auto Clicker Typer",
    "Program Files (x86)\\Auto Clicker Typer",
    "Users\\USERNAME\\AppData\\Local\\Auto Clicker Typer"
};