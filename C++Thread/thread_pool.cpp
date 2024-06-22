#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<condition_variable>
#include<queue>
#include<functional>
class ThreadPool {
public:
    ThreadPool(int numThreads) :stop(false) { // 在构造函数里面指定起始线程个数
         for (int i = 0; i < numThreads; i++) {
            threads.emplace_back([this]{
                while(1) { // 每个线程都是在任务队列里循环地取任务来完成
                    std::unique_lock<std::mutex> lock(mtx);
                    condition.wait(lock, [this]{
                        return !tasks.empty() || stop;
                    });
                    if (stop && tasks.empty()) {
                        return;
                    }
                    std::function<void()> task(std::move(tasks.front()));
                    tasks.pop();
                    lock.unlock();
                    task();
                }
            });
         }
    }

  ~ThreadPool() {
    {
         std::unique_lock<std::mutex> lock(mtx);
         stop = true;
    }

    condition.notify_all();
    for (auto& t : threads) {
        t.join();
    }
  }

  template<class F, class... Args>  /*给生产者提供接口，通过调用这个接口源源不断地往线程池里去加任务
  */
  void enqueue(F &&f, Args&&... args) {
    std::function<void()>task  = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    {
       std::unique_lock<std::mutex> lock(mtx);
       tasks.emplace(std::move(task));
    }
    condition.notify_one();
  }

private:
    std::vector<std::thread> threads;  // 线程数组
    std::queue<std::function<void()>> tasks; // 任务队列
    
    std::mutex mtx;
    std::condition_variable condition;
    bool stop;

};

int main() {
    ThreadPool pool(4);

    for (int i = 0; i < 10; i++) {
        pool.enqueue([i] {
            std::cout<<"task: " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout<< "task: "<< i << " is done "<< std::endl;
        });
    }

    return 0;
}