//No.111
//https://leetcode.com/problems/minimum-depth-of-binary-tree/
//Minimum Depth of Binary Tree
//
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
    int minDepth(TreeNode *root) {
        return minDepth(root,false);
    }
private:
    int minDepth(const TreeNode *root, bool hasbrother){
        if(!root) return hasbrother? INT_MAX:0;
        return 1+min(minDepth(root->left,root->right!=nullptr),
        minDepth(root->right,root->left!=nullptr));
    }
};
