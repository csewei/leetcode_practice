//方法1:
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return NULL;

    struct TreeNode* temp = root->right;    //交換左右child
    root->right = root->left;
    root->left = temp;

    invertTree(root->left); //左
    invertTree(root->right);    //右
    return root;
}


//方法2:
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return NULL;
    //存储结点的栈
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    int stackTop = 0;
    //将根节点入栈
    stack[stackTop++] = root;
    //若栈中还有元素（进行循环）
    while(stackTop) {
        //取出栈顶元素
        struct TreeNode* temp = stack[--stackTop];
        //交换结点的左右孩子
        struct TreeNode* tempNode = temp->right;
        temp->right = temp->left;
        temp->left = tempNode;
        //若当前结点有左右孩子，将其入栈
        if(temp->right)
            stack[stackTop++] = temp->right;
        if(temp->left)
            stack[stackTop++] = temp->left;
    }
    return root;
}


//方法3:利用queue做BFS
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

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root==NULL) {
        return NULL;
    }

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int levelSize = q->size;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            struct TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

    }

    freeQueue(q);
    return root;
}


    invertTree(root->left); //左
    invertTree(root->right);    //右
    return root;
}
