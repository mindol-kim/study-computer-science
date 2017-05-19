
#ifndef linkedstack_h
#define linkedstack_h
#define TRUE    1
#define FALSE   0

#include <stdio.h>

typedef struct _Node {
    char data;
    struct _Node *next;
} Node;

typedef struct _LinkedStack {
    int currentElementCount;
    Node *top;
} LinkedStack;

LinkedStack* createLinkedStack();
int push(LinkedStack *pStack, Node element);
Node* pop(LinkedStack *pStack);
Node* peek(LinkedStack *pStack);
void deleteLinkedStack(LinkedStack *pStack);
int isEmpty(LinkedStack *pStack);

#endif /* linkedstack_h */
