#include <stdio.h>
#include <stdlib.h>

// Ikki tomonlama bog'langan ro'yxat tuguni
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Yangi tugun yaratish
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Xotira ajratishda xatolik!\n");
        return NULL;
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Ro'yxat oxiriga element qo'shish
void append(Node **head, int data) {
    Node *new_node = create_node(data);
    if (!new_node) return;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

// Ro'yxatni ekranga chiqarish
void print_list_forward(Node *head) {
    printf("Ro'yxat (oldindan orqaga): ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Dinamik xotirani to'liq tozalash
void free_list(Node **head) {
    Node *current = *head;
    Node *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
    printf("Xotira muvaffaqiyatli tozalandi!\n");
}

int main() {
    Node *head = NULL;

    printf("--- 2-topshiriq: Doubly Linked List ---\n\n");

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    print_list_forward(head);

    free_list(&head);

    return 0;
}
