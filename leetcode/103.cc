//No.103
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
//Binary Tree Zigzag Level Order Traversal

/*迭代版*/
//在binary level order traversal基础上加上flag控制翻转

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(root == nullptr) return result;
        
        queue<TreeNode *> current, next;
        vector<int> level;
        int flag = 0;
        
        current.push(root);
        
        while(!current.empty()){
            while(!current.empty()){
                TreeNode* node = current.front();
                current.pop();
                level.push_back(node->val);
                if(node->left != nullptr) next.push(node->left);
                if(node->right != nullptr) next.push(node->right);
            }
            if(flag){
                reverse(level.begin(),level.end());
                flag = 0;
            }else{
                flag = 1;
            }
            result.push_back(level);
            level.clear();
            swap(current, next);
        }
        return result;
    }
};

/*迭代版*/
//以nullptr作为行间分隔符，以一个flag确定方向
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(root == nullptr) return result;
        queue<TreeNode *> q;
        bool left_to_right = true;
        vector<int> level;
        
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            if(cur){
                level.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }else{
                if(left_to_right){
                    result.push_back(level);
                }else{
                    reverse(level.begin(),level.end());
                    result.push_back(level);
                }
            
                level.clear();
                left_to_right = !left_to_right;
                if(q.size()>0) q.push(nullptr);
            }
        }
        return result;
    }
};
