//No.24
//https://leetcode.com/problems/swap-nodes-in-pairs/
//Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;
        
        for(ListNode *prev = &dummy, *cur = prev->next, *next = cur->next; next; prev = cur, cur = cur->next, next = cur? cur->next:nullptr){
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }
};
