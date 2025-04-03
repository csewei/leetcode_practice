int searchBorder(int* nums, int numsSize, int target, int LoR) {
    int left = 0, right = numsSize - 1;
    int ans = -1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (target > nums[middle]) {
            left = middle + 1;
        } else if (target < nums[middle]) {
            right = middle - 1;
        } else {
            ans = middle;
            if (LoR == 1) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
    }
    return ans;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int LeftBorder = searchBorder(nums, numsSize, target, 1);
    int RightBorder = searchBorder(nums, numsSize, target, 0);

    *returnSize = 2;
    int* resNums = (int*)malloc(sizeof(int) * 2);
    resNums[0] = LeftBorder;
    resNums[1] = RightBorder;
    return resNums;
}
