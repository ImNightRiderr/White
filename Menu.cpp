
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
#include <iostream>
#include <conio.h>

Menu::Menu() : tools() {}

void Menu::show() {
    while (running) {
        showMainMenu();
        int choice = getValidatedInput(0, 8);
        switch (choice) {
            case 0: quit(); break;
            case 1: showManualTools(); break;
            case 2: showAutoTools(); break;
            case 3: showJournalTools(); break;
            case 4: showMacroTools(); break;
            case 5: showRegistryTools(); break;
            case 6: showEventViewer(); break;
            case 7: showRecordFinder(); break;
            case 8: showBam(); break;
        }
    }
}

void Menu::showMainMenu() {
    clearScreen(); //                                                        \/ Non rimuovere questa riga, per usare il programma devi mantenere l'autore (NightRiderr_) come da licenza. Don't remove this line, to use the program you must keep the author (NightRiderr_) as license.
    std::cout << Config::COLOR_BLUE << Language::Current::TITLE << Config::AUTHOR << Language::Current::SUBTITLE << Config::COLOR_RESET << std::endl << std::endl;
    std::cout << Config::COLOR_BLUE << Language::Current::CHOOSE_OPERATION << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[0]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::QUIT << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[1]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::MANUAL_TOOLS << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[2]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::AUTO_TOOLS << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[3]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::JOURNAL_PATHS << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[4]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::MACRO_PATHS << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[5]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::REGISTRY_PATHS << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[6]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::EVENT_VIEWER << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[7]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::RECORD << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[8]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::BAM << Config::COLOR_RESET << std::endl;
}

void Menu::showManualTools() {
    clearScreen();
    std::cout << Config::COLOR_BLUE << Language::Current::MANUAL_TOOLS << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[0]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::BACK << Config::COLOR_RESET << std::endl << std::endl;
    std::cout << Config::COLOR_BLUE << "[1]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download Process Hacker 2" << Config::COLOR_RESET << std::endl; // https://processhacker.sourceforge.io/
    std::cout << Config::COLOR_BLUE << "[2]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download LastActivityView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/lastactivityview.zip
    std::cout << Config::COLOR_BLUE << "[3]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download WinPrefetchView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/winprefetchview-x64.zip
    std::cout << Config::COLOR_BLUE << "[4]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download Luyten" << Config::COLOR_RESET << std::endl; // https://github.com/deathmarine/Luyten/releases/download/v0.5.4_Rebuilt_with_Latest_depenencies/luyten-0.5.4.exe
    std::cout << Config::COLOR_BLUE << "[5]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download Everything" << Config::COLOR_RESET << std::endl; // https://www.voidtools.com/Everything-1.4.1.1027.x64.zip
    std::cout << Config::COLOR_BLUE << "[6]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download AlternateStreamView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/alternatestreamview-x64.zip
    std::cout << Config::COLOR_BLUE << "[7]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download PreviousFilesRecovery" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/previousfilesrecovery-x64.zip
    std::cout << Config::COLOR_BLUE << "[8]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download RegScanner" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/regscanner-x64.zip
    std::cout << Config::COLOR_BLUE << "[9]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download USBDeview" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/usbdeview-x64.zip
    std::cout << Config::COLOR_BLUE << "[10]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download LoadedDllsView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/loadeddllsview-x64.zip
    std::cout << Config::COLOR_BLUE << "[11]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download ProcessActivityView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/processactivityview-x64.zip
    std::cout << Config::COLOR_BLUE << "[12]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download ExecutedProgramsList" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/executedprogramslist.zip
    std::cout << Config::COLOR_BLUE << "[13]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download BrowserDownloadsView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/browserdownloadsview-x64.zip
    std::cout << Config::COLOR_BLUE << "[14]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download BrowsingHistoryView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/browsinghistoryview-x64.zip
    std::cout << Config::COLOR_BLUE << "[15]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download ShellBagsView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/shellbagsview.zip
    std::cout << Config::COLOR_BLUE << "[16]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download UserAssistView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/userassistview.zip
    std::cout << Config::COLOR_BLUE << "[17]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download MyEventViewer" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/myeventviewer-x64.zip
    std::cout << Config::COLOR_BLUE << "[18]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download InjectedDLL" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/injecteddll.zip
    std::cout << Config::COLOR_BLUE << "[19]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download OpenedFilesView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/ofview-x64.zip
    std::cout << Config::COLOR_BLUE << "[20]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download RecentFilesView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/recentfilesview.zip
    std::cout << Config::COLOR_BLUE << "[21]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download MUICacheView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/muicacheview.zip
    std::cout << Config::COLOR_BLUE << "[22]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download RegDllView" << Config::COLOR_RESET << std::endl; // https://www.nirsoft.net/utils/regdllview-x64.zip
    int choice = getValidatedInput(0, 22);
    if (choice == 0) return;
    tools.downloadManualTool(choice);
    pause();
}

void Menu::showAutoTools() {
    clearScreen();
    std::cout << Config::COLOR_BLUE << Language::Current::AUTO_TOOLS_BROWSER << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[0]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::BACK << Config::COLOR_RESET << std::endl << std::endl;
    std::cout << Config::COLOR_BLUE << "[1]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download Avenge" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[2]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download Echo" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[3]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Download Paladine" << Config::COLOR_RESET << std::endl;
    int choice = getValidatedInput(0, 3);
    if (choice == 0) return;
    tools.downloadAutoTool(choice);
    pause();
}

