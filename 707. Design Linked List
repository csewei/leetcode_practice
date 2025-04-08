typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node* data;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    Node* vhead = (Node*)malloc(sizeof(Node));
    vhead->next = (void*)0;
    obj->data = vhead;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index > obj->size - 1) {
        return -1;
    }
    Node* cur = obj->data;

    while (index-- >= 0) { //因為是取出第n個節點，所以有=
        cur = cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->val = val;

    Node* cur = obj->data;

	newnode->next = cur->next;
	cur->next = newnode;
	obj->size++;
}
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* cur = obj->data;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val; // 給新節點數值
    newnode->next = NULL;

    cur->next = newnode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) return;
    Node* cur = obj->data;

    while (index--) { // 用index==0當例子，可知正確//把cur指向n的前一個節點
        cur = cur->next;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val; // 給新節點數值
    newnode->next = cur->next;
    cur->next = newnode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;
    Node* cur = obj->data;

    while (index--) { // 用index==0當例子，可知正確//把cur指向n的前一個節點
        cur = cur->next;
    }
    Node* tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* tmp = obj->data;
    while (tmp != NULL) {
        Node* n = tmp;
        tmp = tmp->next;
        free(n);
    }
    free(obj);
}
