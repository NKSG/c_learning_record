//No.160
//https://leetcode.com/problems/intersection-of-two-linked-lists/
//Intersection of 2 linked lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        int len1=0, len2=0;
        ListNode *cur1=headA;
        ListNode *cur2=headB;
        while(cur1 && ++len1) cur1 = cur1->next;
        while(cur2 && ++len2) cur2 = cur2->next;
        if(len1>len2)
            for(int i=0; i<len1-len2;i++) headA=headA->next;
        else
            for(int i=0; i<len2-len1;i++) headB=headB->next;
        while(headA){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return false;
    }
};