void Menu::showJournalTools() {
    clearScreen();
    std::cout << Config::COLOR_BLUE << Language::Current::JOURNAL_PATHS << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[0]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::BACK << Config::COLOR_RESET << std::endl << std::endl;
    std::cout << Config::COLOR_BLUE << "[1]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Security changes" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[2]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Explorer restart" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[3]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Deleted files" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[4]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Renamed files" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[5]" << Config::COLOR_RESET << Config::COLOR_CYAN << " File streams" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[6]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Jarcache" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[7]" << Config::COLOR_RESET << Config::COLOR_CYAN << " File creation" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[8]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Data change" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[9]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Extension change" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[10]" << Config::COLOR_RESET << Config::COLOR_CYAN << " System files" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[11]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Temp files" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[12]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Downloads" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[13]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Service changes" << Config::COLOR_RESET << std::endl;
    int choice = getValidatedInput(0, 13);
    if (choice == 0) return;
    tools.executeJournalCommand(choice);
    pause();
}

void Menu::showMacroTools() {
    clearScreen();
    std::cout << Config::COLOR_BLUE << Language::Current::MACRO_PATHS << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_CYAN << Language::Current::SEARCHING << Config::COLOR_RESET << std::endl;
    tools.macroSoftwareFinder();
    pause();
}

void Menu::showRegistryTools() {
    clearScreen();
    std::cout << Config::COLOR_BLUE << Language::Current::REGISTRY_PATHS << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[0]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::BACK << Config::COLOR_RESET << std::endl << std::endl;
    std::cout << Config::COLOR_BLUE << "[1]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Prefetch Settings" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[2]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Store" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[3]" << Config::COLOR_RESET << Config::COLOR_CYAN << " WinRAR Archives" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[4]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Extensions" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[5]" << Config::COLOR_RESET << Config::COLOR_CYAN << " BAM UserSettings" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[6]" << Config::COLOR_RESET << Config::COLOR_CYAN << " MuiCache" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[7]" << Config::COLOR_RESET << Config::COLOR_CYAN << " USB Devices" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[8]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Recently Opened Programs" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[9]" << Config::COLOR_RESET << Config::COLOR_CYAN << " MuiCache (Visited Folders)" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[10]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Injected Files" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[11]" << Config::COLOR_RESET << Config::COLOR_CYAN << " DLL Extensions" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[12]" << Config::COLOR_RESET << Config::COLOR_CYAN << " File Extensions" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[13]" << Config::COLOR_RESET << Config::COLOR_CYAN << " LastVisitedPidlMRU" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[14]" << Config::COLOR_RESET << Config::COLOR_CYAN << " ComDlg32" << Config::COLOR_RESET << std::endl;
    int choice = getValidatedInput(0, 14);
    if (choice == 0) return;
    tools.executeRegistryCommand(choice);
    pause();
}

void Menu::showEventViewer() {
    clearScreen();
    std::cout << Config::COLOR_BLUE << Language::Current::EVENT_VIEWER << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[0]" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << Language::Current::BACK << Config::COLOR_RESET << std::endl << std::endl;
    std::cout << Config::COLOR_BLUE << "[1]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Time Change" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[2]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Log Clear" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[3]" << Config::COLOR_RESET << Config::COLOR_CYAN << " Applications Journal" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[4]" << Config::COLOR_RESET << Config::COLOR_CYAN << " NTFS Journal" << Config::COLOR_RESET << std::endl;
    std::cout << Config::COLOR_BLUE << "[5]" << Config::COLOR_RESET << Config::COLOR_CYAN << " NTFS Logs State" << Config::COLOR_RESET << std::endl;
    int choice = getValidatedInput(0, 5);
    if (choice == 0) return;
    tools.executeEventViewerCommand(choice);
    pause();
}

void Menu::showRecordFinder() {
    clearScreen();
    std::cout << Config::COLOR_BLUE << Language::Current::RECORD << " Finder" << Config::COLOR_RESET << std::endl;
    bool found = screenShareDetection.checkRecordingSoftware();
    if (!found) pause();
}

void Menu::showBam() {
    tools.executeBamAnalysis();
    pause();
}

void Menu::showError(const std::string& message) {
    std::cout << Config::COLOR_ERROR << "Error:" << Config::COLOR_RESET << Config::COLOR_CYAN << " " << message << Config::COLOR_RESET << std::endl;
    pause();
}

void Menu::quit() {
    tools.cleanMainDirectory();
    std::cout << Config::COLOR_BLUE << Language::Current::GOODBYE << Config::COLOR_RESET << std::endl;
    _getch();
    running = false;
}

int Menu::getValidatedInput(int min, int max) {
    std::string input;
    int choice;
    while (true) {
        std::cout << Config::COLOR_CYAN << Language::Current::ENTER_CHOICE << Config::COLOR_RESET;
        std::getline(std::cin, input);
        try {
            choice = std::stoi(input);
            if (choice >= min && choice <= max) return choice;
            showError(Language::Current::INVALID_INPUT + std::to_string(min) + " e " + std::to_string(max) + ".");
        } catch (...) {
            showError(Language::Current::MUST_BE_NUMBER);
        }
    }
}