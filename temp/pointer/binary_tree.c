#include<stdio.h>

struct Tnode {
    int item;
    struct Tnode *leftChild;
    struct Tnode *rightChild;
}

// creare new node
struct Tnode *makeNewNode(int x){
    struct Tnode *newNode = NULL;
    newNode = (struct Tnode*) malloc(sizeof(struct Tnode));

    if(newNode == NULL){
        printf("Out of memory!");
        exit(1);
    }

    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->item = x;

    return newNode;
}

// count all node in tree
int countNodes(struct Tnode* tree){
    if(tree == NULL){
        return 0;
    }

    int lc = countNodes(tree->leftChild);
    int rc = countNodes(tree->rightChild);

    return 1 + lc + rc;
}

// depth
int depth(struct Tnode* tree){
    if(tree == NULL){
        return 0;
    }

    int ld = depth(tree->leftChild);
    int rd = depth(tree->rightChild);

    return 1 + (ld > rd? ld : rd);
}

// free all tree
void freeTree(struct Tnode* tree){
    if(tree == NULL){
        return
    }

    freeTree(tree->leftChild);
    freeTree(tree->rightChild);
    free(tree);
}

int main(){

    return 0;
}
