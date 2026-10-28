#include <atomic>
#include <mutex>
#include <chrono>
#include <iostream>

// Version with mutex
class CounterWithMutex {
    int value = 0;
    std::mutex mtx;
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mtx);
        ++value;
    }
    int get() {
        std::lock_guard<std::mutex> lock(mtx);
        return value;
    }
};
// Lock-free version
class CounterLockFree {
    std::atomic<int> value{0};
public:
    void increment() {
        value.fetch_add(1, std::memory_order_relaxed);
    }
    int get() {
        return value.load(std::memory_order_relaxed);
    }
};
// Benchmark
template<typename Counter>
void benchmark(const std::string& name) {
    Counter counter;
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([&counter]() {
            for (int j = 0; j < 1000000; ++j) {
                counter.increment();
            }
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << name << ": " << duration.count() << " ms" << std::endl;
    std::cout<<"coutnter value is: "<<counter.get()<<std::endl;
}
int main() {
    benchmark<CounterWithMutex>("Mutex");      // ~150-300 ms
    benchmark<CounterLockFree>("Lock-free");   // ~50-100 ms
    return 0;
}