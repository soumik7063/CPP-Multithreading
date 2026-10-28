// Race condition: race condition is a phenomena where more than one thread is trying to accessing 
// a common data.

// Critical section: the part of code where race condition occurs.

// Mutex: it is a blocking protocol , which used to avoid race condition. c++11
// use lock() and unlock() to use mutex.

#include<bits/stdc++.h>
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

std::mutex m;
int value = 0;
void func(){
    m.lock();
    value++;
    m.unlock();

}
int main(){
    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();
    cout<<value;
    return 0;
}