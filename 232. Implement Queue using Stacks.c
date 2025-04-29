
typedef struct {
    int stackIn_top, stackOut_top;
    int stackIn[200], stackOut[200];
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stackIn_top = 0;
    queue->stackOut_top = 0;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stackIn[(obj->stackIn_top)++] = x;
    //(obj->stackIn_top)++;
}

int myQueuePop(MyQueue* obj) {
    int stackIn_top = obj->stackIn_top;     //將stack頂端指標暫時存進區域變數，減少對記憶體的重複存取
    int stackOut_top = obj->stackOut_top;
    
    if(stackOut_top == 0){    // 把stackIn裡的東西，反向放進stackOut
        while(stackIn_top > 0){
            obj->stackOut[stackOut_top++] = obj->stackIn[--stackIn_top];
        }
    }

    int top = obj->stackOut[--stackOut_top];     //把要pop的元素取出

    while(stackOut_top > 0){        //把拿出的東西，再反向放回stackIn
        obj->stackIn[stackIn_top++] = obj->stackOut[--stackOut_top];
    }
    
    obj->stackIn_top = stackIn_top;     //把stackIn_top存回struct
    obj->stackOut_top = stackOut_top;   //.....
    return top;
}


int myQueuePeek(MyQueue* obj) {
    return obj->stackIn[0];
}

bool myQueueEmpty(MyQueue* obj) {
    if ((obj->stackIn_top) == 0 && (obj->stackOut_top) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void myQueueFree(MyQueue* obj) {
    obj->stackIn_top = 0;
    obj->stackOut_top = 0;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
