#include<iostream>
#include<thread>
using namespace std;

// using function pointer
// void func(int x){
//     while(x-- > 0){
//         cout<<x<<endl;
//     }
// }
// int main(){
//     thread t1(func ,10);
//     t1.join();
//     return 0;
// }



// using lambda function

// int main(){
//     auto func = [](int x){
//         while(x-- > 0){
//             cout<<x<<endl;
//         }
//     };
//     thread t1(func ,10);
//     t1.join();

//     return 0;
// }


//using functors
// class Base{
//     public:
//     void operator ()(int x){
//         while(x-- > 0) {
//             cout<<x<<endl;
//         }
//     }
// };
// int main(){
//     thread t1((Base()),10);
//     t1.join();
//     return 0;
// }


// using non static member func
// class Base{
//     public:
//     void run(int x){
//         while(x-- > 0){
//             cout<<x<<endl;
//         }
//     }
// };
// int main(){
//     Base b;
//     thread t1(&Base::run ,&b , 10 );
//     t1.join();
//     return 0;
// }


//using static function

// class Base{
//     public:
//     static void run(int x){
//         while(x-- > 0){
//             cout<<x<<endl;
//         }
//     }
// };
// int main(){
//     thread t1(&Base::run , 10);
//     t1.join();
//     return 0;
// }