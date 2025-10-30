#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node* data;     //用來指向dummyhaed
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {		//建立一個 dummy head node（vhead），其 next 為 NULL。//將 dummy node 指派給 data。
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
    Node* cur = obj->data;  //cur指向dummyhead

    while (index--) { //因為是取出第n個節點，所以有=
        cur = cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->val = val;

    Node* cur = obj->data;  //cur指向dummyhead

	newnode->next = cur->next;
	cur->next = newnode;
	obj->size++;
}
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* cur = obj->data;  //cur指向dummyhead

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
    Node* cur = obj->data;  //cur指向dummyhead

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
    Node* cur = obj->data;  //cur指向dummyhead

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
int main() {
    // 建立 LinkedList
    MyLinkedList* list = myLinkedListCreate();

    // 插入一些資料
    myLinkedListAddAtHead(list, 10);   // [10]
    myLinkedListAddAtTail(list, 20);   // [10, 20]
    myLinkedListAddAtTail(list, 30);   // [10, 20, 30]
    myLinkedListAddAtIndex(list, 1, 15); // [10, 15, 20, 30]

    // 印出目前列表內容
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", myLinkedListGet(list, i));
    }
    printf("\n");

    // 刪除 index = 2 的節點（也就是 20）
    myLinkedListDeleteAtIndex(list, 2); // [10, 15, 30]

    // 再次印出列表內容
    printf("After deletion: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", myLinkedListGet(list, i));
    }
    printf("\n");

    // 釋放記憶體
    myLinkedListFree(list);

    return 0;
}
