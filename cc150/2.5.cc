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


ListNode* addList(ListNode* head1, ListNode* head2, int carry){
    if(head1 == nullptr && head2 == nullptr && carry ==0)
        return nullptr;
    ListNode* result = new ListNode();
    int value = carry;
    if(head1){ value+= head1->data; }
    if(head2){ value+= head2->data; }
    result->data = value%10;
    carry = value/10;
    result->next = addList(head1?head1->next:nullptr,head2?head2->next:nullptr,carry);
    return result;
}

ListNode* addList(ListNode* head1, ListNode* head2){
    return addList(head1,head2,0);
}


int main(){
    int a[]={1,1,2,2,5,3,4,5,6,7,9,8,8,1,2};
    int n = 15;
    int b[]={1,1,2,2,5,3,4,5,6,7,9,8,8,1,2};

    ListNode *head1 = init(a,n);
    ListNode *head2 = init(b,n);
    ListNode *new_head = addList(head1,head2);
    print(new_head);
    
    return 0;
}
