//stack

int evalRPN(char** tokens, int tokensSize) {

    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int stackTop = 0;

    int a1, a2, result;
    for (int i = 0; i < tokensSize; i++) {
        char symbol = (tokens[i])[0];
        if (symbol < '0' && (tokens[i])[1] == '\0') {   //判斷symbol是不是符號//(tokens[i])[1] == '\0'判斷不是-13
            a1 = stack[--stackTop];
            a2 = stack[--stackTop];
            if (symbol == '+') {
                result = a2 + a1;
            } 
            else if (symbol == '-') {
                result = a2 - a1;
            } 
            else if (symbol == '*') {
                result = a2 * a1;
            } 
            else {
                result = a2 / a1;
            }
            stack[stackTop++] = result;
        } 
        else {  //不是符號則push到stack裡
            int num = atoi(tokens[i]);  //字串轉整數
            stack[stackTop++] = num;
        }
    }
    int ans = stack[0];
    free(stack);
    return ans;
}
