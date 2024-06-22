#include<iostream>
#include<unordered_map>
using namespace std;

struct Node {
 int key;
 int value;
 Node* next;
 Node* pre;
 Node():key(0),value(0),next(nullptr),pre(nullptr){}
 Node(int _key, int _value):key(_key), value(_value),next(nullptr),pre(nullptr){}
};

class LRUCache {
private:
unordered_map<int, Node*> cache;
int capacity;
int size;
Node* dummy;
public:
    LRUCache(int capacity):capacity(capacity),size(0),dummy(new Node) {
            dummy->next = dummy;
            dummy->pre = dummy;
    }
    
    int get(int key) {
       if (!cache.count(key)) {
        std::cout<< "get: "<<-1 <<std::endl;
        return -1;
       }  
       moveToHead(cache[key]);
       std::cout<< "get: "<< cache[key]->value <<std::endl;
       return cache[key]->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            Node* node = new Node(key, value);
            cache[key] = node;
            size++;
            if (size > capacity) {
              Node* remove = removeTail();
              cache.erase(remove->key);
              delete remove;
              size--;
            }
            insertToHead(node);
        }
        Node* node = cache[key];
        cache[key]->value = value;
        moveToHead(node);
        std::cout << "put(" << key << ", " << value << ")" << std::endl;
    }
    
 void insertToHead(Node* node) {
    node->next = dummy->next;
    node->pre = dummy; 
    dummy->next->pre = node;
    dummy->next = node;
 }

 void deleteNode(Node* node) {
    node->next->pre = node->pre;
    node->pre->next = node->next;
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
     LRUCache cache(2);

    cache.put(1, 1);    // 缓存内容: {1=1}
    cache.put(2, 2);    // 缓存内容: {1=1, 2=2}
    cache.get(1);       // 返回 1, 缓存内容: {2=2, 1=1}
    cache.put(3, 3);    // 超出容量，删除键2，缓存内容: {1=1, 3=3}
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 超出容量，删除键1，缓存内容: {3=3, 4=4}
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回 3, 缓存内容: {4=4, 3=3}
    cache.get(4);       // 返回 4, 缓存内容: {3=3, 4=4}

    return 0;

}