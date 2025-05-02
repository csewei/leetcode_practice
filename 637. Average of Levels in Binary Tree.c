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

int isEmpty(Queue* q) { return q->front == NULL; }

void enqueue(Queue* q, struct TreeNode* node) {
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
    if (isEmpty(q))
        return NULL;

    QNode* temp = q->front;
    struct TreeNode* node = temp->treeNode;
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

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    double* result = (double*)malloc(sizeof(double) * 1000);
    *returnSize = 0;

    Queue* q = createQueue();
    enqueue(q, root);
    
    double level_average;
    long level_total = 0;
    
    while (!isEmpty(q)) {
        int levelSize = q->size;    //levelSize 就等於目前 queue中所有節點的數量，也就是這一層的節點數
        level_total = 0;
        
        for (int i = 0; i < levelSize;i++) { 
            struct TreeNode* node = dequeue(q);
            level_total += node->val;
            if (node->left)
                enqueue(q, node->left);
            if (node->right)
                enqueue(q, node->right);
        }
        
        level_average = (double)level_total /(double)levelSize;
        result[*returnSize] = level_average;
        (*returnSize)++;
    }
    freeQueue(q);
    return result;
}
