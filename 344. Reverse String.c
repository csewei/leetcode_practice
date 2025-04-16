void reverseString(char* s, int sSize) {
    int i, j;
    int len = sSize;
    char temp;
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
