//No.94
//https://leetcode.com/problems/binary-tree-inorder-traversal/
//Binary Tree Inorder Traversal
//2015.04.24 最后更新

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
private:
    void inorderTraversal(const TreeNode *root, vector<int>& result){
        if(root != nullptr){
            inorderTraversal(root->left, result);
            result.push_back(root->val);
            inorderTraversal(root->right, result);
        }
    }
};

/*迭代版*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        const TreeNode *p = root;
        stack<const TreeNode *> s;
        while(!s.empty()||p!=nullptr){
            if(p!=nullptr){
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
};

/*morris*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *cur = root;
        while(cur != nullptr){
            if(cur->left == nullptr){
                result.push_back(cur->val);
                cur = cur->right;
            }else{
                TreeNode* node = cur->left;
                while(node->right != nullptr && node->right != cur){
                    node = node->right;
                }
                if(node->right == nullptr){
                    node->right = cur;
                    cur = cur->left;
                }else{
                    node->right = nullptr;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
