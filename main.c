#include "main.h"

// Fungsi untuk membuat node baru
int BuatNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memori tidak cukup!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menyisipkan node di awal
void InsertAwal(Node **top, int value) {
    Node *newNode = BuatNode(value);
    newNode->next = *top;
    *top = newNode;
}

// Fungsi untuk menyisipkan node di akhir
void InsertAkhir(Node **top, int value) {
    Node *newNode = BuatNode(value);
    if (*top == NULL) {
        *top = newNode;
        return;
    }
    Node *temp = *top;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Fungsi untuk menyisipkan node setelah node dengan nilai tertentu
void InsertBetween(Node **top, int target, int value) {
    Node *temp = *top;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Nilai %d tidak ditemukan di dalam list.\n", target);
        return;
    }
    Node *newNode = BuatNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Fungsi untuk menyisipkan node berdasarkan nilai
void InsertbyValue(Node **top, int value) {
    Node *newNode = BuatNode(value);
    if (*top == NULL || (*top)->data >= value) {
        newNode->next = *top;
        *top = newNode;
        return;
    }
    Node *temp = *top;
    while (temp->next != NULL) {
        if (temp->next->data >= value) {
            break;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Fungsi untuk menghapus node berdasarkan nilai tertentu
void deletebyValue(Node **top, int value) {
    if (*top == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if ((*top)->data == value) {
        Node *temp = *top;
        *top = (*top)->next;
        free(temp);
        return;
    }
    Node *temp = *top;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Value not found\n");
        return;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Fungsi untuk menghapus node setelah node dengan nilai tertentu
void deleteBetween(Node **top, int target) {
    Node *temp = *top;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("No element to delete after %d\n", target);
        return;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Fungsi untuk menghapus elemen pertama dari linked list
void deleteAwal(Node** top) {
    if (*top == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    Node* temp = *top;
    *top = (*top)->next;
    free(temp);
}

void deleteAkhir(Node** top) {
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

void printList(Node* top) {
    Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

void DeleteAll(Node** top) {
    Node* temp;
    while (*top != NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main() {
    Node *top = NULL;

    InsertAwal(&top, 7);
    PrintList(top);

    InsertAkhir(&top, 11);
    PrintList(top);

    InsertBetween(&top, 7, 9);
    PrintList(top);

    InsertAwal(&top, 5);
    PrintList(top);

    InsertAkhir(&top, 13);
    PrintList(top);

    deleteAkhir(&top);
    PrintList(top);

    deletebyValue(&top, 7);
    PrintList(top);

    deleteAwal(&top);
    PrintList(top);

    DeleteAll(&top);
    PrintList(top);

    return 0;


}
