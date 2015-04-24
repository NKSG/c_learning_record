#include <iostream>
#include <unordered_map>
#include <algorithm>
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

void deleteDups(ListNode* head){
    if(head == nullptr || head->next == nullptr) return; 
    ListNode *pre;
    unordered_map<int,bool> map;
    while(head){
        if(map.find(head->data)!=map.end()){
            pre->next = head->next;
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }else{
            map[head->data] = true;
            pre = head;
            head = head->next;
        }
    }
}
/*
void deleteDups2(ListNode* head){
    if(head == nullptr || head->next == nullptr) return;
    ListNode *cur = head;
    while(cur!=nullptr){
        ListNode *runner = cur;
        while(runner->next!=nullptr){
            if(runner->next->data == cur->data){
                ListNode *temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
                runner = runner->next;
            }else{
                runner = runner->next;
            }
        }
        cur = cur->next;
    }
}
*/

void print(ListNode *head){
    ListNode *cur = head;
    while(cur){
        cout<<cur->data<<"->";
        cur = cur->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    int a[] = {1,1,2,2,5,3,4,5,6,7,8,8,8,1,2};
    int n = 15;
    ListNode *head = init(a,n);
    deleteDups(head);
    print(head);
    return 0;

}

