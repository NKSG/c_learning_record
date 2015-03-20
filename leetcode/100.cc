//No.100
//https://leetcode.com/problems/same-tree/
//Same Tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        if(!p||!q) return false;
        return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
};
//迭代
//
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> s;
        s.push(p);
        s.push(q);
        while(!s.empty()){
            p = s.top(); s.pop();
            q = s.top(); s.pop();
            if(!p&&!q) continue;
            if(!p||!q) return false;
            if(p->val!=q->val) return false;
            s.push(p->left);
            s.push(q->left);
            s.push(p->right);
            s.push(q->right);
        }
        return true;
    }
};
