//No.145
//https://leetcode.com/problems/binary-tree-postorder-traversal/
//Binary Tree Postorder Traversal 

/*递归版*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root){
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
private:
    void postorderTraversal(const TreeNode *root, vector<int>& result){
        if(root != nullptr){
            postorderTraversal(root->left, result);
            postorderTraversal(root->right, result);
            result.push_back(root->val);
        }
    }
};

/*迭代版*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root){
        vector<int> result;
        if(root == nullptr) return result;
        stack<const TreeNode *> s,s2;
        const TreeNode *cur = root;
        s.push(cur);
        while(!s.empty()){
            cur = s.top();
            s.pop();
            s2.push(cur);
            if(cur->left) s.push(cur->left);
            if(cur->right) s.push(cur->right);
        }
        while(!s2.empty()){
            result.push_back(s2.top()->val);
            s2.pop();
        }
        return result;
    }
};


/*这什么鬼？串了啊*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > sortedKeyValue;
        for(int i=0; i<strs.size(); i++){
            string tmp = strs[i];
            std::sort(tmp.begin(),tmp.end());
            sortedKeyValue[tmp].push_back(strs[i]);
        }
        vector<string> result;
        auto it = sortedKeyValue.begin();
        for(;it!=sortedKeyValue.end();it++){
            if((*it).second.size()<=1) continue;
            std::copy((*it).second.begin(),(*it).second.end(),back_inserter(result));
        }
        return move(result);
    }
};

