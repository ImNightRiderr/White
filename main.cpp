
/* 

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
        By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/

#include "Menu.h"
#include "SecurityManager.h"
#include "FileSystem.h"
#include "Language.h"
#include "Config.h"
#include <iostream>
#include <string>
#include <cctype>

bool showWelcomeAlert() {
    system("CLS");
    std::cout << Language::Current::WELCOME_MESSAGE << Config::COLOR_RESET;
    std::string input;
    std::getline(std::cin, input);
    for (auto& c : input) c = std::toupper(c);
    return input == "OK";
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    AllocConsole();
    FILE* dummy;
    freopen_s(&dummy, "CONOUT$", "w", stdout);
    freopen_s(&dummy, "CONIN$", "r", stdin);

    bool skipWelcome = lpCmdLine && std::string(lpCmdLine).find("--skip-welcome") != std::string::npos;
    
    if (!skipWelcome) {
        if (!showWelcomeAlert()) {
            std::cout << Config::COLOR_ERROR << Language::Current::OPERATION_CANCELLED << Config::COLOR_RESET << std::endl;
            Sleep(2000);
            return 0;
        }

        // Dopo il messaggio di benvenuto, controlla i permessi
        if (!SecurityManager::isElevated()) {
            // Tenta di elevare i permessi
            if (!SecurityManager::elevateProcess("--skip-welcome")) {
                // Mostra errore se l'elevazione fallisce
                system("CLS");
                std::cout << Config::COLOR_ERROR << Language::Current::ADMIN_RIGHTS_ERROR << Config::COLOR_RESET << std::endl;
                Sleep(5000);
                return 1;
            }
            return 0;
        }
    } else {
        if (!SecurityManager::isElevated()) {
            system("CLS");
            std::cout << Config::COLOR_ERROR << Language::Current::ADMIN_RIGHTS_ERROR << Config::COLOR_RESET << std::endl;
            Sleep(5000);
            return 1;
        }
    }

    // Continua solo se ha i permessi
    FileSystem::createMainDirectory();
    Menu menu;
    menu.show();

    return 0;
}
