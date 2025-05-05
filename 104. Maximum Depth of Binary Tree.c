//方法1:遞迴
int maxDepth(struct TreeNode* root) {
    if(!root)
        return 0;
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    int max = left > right ? left : right;
    
    return max + 1;     //return 較大值 1為當前層數
}


//方法1.5:
// 全域變數：紀錄最大深度
int result = 0;

// 前序遍歷 + 回溯
void getDepth(struct TreeNode* node, int depth) {
    if (node == NULL) return;

    // 中：更新最大深度
    if (depth > result) {
        result = depth;
    }

    // 左
    if (node->left != NULL) {
        getDepth(node->left, depth + 1);
    }

    // 右
    if (node->right != NULL) {
        getDepth(node->right, depth + 1);
    }
}
// 主函數
int maxDepth(struct TreeNode* root) {
    result = 0; // 初始化
    if (root == NULL) return 0;

    getDepth(root, 1); // 從深度1開始
    return result;
}



//方法2:queue
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

int maxDepth(struct TreeNode* root) {
    if (root==NULL) {
        return 0;
    }

    Queue* q = createQueue();
    enqueue(q, root);
    int floor = 0;
    while (!isEmpty(q)) {
        int levelSize = q->size;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        floor++;
    }

    freeQueue(q);
    return floor;
}
