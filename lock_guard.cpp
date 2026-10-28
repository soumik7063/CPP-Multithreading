// syntax: std::lock_guard<mutex>(m1)

// 1.it is very light weight for owning mutex on scoped basis.
// 2.it aquires mutex lock the moment you create the object of lock_guard.
// 3.it's destructor automatically remove the lock when it get out of scope
// 4. you can not explicitly unlock the lock guard
// 5. you can not copy lock_guard.

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m1;
int buffer = 0;
void func(char threadNo , int loopFor){
    lock_guard<mutex>lock(m1);
    for(int i = 0 ;i < loopFor ; i++){
        buffer++;
        cout<<threadNo<<buffer<<endl;
    }
}
int main(){
    
    thread t1(func , '1' , 5);
    thread t2(func,'0' , 5);
    t1.join();
    t2.join();
    return 0;
}