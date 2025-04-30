//binary traversal

void preOrder(struct TreeNode* cur, int* ret, int* returnSize) {
    if(cur == NULL)
        return;
    ret[(*returnSize)++] = cur->val;    //中
    preOrder(cur->left, ret, returnSize);   //左
    preOrder(cur->right, ret, returnSize);  //右
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    preOrder(root, ret, returnSize);
    return ret;
}
