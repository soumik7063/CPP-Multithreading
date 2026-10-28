// std::recursive_mutex

// 1. it is same as normal mutex , same thread can lock one mutex multiple time using recursive mutex.
// 2. If thread t1 use lock/try_lock 10 times, then it has to use unlock 10 times, otherwise no other thread can the mutex.
// 3. How many time we can lock recursive mutex is not defined but when this number reachs , and we are calling lock() ,
// it will return std::system_error , or if we were used try_lock then returns false;

#include<bits/stdc++.h>
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

recursive_mutex m1;
int buffer = 0;
void recursion(int loopFor , char c){
    if(loopFor <0) return;
    m1.lock();
    cout<<c<<" "<<buffer++<<endl;
    recursion(--loopFor , c);
    m1.unlock();
}
int main(){
    
    thread t1(recursion , 4,'A');
    thread t2(recursion , 4,'B');


    // recursive_mutex for loop
    // for(int i = 0 ;i < 5 ; i++){
    //     m1.lock();
    //     cout<<"locked"<<endl;
        
    // }
    // for(int i = 0 ;i < 5 ; i++){
    //     m1.unlock();
    //     cout<<"unlocked"<<endl;

    // }
    t1.join();
    t2.join();
    return 0;
}