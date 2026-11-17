#include <stdio.h>
#include <stdlib.h>


char *sehirler[] = {"Istanbul", "Ankara", "Izmir", "Bursa", "Antalya"};


int graf[SEHIR_SAYISI][SEHIR_SAYISI] = {
    {0, 1, 0, 1, 0}, 
    {1, 0, 1, 0, 1}, 
    {0, 1, 0, 0, 0}, 
    {1, 0, 0, 0, 1},  
    {0, 1, 0, 1, 0}   
};


int visited_dfs[SEHIR_SAYISI] = {0};


void dfs(int dugum) {
    printf("%s -> ", sehirler[dugum]);
    visited_dfs[dugum] = 1;
    
    for (int i = 0; i < SEHIR_SAYISI; i++) {
        if (graf[dugum][i] == 1 && !visited_dfs[i]) {
            dfs(i);
        }
    }
}


void bfs(int baslangic) {
    int visited_bfs[SEHIR_SAYISI] = {0};
    int queue[SEHIR_SAYISI];
    int front = 0, rear = 0;
    
    
    queue[rear++] = baslangic;
    visited_bfs[baslangic] = 1;
    
    while (front < rear) {
        int guncelDugum = queue[front++];
        printf("%s -> ", sehirler[guncelDugum]);
        
        
        for (int i = 0; i < SEHIR_SAYISI; i++) {
            if (graf[guncelDugum][i] == 1 && !visited_bfs[i]) {
                queue[rear++] = i;
                visited_bfs[i] = 1;
            }
        }
    }
}

int main() {
    int baslangicDugumu = 0; // Istanbul'dan başlatıyoruz
    
    printf("BFS (Genislik Oncelikli Arama) Dolasimi:\n");
    bfs(baslangicDugumu);
    printf("BITTI\n\n");
    
    printf("DFS (Derinlik Oncelikli Arama) Dolasimi:\n");
    dfs(baslangicDugumu);
    printf("BITTI\n");
    
    return 0;
}
