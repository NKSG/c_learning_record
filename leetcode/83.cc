//No.83
//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
//Remove Duplicates from Sorted List
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(cur){
            if(cur->val == pre->val){
                pre->next = cur->next;
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
