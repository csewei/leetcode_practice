//雙指針
//參考27題

void reverse(char* s, int left, int right) { // 反轉指定範圍的字串
    char temp;
    for (left, right; left < right; left++, right--) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }
}
void remove_space(char* s) { // 移除不該有的空格
    int fast_index,
        slow_index = 0; // fast用來遍歷字串//slow指向字串更新後字母應該在的位置
    int len = strlen(s);
    for (fast_index = 0; fast_index < len; fast_index++) {
        if (s[fast_index] != ' ') {
            if (slow_index != 0) { // 因為開頭不能有空格
                s[slow_index] = ' ';
                slow_index++;
            }
            while (fast_index < len && s[fast_index] != ' ') {
                s[slow_index] = s[fast_index];
                slow_index++;
                fast_index++;
            }
        }
    }
    s[slow_index] = '\0'; // 在新的字串結尾新增'\0'表示字串結束
}

char* reverseWords(char* s) {
    remove_space(s);
    int new_len = strlen(s);
    int word_len = 0;
    reverse(s, 0, new_len - 1); //反轉，讓每個詞出現在應該在的位置
    for (int i = 0; i < new_len; i++) {
        while (i < new_len && s[i] != ' ') {    //每當遇到字母，紀錄詞的長度
            i++;
            word_len++;
        }
        reverse(s, i - word_len, i - 1);    //反轉，讓每個詞回到原本順序
        word_len = 0;
    }
    return s;
}
