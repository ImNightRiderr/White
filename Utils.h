/* 

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
        By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/

#pragma once
#include <string>
#include <atomic>
#include <memory>
#include <thread>

class LoadingAnimation {
public:
    static std::unique_ptr<LoadingAnimation> start(const std::string& message);
    ~LoadingAnimation();
    void run();

private:
    LoadingAnimation(const std::string& message);
    std::string message;
    std::thread animationThread;
    std::atomic<bool> running{true};
};

void showLoadingAnimation(const std::string& message, int duration);