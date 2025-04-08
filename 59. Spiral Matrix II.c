/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = n;
    int startx = 0, starty = 0;  //每一圈的起始位置
    int loop = n / 2;
    int mid = n / 2;
    int count = 1;
    int offset = 1;
    int i, j;
    while (loop--) {
        for (j = starty; j < n - offset; j++) {
            matrix[startx][j] = count;
            count++;
        }
        for (i = startx; i < n - offset; i++) {
            matrix[i][j] = count;
            count++;
        }
        for (j; j > starty; j--) {
            matrix[i][j] = count;
            count++;
        }
        for (i; i > startx; i--) {
            matrix[i][j] = count;
            count++;
        }
        startx++;
        starty++;
        offset++;
    }
    if (n % 2 == 1) {
        matrix[mid][mid] = count;
    }
    return matrix;
}
