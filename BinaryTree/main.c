#include <stdio.h>
#include <stdlib.h>

struct n{

    int data;
    struct node * left;
    struct node * right;

}n; typedef struct n node;

node * addnew(node * tree , int x){

    if(tree == NULL){
        node * root = (node *)malloc(sizeof(node));
        root -> right = NULL;
        root -> left = NULL;
        root -> data = x;
        return root;
    }
    node * iter = tree;

    if(iter -> data < x) {
        tree->right = addnew(tree->right, x);
        return tree;}
    tree -> left = addnew(tree -> left , x);
    return tree;
}

void travel(node * tree){
if(tree == NULL) return;
    travel(tree -> left);
    printf("%d ",tree -> data);
    travel(tree -> right);
}

int main() {

    node * tree = NULL;

    tree = addnew(tree , 12);
    tree = addnew(tree , 25);
    tree = addnew(tree , 176);
    tree = addnew(tree , 245);
    tree = addnew(tree , 134);
    tree = addnew(tree , 657);
    tree = addnew(tree , 23);
    tree = addnew(tree , 34);
    tree = addnew(tree , 54);
    travel(tree);

    return 0;
}