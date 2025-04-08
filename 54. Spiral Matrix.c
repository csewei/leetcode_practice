int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = *matrixColSize;
    *returnSize = m * n;
    int* result = (int*)malloc((*returnSize) * sizeof(int));

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int index = 0;

    while (top <= bottom && left <= right) {
        // 向右
        for (int i = left; i <= right; i++){
            result[index] = matrix[top][i];
            index++;
        }
        top++;

        // 向下
        for (int i = top; i <= bottom; i++){
            result[index] = matrix[i][right];
            index++;
        }
        right--;

        // 向左
        if (top <= bottom) {
            for (int i = right; i >= left; i--){
                result[index] = matrix[bottom][i];
                index++;
            }
            bottom--;
        }

        // 向上
        if (left <= right) {
            for (int i = bottom; i >= top; i--){
                result[index] = matrix[i][left];
                index++;
            }
            left++;
        }
    }

    return result;
}
