#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val){
    struct Node* newN = (struct Node*) malloc(sizeof(struct Node));
    newN->data = val;
    newN->next = NULL;

    return newN;
}

void push(struct Node* head, int val){
    struct Node* newN = newNode(val);
    if(head == NULL){
        newN->next = NULL;
    } else {
        newN->next = head;
    }

    head = newN;

    printf("Top of stack is %d\n", head->data);
    printf("----------------\n");
}

int pop(struct Node* head){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }

    int item = head->data;
    struct Node* tmp = head;
    head = head->next;
    free(tmp);

    printf("Top of stack is %d\n", head->data);
    return item;
}

int isEmpty(struct Node* head){
    return head == NULL;
}

int getTop(struct Node* head){
    if(head == NULL){
        return NULL;
    }

    return head->data;
}

int main(){
    struct Node* head = NULL;
    push(head, 10);
    pop(head);

    //printf("Top stack: %d", getTop(head));
}

