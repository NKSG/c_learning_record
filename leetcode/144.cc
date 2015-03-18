//No.144
//https://leetcode.com/problems/binary-tree-preorder-traversal/
//Binary Tree Preorder Traversal 
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        const TreeNode *p;
        stack<const TreeNode *> s;

        p=root;
        if(p!=nulptr) s.push(p);
        while(!s.empty()){
            p = s.top();
            s.pop();
            result.push_back(p->val);
            if(p->right !=nullptr) s.push(p->right);
            if(p->left !=nullptr) s.push(p->left);
        }
        return result;
    }
/*
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> result;
        TreeNode *cur, *prev;

        cur = root;
        while(cur!=nullptr){
            if(cur->left == nullptr){
                result.push_back(cur_val);
                prev = cur;
                cur = cur->next;
            }else{
                TreeNode 
            }
        }
    }
*/
//Morris遍历，线索化


};
