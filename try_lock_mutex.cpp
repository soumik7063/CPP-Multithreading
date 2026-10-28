// 1.try_lock() is not not use to lock mutex , it only check the data is blocked or not , that why it is calling non blocking
// 2.if try_lock() is called again and again by the same thread which owns the mutex the behabiour is undefined.

// if you want to use lock again and again in a same thread then you should go for recursive_mutex.

#include<bits/stdc++.h>
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex m;
int value = 0;
void func(){
    for(int i = 1 ;i <= 100000; i++){
      
        if(m.try_lock()){
            value++;
            m.unlock();
        }
        // m.lock();
        // value++;
        // m.unlock();
    }
}
int main(){
    
    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();
    cout<<value;
    return 0;
}