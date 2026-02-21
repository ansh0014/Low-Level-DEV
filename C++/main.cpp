#include <iostream>
#include <thread>
#include <windows.h>
void worker(){
    std::cout <<"Worker thread ID:"
              <<GetCurrentThreadId()<<"\n";
        Sleep(10000);  
}
int main(){
    std::cout<<"Main Thread ID "
             << GetCurrentThreadId()<<"\n";

        std::thread t(worker);
    t.join();
    return 0;   
}
