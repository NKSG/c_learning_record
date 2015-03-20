//No.19
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//Remove Nth Node From End of List 
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy, *q = &dummy;
        for(int i=0;i<n;i++)
            q=q->next;
        while(q->next){
            p=p->next;
            q=q->next;
        }
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return dummy.next;
    }
};
