暴力法
int removeElement(int* nums, int numsSize, int val) {
    int ans = numsSize;
    for (int i = 0; i < ans; i++) {
        if (nums[i] == val) {
            for (int j = i + 1; j < ans; j++) {
                nums[j - 1] = nums[j];
            }
            i--;
            ans--;
        }
    }
    return ans;
}
雙指標法
int removeElement(int* nums, int numsSize, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < numsSize; fastIndex++) {
        if (nums[fastIndex] != val) {
            nums[slowIndex] = nums[fastIndex];
            slowIndex++;
        }
    }
    return slowIndex;
}
