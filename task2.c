#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Xotira ajratishda xatolik!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}


void free_list(Node** head) {
    Node* current = *head;
    Node* next_node = NULL;
    
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}

int main() {
    printf("--- 2-topshiriq: Doubly Linked List ---\n");
    
   
    Node* head = create_node(10);
    head->next = create_node(20);
    head->next->prev = head;
    
    head->next->next = create_node(30);
    head->next->next->prev = head->next;

    
    Node* temp = head;
    printf("Ro'yxat (oldindan orqaga): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    
    free_list(&head);
    printf("Xotira muvaffaqiyatli tozalandi!\n");

    return 0;
}
