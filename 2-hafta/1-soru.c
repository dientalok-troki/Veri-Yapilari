#include "stdio.h"
#include "stdlib.h"

struct Node {
    int data;
    struct Node *next;
};

int main() {
    // 2. Adim: Node icin bellekten yer ayirma (malloc kullanimi)
    struct Node* dugum = NULL;
    dugum = (struct Node*)malloc(sizeof(struct Node));
    
    dugum->data = 10;
    dugum->next = NULL;
    
    printf("Olusturulan Node icindeki deger: %d\n", dugum->data);
    
    free(dugum);
    
    return 0;
}
