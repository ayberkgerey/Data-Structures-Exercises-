#include <stdio.h>
#include <stdlib.h>

 struct n{
     int x;
     struct n * next;
};
typedef struct n node;

void printAll(node * r){
    int i = 0;
    while(r -> next != NULL){
        i++;
        printf("%d. value is %d \n", i , r -> x);
        r = r -> next;
    }
}

int main() {
    node * root;
    root = (node *)malloc(sizeof(node));

    //able to assign values manually.
    root -> x = 10;
    root -> next = (node *)malloc(sizeof(node));
    root -> next -> x = 15;
    root -> next -> next = (node *)malloc(sizeof(node));
    root -> next -> next -> x = 20;

    node * iter;
    iter = root -> next -> next;

    int i;
    //able to assign values with loop.
    for(i = 1 ; i<=4 ; i++){
        iter -> next = (node *)malloc(sizeof(node));
        iter = iter -> next;
        iter -> x = i*5;
        iter -> next = NULL;
    }
    printAll(root);

    return 0;
}