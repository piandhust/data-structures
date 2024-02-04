#include<stdio.h>
#define INT_MIN -2147483648

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void push(int item){
    // Khoi tao mot node moi
    struct Node* newN = (struct Node*) malloc(sizeof(struct Node));
    newN->data = item;
    newN->next = head;

    head = newN;
}

int isEmpty(){
    return head == NULL;
}

int pop(){
    if(isEmpty()){
        return INT_MIN;
    }

    int front = head->data;
    struct Node* tmp = head;
    head = head->next;
    free(tmp);

    return front;
}

int getTop(){
    return head->data;
}

int main(){
    push(2);
    push(3);

    printf("Top stack is %d\n", getTop());

    pop();
    printf("Top stack is %d\n", head->data);
}
