//使用陣列模擬stack

char* removeDuplicates(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(sizeof(char) * len + 1); // extra 1 for '\0'
    int top = 0;
    for(int i = 0;i<len;i++){
        if (top > 0 && stack[top - 1] == s[i]) {//如果當前s[i]與stack的top相同
            top--;  // pop 掉上一個
        } else {
            stack[top++] = s[i];  // push 當前字元
        }        
    }
    stack[top] = '\0';
    return stack;
}

//使用linked list實作stack(這題不適合)


typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct mystack {
    Node* top;
    int size;
} Stack;

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void stack_push(Stack* s, int val) {

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val;
    newnode->next = s->top;
    s->top = newnode;
    s->size++;
}

int stack_pop(Stack* s) {
    if (s->top == NULL) {
        printf("stack is empty");
        return -1;
    }
    Node* temp = s->top;
    int target = temp->val;

    s->top = temp->next;
    free(temp);
    s->size--;

    return target;
}
int stack_top(Stack* s) {
    if (s->top == NULL) {
        printf("stack is empty");
        return -1;
    }
    return s->top->val;
}

bool isempty(Stack* s) { return s->size == 0; }

void stack_free(Stack* s) {
    while (s->top != NULL) {
        Node* temp = s->top;
        s->top = temp->next;
        free(temp);
    }
    free(s);
}

char* removeDuplicates(char* s) {
    Stack* stack = create_stack();
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (isempty(stack) != 1 && stack_top(stack) == s[i]) {
            stack_pop(stack);
        } 
        else {
            stack_push(stack, s[i]);
        }
    }
    int j = stack->size;
    s[j] = '\0';
    j--;
    while (isempty(stack) != 1) {       //
        s[j] = stack_pop(stack);
        j--;
    }
    free(stack);
    return s;
}
