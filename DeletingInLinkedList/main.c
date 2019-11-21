#include <stdio.h>
#include <stdlib.h>


struct n{
    int data ;
    struct n * next;
};typedef struct n node;


void printAll(node * r){

    printf("%d ",r->data);
    while(r -> next != NULL){
        r = r -> next;
        printf("%d ", r -> data);
    }
}

node * addNode(node * r , int x){

    node * iter = r;

    while(iter -> next != NULL){
        iter = iter -> next;}

    iter -> next = (node *)malloc(sizeof(node));
    iter -> next -> data = x;
    iter -> next -> next = NULL;

    return r;
}

node * deleteNode(node *r , int x){

    node * iter = r;
    node * temp;

    if(r -> data == x){
        temp = r;
        r = r -> next;
        free(temp);
        return r;
    }


    while(iter -> next != NULL && iter -> next -> data != x){
      iter = iter -> next;}

    if(iter -> next == NULL){
        printf("\n The number could not find");
        return r;
    }

    temp = iter -> next;
    iter -> next = temp-> next;
    free(temp);

    return r;
}


int main() {

    node * root = (node *)malloc(sizeof(node));
    root -> data = 4;
    root -> next = NULL;

    root = addNode(root,40);
    root = addNode(root,50);
    root = addNode(root, 450);

    printAll(root);
    printf("\nAfter deleting : ");
    deleteNode(root , 50);

    printAll(root);

    return 0;
}