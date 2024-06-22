/*反转链表*/ 
#include <iostream>

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int val):val(val), next(nullptr){}
  ListNode(int val, ListNode* next):val(val), next(next){}
};

ListNode* reverseList(ListNode* head) {
     ListNode* p = head;
     ListNode* q = nullptr;
     while(p) {
      ListNode* tmp = p->next;
      p->next = q;
      q = p;
      p = tmp;
     }
     return q;
}

void printfList(ListNode* head) {
  while(head) {
    std::cout<<head->val<<' ';
    head = head->next;
  }
  std::cout<<std::endl;
}

int main() {
   
   ListNode* p5 = new ListNode(5, nullptr);
   ListNode* p4 = new ListNode(4, p5);
   ListNode* p3 = new ListNode(3, p4);
   ListNode* p2 = new ListNode(2, p3);
   ListNode* head = new ListNode(1, p2);


   printfList(head);

   ListNode* ans = reverseList(head);
   
   printfList(ans);
   
}