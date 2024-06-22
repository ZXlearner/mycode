#include<iostream>
#include<thread>
#include<mutex>

int a = 0;
std::timed_mutex mux;
void foo () {
    for (int i = 0; i < 2; i++) {
    std::unique_lock<std::timed_mutex> lg(mux, std::defer_lock);
    if ( lg.try_lock_for(std::chrono::seconds(2))) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        a += 1;
    }

    }
}

int main() {
    std::thread t1(foo);
    std::thread t2(foo);

    t1.join();
    t2.join();

    std::cout<< a <<std::endl;
    return 0;

}