typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct mystack{
    Node *top;
    int size;
}Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void stack_push(Stack *s,int value){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->val = value;
    newnode->next = s->top;
    s->top = newnode;
    s->size++;
}

int stack_pop(Stack *s){

    if (s->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }

    Node *temp = s->top;
    int val = temp->val;
    
    s->top = s->top->next;      //top移動到下個節點
    free(temp);
    s->size--;
    return val;
}

int stack_top(Stack *s){
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}
bool isempty(Stack *s){
    return s->size == 0;
}

void stack_free(Stack *s){
    while(s->top!=NULL){
        Node *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    free(s);
}
