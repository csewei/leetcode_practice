bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;
    
    while (i < bitsSize - 1) {  // 留最後一個不處理
        if (bits[i] == 0) {
            i += 1;  // 0 是單獨一個字符
        } else {
            i += 2;  // 1 開頭一定是兩個字符 (10 或 11)
        }
    }
    
    // 能走到這裡代表最後一個字符沒被前面吃掉
    // 如果 i == bitsSize-1 → 最後是 0（1-bit）
    // 如果 i == bitsSize   → 最後被吃掉了（變成2-bit的一部分）
    return i == bitsSize - 1;
}
