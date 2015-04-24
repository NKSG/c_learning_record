//No.114
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//Flatten Binary Tree to Linked List

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
    void flatten(TreeNode *root) {
        if(root == nullptr) return;
        stack<TreeNode *> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* p = s.top();
            s.pop();
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
            
            p->left = nullptr;
            if(!s.empty()){
                p->right = s.top();
            }
        }
    }
};
