//方法1:遞迴(一般binary tree想法)
int countNodes(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    int num = left + right + 1;     //左+右+中間
    return num;
}


//方法2:
