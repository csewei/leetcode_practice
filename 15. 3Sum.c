/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

//利用雙指針

int cmp(const void* ptr1, const void* ptr2) { // 運用qsort
    return *((int*)ptr1) > *((int*)ptr2);
}

int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {
    int** ans = (int**)malloc(sizeof(int*) * 20000);
    int ans_size = 0;
    qsort(nums, numsSize, sizeof(int), cmp); // 排序//設三數為A,B,C,A<=B<=C
    int i = 0;

    for (i = 0; i < numsSize; i++) {
        if(nums[i] > 0){    //經過排序後，如果A>0代表B,C>0，A+B+C>0
            break;
        }
        if (i != 0 && nums[i] == nums[i - 1]) { // nums[i]為A  //去除A重複出現
            continue;
        }
        int left = i + 1, right = numsSize - 1;

        while (left < right) { // nums[left]為B,nums[right]為C
            if (nums[i] + nums[left] + nums[right] > 0) { // A+B+C > 0
                right--;
            } 
            else if (nums[i] + nums[left] + nums[right] < 0) { // A+B+C < 0
                left++;
            } 
            else {
                int* arr =
                    (int*)malloc(sizeof(int) * 3); // A+B+C=0時 新增輸出的陣列
                arr[0] = nums[i];
                arr[1] = nums[left];
                arr[2] = nums[right];
                ans[ans_size] = arr;
                ans_size++;
                while (right > left &&
                       nums[left] ==
                           nums[left + 1]) { // ex:[0,-1,-1,-1,1,1,1]
                                             // 為了避免[0,-1,1]重複出現
                    left++;
                }
                while (right > left && nums[right] == nums[right - 1]) {
                    right--;
                }
                // 更新左右指針
                left++;
                right--;
            }
        }
    }
    // 設定輸出的陣列
    *returnSize = ans_size; // 目前找到了幾組答案
    *returnColumnSizes =
        (int*)malloc(sizeof(int) *
                     ans_size); // 為「每組答案的長度」配置空間，一共 ans_size個

    int z;
    for (z = 0; z < ans_size; z++) {
        (*returnColumnSizes)[z] = 3;
    }
    return ans;
    free(ans);
}
