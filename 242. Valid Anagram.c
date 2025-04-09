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
