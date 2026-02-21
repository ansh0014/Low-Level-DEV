#include<iostream>
#include<thread>
#include<chrono>
#include<windows.h>
void worker(){}
int main(){
    auto start=std::chrono::high_resolution_clock::now();
    std::thread t(worker);
    t.join();
    auto end=std::chrono::high_resolution_clock::now();
    std::cout<<"Thread creation time:"
             <<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
             <<"microseconds\n";   
}