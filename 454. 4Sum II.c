//使用uthash

typedef struct {
    int key;
    int value;
    UT_hash_handle hh; // make this structure hashable
} map;

map* hashMap = NULL;

void hashMapAdd(int key, int value) { // 把元素加入hash
    map* s;
    // key already in the hash?
    HASH_FIND_INT(hashMap, &key, s);
    if (s == NULL) {    //此key原本不在map裡
        s = (map*)malloc(sizeof(map));
        s->key = key;
        s->value = value;   //此key第一次出現，新增出現次數(value)
        HASH_ADD_INT(hashMap, key, s);
    }
    else{
        s->value += value;  //每次相同的key出現value變多
    }
}

map* hashMapFind(int key) {
    map* s;
    // *s: output pointer
    HASH_FIND_INT(hashMap, &key, s);
    return s; // 回傳對應的節點
}

void hashMapCleanup() { // 清理 hash 表記憶體
    map *cur, *tmp;
    HASH_ITER(hh, hashMap, cur, tmp) {
        HASH_DEL(hashMap, cur);
        free(cur);
    }
}

void hashPrint() {
    map* s;
    for (s = hashMap; s != NULL; s = (map*)(s->hh.next)) {
        printf("key %d, value %d\n", s->key, s->value);
    }
}

int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size,
                 int* nums3, int nums3Size, int* nums4, int nums4Size) {
    int i, j;
    map* hashMapRes;
    hashMap = NULL;
    int ans = 0;

    for (i = 0; i < nums1Size; i++) {
        for (j = 0; j < nums2Size; j++) {
            hashMapAdd(nums1[i] + nums2[j], 1); // 把A+B存到map裡
        }
    }
    int target = 0;
    for (i = 0; i < nums3Size; i++) {
        for (j = 0; j < nums4Size; j++) {
            target = 0 - (nums3[i] + nums4[j]); // 0 - (C+D) = A+B
            hashMapRes = hashMapFind(target);
            if (hashMapRes) { ////若target在map裡
                ans += hashMapRes->value;   //map裡的value代表有幾組不同的nums1[i]+nums[j]可以有相同的key值
            }
        }
    }
    hashMapCleanup();
    return ans;
}
