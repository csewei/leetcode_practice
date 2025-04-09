bool canConstruct(char* ransomNote, char* magazine) {
    int hash[26] = {0};
    int ransom_len = strlen(ransomNote), mag_len = strlen(magazine);
    for (int i = 0; i < mag_len; i++) {
        hash[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransom_len; i++) {
        hash[ransomNote[i] - 'a']--;
        if (hash[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}
