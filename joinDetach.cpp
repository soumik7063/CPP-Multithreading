// JOIN
//1. once a thread is started we wait to complete this thead calling join() function on this thread object
//2. Double join esult into program termination , system error
//3.if needed we should check thread is joinable before join (using joinable() func);
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// join

// void run(int count){
//     while(count --> 0){
//         cout<<"Soumik"<<endl;
//     }
// }
// int main(){
//     thread t1(run , 10);
//     t1.join();
//     // t1.join(); should not use double join.
//     if(t1.joinable()){ // it is safe
//         t1.join();
//     }
//     return 0;
// }


// Detach 
//1. This is used to detach newly created thread from the parent thread.
// 2.always check  before detaching , that the thread is joinable , otherwise we may end up double detaching ,
// which lead to program termination.
// 3. if we have detached thread nd main function is returning then the detached thread execution is suspended

// Notes
// you should either join or detach ,on thread object other wise during thread's object destructor ,
// will terminate the program, becz in dectructor , it will check whether the thread is still joibale or nor , if yes then terminate the programl

// detach

void run(int count){
    while(count --> 0){
        cout<<"Soumik"<<endl;
    }
    this_thread::sleep_for(chrono::seconds(3));
}

int main(){
    int tem;
    thread t1(run , 10);
    cout<<"main"<<endl;
    t1.detach();
    cout<<"main after"<<endl;
    return 0;
}