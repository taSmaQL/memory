#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <TlHelp32.h>
#include <cstdint>

namespace VARS {
    extern uintptr_t baseAddress;
    extern DWORD processId;
    extern HANDLE processHandle;

    DWORD GetProcess(const wchar_t* Target);
    uintptr_t GetModuleBaseAddress(DWORD processId, const wchar_t* ModuleTarget);
    bool Initialize();

    template <typename type>
    type memRead(uintptr_t pointerStatic) {
        type value = { };
        if (processHandle && processHandle != INVALID_HANDLE_VALUE) {
            ReadProcessMemory(processHandle, (LPVOID)pointerStatic, &value, sizeof(type), NULL);
        }
        return value;
    }

    template <typename type>
    bool memWrite(uintptr_t pointerStatic, type value) {
        if (processHandle && processHandle != INVALID_HANDLE_VALUE) {
            return WriteProcessMemory(processHandle, (LPVOID)pointerStatic, &value, sizeof(type), NULL);
        }
        return false;
    }
}