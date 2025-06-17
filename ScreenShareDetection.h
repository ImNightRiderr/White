/*

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
    By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/ 

#pragma once
#include <string>
#include <vector>

class ScreenShareDetection {
public:
    bool checkRecordingSoftware();
    static const std::vector<std::string> keywords;
    static const std::vector<std::wstring> vmKeys;
private:
    struct RecordingSoftware {
        std::string processName;
        std::string displayName;
    };
    std::vector<RecordingSoftware> getRecordingSoftwareList();
    bool isProcessRunning(const std::string& processName);
    void killProcess(const std::string& processName);
    void handleRecordingSoftwareTermination(const std::vector<std::string>& foundSoftware);
};