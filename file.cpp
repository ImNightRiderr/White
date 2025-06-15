#include <iostream>
#include <windows.h>

int main() {
    // Imposta la codepage 850 (Latin-1) per la console
    SetConsoleOutputCP(850);

    // Caratteri accentati usando i codici ASCII estesi (codepage 850)
    unsigned char accentate[] = {
        181, 182, 183, 199, 142, 143,  // ÀÁÂÃÄÅ
        212, 144, 210, 211,            // ÈÉÊË
        222, 214, 215, 216,            // ÌÍÎÏ
        227, 224, 226, 229, 153,       // ÒÓÔÕÖ
        235, 233, 234, 154,            // ÙÚÛÜ
        133, 160, 131, 198, 132, 134,  // àáâãäå
        138, 130, 136, 137,            // èéêë
        141, 161, 140, 139,            // ìíîï
        149, 162, 147, 228, 148,       // òóôõö
        151, 163, 150, 129             // ùúûü
    };

    for (int i = 0; i < sizeof(accentate); ++i) {
        std::cout << "carattere num " << (int)accentate[i] 
                 << " con escape \\" << std::oct << (int)accentate[i] 
                 << " = '" << accentate[i] << "'" << std::endl;
    }
    return 0;
}