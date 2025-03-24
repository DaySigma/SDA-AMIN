#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

void initStack(Stack *S) {
    S->top = NULL;
}

void pushSuccess(Stack *S, Ghost ghost) {
    address newNode = (address)malloc(sizeof(ElmtList));
    newNode->ghost = ghost;
    newNode->next = S->top;
    S->top = newNode;
    printf("Hantu '%s' berhasil menakuti dan masuk riwayat.\n", ghost.name);
}

Ghost popSuccess(Stack *S) {
    if (S->top == NULL) {
        Ghost empty = {"", "", "", ""};
        printf("Riwayat keberhasilan kosong.\n");
        return empty;
    }
    address temp = S->top;
    Ghost ghost = temp->ghost;
    S->top = S->top->next;
    free(temp);
    return ghost;
}

void displaySuccess(Stack *S) {
    if (S->top == NULL) {
        printf("Riwayat keberhasilan kosong.\n");
        return;
    }
    address temp = S->top;
    printf("Riwayat Keberhasilan:\n");
    while (temp != NULL) {
        printf("- %s\n", temp->ghost.name);
        temp = temp->next;
    }
}
