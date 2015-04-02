#include <limits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val=0, TreeNode *left = nullptr, TreeNode *right = nullptr):val(val),left(left),right(right){}
};
class Solution{
    int min = numeric_limits<int>::min();
    int max = numeric_limits<int>::max();
    
    int getMin(int val1, int val2){
        return val1<val2?val1:val2;
    }

    int getMax(int val1, int val2){
        return val1>val2?val1:val2;
    }

    void travle(TreeNode* root){
        if(root == nullptr) return;
        min = getMin(min,root->val);
        max = getMax(max,root->val);
        travle(root->left);
        travle(root->right);
    }

    int getValue(){
        int ans = max-min;
        return ans>0? ans:(-1)*ans;
    }

    int maxValue(TreeNode* root){
        travle(root);
        return getValue();
    }

};
