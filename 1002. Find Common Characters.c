void updateHashTable(int* hashTableOne, int* hashTableTwo) {
    int i;
    for(i = 0; i < 26; i++) {
        hashTableOne[i] = hashTableOne[i] < hashTableTwo[i] ? hashTableOne[i] : hashTableTwo[i];    //紀錄比較各word中不同字母出現次數的最小值
    }
}

char** commonChars(char** words, int wordsSize, int* returnSize) {
    int hash[26] = {0};
    if(wordsSize == 0){ //若intput為空，返回NULL
        return NULL;
    }
    *returnSize = 0;
    char** ret = (char**)malloc(sizeof(char*) * 100);   //一個word最長100個字母，最壞情形output會是100個字母
    int i;
    for(i = 0; i < strlen(words[0]); i++){
        hash[words[0][i] - 'a']++;
    }
        
    for(i = 1; i < wordsSize; i++) {        //由第一個word當基準，與其他word比較個字母出現次數，並記錄較小值
        int newHashTable[26] = { 0 };
        for(int j = 0; j < strlen(words[i]); j++) {
            newHashTable[words[i][j] - 'a']++;
        }
        updateHashTable(hash, newHashTable);   
    }
    for(i = 0; i < 26; i++) {
        if(hash[i]) {   //hash紀錄字串共同字母各有幾個
            int j;
            for(j = 0; j < hash[i]; j++) {  //有幾個該字母就輸出幾次
                char* tempString = (char*)malloc(sizeof(char) * 2);
                tempString[0] = i + 'a';
                tempString[1] = '\0';
                ret[(*returnSize)++] = tempString;
            }
        }
    }
    return ret;
    free(ret);
}
