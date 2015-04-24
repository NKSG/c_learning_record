#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int val=0, ListNode *n = nullptr):data(val),next(n){}
};

ListNode* init(int a[], int n){
    ListNode *head = new ListNode(a[0]);
    ListNode *pre = head;
    for(int i=1; i<n; ++i){
        ListNode *p = new ListNode(a[i]);
        pre->next = p;
        pre = pre->next;
    }
    return head;
}

void print(ListNode *head){
    ListNode *cur = head;
    while(cur){
        cout<<cur->data<<"->";
        cur = cur->next;
    }
    cout<<"NULL"<<endl;
}

ListNode* nthToLast(ListNode *head, int k){
    if(head == nullptr || k<0) return nullptr;
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast && k--){
        fast = fast->next;
    }
    if(!fast){return slow;}
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    int a[]={1,1,2,2,5,3,4,5,6,7,9,8,8,1,2};
    int n = 15;
    ListNode *head = init(a,n);
    ListNode *x = nthToLast(head,5);
    cout<<x->data<<endl;
    return 0;
}
