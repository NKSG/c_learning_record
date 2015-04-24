//No.107
//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
//Binary Tree Level Order Traversal 2

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        traverse(root,1,result);
        std::reverse(result.begin(),result.end());
        return result;
    }
    
    void traverse(TreeNode *root, size_t level, vector<vector<int> > &result){
        if(!root) return;
        if(level>result.size())
            result.push_back(vector<int>());
        result[level-1].push_back(root->val);
        traverse(root->left,level+1,result);
        traverse(root->right,level+1,result);
    }
};
