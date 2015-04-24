#include <iostream>
#include <limits>
using namespace std;
//不存在重复元素
long long pre = numeric_limits<long long>::min();
bool inorder_BST(TreeNode *root){
    if(root == nullptr) return true;
    if(!inorder_BST(root->left))
        return false;
    if(pre >= root->val)
        return false;
    pre = root->val;
    if(!inorder_BST(root->right))
        return false;
    return true;
}

bool check_BST(TreeNode *root, int min, int max){
    if(root == nullptr) return true;
    if(root->val<min || root->val>=max){
        return false;
    }
    if(!check_BST(root->left, min, root->val)||!check_BST(root->right,root->val,max)){
        return false;
    }
    return true;
}

bool check_BST(TreeNode *root){
    return check_BST(root,numeric_limits<int>::min(),numeric_limits<int>::max());
}
