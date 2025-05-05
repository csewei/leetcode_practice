//方法1: 遞迴
int maxDepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int max = 0;
    for (int i = 0; i < root->numChildren; i++) {
        int temp = maxDepth(root->children[i]);
        max = temp > max ? temp : max;
    }
    return max + 1;
}



//方法2:BFS
typedef struct QNode {
    struct Node* treeNode;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode* front;
    QNode* rear;
    int size;
} Queue;

/*** Queue 操作 ***/
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

int isEmpty(Queue* q) { return q->front == NULL; }

void enqueue(Queue* q, struct Node* node) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

struct Node* dequeue(Queue* q) {
    if (isEmpty(q))
        return NULL;

    QNode* temp = q->front;
    struct Node* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    q->size--;
    return node;
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int maxDepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    Queue* q = createQueue();
    enqueue(q, root);
    int floor = 0;
    while (!isEmpty(q)) {
        int levelSize = q->size;

        for (int i = 0; i < levelSize; i++) {
            struct Node* node = dequeue(q);
            for (int j = 0; j < node->numChildren; j++) {
                    enqueue(q, node->children[j]);
            }
        }
        floor++;
    }
    freeQueue(q);
    return floor;
}
