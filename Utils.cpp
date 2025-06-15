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
#include <thread>

LoadingAnimation::LoadingAnimation(const std::string& msg) : message(msg) {
    animationThread = std::thread(&LoadingAnimation::run, this);
}

LoadingAnimation::~LoadingAnimation() {
    running = false;
    if (animationThread.joinable()) {
        animationThread.join();
    }
    std::cout << "\r" << std::string(message.length() + 4, ' ') << "\r" << std::flush;
    system("CLS");  // Add CLS when animation ends
}

void LoadingAnimation::run() {
    const char sequence[] = {'|', '/', '-', '\\'};
    int count = 0;
    
    while (running) {
        std::cout << "\r" << Config::COLOR_BLUE << message << " "
                  << Config::COLOR_CYAN << sequence[count % 4]
                  << Config::COLOR_RESET << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        count++;
    }
}

std::unique_ptr<LoadingAnimation> LoadingAnimation::start(const std::string& message) {
    return std::unique_ptr<LoadingAnimation>(new LoadingAnimation(message));
}

void showLoadingAnimation(const std::string& message, int duration) {
    auto animation = LoadingAnimation::start(message);
    Sleep(duration);
}