//No.199
//https://leetcode.com/problems/binary-tree-right-side-view/
//Binary Tree Right Side View 

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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        queue<TreeNode *> q;
        vector<int> level;
        if(root != nullptr){
            q.push(root);
            q.push(nullptr);
        }
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node){
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }else{
                result.push_back(level.back());
                level.clear();
                if(q.size()>0) q.push(nullptr);
            }
        }
        return result;
    }
};
