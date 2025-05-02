//linked_list queue

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

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q,struct Node* node) {
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
    if (isEmpty(q)) return NULL;

    QNode* temp = q->front;
    struct Node* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
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

struct Node* connect(struct Node* root)  {
    if (root==NULL) {
        return NULL;
    }

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int levelSize = q->size;
        struct Node* prev = NULL;      //每層開始前prev設為NULL

        for (int i = 0; i < levelSize; i++) {
            struct Node* node = dequeue(q);

            if(prev){
                prev->next = node;
            }
            prev = node;
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        prev->next = NULL;      //每層的最後一個指向NULL
    }

    freeQueue(q);
    return root;
}
