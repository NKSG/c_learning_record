//No.129
//https://leetcode.com/problems/sum-root-to-leaf-numbers/
//Sum Root to Leaf Numbers 
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
    int sumNumbers(TreeNode *root) {
        return dfs(root,0);
    }
private:
    int dfs(TreeNode *root, int sum){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr)
            return sum*10+root->val;
        return dfs(root->left,sum*10+root->val)+dfs(root->right,sum*10+root->val);
    }
};
