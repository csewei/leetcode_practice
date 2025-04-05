
int totalFruit(int* fruits, int fruitsSize) {
    int count[100000] = {0};    //記錄所有種類水果的數量
    int left = 0,right = 0;
    int max_len = 0,unique = 0;

    while(right < fruitsSize){
        if(count[fruits[right]] == 0){  //若該種水果原本有0個
            unique++;
        }
        count[fruits[right]]++;
        right++;

        while(unique > 2){
            count[fruits[left]]--;
            if(count[fruits[left]] == 0){
                unique--;
            }
            left++;
        }
        if (right - left > max_len) {
            max_len = right - left;
        }
    }
    return max_len;
}
