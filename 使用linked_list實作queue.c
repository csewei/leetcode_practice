typedef struct Node {
    int data;          // 儲存的資料
    struct Node* next; // 指向下一個節點
} Node;

typedef struct {
    Node* front; // 指向隊首節點（最早加入）
    Node* rear;  // 指向隊尾節點（最新加入）
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (q->rear == NULL) { // queue 是空的
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;  // 或自訂錯誤碼
    }

    Node* temp = q->front;
    int val = temp->val;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->val;
}
