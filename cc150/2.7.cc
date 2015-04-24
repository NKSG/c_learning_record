#include <stack>
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


bool isPalindrome(ListNode *head){
    if(head == nullptr || head->next == nullptr) return true;
    ListNode *slow = head;
    ListNode *fast = head;
    bool odd = false;
    stack<int> stack;
    while(fast){
        stack.push(slow->data);
        slow = slow->next;
        if(!fast->next){
            odd = true;
            break;
        }else{
            fast = fast->next->next;
        }
    }
    if(odd){
        stack.pop();
    }
    while(slow){
        if(stack.top()==slow->data){
            stack.pop();
            slow = slow->next;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    int a[]={1,2,5,2,3,2,5,2,1};
    int n = 9;
    ListNode *head = init(a,n);
    cout<<isPalindrome(head)<<endl;    
    return 0;
}
