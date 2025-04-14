//使用uthash

typedef struct {
    int key;
    int value;
    UT_hash_handle hh; // make this structure hashable
} map;

map* hashMap = NULL;

void hashMapAdd(int key, int value) {   //把元素加入hash
    map* s;
    // key already in the hash?
    HASH_FIND_INT(hashMap, &key, s);
    if (s == NULL) {
        s = (map*)malloc(sizeof(map));
        s->key = key;
        HASH_ADD_INT(hashMap, key, s);
    }
    s->value = value;
}

map* hashMapFind(int key) {
    map* s;
    // *s: output pointer
    HASH_FIND_INT(hashMap, &key, s);
    return s;   //回船對應的節點
}

void hashMapCleanup() {     //清理 hash 表記憶體
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

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, *ans;
    map* hashMapRes; 
    hashMap = NULL;
    ans = malloc(sizeof(int) * 2);

    for (i = 0; i < numsSize; i++) {
        hashMapRes = hashMapFind(target - nums[i]);     //查詢補數是否在map裡
        if(hashMapRes){ 
            ans[0] = i;
            ans[1] = hashMapRes -> value ;
            *returnSize = 2;
            return ans;
        }
        hashMapAdd(nums[i], i);     //把元素加入map
    }
    hashMapCleanup();   //釋放記憶體
    return NULL;
}
