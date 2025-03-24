#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

void initSLL(List *L) {
    L->first = NULL;
}

void insertGhost(List *L, Ghost ghost) {
    address newNode = (address)malloc(sizeof(ElmtList));
    newNode->ghost = ghost;
    newNode->next = NULL;

    if (L->first == NULL) {
        L->first = newNode;
    } else {
        address temp = L->first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Hantu '%s' ditambahkan ke database.\n", ghost.name);
}

void displayGhosts(List *L) {
    if (L->first == NULL) {
        printf("Database hantu kosong.\n");
        return;
    }
    address temp = L->first;
    printf("Daftar Hantu:\n");
    while (temp != NULL) {
        printf("- %s (%s) | Kekuatan: %s | Kelemahan: %s\n", 
               temp->ghost.name, temp->ghost.type, temp->ghost.power, temp->ghost.weakness);
        temp = temp->next;
    }
}

address findGhost(List *L, char *name) {
    address temp = L->first;
    while (temp != NULL) {
        if (strcmp(temp->ghost.name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void editGhost(List *L, char *name) {
    address ghostNode = findGhost(L, name);
    if (ghostNode == NULL) {
        printf("Hantu '%s' tidak ditemukan.\n", name);
        return;
    }
    printf("Masukkan jenis baru: ");
    fgets(ghostNode->ghost.type, 50, stdin);
    ghostNode->ghost.type[strcspn(ghostNode->ghost.type, "\n")] = 0;
    printf("Masukkan kekuatan baru: ");
    fgets(ghostNode->ghost.power, 50, stdin);
    ghostNode->ghost.power[strcspn(ghostNode->ghost.power, "\n")] = 0;
    printf("Masukkan kelemahan baru: ");
    fgets(ghostNode->ghost.weakness, 50, stdin);
    ghostNode->ghost.weakness[strcspn(ghostNode->ghost.weakness, "\n")] = 0;
    printf("Data hantu '%s' telah diperbarui.\n", name);
}

void deleteGhost(List *L, char *name) {
    address current = L->first;
    address prev = NULL;

    while (current != NULL && strcmp(current->ghost.name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Hantu '%s' tidak ditemukan.\n", name);
        return;
    }

    if (prev == NULL) {
        L->first = current->next;
    } else {
        prev->next = current->next;
    }
    printf("Hantu '%s' telah dihapus dari database.\n", name);
    free(current);
}
