// PART-1-Concurrency Using Multiple Processes
#include<windows.h>
#include<stdio.h>
int main(){
    STARTUPINFO si={0};
    PROCESS_INFORMATION pi={0};
    printf("Parent PID: %lu\n", GetCurrentProcessId());
    if(CreateProcess(
        "child.exe",
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        
        NULL,
        NULL,
        &si,
        &pi
    )){
        printf("child process created.\n");
        WaitForSingleObject(pi.hProcess,INFINITE);
    }else{
        printf("process creation failed.\n");
    }
    return 0;
}
