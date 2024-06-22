#include <iostream>
#include <thread>
void foo(int* ptr) {
    std::cout << *ptr << std::endl; // 访问已经被销毁的指针
}
int main() {
    int x = 1;
    std::thread t(foo, &x); // 传递指向局部变量的指针
    t.detach();
    return 0;
}