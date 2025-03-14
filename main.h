#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Definisi struct node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Deklarasi fungsi
int BuatNode(int value);
void InsertAwal(Node **top, int value);
void InsertAkhir(Node **top, int value);
void InsertBetween(Node **top, int target, int value);
void InsertbyValue(Node **top, int value);
void printList(Node *top);
void deleteAwal(Node **top)
void deleteAkhir(Node **top)
void deletebyValue(Node **top, int value)
void deleteBetween(Node **top, int target)
void printList(Node *top)

int BuatNode(int value){
} // membuat node untuk linked list

void InsertAwal(Node **top, int value){
} // memasukkan nilai ke node awal

void InsertAkhir(Node **top, int value){
} // memasukkan nilai ke node akhir

void InsertBetween(Node **top, int target, int value){
} // memasukkan nilai ke node yang berada di tengah

void InsertbyValue(Node **top, int value){
} // memasukkan nilai berdasarkan nilai tertentu

void deleteAwal(Node **top){
} // menghapus node paling depan

void deleteAkhir(Node **top){
} // menghapus node paling akhir

void deletebyValue(Node **top, int value){{
} // menghapus node berdasarkan nilai tertentu

void deleteBetween(Node **top, int target){
} // menghapus node yang berada di tengah

void printList(Node *top){
} // menampilkan nilai nilai yanga ada di list

void DeleteAll(Node **top){
} //menghapus semua node

#endif // MAIN_H
