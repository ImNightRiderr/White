
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

extern const std::vector<std::string> programPaths; 

class Tools {
public:
    void downloadManualTool(int toolId);
    void downloadAutoTool(int toolId);
    void executeJournalCommand(int commandId);
    void executeRegistryCommand(int commandId);
    void executeEventViewerCommand(int commandId);
    void executeSCQuery(int queryId);
    void executeBamAnalysis();
    void findRecordingSoftware();
    void macroSoftwareFinder();
    void cleanMainDirectory();
    bool checkScreenSharing();

private:
    void handleMacroPathsSelection(const std::vector<std::string>& foundPaths);
    std::vector<std::string> getScreenSharingProcesses();
    bool isProcessRunning(const std::string& processName);
};