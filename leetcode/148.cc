//No.148
//https://leetcode.com/problems/sort-list/
//sort list
///
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        while(ptr2->next && ptr2->next->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        ptr2 = ptr1->next;
        ptr1->next = nullptr;
        ptr1 = head;
        return merge(sortList(ptr1),sortList(ptr2));
    }
    
    ListNode *merge(ListNode *head1, ListNode *head2){
        if(head1==nullptr) return head2;
        if(head2==nullptr) return head1;
        ListNode *tmp;
      if(head1->val<=head2->val){
            tmp = head1;
            head1 = head1->next;
        }else{
            tmp = head2;
            head2 = head2->next;
        }
        tmp->next = merge(head1,head2);
        return tmp;
    }
};
