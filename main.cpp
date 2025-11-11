#include "memory.h"
#include <iostream>

int main() {
    if (!VARS::Initialize()) {
        std::cout << "CS2 process not found!" << std::endl;
        std::cout << "Make sure CS2 is running!" << std::endl;
        std::cout << "Press Enter to exit..." << std::endl;
        std::cin.get();
        return 1;
    }

    std::cout << "CS2 process found!" << std::endl;
    std::cout << "Process ID: " << VARS::processId << std::endl;
    std::cout << "Base Address: 0x" << std::hex << VARS::baseAddress << std::dec << std::endl;
    std::cout << "Process Handle: " << VARS::processHandle << std::endl;

    // Test if memory reading actually works
    std::cout << "\n=== Testing Memory Read ===" << std::endl;
    try {
        uint16_t dosHeader = VARS::memRead<uint16_t>(VARS::baseAddress);
        std::cout << "DOS Header: 0x" << std::hex << dosHeader << std::dec << std::endl;

        if (dosHeader == 0x5A4D) {
            std::cout << "SUCCESS: Memory reading works!" << std::endl;
        }
        else {
            std::cout << "Memory read worked but got unexpected value" << std::endl;
        }
    }
    catch (...) {
        std::cout << "FAILED: Cannot read memory" << std::endl;
    }

    std::cout << "\nPress Enter to exit..." << std::endl;
    std::cin.get();
    return 0;
}