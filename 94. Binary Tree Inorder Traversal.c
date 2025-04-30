void inOrder(struct TreeNode* cur,int* ret ,int* returnSize){
    if(cur==NULL){
        return;
    }
    inOrder(cur->left,ret,returnSize);
    ret[(*returnSize)++] = cur->val; 
    inOrder(cur->right,ret,returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ret = (int*)malloc(sizeof(int)*100);
    *returnSize = 0;
    inOrder(root,ret,returnSize);
    return ret;
}
