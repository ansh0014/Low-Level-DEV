#include<iostream>
#include<thread>
#include<mutex>
#include<windows.h>
using namespace std;
int counter=0;
std::mutex mtx;
void increment_counter(){
    for(int i=0;i<100000;i++){
        // mtx.lock();
        // counter++;
        // mtx.unlock();
// this is create the deadlock 
std::lock_guard<std::mutex> lock(mtx);
counter++;
    }
}
int main(){
    thread t1(increment_counter);
    thread t2(increment_counter);
    t1.join();
    t2.join();
    cout<<"Final counter value: "<<counter<<endl;

}