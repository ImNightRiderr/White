/*

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
    By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/

#include "ScreenShareDetection.h"
#include "Config.h"
#include "Utils.h"
#include "Language.h" 
#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <iostream>
#include <conio.h>
#include <algorithm>

bool IsVM_Registry()
{
    std::cout << "\n[DEBUG] Starting VM Detection...\n";
    
    const WCHAR* registryPaths[] = {
        L"HARDWARE\\DESCRIPTION\\System\\BIOS",
        L"SYSTEM\\CurrentControlSet\\Control\\SystemInformation",
        L"SYSTEM\\HardwareConfig\\Current"
    };

    const WCHAR* registryKeys[] = {
        L"SystemManufacturer",
        L"SystemProductName",
        L"BIOSVendor",
        L"BIOSVersion",
        L"VideoBiosVersion",
        L"SystemFamily"
    };

    for (const auto& path : registryPaths) {
        HKEY hKey = nullptr;
        std::cout << "[DEBUG] Checking registry path: " << std::string(path, path + wcslen(path)) << "\n";
        
        if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, path, 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
            WCHAR buf[1024];
            DWORD size, type;

            for (const auto& keyName : registryKeys) {
                size = sizeof(buf);
                if (RegQueryValueExW(hKey, keyName, nullptr, &type, (LPBYTE)buf, &size) == ERROR_SUCCESS) {
                    std::wstring value(buf);
                    std::cout << "[DEBUG] Key: " << std::string(keyName, keyName + wcslen(keyName)) 
                             << " Value: " << std::string(value.begin(), value.end()) << "\n";

                    std::wstring valueLower = value;
                    std::transform(valueLower.begin(), valueLower.end(), valueLower.begin(), ::towlower);

                    for (const auto& vmKey : ScreenShareDetection::vmKeys) {
                        if (valueLower.find(vmKey) != std::wstring::npos) {
                            std::cout << "\033[31m[DETECTED] VM signature found: " 
                                    << std::string(vmKey.begin(), vmKey.end()) 
                                    << " in " << std::string(keyName, keyName + wcslen(keyName)) 
                                    << "\033[0m\n";
                            RegCloseKey(hKey);
                            return true;
                        }
                    }
                }
            }
            RegCloseKey(hKey);
        }
        else {
            std::cout << "[ERROR] Failed to open registry path: " 
                     << std::string(path, path + wcslen(path)) << "\n";
        }
        
    }


    HKEY hVBoxKey = nullptr;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Oracle\\VirtualBox Guest Additions", 
                      0, KEY_READ, &hVBoxKey) == ERROR_SUCCESS) {
        std::cout << "\033[31m[DETECTED] VirtualBox Guest Additions found\033[0m\n";
        RegCloseKey(hVBoxKey);
        return true;
    }

    std::cout << "[DEBUG] No VM detected\n";
    
    return false;
}

bool IsRunningInVM()
{
    return IsVM_Registry(); 
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    char title[512];
    DWORD pid;
    GetWindowTextA(hwnd, title, sizeof(title));
    if (strlen(title) == 0) return TRUE;

    GetWindowThreadProcessId(hwnd, &pid);
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
    if (!hProcess) return TRUE;
    char processName[MAX_PATH] = {0};
    if (GetModuleBaseNameA(hProcess, NULL, processName, MAX_PATH)) {
        std::string titleStr = title;
        std::transform(titleStr.begin(), titleStr.end(), titleStr.begin(), ::tolower);

        for (const auto& keyword : ScreenShareDetection::keywords) {
            if (titleStr.find(keyword) != std::string::npos) {
                std::vector<std::string>* found = reinterpret_cast<std::vector<std::string>*>(lParam);
                std::string proc(processName);
                std::transform(proc.begin(), proc.end(), proc.begin(), ::tolower);
                if (std::find(found->begin(), found->end(), proc) == found->end()) {
                    found->push_back(proc);
                }
                break;
            }
        }
    }
    CloseHandle(hProcess);
    return TRUE;
}

bool ScreenShareDetection::checkRecordingSoftware() {
    
    system("CLS");
    bool foundAny = false;
    bool foundAnyVM = false;
    std::vector<std::string> foundSoftware;

    auto loading = LoadingAnimation::start(Language::Current::CHECKING_SCREEN_SHARE);

    if (IsRunningInVM()) {
        foundAnyVM = true;
    }

    auto softwareList = getRecordingSoftwareList();
    for(const auto& software : softwareList) {
        if(isProcessRunning(software.processName)) {
            if (std::find(foundSoftware.begin(), foundSoftware.end(), software.processName) == foundSoftware.end()) {
                foundSoftware.push_back(software.processName);
                foundAny = true;
            }
        }
    }

    std::vector<std::string> foundSharingBrowsers;
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&foundSharingBrowsers));
    std::vector<std::string> browserProcesses = {
        "chrome.exe", "msedge.exe", "firefox.exe", "opera.exe", "opera_gx.exe", "brave.exe",
        "vivaldi.exe", "tor.exe", "waterfox.exe", "palemoon.exe", "seamonkey.exe", "chromium.exe",
        "maxthon.exe", "whale.exe", "yandex.exe", "dragon.exe", "iron.exe", "epic.exe", "librewolf.exe",
        "avastbrowser.exe", "comodo_dragon.exe", "ucbrowser.exe", "safari.exe", "midori.exe", "netscape.exe",
        "avant.exe", "lunascape.exe", "k-meleon.exe", "falkon.exe", "otter-browser.exe", "qutebrowser.exe",
        "slimbrowser.exe", "dooble.exe", "centbrowser.exe", "coc_coc_browser.exe", "srware iron.exe",
        "torch.exe", "sleipnir.exe", "baidubrowser.exe", "360se.exe", "maxthon_portable.exe", "orbitum.exe",
        "blisk.exe", "sputnik.exe", "puffinbrowser.exe", "avira_browser.exe", "cryptotab.exe"
    };
    for (const auto& browser : foundSharingBrowsers) {
        if (std::find(browserProcesses.begin(), browserProcesses.end(), browser) != browserProcesses.end()) {
            if (std::find(foundSoftware.begin(), foundSoftware.end(), browser) == foundSoftware.end()) {
                foundSoftware.push_back(browser);
                foundAny = true;
            }
        }
    }

    std::vector<std::string> remoteServices = {
        "TeamViewer_Service.exe", "sshd.exe", "vncserver.exe", "winvnc.exe",
        "tv_w32.exe", "atrc.exe", "rundll32.exe", "msra.exe", "remotepg.exe", "AnyDesk.exe",
        "RemoteDesktop.exe", "RemoteAssistance.exe", "RemoteSupport.exe", "RemoteAccessService.exe",
        "RemoteDesktopManager.exe", "RemoteUtilitiesService.exe", "LogMeIn.exe", "SplashtopStream.exe",
        "Chrome Remote Desktop.exe", "Zoom.exe", "Skype.exe", "Discord.exe", "Slack.exe",
    };
    for (const auto& srv : remoteServices) {
        if (isProcessRunning(srv)) {
            if (std::find(foundSoftware.begin(), foundSoftware.end(), srv) == foundSoftware.end()) {
                foundSoftware.push_back(srv);
                foundAny = true;
            }
        }
    }
    
    loading.reset();
    
    if(foundAnyVM) {
        std::cout << Config::COLOR_BLUE << Language::Current::VIRTUAL_ENVIRONMENT_DETECTED
                  << Config::COLOR_RESET << std::endl;
        std::cout << Config::COLOR_CYAN << Language::Current::CONTINUE_CHECKING << std::endl;
        Sleep(2000);
    } else {
        std::cout << Config::COLOR_BLUE << Language::Current::NO_VIRTUAL_ENVIRONMENT_DETECTED
                  << Config::COLOR_RESET << std::endl;
    }
    if (!foundAny) {
        std::cout << Config::COLOR_CYAN << Language::Current::NO_RECORDING_SOFTWARE
                  << Config::COLOR_RESET << std::endl;
        Sleep(2500);
        return false;
    } else if (!foundSoftware.empty()) {
        handleRecordingSoftwareTermination(foundSoftware);
        std::cout << "\n" << Language::Current::PRESS_KEY << std::endl;
        _getch();
        return true;
    }
    return false;
}

std::vector<ScreenShareDetection::RecordingSoftware> ScreenShareDetection::getRecordingSoftwareList() {
    return {
        {"obs64.exe", "OBS Studio"},
        {"obs32.exe", "OBS Studio"},
        {"action.exe", "Action!"},
        {"bdcam.exe", "Bandicam"},
        {"nvidia share.exe", "NVIDIA Share"},
        {"Radeon-Settings.exe", "AMD Radeon Settings"},
        {"NVIDIA GeForce Experience.exe", "NVIDIA GeForce Experience"},
        {"ShareX.exe", "ShareX"},
        {"Lightshot.exe", "Lightshot"},
        {"CamtasiaStudio.exe", "Camtasia Studio"},
        {"screen-capture.exe", "Screen Capture"},
        {"flashplayer.exe", "Adobe Flash Player"},
        {"fraps.exe", "Fraps"},
        {"XSplit.Core.exe", "XSplit"},
        {"wmplayer.exe", "Windows Media Player"},
        {"vlc.exe", "VLC Media Player"},
        {"mpc-hc64.exe", "Media Player Classic"},
        {"dxtory.exe", "Dxtory"},
        {"playclaw.exe", "PlayClaw"},
        {"mirillis.exe", "Mirillis Action"},
        {"screencast.exe", "Screencast"},
        {"movavi.screen.recorder.exe", "Movavi Screen Recorder"},
        {"icecream screen recorder.exe", "Icecream Screen Recorder"},
        {"screenhunter.exe", "ScreenHunter"},
        {"captura.exe", "Captura"},
        {"streamlabs obs.exe", "Streamlabs OBS"},
        {"gadwin printscreen.exe", "Gadwin PrintScreen"},
        {"apowerrec.exe", "Apowersoft Screen Recorder"},
        {"atube catcher.exe", "aTube Catcher"},
        {"gom cam.exe", "GOM Cam"},
        {"debut.exe", "Debut Video Capture"},
        {"snagit32.exe", "Snagit"},
        {"screenrecorder.exe", "Screen Recorder"},
        {"GameBar.exe", "Xbox Game Bar"},
        {"amd-radeon-software.exe", "AMD Radeon Software"}
    };
}

bool ScreenShareDetection::isProcessRunning(const std::string& processName) {
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

void ScreenShareDetection::killProcess(const std::string& processName) {
    std::string command = "powershell -Command \"Get-Process -Name '" + processName.substr(0, processName.find_last_of('.')) + "' -ErrorAction SilentlyContinue | Stop-Process -Force\"";
    system(command.c_str());
}

void ScreenShareDetection::handleRecordingSoftwareTermination(const std::vector<std::string>& foundSoftware) {
    while (true) {
        
        system("CLS");
        std::cout << Config::COLOR_BLUE << Language::Current::SELECT_PROCESS
                  << Config::COLOR_RESET << std::endl;
        std::cout << Config::COLOR_BLUE << "Nota:" << Config::COLOR_RESET
                  << Config::COLOR_CYAN << " " << Language::Current::RECORDING_NOTE
                  << Config::COLOR_RESET << std::endl << std::endl;

        std::cout << Config::COLOR_BLUE << "[0]" << Config::COLOR_RESET
                  << Config::COLOR_CYAN << " " << Language::Current::BACK << Config::COLOR_RESET << std::endl;

        for (size_t i = 0; i < foundSoftware.size(); ++i) {
            std::cout << Config::COLOR_BLUE << "[" << i + 1 << "]" << Config::COLOR_RESET
                      << Config::COLOR_CYAN << " " << foundSoftware[i]
                      << Config::COLOR_RESET << std::endl;
        }

        std::string input;
        std::getline(std::cin, input);

        if (input == "0") return;

        try {
            int choice = std::stoi(input);
            if (choice > 0 && choice <= static_cast<int>(foundSoftware.size())) {
                auto loading = LoadingAnimation::start(Language::Current::TERMINATING_PROCESS);
                killProcess(foundSoftware[choice-1]);
                loading.reset();
                std::cout << Config::COLOR_BLUE << Language::Current::PROCESS_TERMINATED << ": " << Config::COLOR_CYAN
                          << foundSoftware[choice-1] << Config::COLOR_RESET << std::endl;
                return;
            }
        } catch (...) {
        // pass
        }
    }
}

const std::vector<std::wstring> ScreenShareDetection::vmKeys = {
    L"vmware", L"vmware, inc.", L"vmware virtual platform",
    L"virtualbox", L"innotek gmbh", L"oracle corporation",
    L"kvm", L"qemu", L"bochs", L"acrn",
    L"xen", L"xenproject", L"xen hvm",
    L"hyper-v", L"microsoft corporation", L"microsoft virtual pc",
    L"microsoft virtual server", L"parallels", L"bhyve",
    L"amazon ec2", L"google compute engine",
    L"microsoft azure", L"digitalocean", L"openstack",
    L"virtual machine", L"parallels software international inc." // aggiungi qui se serve
};


const std::vector<std::string> ScreenShareDetection::keywords = {
    // Italiano
    "condividendo il tuo schermo", "condivisione schermo", "sta condividendo il tuo schermo",
    "sta condividendo lo schermo", "condividi schermo", "condividi il tuo schermo",
    "condivisione dello schermo", "sta presentando", "presentazione schermo",
    "sta condividendo", "presentazione", "schermo condiviso",
    "condivide una finestra", "condivisione finestra", "sta condividendo una finestra",
    "condividi finestra", "finestra condivisa", "sta condividendo la finestra",
    "condividendo una finestra", "condividendo la finestra", "finestra in condivisione",
    "schermo in condivisione", "condivisione attiva", "schermo attivo",
    "finestra attiva", "stai condividendo lo schermo", "stai condividendo una finestra",

    // Inglese
    "screen sharing", "sharing indicator", "is sharing your screen", "is presenting",
    "share your screen", "sharing your screen", "presenting now", "you are sharing your screen",
    "stop sharing", "currently sharing", "presenting", "sharing screen",
    "is sharing", "is presenting", "share screen", "screen is being shared",
    "window sharing", "is sharing a window", "sharing a window",
    "share a window", "sharing window", "window is being shared",
    "window shared", "screen shared", "active sharing", "sharing active",
    "you are presenting", "window is active", "screen is active",

    // Francese
    "partage d'écran", "partage votre écran", "partager l'écran", "partage de l'écran",
    "vous partagez votre écran", "partage d’ecran", "partager votre écran",
    "partage de fenêtre", "partager une fenêtre", "fenêtre partagée", "partage votre fenêtre",
    "vous partagez une fenêtre", "fenêtre en partage", "écran partagé",
    "partage en cours", "partage actif", "vous présentez votre écran",
    "présentation en cours", "présente maintenant", "partage de l’écran en cours",
    "partage de la fenêtre en cours", "fenêtre en cours de partage", "écran en cours de partage",
    "partage de contenu", "présentation d’écran", "présentation de fenêtre",

    // Tedesco
    "bildschirmfreigabe", "teilt ihren bildschirm", "bildschirm teilen", "bildschirm wird geteilt",
    "sie teilen ihren bildschirm", "bildschirmfreigabe aktiv", "bildschirm wird gerade geteilt",
    "fensterfreigabe", "teilt ihr fenster", "fenster teilen", "fenster wird geteilt", "fensterfreigabe aktiv",
    "sie präsentieren jetzt", "sie teilen ein fenster", "fenster wird gerade geteilt",
    "bildschirm geteilt", "fenster geteilt", "freigabe aktiv", "freigabe läuft",
    "sie präsentieren", "sie teilen", "bildschirm ist aktiv", "fenster ist aktiv",
    "freigabe von bildschirm", "freigabe von fenster", "bildschirmfreigabe läuft",

    // Spagnolo
    "compartiendo pantalla", "está compartiendo tu pantalla", "compartir pantalla",
    "estás compartiendo tu pantalla", "pantalla compartida", "compartiendo su pantalla",
    "compartiendo una ventana", "compartir una ventana", "ventana compartida", "está compartiendo una ventana",
    "pantalla en uso", "ventana en uso", "compartiendo ora", "presentando pantalla",
    "presentando ventana", "compartición activa", "compartiendo ora", "compartir ora",
    "compartición de pantalla", "compartición de ventana", "presentazione attiva",
    "estás presentando", "está presentando", "pantalla activa", "ventana activa",
    "compartiendo contenido", "compartiendo presentación", "compartición en corso",

    // Portoghese 
    "compartilhando tela", "está compartilhando sua tela", "compartilhar tela",
    "você está compartilhando sua tela", "tela compartilhada", "compartilhando a tela",
    "compartilhando uma janela", "compartilhar uma janela", "janela compartilhada", "está compartilhando uma janela",
    "tela em uso", "janela em uso", "compartilhamento ativo", "compartilhamento de tela",
    "compartilhamento de janela", "apresentando tela", "apresentando janela",
    "você está apresentando", "apresentação ativa", "tela ativa", "janela ativa",
    "compartilhando conteúdo", "compartilhamento em andamento", "compartilhamento em corso",
    "apresentação em andamento", "apresentação em corso", "compartilhamento iniciado",

    // Russo
    "демонстрация экрана", "делится вашим экраном", "вы демонстрируете экран",
    "экран транслируется", "вы делитесь экраном", "показ экрана", "вы сейчас делитесь экраном",
    "демонстрация окна", "делится вашим окном", "вы демонстрируете окно", "окно транслируется", "вы делитесь окном", "показ окна",
    "экран общий", "окно общее", "вы сейчас демонстрируете экран", "вы сейчас демонстрируете окно",
    "демонстрация активна", "демонстрация идет", "вы показываете экран", "вы показываете окно",
    "экран активен", "окно активно", "демонстрация содержимого", "демонстрация презентации",
    "вы ведете презентацию", "вы делитесь содержимым", "вы делитесь презентацией",

    // Cinese (semplificato e tradizionale)
    "正在共享屏幕", "屏幕共享", "你正在共享屏幕", "共享屏幕中", "正在分享屏幕", "屏幕正在共享",
    "正在共享窗口", "窗口共享", "你正在共享窗口", "共享窗口中", "窗口正在共享",
    "屏幕已共享", "窗口已共享", "正在演示屏幕", "正在演示窗口", "屏幕处于共享状态",
    "窗口处于共享状态", "你正在演示屏幕", "你正在演示窗口", "共享内容中", "共享演示中",
    "屏幕处于演示状态", "窗口处于演示状态", "内容正在共享", "演示正在进行", "共享正在进行",

    // Giapponese
    "画面を共有しています", "画面共有", "あなたの画面を共有しています", "画面をシェアしています",
    "画面の共有", "画面をプレゼンしています",
    "ウィンドウを共有しています", "ウィンドウ共有", "あなたのウィンドウを共有しています", "ウィンドウの共有",
    "画面が共有されています", "ウィンドウが共有されています", "画面を表示中", "ウィンドウを表示中",
    "共有中", "プレゼン中", "画面のプレゼンテーション", "ウィンドウのプレゼンテーション",
    "画面がアクティブです", "ウィンドウがアクティブです", "共有がアクティブです", "プレゼンがアクティブです",
    "画面の共有中", "ウィンドウの共有中", "コンテンツを共有しています"
};