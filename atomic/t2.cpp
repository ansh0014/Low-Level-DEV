// now we learn about the atomics
#include<iostream>
#include<thread>
#include<atomic>
using namespace std;
std::atomic<int> counter(0);
void increment(){
    int n=1000000;
    for(int i=0;i <n;i++){
        counter++;
    }
}
int main(){
    thread t1(increment);
    thread t2(increment);
    t1.join();
    t2.join();
    cout<<counter<<endl;
}
