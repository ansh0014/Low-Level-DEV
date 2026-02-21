#include<windows.h>
#include<stdio.h>
int main(){
    printf("Child PID : %lu \n",GetCurrentProcessId());
    Sleep(9000);
    return 0;
}