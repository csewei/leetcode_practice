/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

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

char*** groupAnagrams(char** strs, int strsSize, int* returnSize,int** returnColumnSizes) {
    if (strsSize == 0) {
        *returnSize = 0;
        **returnColumnSizes = 0;
        return NULL;
    }

    char*** res = (char***)malloc(strsSize * sizeof(char**));
    int res_group = 0,res_group_number = 0;
    bool finish = false;
    
    while(!finish){
        for (int i = 0; i < strsSize; i++) {
            if ( && isAnagram(strs[res_group], strs[i])) {
                res[res_group][res_group_number] = strs[i];
                res_group_number++;
            }   
        }
        res_group++;
    }
    return res;
}
