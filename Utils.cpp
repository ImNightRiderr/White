
/*

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
        By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/

#include "Utils.h"
#include "Config.h"
#include <iostream>
#include <windows.h>

void showLoadingAnimation(const std::string& message, int duration) {
    const char sequence[] = {'|', '/', '-', '\\'};
    int count = 0;
    int iterations = duration / 100;  

    for (int i = 0; i < iterations; i++) {
        std::cout << "\r" << Config::COLOR_BLUE << message << " "
                  << Config::COLOR_CYAN << sequence[count % 4]
                  << Config::COLOR_RESET << std::flush;
        Sleep(100);
        count++;
    }
    std::cout << "\r" << std::string(message.length() + 4, ' ') << "\r";
}