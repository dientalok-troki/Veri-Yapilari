#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void addOrdered(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

void removeNode(Node** head, int value) {
    if (*head == NULL) return;

    if ((*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

int count(Node* head) {
    int c = 0;
    Node* current = head;
    while (current != NULL) {
        c++;
        current = current->next;
    }
    return c;
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

    addOrdered(&head, 23);
    addOrdered(&head, 11);
    addOrdered(&head, 5);
    addOrdered(&head, 9);
    addOrdered(&head, 6);
    addOrdered(&head, 4);
    addOrdered(&head, 12);
    addOrdered(&head, 24);

    printList(head);
    
    removeNode(&head, 9);
    printList(head);
    
    printf("%d\n", count(head));
    
    clear(&head);

    return 0;
}
