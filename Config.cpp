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