#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

void initQueue(Queue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
}

void enqueueGhost(Queue *Q, Ghost ghost) {
    address newNode = (address)malloc(sizeof(ElmtList));
    newNode->ghost = ghost;
    newNode->next = NULL;

    if (Q->tail == NULL) {
        Q->head = Q->tail = newNode;
    } else {
        Q->tail->next = newNode;
        Q->tail = newNode;
    }
    printf("Hantu '%s' masuk antrian untuk menakuti.\n", ghost.name);
}

Ghost dequeueGhost(Queue *Q) {
    if (Q->head == NULL) {
        Ghost empty = {"", "", "", ""};
        printf("Antrian hantu kosong.\n");
        return empty;
    }
    address temp = Q->head;
    Ghost ghost = temp->ghost;
    Q->head = Q->head->next;
    if (Q->head == NULL) {
        Q->tail = NULL;
    }
    free(temp);
    return ghost;
}

void displayQueue(Queue *Q) {
    if (Q->head == NULL) {
        printf("Antrian hantu kosong.\n");
        return;
    }
    address temp = Q->head;
    printf("Antrian Hantu:\n");
    while (temp != NULL) {
        printf("- %s\n", temp->ghost.name);
        temp = temp->next;
    }
}
