
#include<iostream>
using namespace std;
template <typename T, std::size_t N> 
class RingBuffQueue{
public:
  constexpr RingBuffQueue() : head(0), tail(0){}
  
   // 如果满了返回false, 成功返回true
  bool enqueue(T val) {
    if ((tail + 1) % N == head) {
        return false;
    }
    buffer[tail] = val;
    tail = (tail + 1) % N;
    return true;
  }
  
  // 如果空返回nullopt, 成功返回队首元素
  std::optional<T> dequeue() {
      if (head == tail) {
        return nullopt;
      }
      T res = buff[head];
      head = (head + 1) % N;
      return res;
  }
  
  private:
  std::array<T, N> buff;
  size_t head;
  size_t tail;
};
