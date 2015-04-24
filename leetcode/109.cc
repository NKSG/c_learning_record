//No.109
//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
//Convert Sorted List to Binary Search Tree 
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while(p){
            len++;
            p = p->next;
        }
        return sortedListToBST(head, 0, len-1);
    }
private:
    TreeNode *sortedListToBST(ListNode* &head, int start, int end){
        if(start>end) return nullptr;
        int mid = start + (end-start)/2;
        TreeNode *leftChild = sortedListToBST(head,start,mid-1);
        TreeNode *parent = new TreeNode(head->val);
        parent->left = leftChild;
        head = head->next;
        parent->right = sortedListToBST(head, mid+1,end);
        return parent;
    }
};
