#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
mutex m1,m2;
int balance = 0;
void addMoney(int money){
    m1.lock();
    this_thread::sleep_for(chrono::nanoseconds(1));
    m2.lock();
    balance += money;
    m1.unlock();
    m2.unlock();
}

void withdrawMoney(int money){
    m2.lock();
    this_thread::sleep_for(chrono::nanoseconds(1));
    m1.lock();
    balance -= money;
    m2.unlock();
    m1.unlock();
}

int main(){
    thread t1(addMoney , 1000);
    thread t2(withdrawMoney , 500);

    t1.join();
    t2.join();

    cout<<balance<<endl;
    return 0;
}