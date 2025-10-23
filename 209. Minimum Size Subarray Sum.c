//使用滑動視窗

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int sum = 0; // 當前窗口的和
    int ans = numsSize + 1; // 初始化為一個不可能的長度，表示無解

    for (int right = 0; right < numsSize; right++) {
        sum += nums[right]; // 擴展窗口，加入右邊元素

        // 當窗口和 >= target 時，縮小窗口
        while (sum >= target) {
            ans = ans < (right - left + 1) ? ans : (right - left + 1); // 更新最小長度
            sum -= nums[left]; // 縮小窗口，移除左邊元素
            left++;
        }
    }

    // 如果 ans 仍為 numsSize + 1，說明無解，返回 0
    return ans == numsSize + 1 ? 0 : ans;
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
