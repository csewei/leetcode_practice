bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    if (p == NULL && q != NULL) {
        return false;
    } 
    else if (p != NULL && q == NULL) {
        return false;
    } 
    else if (p == NULL && q == NULL) {
        return true;
    } 
    else if (p->val != q->val) {
        return false;
    }

    bool left_comp = isSameTree(p->left, q->left);
    bool right_comp = isSameTree(p->right, q->right);
    bool ans = left_comp && right_comp;
    return ans;
}
