// topic: std::lock() function in C++11
// it is used to lock multiple mutexes at once without the risk of deadlock

//notes
// syntax: std::lock(m1, m2, m3, ...);
//1. all arguments are locked via a sequence of calls to lock() , try_lock() and unlock() functions
//2. order of locking is implementation defined and may vary from one call to another
//3. it is blocking call and will block until all mutexes are locked


// example1 of no deadlock
// thread 1.           thread 2
// std::lock(m1, m2)   std::lock(m1, m2)

// example2 of no deadlock
// thread 1.           thread 2
// std::lock(m1, m2)   std::lock(m2, m1)

//example 3 no deadlock
// thread 1.           thread 2
// std::lock(m1, m2,m3,m4)   std::lock(m3,m4)
                            // std::lock(m1,m2)

//example 4 deadlock
// thread 1.           thread 2
// std::lock(m1, m2)   std::lock(m3,m4)
// std::lock(m3,m4)   std::lock(m1,m2)

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m1, m2;

void task_a(){
    while(true){
        std::lock(m1, m2);
        cout<<"task_a is running"<<endl;
        m1.unlock();
        m2.unlock();
    }
}
void task_b(){
    while(true){
        std::lock(m1, m2);
        cout<<"task_b is running"<<endl;
        m1.unlock();
        m2.unlock();
    }
}
int main(){
    thread t1(task_a);
    thread t2(task_b);
    t1.join();
    t2.join();
    return 0;
}