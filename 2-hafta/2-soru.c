#include "stdio.h"
#include "stdlib.h"

// Node yapisini (struct) olusturma
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node* node1 = NULL;
    struct Node* node2 = NULL;
    
    node1 = (struct Node*)malloc(sizeof(struct Node));
    node2 = (struct Node*)malloc(sizeof(struct Node));
    
    node1->data = 10;
    
    node2->data = 20;
    node2->next = NULL;
    
    node1->next = node2;
    
    printf("Birinci eleman: %d\n", node1->data);
    printf("Ikinci eleman (node1 uzerinden ulasarak): %d\n", node1->next->data);
    
    free(node1);
    free(node2);
    
    return 0;
}
