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


ListNode* partition(ListNode* head, int mid){
    ListNode *left_end = nullptr;
    ListNode *right_end = nullptr;
    ListNode *left_head = nullptr;
    ListNode *right_head = nullptr;
    while(head){
        ListNode *next = head->next;
        head->next = nullptr;
        if(head->data<mid){
            if(left_head==nullptr){
                left_head = head;
                left_end = left_head;
            }else{
                left_end->next = head;
                left_end = head;
            }
        }else{
            if(right_head == nullptr){
                right_head = head;
                right_end = right_head;
            }else{
                right_end->next = head;
                right_end = head;
            }
        }
        head = next;
    }

    if(left_head == nullptr) return right_head;
    left_end->next = right_head;
    return left_head;
}

int main(){
    int a[]={1,1,2,2,5,3,4,5,6,7,9,8,8,1,2};
    int n = 15;

    ListNode *head = init(a,n);
    print(head);
    ListNode *head2 = partition(head,7);
    print(head2);
    
    return 0;
}
