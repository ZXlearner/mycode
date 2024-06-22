// 异步编程

#include<iostream>
#include<future>
using namespace std;

int func(std::promise<int> &f) {
    f.set_value(10000);
}

int main() {
    // std::future<int> future_result = std::async(std::launch::async, func);


    // std::packaged_task<int()> task(func);
    // auto future_result = task.get_future();
    // std::thread t1(std::move(task));
    // cout << func() << endl;
    // t1.join();
    // cout << future_result.get() << endl;
    std::promise<int> f;
    auto future_result = f.get_future();

    std::thread t1(func, std::ref(f));

    t1.join();

    cout << future_result.get() <<endl;
     
    return 0;
}
