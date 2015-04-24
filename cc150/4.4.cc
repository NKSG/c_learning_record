#include <vector>
#include <list>
#include <iostream>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

vector<list<TreeNode*> > createLevelLinkedList(TreeNode* &head){
    list<TreeNode*> li;
    vector<list<TreeNode*> > result;
    li.push_back(head);
    result.push_back(li);
    int level = 0;
    while(!result[level].empty()){
        list<TreeNode*> current;
        for(auto it=result[level].begin(); it!=result[level].end(); ++it){
            TreeNode *temp = *it;
            if(temp->left) current.push_back(temp->left);
            if(temp->right) current.push_back(temp->right);
        }
        level++;
        if(!current.empty()){
            result.push_back(current);
        }
    }
    return result;
}
