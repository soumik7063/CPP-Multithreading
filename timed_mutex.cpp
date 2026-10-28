// std::timed_mutex is blocked till timeout time or the block is aquired and returns true if success
// otherwise false

// member function
// 1. lock
// 2. try_lock
// 3. try_lock_for
// 4.try_lock_until
// 5.unlock

// example: try_lock_for
// waits unitll specifie time elapsed or lock aquired whichever come first.
// on successfull lock aquisition returns true otherwise retuns false;

#include<bits/stdc++.h>
#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;
timed_mutex m;
int Common = 0;

//try_lock_for

// void func(int i){
//     if(m.try_lock_for(chrono::seconds(2))){
//         Common++;
//         this_thread::sleep_for(chrono::seconds(3));
//         cout<<"Thread "<<i<<" Entered"<<endl;
//         m.unlock();
//     }else{
//         cout<<"Thread "<<i<<" Not Entered"<<endl;
//     }
// }


// try_lock_until
void func(int i){
    auto now = chrono::steady_clock::now();
    if(m.try_lock_until(now + chrono::seconds(2))){
        Common++;
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"Thread "<<i<<" Entered"<<endl;
        m.unlock();
    }else{
        cout<<"Thread "<<i<<" Not Entered"<<endl;
    }
}
int main(){
    
    thread t1(func ,1);
    thread t2(func ,2);

    t1.join();
    t2.join();
    return 0;
}