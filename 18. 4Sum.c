/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

// 雙指針
// 先看3Sum
int cmp(const void* ptr1, const void* ptr2) { // 運用qsort
    return *((int*)ptr1) > *((int*)ptr2);
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize,
              int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp); // 排序
    int** ans = (int**)malloc(sizeof(int*) * 20000);
    int a, b, left, right, ans_size = 0;

    for (a = 0; a < numsSize; a++) {           // A+B+C+D = target，A>=B>=C>=D
        if (nums[a] > 0 && nums[a] > target) { // nums[a]為A//A剪枝
            break;
        }

        if (a > 0 && nums[a] == nums[a - 1]) { // A去除重複
            continue;
        }
        for (b = a + 1; b < numsSize; b++) {
            if (nums[a] + nums[b] > 0 && nums[a] + nums[b] > target) { // B剪枝
                break;
            }

            if (b > a + 1 && nums[b] == nums[b - 1]) { // B去除重複
                continue;
            }

            left = b + 1;
            right = numsSize - 1;

            while (left < right) {
                if ((long long)nums[a] + nums[b] + nums[left] + nums[right] > target) {
                    right--;
                } 
                else if ((long long)nums[a] + nums[b] + nums[left] + nums[right] < target) {
                    left++;
                } 
                else {
                    int* arr = (int*)malloc(sizeof(int) * 4);
                    arr[0] = nums[a];
                    arr[1] = nums[b];
                    arr[2] = nums[left];
                    arr[3] = nums[right];
                    ans[ans_size] = arr;
                    ans_size++;
                    while (left < right && nums[left] == nums[left + 1]) {  //left去除重複
                        left++;
                    }

                    while (left < right && nums[right] == nums[right - 1]) {  //right去除重複
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
    }
    *returnSize = ans_size;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ans_size);
    for (int z = 0; z < ans_size; z++) {
        (*returnColumnSizes)[z] = 4;
    }
    return ans;
    free(ans);
}
