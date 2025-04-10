/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size,
                  int* returnSize) {
    int nums1cnt[1005] = {0};
   
    int smaller = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* ans = (int*)calloc(smaller, sizeof(int));
    int ans_index = 0;

    int i;
    for (i = 0; i < nums1Size; i++) {
        nums1cnt[nums1[i]]++;
    }
    for (i = 0; i < nums2Size; i++) {
        if (nums1cnt[nums2[i]] > 0) {   //若>0，代表nums2[i]這個數字在nums1裡也有
            ans[ans_index] = nums2[i];
            ans_index++;
            nums1cnt[nums2[i]] = 0; //避免同一個數字輸出兩次
        }
    }
    *returnSize = ans_index;
    return ans;
}
