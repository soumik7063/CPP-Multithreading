// TOPIC: Introduction to thread in c++ (c++11)
// QUESTIONS
// 1. What do you understand by thread and give one example in C++?
// ANSWER

// In evey application there is a default thread which is main(), in side this we create other threads.
// / 1. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads.
// For example:

// (a) The browser has multiple tabs that can be different threads.
// (b) Ms word has multiple thread , one thread to format the text and another is used to check spell.
// using nur wote breading ote thrend to foretthe tea another end to process inputs (spell checker)
// WAYS TO CREATE THREADS IN C++11
// 11 1. Function Pointers
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static Member functions
// REQUIREMENT
// Find the addition of all odd number from 1 to 1900000000 and all even number from 1 to 1900000000


#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull Oddsum = 0,evenSum = 0;

void findOdd(ull start , ull end){
    for(ull i = start; i<=end ; i++){
        if(i&1) {
            Oddsum += i;
        }
    }
}
void findEven(ull start , ull end){
    for(ull i = start ; i <= end ; i++){
        if((i&1) == 0){
            evenSum += i;
        }
    }
}
int main(){
    ull start = 0,end = 1900000000;

    auto startTime = high_resolution_clock::now();

    thread t1(findEven , start , end);
    thread t2(findOdd , start , end);

    t1.join();
    t2.join();
    // findEven(start,end);
    // findOdd(start,end);
    auto stopTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stopTime-startTime);
    cout<<"Oddsum: "<<Oddsum<<endl;
    cout<<"EvenSum: "<<evenSum<<endl;

    cout<<"time taken  :" << duration.count()/1000<<" ms"<<endl;
    return 0;
}