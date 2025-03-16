#include <stdio.h>
#include <stdlib.h>
#include "main.h"

Node* CreateNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void InsertAtFirst(Node** top, int value) {
    Node* newNode = CreateNode(value);
    newNode->next = *top;
    *top = newNode;
}

void InsertAtLast(Node** top, int value) {
    Node* newNode = CreateNode(value);
    if (*top == NULL) {
        *top = newNode;
        return;
    }
    Node* temp = *top;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertBetween(Node* top, int target, int value) {
    Node* temp = top;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }
    Node* newNode = CreateNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void InsertByValue(Node** top, int value) {
    Node* newNode = CreateNode(value);
    if (*top == NULL || (*top)->data >= value) {
        newNode->next = *top;
        *top = newNode;
        return;
    }
    Node* temp = *top;
    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void DeleteAtFirst(Node** top) {
    if (*top == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    Node* temp = *top;
    *top = (*top)->next;
    free(temp);
}

void DeleteAtLast(Node** top) {
    if (*top == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if ((*top)->next == NULL) {
        free(*top);
        *top = NULL;
        return;
    }
    Node* temp = *top;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void PrintList(Node* top) {
    Node* temp = top;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void DeleteByValue(Node** top, int value) {
    if (*top == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if ((*top)->data == value) {
        Node* temp = *top;
        *top = (*top)->next;
        free(temp);
        return;
    }
    Node* temp = *top;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Value not found\n");
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void DeleteBetween(Node** top, int target) {
    Node* temp = *top;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("No element to delete after %d\n", target);
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void DeleteAll(Node** top) {
    while (*top != NULL) {
        Node* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main() {
    Node* top = NULL;

    InsertAtFirst(&top, 7);
    PrintList(top);

    InsertAtLast(&top, 11);
    PrintList(top);

    InsertBetween(top, 7, 9);
    PrintList(top);

    InsertAtFirst(&top, 5);
    PrintList(top);

    InsertAtLast(&top, 13);
    PrintList(top);

    DeleteAtLast(&top);
    PrintList(top);

    DeleteByValue(&top, 7);
    PrintList(top);

    DeleteAtFirst(&top);
    PrintList(top);
    
    DeleteAll(&top);
    PrintList(top);
    return 0;
}
