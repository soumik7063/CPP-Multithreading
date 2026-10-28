#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
class Order{
    private:
        int orderKey;
        int orderPrice;
    public:
        Order(int ok , int op):orderKey(ok),orderPrice(op){}
        void logOrder(){
            cout<<"Order Address \t"<< orderKey<<endl;
        }
};
class Order1{
    private:
        int orderKey;
        int orderPrice;
    public:
        Order1(int ok , int op):orderKey(ok),orderPrice(op){}
        void logOrder(){
            cout<<"Order Address \t"<< orderKey<<endl;
        }
        static MemoryManagement mm;
        void* operator new(const size_t size){
            return mm.memAllocate();
        }
        void operator delete(void* mem_add){
            return mm.DeAllocate(mem_add);
        }

};
class MemoryManagement{
    private:
        vector<void*>FreeList;
        char *memory_;
    public:
        MemoryManagement(int n , int size){
            memory_ = new char[n*size];
            for(auto it = 0 ; it < n ; it++){
                FreeList.push_back(memory_ + it*size);
            }
        }
        ~MemoryManagement(){
            delete []memory_;
        }
        void * memAllocate(){
            auto it = FreeList.back();
            FreeList.pop_back();
            return it;
        }
        void DeAllocate(void * mem){
            FreeList.push_back(mem);
        }
};
int main(){
    
    auto startTime = high_resolution_clock::now();

    for(int i = 0 ;i < 999999 ; i++){
        Order*o1 = new Order(i+10,30);
        Order*o2 = new Order(i+10,30);
        Order*o3 = new Order(i+10,30);
        Order*o4 = new Order(i+10,30);
        Order*o5 = new Order(i+10,30);
        Order*o6 = new Order(i+10,30);
        Order*o7 = new Order(i+10,30);
        Order*o8 = new Order(i+10,30);

        delete o1;
        delete o2;
        delete o3;
        delete o4;
        delete o5;
        delete o6;
        delete o7;
        delete o8;

    }
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);

    cout<<"Total time taken1: "<<duration.count()/1000<<" ms\n";

    auto startTime1 = high_resolution_clock::now();

    for(int i = 0 ;i < 999999 ; i++){
        Order1*o1 = new Order1(i+10,30);
        Order1*o2 = new Order1(i+10,30);
        Order1*o3 = new Order1(i+10,30);
        Order1*o4 = new Order1(i+10,30);
        Order1*o5 = new Order1(i+10,30);
        Order1*o6 = new Order1(i+10,30);
        Order1*o7 = new Order1(i+10,30);
        Order1*o8 = new Order1(i+10,30);

        delete o1;
        delete o2;
        delete o3;
        delete o4;
        delete o5;
        delete o6;
        delete o7;
        delete o8;

    }
    auto endTime1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(endTime1 - startTime1);

    cout<<"Total time taken2: "<<duration1.count()/1000<<" ms\n";
    return 0;
}