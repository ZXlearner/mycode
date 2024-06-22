#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(nullptr){}
    ListNode(int val, ListNode * next):val(val),next(next){}
};

ListNode* reverseList(ListNode* head) {
    ListNode* p = head;
    ListNode* q = nullptr;
    while(p) {
        ListNode* tmp = p->next;
        p ->next = q;
        q = p;
        p = tmp;
    }
    return q;
}

ListNode* reverseFromNode(ListNode*head , ListNode* startNode) {
        ListNode* p = head;
        while(p->next != startNode) {
            p = p->next;
        }
        ListNode* q = reverseList(startNode);
        p->next = q;
        return head; 
}

void PrintfList(ListNode * head) {
    while(head) {
    std::cout<<head->val<<" ";
    head = head->next;
    }
    std::cout<<std::endl;
}


int main() {
    ListNode* p5 = new ListNode(5);
    ListNode* p4 = new ListNode(4, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* head = new ListNode(1, p2);
    PrintfList(head);
    
    ListNode* startNode = head->next->next;
    ListNode* newHead = reverseFromNode(head, startNode);
    PrintfList(newHead);

}