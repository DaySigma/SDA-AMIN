#ifndef QUEUE_H
#define QUEUE_H

#include "ghost.h"

typedef struct Queue {
    address head;
    address tail;
} Queue;

void initQueue(Queue *Q);
void enqueueGhost(Queue *Q, Ghost ghost);
Ghost dequeueGhost(Queue *Q);
void displayQueue(Queue *Q);

#endif
