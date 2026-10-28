// std::try_lock() is used to lock all the lockable objects passed it in one by one order

// syntax : std::try_lock(m1,m2,m3 ,.....mn); m = mutex;

// 1. on success of this fucnton returns -1 , otherwise it will return 0based mutex index number which it couldn't lock
// 2. if it fails to lock a mutex , it unlock all the mutex which is locked before
// 3. if there is a exception while locking , it unlock all the mutex which is locked berfore.

#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

int X = 0 , Y = 0;
mutex m1 ,m2;
void doSomeRest(int seconds){this_thread::sleep_for(chrono::seconds(seconds));}
void incrementXY(int &x , mutex & m,const char* c){
    for(int i = 0 ;i < 5; i++){
        m.lock();
        x++;
        cout<<c<<x<<endl;
        m.unlock();
        doSomeRest(2);
    }
}
void combine(){
    int useCount = 5;
    int XpluxY = 0;
    
    while(1){
        int lockResult = try_lock(m1,m2);
        if(lockResult == -1){
            if(X != 0 && Y != 0){
                useCount--;
                XpluxY+= X+Y;
                X = 0;
                Y = 0;
                cout<<XpluxY<<endl;
            }
            m1.unlock();
            m2.unlock();
            if(useCount == 0) break;
        }
    }
}
using namespace std;
int main(){
    thread t1(incrementXY, ref(X) ,ref(m1), "X");
    thread t2(incrementXY , ref(Y),ref(m2), "Y");
    thread t3(combine);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}