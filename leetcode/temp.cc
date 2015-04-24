#include <iostream>
using namespace std;
class cat
{
    int age;
public:
    cat() {age = 1;}
    ~cat() {}
    void miao(void) {cout<<"Miao, my age = "<<age<<endl;}
};
int main(void)
{
    cat kitty;
    int * p = (int *)(&kitty);
    *p = 20;
    kitty.miao();
   return 0;
}




void BinaryTreePreOrder(TreeNode *head){
    if(head == nullptr) {
        visit(head);
    BinaryTreePreOrder(head->left);
    BinaryTreePreOrder(head->right);
}

vector<int> preorderTraversal(TreeNode *root){
    vector<int> result;
    const TreeNode *p;
    stack<const TreeNode *>s;
    
    p = root;
    if(p!=nullptr) s.push(p);
    while(!s.empty()){
        p = s.top();
        s.pop();
        result.push_back(p->val);
        if(p->right != nullptr) s.push(p->right);
        if(p->left != nullptr) s.push(p->left);
    }
    return result;
}


vector<int> preorderTraversal(TreeNode *root){
    vector<int> result;
    TreeNode *cur, *prev;

    cut = root;
    while(cur!=nullptr){
        if(cur->left == nullptr){
            result.push_back(cur->val);
            prev = cur;
            cur = cur->right;
        }else{
            TreeNode *node = cur->left;
            while(node->right != nullptr && node->right != cur)
                node = node->right;
            if(node->right == nullptr){
                result.push_back(cur->val);
                node->right = cur;
                prev = cur;
                cur = cur->left;
            }else{
                node->right = nullptr;
                cur = cur->right;
            }
        }
        return result;
    }
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};
