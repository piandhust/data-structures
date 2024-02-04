#include <stdio.h>
#include<stdlib.h>

#define INT_MIN -2147483648

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void push(int val){
    struct Node* newN = (struct Node*) malloc(sizeof(struct Node));
    newN->data = val;

    if(head == NULL){
        newN->next = NULL;
    } else {
        newN->next = head;
    }

    head = newN;

    printf("Top of stack is %d\n", head->data);
    printf("----------------\n");
}

int pop(){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }

    int item = head->data;
    struct Node* tmp = head;
    head = head->next;
    free(tmp);

    return item;
}

int isEmpty(){
    return head == NULL;
}

int getTop(){
    if(head == NULL){
        return INT_MIN;
    }

    return head->data;
}

int main(){
    push(10);
    pop();

    printf("Top stack: %d", getTop(head));
}

