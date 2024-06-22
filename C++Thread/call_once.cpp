#include<iostream>
#include<thread>
#include<mutex>
#include<string>
//static Log*log = nullptr;
static std::once_flag once;

class Log {
public:
      Log() {};
      Log(const Log& log) = delete;
      Log& operator=(const Log& log) = delete;

      static Log& GetInstance() {
        static Log*log = nullptr;
        std::call_once(once, init);
        return *log;
      } 

      static void init() {
        static Log*log = nullptr;
        if (!log) log = new Log;
      }

      void PrintLog(std::string msg) {
        std::cout << __TIME__<<' '<< msg << std::endl;
      }
};

void print_error() {
     Log::GetInstance().PrintLog("ERROR");
}




int main() {
    std::thread t1(print_error);
    std::thread t2(print_error);

    t1.join();
    t2.join();
}
         