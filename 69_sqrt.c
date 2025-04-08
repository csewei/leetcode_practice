int mySqrt(int x) {
    int left = 0, right = x, ans = 0;
    if(x == 0){
        return 0;
    }
    if(x == 1){
        return 1;
    }
    while (left <= right) {
        int middle = left + ((right - left) / 2);
        if (middle > x / middle) {
            right = middle - 1;
        } else if (middle < x / middle) {
            left = middle + 1;
            ans = middle;
        } else {
            return middle;
        }
    }
    return ans;
}
