
#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

LinkedStack* createLinkedStack() {
    LinkedStack *stack;
    
    stack = (LinkedStack *) malloc(sizeof(LinkedStack));
    memset(stack, 0, sizeof(LinkedStack));
    
    return stack;
}

int push(LinkedStack *pStack, Node element) {
    Node *pNewElement = NULL;
    pNewElement = (Node *) malloc(sizeof(Node));
    *pNewElement = element;
    
    pNewElement->next = pStack->top;
    pStack->top = pNewElement;
    
    pStack->currentElementCount++;
    return TRUE;
}

Node* pop(LinkedStack *pStack) {
    Node *pReturn;
    
    if (isEmpty(pStack))
        return NULL;
    
    pReturn = pStack->top;
    pStack->top = pReturn->next;
    pReturn->next = NULL;
    
    pStack->currentElementCount--;
    return pReturn;
}

Node* peek(LinkedStack *pStack) {
    Node *pReturn;
    
    if (isEmpty(pStack))
        return NULL;
    
    pReturn = pStack->top;
    return pReturn;
}
void deleteLinkedStack(LinkedStack *pStack) {
    Node *deleteNode;
    int i;
    
    for (i=0; i<pStack->currentElementCount; i++) {
        deleteNode = pop(pStack);
        free(deleteNode);
    }
    
    free(pStack);
}

int isEmpty(LinkedStack *pStack) {
    int ret = FALSE;
    
    if (pStack->currentElementCount == 0)
        ret = TRUE;
    
    return ret;
}
