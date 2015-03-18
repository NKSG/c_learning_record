//No.101
//https://leetcode.com/problems/symmetric-tree/
//Symmetric Tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归版本
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return root? isSymmetric(root->left,root->right):true;
    }
    bool isSymmetric(TreeNode *left, TreeNode *right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        return left->val == right->val && isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }
};
//迭代版本
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        stack<TreeNode *> s;
        s.push(root->left);
        s.push(root->right);
        
        while(!s.empty()){
            auto p =s.top(); s.pop();
            auto q =s.top(); s.pop();
            
            if(!p && !q) continue;
            if(!p || !q) return false;
            if(p->val != q->val) return false;
            
            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
        return true;
    }

};
