#include <iostream>
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

int getHeight(TreeNode *root){
    if(root==nullptr) return 0;
    return std::max(getHeight(root->left),getHeight(root->right))+1;
}

bool isBalanced(TreeNode *root){
    if(root == nullptr) return true;
    if(isBalanced(root->left)&&isBalanced(root->right)){
        int diff = getHeight(root->left) - getHeight(root->right);
        if(std::abs(diff)>1){return false;}else{return true;}
    }else{
        return false;
    }
}


