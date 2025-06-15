
/*

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
        By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/

#pragma once
#include <windows.h>
#include <string>
#include <shlobj.h>
#include <iostream>
#include "Config.h"
#include "Language.h"
#include "Utils.h"

class FileSystem {
public:
    static bool isValidUrl(const std::string& url) {
        return url.rfind("http://", 0) == 0 || url.rfind("https://", 0) == 0;
    }

    static void openBrowser(const std::string& url) {
        if (!isValidUrl(url)) {
            std::cerr << Config::COLOR_ERROR << Language::Current::ERR << " URL: " << url << Config::COLOR_RESET << std::endl;
            return;
        }
        std::string command = "start " + url;
        system(command.c_str());
    }

    static std::string getUserDirectory() {
        char userFolderPath[MAX_PATH];
        if (SHGetFolderPathA(nullptr, CSIDL_PROFILE, nullptr, 0, userFolderPath) != S_OK) {
            return "";
        }
        return std::string(userFolderPath);
    }

    static bool createDirectory(const std::string& path) {
        return CreateDirectoryA(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
    }

    static bool directoryExists(const std::string& path) {
        DWORD attrs = GetFileAttributesA(path.c_str());
        return (attrs != INVALID_FILE_ATTRIBUTES && (attrs & FILE_ATTRIBUTE_DIRECTORY));
    }

    static int executePowerShell(const std::string& script) {
        std::string command = "powershell -ExecutionPolicy Bypass -Command " + script;
        return system(command.c_str());
    }

    static void downloadFile(const std::string& url, const std::string& fileName) {
        if (!isValidUrl(url)) {
            std::cerr << Config::COLOR_ERROR << Language::Current::ERR << " URL: " << url << Config::COLOR_RESET << std::endl;
            return;
        }
        std::string destPath = Config::TOOLS_PATH;
        std::string fullPath = destPath + "\\" + fileName;
        
        std::string command = "powershell -ExecutionPolicy Bypass -Command \"";
        command += "Invoke-WebRequest -Uri '" + url + "' ";
        command += "-OutFile '" + fullPath + "'\"";
        system(command.c_str());
        
        std::cout << Config::COLOR_BLUE << Language::Current::FOUND_SOFTWARE << Config::COLOR_CYAN << fullPath << Config::COLOR_RESET << std::endl;
    }

    static void executeJournal(const std::string& command, const std::string& savedFile) {
        std::string fullPath = Config::JOURNAL_PATH + savedFile;
        std::string fullCommand = command + fullPath;
        
        showLoadingAnimation(Language::Current::JOURNAL_LOADING, 9000);
        system(fullCommand.c_str());
        std::cout << Config::COLOR_BLUE << Language::Current::DOWNLOADING
                  << Config::COLOR_RESET << std::endl;
        std::cout << Config::COLOR_BLUE << Language::Current::FOUND_SOFTWARE
                  << Config::COLOR_CYAN << fullPath
                  << Config::COLOR_RESET << std::endl;
    }

    static void createMainDirectory() {
        createDirectory(Config::BASE_PATH);
        createDirectory(Config::TOOLS_PATH);
        createDirectory(Config::JOURNAL_PATH);
    }

    static void openRegedit(const std::string& path) {
        std::string command = "reg add " + path;
        system(command.c_str());
        system("regedit");
    }
}; 