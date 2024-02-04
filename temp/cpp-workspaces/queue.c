#define INT_MIN -2147483648

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity){
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = -1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Kiem tra queue day
int isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}

// Kiem tra queue rong
int isEmpty(struct Queue* queue){
    return (queue->size == 0);
}

// Them phan tu vao queue
void enqueue(struct Queue* queue, int item){
    if(isFull(queue)){
        return;
    }

    queue->rear = (queue->rear + 1);
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1);
    queue->size = queue->size - 1;
    return item;
}

int getFront(struct Queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }

    return queue->array[queue->front];
}

int getRear(struct Queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }

    return queue->array[queue->rear];
}

int main(){
    struct Queue* queue = createQueue(10);
    enqueue(queue, 1);
    enqueue(queue, 2);
    printf("Top of queue is %d", getFront(queue));
    printf("Rear of queue is %d", getRear(queue));

}
