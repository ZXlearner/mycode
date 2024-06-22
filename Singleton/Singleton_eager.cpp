//饿汉模式，类加载时就创建实例（通过声明类的静态成员变量），不管实例是否被使用
// 是线程安全的
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
        a += 1;
        std::cout << "hello world" << std::endl;
        return a;
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
    singleton& instance1 = singleton::getInstance();
    instance1.doSomething(10);

    singleton& instance2 = singleton::getInstance();
    instance2.doSomething(11);

    // 验证两个实例是否相同
    std::cout << "Are the two instances the same? " 
              << (&instance1 == &instance2 ? "Yes" : "No") << std::endl;

    return 0;
}

