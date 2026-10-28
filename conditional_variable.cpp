#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

mutex m1;
condition_variable cv;
int balance = 0;

void addMoney(int money){
    lock_guard<mutex>lg(m1);
    balance += money;
    cout<<"Rs:"<<money <<" added successfully \n current balance is "<<balance<<endl;
    cv.notify_one();
}
bool check(int bal){
    return bal > 0;
}
void withdrawMoney(int money){
    unique_lock<mutex> ul(m1);
    // cv.wait(ul , check(balance));
    cv.wait(ul , [] {return (balance > 0) ? true : false;});
    if(balance >= money){
        balance -= money;
        cout<<"Amount deducted "<<endl;
    }else{
        cout<<"Sorry ! Insufficient Balance "<<endl;
    }
    cout<< "current balance is "<<balance<<endl;
}

int main(){
    thread t1(withdrawMoney ,500);
    thread t2(addMoney , 500);

    t1.join();
    t2.join();
    return 0;
    // https://github.com/cedwies/low-latency-trading/
}