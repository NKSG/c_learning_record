//No.98
//https://leetcode.com/problems/validate-binary-search-tree/
//Validate Binary Search Tree 

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
    bool isValidBST(TreeNode *root) {
        TreeNode *prev = nullptr;
        return isValidBST(root,prev);
    }
private:
    bool isValidBST(TreeNode *root, TreeNode* &prev){
        if(root == nullptr) return true;
        if(!isValidBST(root->left,prev)) return false;
        if(prev !=nullptr && prev->val>=root->val) return false;
        prev = root;
        return isValidBST(root->right, prev);
    }
};
