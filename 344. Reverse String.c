//雙指針

void reverseString(char* s, int sSize) {
    int left, right;
    int len = sSize;
    char temp;
    for (left = 0, right = len - 1; left < len / 2; left++, right--) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }
}
