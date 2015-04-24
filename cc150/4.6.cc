TreeNode* nextNode(TreeNode *head){
    if(head==nullptr) return nullptr;
    if(head->right){
        TreeNode *pos = head->right;
        while(pos->left){
            pos = pos->left;
        }
        return pos;
    }else{
        TreeNode *x = head->parent;
        while(x!=nullptr && x.left!=head){
            head = x;
            x = x.parrent;
        }
        return x;
    }
}
