#include <windows.h>
#include <iostream>
#include <chrono>
int main()
{
    STARTUPINFOA si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);
    auto start = std::chrono::high_resolution_clock::now();
    if (CreateProcess(
            "child.exe", // executable
            NULL,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi))
    {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else
    {
        std::cout << "Process creation failed.\n";
        return 1;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Process creation time:"
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds\n";
    return 0;
}
