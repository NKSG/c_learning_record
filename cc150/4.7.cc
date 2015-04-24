bool hasNode(ListNode* root, ListNode* p){
    if(!root) return false;
    if(root == p) return true;
    return hasNode(root->left,p) || hasNode(root->right,p);
}

ListNode* LCA(ListNode* root, ListNode* p , ListNode* q){
    if(hasNode(root->left,p) && hasNode(root->left,q))
        return LCA(root->left,p,q);
    if(hasNode(root->right,p) && hasNode(root->right,q))
        return LCA(root->right,p,q);
    return root;
}

ListNode* LCA_helper(ListNode* root, ListNode* p, ListNode* q){
    if(hasNode(root,p) && hasNode(root,q))
        return LCA(root,p,q);
    return nullptr;
}




ListNode* LCA_better(ListNode *root, ListNode *p, ListNode *q){
    if(!root) return nullptr;
    if(root==p||root==q) return root;
    ListNode *L = LCA(root->left,p,q);
    ListNode *R = LCA(root->right,p,q);
    if(L && R) return root;
    return L? L:R;
}
