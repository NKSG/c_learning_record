//No.116
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
//Populating Next Right Pointers in Each Node
//Same as No.117

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
                while(root){
            TreeLinkNode *next = nullptr;
            TreeLinkNode *prev = nullptr;
            for(; root; root = root->next){
                if(!next) next = root->left? root->left:root->right;
                if(root->left){
                    if(prev) prev->next = root->left;
                    prev = root->left;
                }
                if(root->right){
                    if(prev) prev->next = root->right;
                    prev = root->right;
                }
            }
            root = next;
        }
    }
};
