//linked_list queue

typedef struct QNode {
    struct TreeNode* treeNode;
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

void enqueue(Queue* q,struct TreeNode* node) {
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

struct TreeNode* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;

    QNode* temp = q->front;
    struct TreeNode* node = temp->treeNode;
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

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root==NULL) {
        *returnSize = 0;
        return NULL;
    }
    int* result = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int levelSize = q->size;
        int level;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            if(i == levelSize - 1){
                level = node->val;
            }
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        result[*returnSize] = level;
        (*returnSize)++;
    }

    freeQueue(q);
    return result;
}
