#define MAX_PATH_LEN 1000
#define MAX_RESULT_SIZE 1000
#define MAX_STRING_LEN 256

// 主遞迴函數：構建所有從根到葉的路徑
void traversal(TreeNode* cur, int* path, int pathSize, char result[][MAX_STRING_LEN], int* resultSize) {       //result為總共有幾條path
    path[pathSize++] = cur->val;  // 將當前節點加入 path 中 

    // 如果是葉節點
    if (cur->left == NULL && cur->right == NULL) {
        char sPath[MAX_STRING_LEN] = "";
        char buffer[32];

        // 將 path 陣列轉成字串，例如：1->2->5
        for (int i = 0; i < pathSize - 1; i++) {
            sprintf(buffer, "%d->", path[i]);
            strcat(sPath, buffer);
        }
        sprintf(buffer, "%d", path[pathSize - 1]);  //path裡的最後一個不需要->
        strcat(sPath, buffer);

        // 儲存這條路徑
        strcpy(result[*resultSize], sPath);
        (*resultSize)++;
        return;
    }

    // 遞迴處理左子樹
    if (cur->left) {
        traversal(cur->left, path, pathSize, result, resultSize);
    }

    // 遞迴處理右子樹
    if (cur->right) {
        traversal(cur->right, path, pathSize, result, resultSize);
    }
}

char** binaryTreePaths(TreeNode* root, int* returnSize) {
    static char result[MAX_RESULT_SIZE][MAX_STRING_LEN]; // 暫存的結果（固定大小）
    int* path = (int*)malloc(sizeof(int) * MAX_PATH_LEN); // path 儲存一條目前的路徑
    *returnSize = 0;

    if (root == NULL) {
        free(path);
        return NULL;
    }

    traversal(root, path, 0, result, returnSize);

    // 將 result 複製到動態配置的 char* 陣列中
    char** finalResult = (char**)malloc(sizeof(char*) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        finalResult[i] = strdup(result[i]);  // strdup 自動 malloc 並複製字串
    }

    free(path);
    return finalResult;
}
