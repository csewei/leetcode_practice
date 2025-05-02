//方法1.遞迴
bool compare(struct TreeNode* left,struct TreeNode* right) {
    if (left == NULL && right != NULL)      //空節點的情況
        return false;
    else if (left != NULL && right == NULL)
        return false;
    else if (left == NULL && right == NULL)
        return true;
    else if (left->val != right->val)   //左右都不為空但數字不同
        return false;

    bool outside = compare(left->left, right->right);   // 左子樹的左，右子樹的右比較
    bool inside = compare(left->right, right->left);    // 左子樹的右，右子樹的左比較
    bool isSame = outside && inside;                    
    return isSame;
}

bool isSymmetric(struct TreeNode* root) {
    return compare(root->left,root->right);
}


//方法2.
