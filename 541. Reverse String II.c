//雙指針

void reverse(char* s, int left, int right) {
    char temp;
    for (left, right; left < right; left++, right--) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }
}
char* reverseStr(char* s, int k) {
    int len = strlen(s);
    for (int i = 0; i < len; i += (2 * k)) {    //每隔2k個字母對前k個字母反轉
        if (i + k <= len) {     //剩餘字母<2k但>=k個
            reverse(s, i, i + k - 1);
            continue;
        } 
        else {  //剩餘字母<k個
            reverse(s, i, len - 1);
        }
    }
    return s;
}
