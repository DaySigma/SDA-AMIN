#ifndef STACK_H
#define STACK_H

#include "Ghost.h"

typedef struct Stack {
    address top;
} Stack;

void initStack(Stack *S);
void pushSuccess(Stack *S, Ghost ghost);
Ghost popSuccess(Stack *S);
void displaySuccess(Stack *S);

#endif
