#include "stdio.h"

int main() {
    int dizi[10];
    int n = 10; // Dizideki eleman sayisini ifade etmektedir
    
    // 1. Asama: Kullanicidan dizinin 10 elemanini alma
    printf("Lutfen 10 adet tamsayi giriniz:\n");
    for(int i = 0; i < n; i++) {
        printf("%d. eleman: ", i + 1);
        scanf("%d", &dizi[i]);
    }
    
    // 2. Asama: Elemanlari ekrana yazdirma
    printf("\nGirdiginiz elemanlar:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
    
    return 0;
}

/*
SORU 1 - TEORIK CEVAPLAR:

2) Zaman Maliyeti:
Programda iki adet dongu vardir. Ilk dongu elemanlari 
almak (c1*n), ikinci dongu yazdirmak (c2*n) icin calisir. 
Sabit islemlere de c3 dersek:
T(n) = c1*n + c2*n + c3 = (c1 + c2)n + c3 seklinde 
dogrusal bir fonksiyondur.

3) Zaman Karmasikligi:
T(n) fonksiyonunda en buyuk buyume hizi n'e baglidir. 
Sabit katsayilar atildiginda zaman karmasikligi O(n) olur.

4) Alan Karmasikligi:
Elemanlari saklamak icin n (10) boyutunda bir tamsayi dizisi 
olusturulmustur. Bellekte kaplanan alan, veri boyutuyla 
dogru orantili arttigi icin alan karmasikligi O(n)'dir.
*/
