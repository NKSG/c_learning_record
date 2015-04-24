//No.144
//https://leetcode.com/problems/binary-tree-preorder-traversal/
//Binary Tree Preorder Traversal 
//2015.04.24 最终更新

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*递归版本*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorderTraversal(root, result);
        return result;
    }
private:
    void visit(const TreeNode *node, vector<int>& result){
        result.push_back(node->val);
    }
    void preorderTraversal(const TreeNode *root, vector<int>& result){
        if(root != nullptr){
            visit(root, result);
            preorderTraversal(root->left, result);
            preorderTraversal(root->right, result);
        }
    }
};

/*迭代版本*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        const TreeNode *p;
        stack<const TreeNode *> s;

        p=root;
        if(p!=nullptr) s.push(p);
        while(!s.empty()){
            p = s.top();
            s.pop();
            result.push_back(p->val);
            if(p->right !=nullptr) s.push(p->right);
            if(p->left !=nullptr) s.push(p->left);
        }
        return result;
    }
/*Morris遍历*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *cur;
        cur = root;
        while(cur != nullptr){
            if(cur->left == nullptr){
                result.push_back(cur->val);
                cur = cur->right;
            }else{
                TreeNode *node = cur->left;
                while(node->right != nullptr && node->right != cur){
                    node = node->right;
                }
                if(node->right == nullptr){
                    result.push_back(cur->val);
                    node->right = cur;
                    cur = cur->left;
                }else{
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
