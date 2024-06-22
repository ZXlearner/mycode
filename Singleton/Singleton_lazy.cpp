// 静态局部变量实现的懒汉单例模式
//是线程安全的，通过static关键字保证了多线程环境下的安全性，因为C++11规范保证了静态局部变量的初始化是线程安全的
#include <iostream>

class singleton {
public:
    // 禁止拷贝构造和赋值操作
    singleton(const singleton&) = delete;
    singleton& operator=(const singleton&) = delete;

    // 静态方法，返回单例实例
    static singleton& getInstance() {
        static singleton instance;
        return instance;
    }

    // 公有方法，供外部调用
    int& doSomething(int a) {
     static int b = a;
        std::cout << "hello world" <<"  "<< b << std::endl;
      return b;
    }

private:
    // 私有构造函数，防止外部创建实例
    singleton() {
        std::cout << "Singleton instance created!" << std::endl;
    }

    // 私有析构函数，防止外部删除实例
    ~singleton() {
        std::cout << "Singleton instance destroyed!" << std::endl;
    }
};

int main() {
  int a = 10;
    singleton& instance1 = singleton::getInstance();
    instance1.doSomething(a);
  int b = 11;
    singleton& instance2 = singleton::getInstance();
    instance2.doSomething(b);

    // 验证两个实例是否相同
    std::cout << "Are the two instances the same? " 
              << (&instance1 == &instance2 ? "Yes" : "No") << std::endl;

    return 0;
}
