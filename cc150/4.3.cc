TreeNode buildBST(int arr[], int start, int end){
    if(start>end) return nullptr;
    int mid = (start+end)>>1;
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildBST(arr,start,mid-1);
    root->right = buildBST(arr,mid+1,end);
    return root;
}
