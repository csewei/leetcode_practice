//方法一(hash數組)
int getsum(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}
bool isHappy(int n) {
    int sum = getsum(n);
    int hash[820] = {0}; // 因為題目說n<=2^31-1也就是最多10位數，getsum最大9^2*10=810
    while (sum != 1) {
        if (hash[sum] == 1) {   //代表hash裡有出現過，也就是getsum開始循環
            return false;
        }
        else{
            hash[sum]++;
        }
        sum = getsum(sum);
    }
    return true;
}

//方法二(快慢指針)

int getsum(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}
bool isHappy(int n) {   //若為快樂數，則slow和fast最後都為1//若不為快樂數，則
                        //則循環時有時slow和fast會相同
    int fast = n, slow = n;
    do{
        slow = getsum(slow);        // slow走一步
        fast = getsum(fast);        // fast走兩步
        fast = getsum(fast);
    }while(fast != slow);
    
    if(fast == 1){
        return true;
    }
    else{
        return false;
    }
}
