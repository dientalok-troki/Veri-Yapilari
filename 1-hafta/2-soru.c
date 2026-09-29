#include "stdio.h"

int main() {
    int sayi, orjinalSayi, kalan, ters = 0;
    
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &sayi);
    
    orjinalSayi = sayi;
    
    while(sayi != 0) {
        kalan = sayi % 10;
        ters = (ters * 10) + kalan;
        sayi = sayi / 10;
    }
    
    if(orjinalSayi == ters) {
        printf("%d bir palindrom sayidir.\n", orjinalSayi);
    } else {
        printf("%d bir palindrom sayi degildir.\n", orjinalSayi);
    }
    
    return 0;
}
