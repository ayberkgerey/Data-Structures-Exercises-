#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

void printAll(node * root){

    while(root != NULL){
        printf("%d -> ",root -> data);
        root = root -> next;
    }
}


int pop(node * root){
    if(root == NULL){
        printf("\nStack is Empty");
        return -1;
    }

    node * iter = root;
    while(iter -> next -> next != NULL)
        iter = iter -> next;
        node * temp = iter -> next;
        int rValue = temp -> data;
        free(temp);
        iter -> next = NULL;

        return rValue;
}


node * push (node * root , int a){
    if(root == NULL){
        root = (node *)malloc(sizeof(node));
        root -> data = a;
        root -> next = NULL;
        return root;
    }

    node * iter = root;
    while(iter -> next != NULL)
        iter = iter -> next;

    node * temp = (node *)malloc(sizeof(node));
    temp -> data = a;
    iter -> next = temp;
    temp -> next = NULL;

    return root;
}


int main() {

    node * s = NULL;
    s = push(s , 10);
    s = push(s , 20);
    printAll(s);
    fflush(stdout);
    perror("Passed");
    printf("%d -> ",pop(s));
    printf("%d -> ",pop(s));

    return 0;
}