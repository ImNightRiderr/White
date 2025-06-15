
/* 

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
        By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/

#pragma once
#include "Tools.h"
#include "Config.h"
#include "ScreenShareDetection.h"
#include <string>

class Menu {
public:
    Menu();
    void show();

private:
    Tools tools;
    ScreenShareDetection screenShareDetection;
    bool running = true;

    void showMainMenu();
    void showManualTools();
    void showAutoTools();
    void showJournalTools();
    void showMacroTools();
    void showRegistryTools();
    void showEventViewer();
    void showRecordFinder();
    void showBam();

    void showError(const std::string& message);
    void clearScreen() { system("CLS"); }
    void pause() { system("PAUSE"); }
    void quit();

    int getValidatedInput(int min, int max);
};