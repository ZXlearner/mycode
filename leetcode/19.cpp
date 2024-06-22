/*删除链表的倒数第N个节点*/
#include<iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _val):val(_val), next(nullptr){}
    ListNode(int _val, ListNode* node):val(_val), next(node){}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* dummy  = new ListNode(0, head);
     ListNode* p = dummy;
     ListNode* q = head;
     for(int i = 0; i < n; i++) {
        q = q->next;
     }
     while(q) {
        q = q->next;
        p = p->next;
     }
     ListNode* tmp = p->next;
     p->next = p->next->next;
    delete tmp;
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
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
   int n = 2;

   ListNode* ans = removeNthFromEnd(head, n);
   
   printfList(ans);
   
}