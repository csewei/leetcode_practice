//方法1: 遞迴
int maxDepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int max = 0;
    for (int i = 0; i < root->numChildren; i++) {
        int temp = maxDepth(root->children[i]);
        max = temp > max ? temp : max;
    }
    return max + 1;
}



//方法2:BFS
