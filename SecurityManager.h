
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
#include <conio.h>
#include <iostream>
#include "Config.h"

class SecurityManager {
public:
    static bool isElevated();
    static bool elevateProcess(const char* extraArgs = nullptr);
};