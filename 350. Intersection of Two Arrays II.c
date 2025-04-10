int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size,
               int* returnSize) {
    int smaller = nums1Size > nums2Size ? nums1Size : nums2Size;
    int* ans = (int*)calloc(smaller,sizeof(int));
    int nums1cnt[1005] = {0};
    int ans_index = 0;
    int i;
    for (i = 0; i < nums1Size; i++){ 
        nums1cnt[nums1[i]]++;
    }
    for (i = 0; i < nums2Size; i++) {
        if (nums1cnt[nums2[i]] > 0) {
            ans[ans_index] = nums2[i];  //若在nums1cnt裡有nums2有的數字，則輸出該數字
            ans_index++;
            nums1cnt[nums2[i]]--;   //該數字在nums1cnt裡的數量-1
        }
    }
    *returnSize = ans_index;
    return ans;
}
