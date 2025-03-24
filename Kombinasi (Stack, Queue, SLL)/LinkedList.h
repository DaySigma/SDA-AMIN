#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Ghost.h"

typedef struct List {
    address first;
} List;

void initSLL(List *L);
void insertGhost(List *L, Ghost ghost);
void displayGhosts(List *L);
address findGhost(List *L, char *name);
void editGhost(List *L, char *name);
void deleteGhost(List *L, char *name);

#endif
