//方法1.遞迴
bool compare(struct TreeNode* left,struct TreeNode* right) {
    if (left == NULL && right != NULL)      //空節點的情況
        return false;
    else if (left != NULL && right == NULL)
        return false;
    else if (left == NULL && right == NULL)
        return true;
    else if (left->val != right->val)   //左右都不為空但數字不同
        return false;

    bool outside = compare(left->left, right->right);   // 左子樹的左，右子樹的右比較
    bool inside = compare(left->right, right->left);    // 左子樹的右，右子樹的左比較
    bool isSame = outside && inside;                    
    return isSame;
}

bool isSymmetric(struct TreeNode* root) {
    return compare(root->left,root->right);
}


//方法2.queue
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
bool isSymmetric(struct TreeNode* root) {
    
    if(root == NULL)
        return 1;   

    Queue* q = createQueue();
    enqueue(q, root->left);
    enqueue(q, root->right);

    while(!isEmpty(q)){
        struct TreeNode* left = dequeue(q);
        struct TreeNode* right = dequeue(q);

        if(!left && !right){    //如果是一對空節點，就不用跑下面的子節點加入queue的部分
            continue;
        }
        if(!left || !right){
            return false;
        }
        else if(left->val != right->val){
            return false;
        }
        enqueue(q,left->left);
        enqueue(q,right->right);
        enqueue(q,left->right);
        enqueue(q,right->left);   
    }
    return true;
}
