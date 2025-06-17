/*

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
    By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/

#include "Config.h"

namespace Config {
    std::string BASE_PATH;
    std::string TOOLS_PATH;
    std::string JOURNAL_PATH;

    void setBasePath(std::string path) {
        BASE_PATH = path;
        TOOLS_PATH = BASE_PATH + "\\Tools";
        JOURNAL_PATH = BASE_PATH + "\\Journal";
    }
}