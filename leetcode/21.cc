//No.21
//https://leetcode.com/problems/merge-two-sorted-lists/
//Merge Two Sorted Lists


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
    //不需要额外申请空间
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *base = NULL;
        ListNode *other = NULL;
        if(l1->val<=l2->val){
            base = l1;
            other = l2;
        }else{
            base = l2;
            other = l1;
        }
        ListNode *new_ptr = base;
        ListNode *cur = NULL;
        while(base && other){
            if(base->val <= other->val){
                cur = base;
                base=base->next;
            }else{
                cur->next = other;
                cur = other;
                ListNode *next = other->next;
                other->next = base;
                other = next;
            }
        }
        if(other){
            cur->next = other;
        }
        return new_ptr;
    }
};

//思想虽好，但是程序还是可以简化的，通过建立一个头结点，就不需要判断哪个作为base或other了

    ListNode *mergeTwoLists(ListNode *l1,ListNode *l2){
        ListNode head(-1);//这里需要申请空间吧?
        for(ListNode *p = &head; l1!=nullptr || l2!=nullptr; p = p->next){
            int val1 = l1==nullptr? INT_MAX:l1->val;
            int val2 = l2==nullptr? INT_MAX:l2->val;
            if(val1<=val2){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        return head.next;
    }
