// syntax: unique_lock<mutex> lock(m1);

// Notes:
// 1. The class unique_lock is amutex ownership wrapper
// 2. it allows
//     a: can have different locking strategies
//     b:time-constrained attempts at locking (try_lock_for , try_lock_until)
//     c:recursive locking
//     d:transfer of lock ownership (move not copy)

// locking strategies:
//     1.defer_lock: do not acquire ownership of mutex
//     2.try_to_lock: try to acquire ownership of the mutex without blocking
//     3.adopt_lock:assume the calling thread already has ownwership of the mutex

#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

mutex m1;
int buffer = 0;

//Example 1
// void task(const char threadNo , int loopFor){
//     unique_lock<mutex> lock(m1,adopt_lock);
//     for(int i = 0 ;i < loopFor ; i++){
//         buffer++;
//         cout<<threadNo<<" "<<buffer<<endl;
//     }
// }

//Example 2
void task(const char threadNo , int loopFor){
    unique_lock<mutex> lock(m1,defer_lock); // Does not call lock on m1 , bcz of defer_lock
    lock.lock(); // but when we call lock explicitly , then lock occur
    for(int i = 0 ;i < loopFor ; i++){
        buffer++;
        cout<<threadNo<<" "<<buffer<<endl;
    }
    // lock.unlock() is not needed , it will be unlocked automatically by the destructor when the scope end
}
int main(){
    thread t1(task , '1' , 10);
    thread t2(task , '2' ,10);

    t1.join();
    t2.join();

    return 0;
}
