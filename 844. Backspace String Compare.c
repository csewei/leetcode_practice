//方法一(使用stack)
#define MAX_SIZE 200
void processString(char *input, char *output) {
    int top = 0; // stack 的指標
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != '#') {
            output[top] = input[i]; // push 字元
            top++;
        } else if (top > 0) {
            top--; // pop 最後一個字元
        }
    }
    output[top] = '\0'; // 結尾加上空字元
}
bool backspaceCompare(char* s, char* t) {
    char processedS[MAX_SIZE];
    char processedT[MAX_SIZE];

    processString(s, processedS);
    processString(t, processedT);
    
    return strcmp(processedS, processedT) == 0;
}

//方法二(two ppointers)


bool backspaceCompare(char* s, char* t) {
    int sSkipNum = 0, tSkipNum = 0;
    int slength = strlen(s) - 1, tlength = strlen(t) - 1;
    while (1) {
        while (slength >= 0) {       // 由後往前
            if (s[slength] == '#') { // 遇到# 記錄下來 要跳過
                sSkipNum++;
            } 
            else {
                if (sSkipNum > 0) { // 跳過#
                    sSkipNum--;
                }
                else {
                    break;
                }
            }
            slength--;
        }
        while (tlength >= 0) {
            if (t[tlength] == '#') {
                tSkipNum++;
            }
            else {
                if (tSkipNum > 0) {
                    tSkipNum--;
                }
                else {
                    break;
                }
            }
            tlength--;
        }
        if (slength < 0 || tlength < 0) {   //已全部完成
            break;
        }
        if (s[slength] != t[tlength]){
            return false;
        }
        slength--;  //因為跳出s去除#的while後沒有slength--，所以這邊要有
        tlength--;  //
    }
    if (slength == -1 && tlength == -1){
        return true;
    }
    else{
        return false; //s和t都去除#後，長度不一樣
    } 
}
