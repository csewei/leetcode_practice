//使用滑動視窗

int minSubArrayLen(int target, int* nums, int numsSize) {
    int subarray_sum = 0, subarray_len = 0;
    int i = 0, ans = INT_MAX;            // i代表起始指針
    for (int j = 0; j < numsSize; j++) { // j代表終止指針
        subarray_sum += nums[j];
        while (subarray_sum >= target) {
            subarray_len = j - i + 1;
            if(ans < subarray_len){
    
            }
            else{
                ans = subarray_len;
            }
            subarray_sum -= nums[i];
            i++;
        }
    }
    if(ans == INT_MAX){
        return 0;
    }
    else{
        return ans;
    }
}


//錯誤答案，題目說subarray，如果sort的話array順序會打亂
int partition(int* arr, int low, int high) {
    int pivot = arr[high]; // 選擇最後一個元素為基準
    int i = low - 1;       // i 指向比 pivot 小的最後一個元素

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // 如果當前元素小於 pivot
            i++;              // 移動 i
            // 交換 arr[i] 和 arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 交換 pivot 到正確位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // 返回 pivot 的最終位置
}
// 快速排序函式 (QuickSort)
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 找到 pivot 位置
        quickSort(arr, low, pi - 1);        // 遞迴處理左半部
        quickSort(arr, pi + 1, high);       // 遞迴處理右半部
    }
}
int minSubArrayLen(int target, int* nums, int numsSize) {
    quickSort(nums, 0, numsSize - 1);
    int i = numsSize, ans = 0, count = 0;

    while (1) {
        i--;
        ans = ans + nums[i];
        count++;
        if(ans >= target){
            return count;
        }
        if(count == numsSize){
            return 0;
        }
    }
}
