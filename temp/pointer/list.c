#include<stdio.h>
#define INT_MIN -2147483648

struct node {
    int data;
    struct node *next;
};

struct node* head = NULL;

int isEmpty(){
    return head == NULL;
}

void print_list(){
    struct node *current = head;

    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

// push to front list
void push(int item){
    struct node* newN = (struct node*) malloc(sizeof(struct node));
    newN->data = item;
    newN->next = head;

    head = newN;
}

// pop last
void pop(){
    struct node* it = head;

    if(it->next == NULL){
        head = NULL;
        free(it);
        return;
    }

    while(it->next->next != NULL){
        it = it->next;
    }

    struct node* lastN = it->next;
    it->next = NULL;
    free(lastN);
}

void insert_by_index(int item, int inx){
    if(inx == 0){
        push(item);
        return;
    }

    struct node* it = head;
    int cnt = 1;

    while(cnt < inx){
        it = it->next;
        cnt++;
    }

    struct node* prev = it;
    struct node* next = it->next;

    // create new node
    struct node* newN = (struct node*) malloc(sizeof(struct node));
    newN->data = item;


}


int main(){
    // data example
    push(1);
    push(2);
    push(4);
    pop();
    pop();
    push(4);

    print_list();
}
