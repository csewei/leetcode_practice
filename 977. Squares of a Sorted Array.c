//方法一(先全部平方，再用quick sort(較慢))

int partition(int *arr, int low, int high) {
    int pivot = arr[high]; // 選擇最後一個元素為基準
    int i = low - 1;       // i 指向比 pivot 小的最後一個元素

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // 如果當前元素小於 pivot
            i++; // 移動 i
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
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 找到 pivot 位置
        quickSort(arr, low, pi - 1);  // 遞迴處理左半部
        quickSort(arr, pi + 1, high); // 遞迴處理右半部
    }
}
int* sortedSquares(int* nums, int numsSize, int* returnSize) {

    *returnSize = numsSize;
    int* resNums = (int*)malloc(sizeof(int) * numsSize);
    
    for(int  i = 0; i < numsSize;i++){
        resNums[i] = nums[i]*nums[i];
    }
    quickSort(resNums,0,numsSize - 1);
    return resNums;
}


//方法二(two pointers(較快))

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* resNums = (int*)malloc(sizeof(int) * numsSize);

    int i = numsSize, left = 0, right = numsSize - 1;

    while (left <= right) {
        i--;   
        if (nums[left] + nums[right] < 0) {  //因為input為由小到大排列
            resNums[i] = nums[left]*nums[left];  
            left++;
        } 
        else {
            resNums[i] = nums[right]*nums[right];
            right--;
        }
    }
    return resNums;
}
