//No.106
//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
//Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(begin(inorder),end(inorder),begin(postorder),end(postorder));
    }

    template<typename InputIterator>
    TreeNode *buildTree(InputIterator in_first, InputIterator in_last, InputIterator post_first, InputIterator post_last){
        if(in_first == in_last) return nullptr;
        if(post_first == post_last) return nullptr;
        TreeNode *root = new TreeNode(*(prev(post_last)));
        auto inRootPos = find(in_first, in_last, *(prev(post_last)));
        auto leftSize = distance(in_first,inRootPos);
        
        root->left = buildTree(in_first,inRootPos,post_first,next(post_first,leftSize));
        root->right = buildTree(next(inRootPos),in_last,next(post_first,leftSize),prev(post_last));
    
        return root;
    }
};
