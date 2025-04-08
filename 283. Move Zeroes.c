//方法一(先數有幾個0)
void moveZeroes(int* nums, int numsSize) {
    int zcount = 0, j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            zcount++;
        } else {
            nums[j] = nums[i];
            j++;
        }
    }
    for (int z = 0; z < zcount; z++) {
        nums[numsSize - 1 - z] = 0;
    }
}

//方法二(雪球法)
void moveZeroes(int* nums, int numsSize) {
    int snowball_size = 0, temp = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            snowball_size++;
        } else if (snowball_size > 0) {
            temp = nums[i];
            nums[i] = 0;
            nums[i - snowball_size] = temp;
        }
    }
}
