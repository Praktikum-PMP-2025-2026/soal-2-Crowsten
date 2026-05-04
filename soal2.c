/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 - Dynamic Structures
 *   Hari dan Tanggal    : Senin 4 Mei 2026
 *   Nama (NIM)          : Jonathan Chandra (13224103)
 *   Nama File           : Soal2.c
 *   Deskripsi           :  Penggabungan Dua Jalur Terurut
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void print(struct Node* temp) {
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void swap (struct Node *head , struct Node *before){
    int temp = head->data;
    head->data = before->data;
    before->data = temp;
}


void sort(struct Node *start){
    int count =1;
    struct Node *temp;
    if (start == NULL){
        return;
    }

    while (count) {
        count = 0;
        temp = start;
        
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                swap(temp, temp->next);
                count = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int N,M;

    struct Node* head = NULL;
    struct Node* heads = NULL;
    struct Node* temp = NULL;
    
    
    if (scanf("%d", &N) != 1) return 0;
    for (int i = 0; i < N; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &(newNode->data));
        newNode->next = head;
        head = newNode;
    }

    if (scanf("%d", &M) != 1) return 0;
    for (int j = 0; j < M; j++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &(newNode->data));
        newNode->next = heads;
        heads = newNode;
    }

if (head == NULL) {
        head = heads;
    } else {
        temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = heads;
    }

    sort(head);
    
    printf("MERGED ");
    if(head!=NULL){
        print(head);
    }
    else{
        printf("EMPTY");
    }

    return 0;
}
