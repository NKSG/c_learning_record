#include <iostream>

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int val=0, ListNode *n = nullptr):data(val),next(n){}
};

ListNode* findBeginning(ListNode* head){
    if(head==nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast){
        slow = slow->next;
        if(!fast->next){
            return nullptr;
        }
        fast = fast->next->next;
        if(fast == slow){
            break;
        }
    }
    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
