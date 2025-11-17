bool kLengthApart(int* nums, int numsSize, int k) {
    int lastOccured = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            if (lastOccured != -1) {
                int gap = i - lastOccured - 1;
                if (gap < k) return false;
            }
            lastOccured = i;
        }
    }
    return true;
}
