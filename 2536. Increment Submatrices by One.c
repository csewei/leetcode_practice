//法1:(difference array)(較佳)

int** rangeAddQueries(int n, int** queries, int queriesSize,
                      int* queriesColSize, int* returnSize,
                      int** returnColumnSizes) {
    
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) (*returnColumnSizes)[i] = n;

    // 建立 (n+1) x (n+1) 的差分陣列，自動初始化為 0
    int** diff = (int**)calloc(n + 1, sizeof(int*));
    for (int i = 0; i <= n; i++) {
        diff[i] = (int*)calloc(n + 1, sizeof(int));
    }

    // Step 1: 標記差分
    for (int i = 0; i < queriesSize; i++) {
        int r1 = queries[i][0], c1 = queries[i][1];
        int r2 = queries[i][2], c2 = queries[i][3];

        diff[r1][c1] += 1;

        if (r2 + 1 < n) diff[r2 + 1][c1] -= 1;
        if (c2 + 1 < n) diff[r1][c2 + 1] -= 1;
        if (r2 + 1 < n && c2 + 1 < n) diff[r2 + 1][c2 + 1] += 1;
    }

    // Step 2: 還原成答案（2D 前綴和）
    int** mat = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            int val = diff[i][j];
            if (i > 0) val += mat[i-1][j];
            if (j > 0) val += mat[i][j-1];
            if (i > 0 && j > 0) val -= mat[i-1][j-1];
            mat[i][j] = val;
        }
    }

    // 釋放 diff
    for (int i = 0; i <= n; i++) free(diff[i]);
    free(diff);

    return mat;
}

//法2:(暴力法)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** rangeAddQueries(int n, int** queries, int queriesSize,
                      int* queriesColSize, int* returnSize,
                      int** returnColumnSizes) {

    *returnSize = n;

    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }

    int** mat = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)calloc(n, sizeof(int));  // 用 calloc 自動初始化為 0
    }

    int row_start, row_end, col_start, col_end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }
    for (int i = 0; i < queriesSize; i++) {
        row_start = queries[i][0];
        col_start = queries[i][1];
        row_end = queries[i][2];
        col_end = queries[i][3];

        for (int j = row_start; j <= row_end; j++) {
            for (int k = col_start; k <= col_end; k++) {
                mat[j][k]++;
            }
        }
    }

    return mat;
}
