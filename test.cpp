#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    int key;
    int val;
    Node* pre;
    Node* next;
    Node():key(0), val(0), pre(nullptr), next(nullptr){}
    Node(int x, int y):key(x), val(y), pre(nullptr), next(nullptr){}
};

class LruCache{
private:
    unordered_map<int, Node*> cache;
    int capacity;
    int size;
    Node* dummy;
public:
    LruCache(int _capacity):capacity(_capacity), size(0), dummy(new Node){
        dummy->next = dummy;
        dummy->pre = dummy;
    }
    
    int get(int key) {
       if(!cache.count(key)) {
        std::cout<<"get: ("<<-1<<')'<<std::endl;
        return -1;
       }
        moveToHead(cache[key]);
        std::cout<<"get: ("<<cache[key]->val<<')'<<std::endl;
       return cache[key]->val;
    }

    void put(int key, int value){
         if(!cache.count(key)) {
            Node* node = new Node(key, value);
              cache[key] = node;
              size++;
              if(size > capacity) {
                Node* tmp = removeTail();
                cache.erase(tmp->key);
                delete tmp;
                size--;
              }
              insertToHead(node);
         }
         moveToHead(cache[key]);
         std::cout<< "pull: ("<<key<<','<<value<<')'<<std::endl;
    }

    void insertToHead(Node* node){
          dummy->next->pre = node;
          node->next = dummy->next;
          dummy->next = node;  
          node->pre = dummy;  
    }

    void deleteNode(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void moveToHead(Node* node) {
         deleteNode(node);
         insertToHead(node);
    }

    Node* removeTail() {
        Node* node = dummy->pre;
        deleteNode(node);
        return node;
    }


};


int main(){
    LruCache cache(2);
cache.put(1, 1);    // 缓存内容: {1=1}
    cache.put(2, 2);    // 缓存内容: {1=1, 2=2}
    cache.get(1);       // 返回 1, 缓存内容: {2=2, 1=1}
    cache.put(3, 3);    // 超出容量，删除键2，缓存内容: {1=1, 3=3}
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 超出容量，删除键1，缓存内容: {3=3, 4=4}
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回 3, 缓存内容: {4=4, 3=3}
    cache.get(4);       // 返回 4, 缓存内容: {3=3, 4=4}
}