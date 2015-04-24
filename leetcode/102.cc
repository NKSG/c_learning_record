//No.102
//https://leetcode.com/problems/binary-tree-level-order-traversal/
//Binary Tree Level Order Traversal
//
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

/*递归版*/
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        levelOrder(root,1,result);
        return result;
    }
private:
    void levelOrder(TreeNode *root, int level, vector<vector<int> >& result){
        if(!root) return;
        if(level>result.size())
            result.push_back(vector<int>());
        result[level-1].push_back(root->val);
        levelOrder(root->left, level+1, result);
        levelOrder(root->right, level+1, result);
    }
};

/*递归版*/
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(root == nullptr) return result;
        
        queue<TreeNode *> current, next;
        vector<int> level;
        
        current.push(root);
        
        while(!current.empty()){
            while(!current.empty()){
                TreeNode* node = current.front();
                current.pop();
                level.push_back(node->val);
                if(node->left != nullptr) next.push(node->left);
                if(node->right != nullptr) next.push(node->right);
            }
            result.push_back(level);
            level.clear();
            swap(current, next);
        }
        return result;
    }
};
