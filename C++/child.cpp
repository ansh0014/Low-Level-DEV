#include<windows.h>
#include<iostream>
int main(){
    std::cout<<"Child PID:"<<GetCurrentProcessId()<<"\n";
    // small delay so process 
    Sleep(50);
    return 0;
}