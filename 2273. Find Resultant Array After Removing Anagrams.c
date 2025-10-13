/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_WORDS 100
#define MAX_LEN 10

bool isAnagram(char* s, char* t) {
    int slen = strlen(s), tlen = strlen(t);

    if (slen != tlen) {
        return false;
    }
    int hash[26] = {0};
    for (int i = 0; i < slen; i++) {
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (hash[i] != 0) {
            return false;
        }
    }
    return true;
}

char** removeAnagrams(char** words, int wordsSize, int* returnSize) {

    if (wordsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    char** res = (char**)malloc(wordsSize * sizeof(char*));
    res[0] = words[0];
    int res_num = 0;
    for (int i = 1; i < wordsSize; i++) {
        if (!isAnagram(res[res_num], words[i])) {
            res_num++;
            res[res_num] = words[i];
        }
    }
    *returnSize = res_num + 1;
    return res;
}
