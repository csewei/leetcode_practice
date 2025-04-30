/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 定義 TreeNode 結構
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Queue 節點：儲存 TreeNode*
typedef struct QNode {
    TreeNode* treeNode;
    struct QNode* next;
} QNode;

// Queue 本體
typedef struct Queue {
    QNode* front;
    QNode* rear;
} Queue;

// 建立新的 Queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 判斷是否為空
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// 入隊操作：加入 TreeNode*
void enqueue(Queue* q, TreeNode* node) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 出隊操作：回傳 TreeNode* 並移除
TreeNode* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;

    QNode* temp = q->front;
    TreeNode* node = temp->treeNode;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
}
