#include <stdio.h>
#include <stdlib.h>

struct n{
        int x;
        struct n * next;
};
typedef struct n node;

void printAll(node * r){
    int i = 0;
    while(r -> next != NULL) {
        i++;
        printf("%d. value is %d \n", i, r->x);
        r = r->next;
    }
}

void add(node * r , int x){
    while(r -> next != NULL){
        r = r -> next;
    }
    r -> next = (node *)malloc(sizeof(node));
    r -> next -> x = x;
    r -> next -> next = NULL;
}

node * sequentialInsertion(node * r ,int x){

    if(r == NULL){
        r = (node *) malloc(sizeof(node));
        r -> next = NULL;
        r -> x = x;
        return r;
    }

    if(r -> x > x){
        node * temp = (node *)malloc(sizeof(node));
        temp -> x = x;
        temp -> next = r;
        return temp;
    }

    node * iter = r;
    while(iter -> next != NULL && iter -> next -> x < x){
        iter = iter -> next;
    }

    node * temp = (node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> x = x;
    return r;

}

int main() {
    node * root;
    root = NULL;

    root =  sequentialInsertion(root,400);
    root =  sequentialInsertion(root,300);
    root =  sequentialInsertion(root,320);
    root =  sequentialInsertion(root,450);
    root =  sequentialInsertion(root,550);

    printAll(root);

    return 0;
}