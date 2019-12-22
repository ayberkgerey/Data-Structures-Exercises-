#include <stdio.h>
#include <stdlib.h>

struct n{

    int data;
    struct n *next;
}n;
typedef struct n node;

 node * root = NULL;
 node * end = NULL;

void enque(int x){

    if(root == NULL){
        root = (node *)malloc(sizeof(node));
        root -> data = x;
        root -> next = NULL;
        end = root;
    }
    else{
        end -> next = (node *)malloc(sizeof(node));
        end = end -> next;
        end -> data = x;
        end -> next = NULL;
    }

}

int deque(){
    if(root == NULL){
        printf("\nLinked List boş");
        return -1;
    }
    int rValue = root -> data;
    node * temp = root;
    root = root -> next;
    free(temp);
}

int main(){

    enque(10);
    deque();

    return 0;
}
