#include "memory.h"
#include <iostream>
#include <thread>
int main() {
    if (!VARS::Initialize()) {
        std::cout << "The process not found!" << std::endl;
        std::cout << "Press Enter to exit..." << std::endl;
        std::cin.get();
        return 1;
    }

    std::cout << "The process found." << std::endl;
    std::cout << "Process ID: " << VARS::processId << std::endl;
    std::cout << "Base Address: 0x" << std::hex << VARS::baseAddress << std::dec << std::endl;

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2));

        uintptr_t localPlayer = VARS::memRead<uintptr_t>(VARS::baseAddress + 0x1BEAEB8);
        if (!localPlayer) continue;
       
        int32_t m_fFlags = VARS::memRead<int32_t>(localPlayer + 0x18);

            if (GetAsyncKeyState(VK_SPACE)) {
                VARS::memWrite(VARS::baseAddress + 0x1BE4830, 65537);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                VARS::memWrite(VARS::baseAddress + 0x1BE4830, 256);

        }

    }

    std::cout << "\nPress Enter to exit..." << std::endl;
    std::cin.get();
    return 0;
}