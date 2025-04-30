typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* front; // 指向隊首節點
    Node* back;  // 指向隊尾節點(新加入的節點)
    int size;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));

    obj->front = NULL;
    obj->back = NULL;
    obj->size = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) { // 從尾部加入元素
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->val = x;
    new_node->next = NULL;

    if (obj->back) { // 若queue不為空
        obj->back->next = new_node;
    } else {
        obj->front = new_node;
    }
    obj->back = new_node;
    obj->size++;
}

int myStackPop(MyStack* obj) { // 從尾部取出元素
    int target = obj->back->val;
    if (obj->front == obj->back) { // 若queue為空
        free(obj->back);
        obj->front = NULL;
        obj->back = NULL;
    } else {
        Node* prev = obj->front;
        while (prev->next != obj->back) { // 移動到queue尾部節點的前一個
            prev = prev->next;
        }

        free(obj->back);
        obj->back = prev;
        obj->back->next = NULL;
    }

    obj->size--;
    return target;
}

int myStackTop(MyStack* obj) { return obj->back->val; }

bool myStackEmpty(MyStack* obj) { return obj->size == 0; }

void myStackFree(MyStack* obj) {
    while (obj->front != NULL) {
        Node* temp = obj->front;
        obj->front = obj->front->next;
        free(temp);
    }
    free(obj);
}
