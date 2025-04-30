void postOrder(struct TreeNode* cur,int* ret, int* returnSize){
    if(cur == NULL)
        return;
    postOrder(cur->left, ret, returnSize);
    postOrder(cur->right, ret, returnSize);
    ret[(*returnSize)++] = cur->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ret = (int*)malloc(sizeof(int)*100);
    *returnSize = 0;
    postOrder(root,ret,returnSize);
    return ret;
}
