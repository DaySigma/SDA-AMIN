#ifndef GHOST_H
#define GHOST_H

typedef struct Ghost {
    char name[50];
    char type[50];
    char power[50];
    char weakness[50];
} Ghost;

typedef struct tElmtList *address;
typedef struct tElmtList {
    Ghost ghost;
    address next;
} ElmtList;

int scareSuccess(Ghost ghost, char *humanWeakness);
void createScareMessage(Ghost ghost, int success, char *message);

#endif