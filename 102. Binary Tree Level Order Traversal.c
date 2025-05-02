//linked_list queue

/*** Queue 節點與 Queue 定義 ***/
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
    q_size--;
    return node;
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root==NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int levelSize = q->size;
        int* level = (int*)malloc(sizeof(int) * levelSize);

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            level[i] = node->val;
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
    }

    freeQueue(q);
    return result;
}
