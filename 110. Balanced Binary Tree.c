int getHeight(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int left_height = getHeight(node->left);
    if (left_height == -1)
        return -1;
    int right_height = getHeight(node->right);
    if (right_height == -1)
        return -1;
    int result;
    
    if (abs(left_height - right_height) > 1) {
        result = -1;
    } else {
        return 1 + (left_height > right_height ? left_height : right_height);
    }

    return result;
}
bool isBalanced(struct TreeNode* root) {
    return getHeight(root) == -1 ? false : true;
}
