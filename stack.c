#define INT_MIN -2147483648

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};


// Khoi tao ngan xep
struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
}

// Kiem tra xem ngan xep day chua
int isFull(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}

// Kiem tra ngan xep rong khong
int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

// Them phan tu vao stack
void push(struct Stack* stack, int item){
    if(isFull(stack)){
        return;
    }

    stack->array[++stack->top] = item;
    printf("%d push to stack\n", item);
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        return INT_MIN;
    }

    return stack->array[stack->top--];
}

int getTop(struct Stack* stack){
    if(isEmpty(stack)){
        return INT_MIN;
    }

    return stack->array[stack->top];
}

int main(){
    struct Stack* stack = createStack(10);
    push(stack, 2);
    push(stack, 3);
    printf("Top of value in stack: %d", getTop(stack));

}
