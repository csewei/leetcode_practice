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


//    非遞迴

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode** stack =
        (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    
    int* result = (int*)malloc(sizeof(int) * 100);
    int top = -1;
    *returnSize = 0;

    if (root == NULL) {
        free(stack);
        return result;
    }
    
    // 將根節點放入 stack
    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];              // 中
        result[(*returnSize)++] = node->val;

        if (node->right){
            stack[++top] = node->right;        // 右先進（後出）
        } 
        if (node->left){
            stack[++top] = node->left;         // 左後進（先出）    
        } 
    }

    free(stack);
    return result;
}
