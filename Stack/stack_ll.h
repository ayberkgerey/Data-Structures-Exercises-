#ifndef STACK_STACK_LL_H
#define STACK_STACK_LL_H

struct n{
    int data;
    struct n *next;

}n;
typedef struct n node;

int pop(node *);
node * push(node * , int);

#endif //STACK_STACK_LL_H
