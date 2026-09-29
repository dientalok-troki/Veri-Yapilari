#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAt(Node** head, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int currentPos = 0;

    while (current->next != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteAt(Node** head, int position) {
    if (*head == NULL || position < 0) return;

    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    int currentPos = 0;

    while (current->next != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }

    if (current->next == NULL) return;

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void clear(Node** head) {
    Node* current = *head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    Node* head = NULL;

    insertAt(&head, 10, 0);
    insertAt(&head, 20, 1);
    insertAt(&head, 30, 5);
    insertAt(&head, 5, -2);
    
    printList(head);
    
    deleteAt(&head, 2);
    printList(head);
    
    clear(&head);

    return 0;
}
