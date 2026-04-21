// #include<thread>
// // void task(){
// //     // work

// // }
// // int main(){
// //     std::thread t(task);
// //     t.join();
// // }
// // now we do the function object
// // class Task{
// //     public;
// //     void operator()(){
// //         // work
// //     }
// // };
// // std:: thread t(task)
// // lambda 
// // std::thread t([](){

// // // });

#include<thread>
#include<iostream>
#include<chrono>
#include<vector>
#include<windows.h>
using namespace std;
void process_task(int id,int work_time){
    cout<<"Thread"<<id<<"started\n";
    Sleep(work_time);
    cout<<"Thread"<<id<<"finished\n";
}
int main(){
    vector<std::thread>threads;
    int num_threads=std::thread::hardware_concurrency();
    cout<<"Launching"<<num_threads<<"threads\n";
    for(int i=0;i<num_threads;i++){
        int work_time=500+(i*100);
        threads.push_back(std::thread(process_task,i,work_time));
    }
    for(auto& t:threads){
        if(t.joinable()){
            t.join();
        }
    }
    cout<<"All task completed\n";
    return 0;
}