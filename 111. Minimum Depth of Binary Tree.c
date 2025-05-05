//方法1:遞迴(較簡單但速度較慢)
int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left_tree = minDepth(root->left);
    int right_tree = minDepth(root->right);

    if (root->left == NULL && root->right != NULL) {
        return 1 + right_tree;
    } 
    else if (root->right == NULL && root->left != NULL) {
        return 1 + left_tree;
    } 
    int min = 1 + (left_tree < right_tree ? left_tree : right_tree);
    
    return min;
}



//方法2:BFS
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

int minDepth(struct TreeNode* root) {
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
            if((!node->left) && (!node->right)){
                return floor + 1;
            }
        }
        floor++;
    }
    freeQueue(q);
    return floor;
}
