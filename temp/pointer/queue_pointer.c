#include<stdio.h>
#define INT_MIN -2147483

struct Node {
    int data;
    struct Node* next;
};


struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int item){
    // Khoi tao mot node moi
    struct Node* newN = (struct Node*) malloc(sizeof(struct Node));
    newN->data = item;

    if(front == NULL && rear == NULL){
        front = newN;
        rear = newN;
    } else {
        rear->next = newN;
        rear = rear->next;
    }
}

int isEmpty(){
    return front == NULL;
}

int dequeue(){
    if(isEmpty()){
        return INT_MIN;
    }

    int item = front->data;
    struct Node* tmp = front;
    front = front->next;
    free(tmp);

    return item;
}

int getTop(){
    return front->data;
}

int main(){
    /*
    enqueue(3);
    enqueue(4);

    printf("top queue is %d", getTop());
    */

    int arr[5];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;

    int* add1 = &arr;

    printf("address of array: %p\n", arr);
    printf("address of array: %p\n", &arr[1]);
    printf("address of array: %p\n", add1 + 1);

    free(arr);

    printf("address of array: %p\n", arr);
    printf("address of array: %p\n", add1 + 1);
    printf("value of array: %d", *(add1 + 1));
}


