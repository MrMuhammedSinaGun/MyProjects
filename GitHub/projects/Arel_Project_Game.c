#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){

   / srand(time(NULL)); // Rastgele sayı oluşturmak için başlangıç noktası
    int num = rand() % 20 + 1; // 1 ile 20 arasında rastgele sayı
    int guess = 0;

    printf("1 ile 20 arasinda bir sayiyi tahmin edin:\n");

    while (guess != num) { // Kullanıcı doğru tahmini yapana kadar döner
        printf("Tahmininizi girin: ");
        scanf("%d", &guess); // Kullanıcıdan tahmin alır

        if (guess < num) {
            printf("Daha yüksek bir sayi deneyin.\n");
        } else if (guess > num) {
            printf("Daha düşük bir sayi deneyin.\n");
        } else {
            printf("Tebrikler! Doğru tahmin.\n");
        }
    }

   /* int i;

    printf("1-10 kadar sayilarin kupu:\n");
    for (i = 1; i <= 100; i++) {
        printf("%d^3 = %d\n", i, i * i * i);
    }*/
   
   /*int num, sum = 0;

    printf("Bir sayi girin: ");
    scanf("%d", &num);

    for (int i = 1; i < num; i++) {
        if (num % i == 0) { // i num'un böleni ise
            sum += i; // böleni toplama ekle
        }
    }

    if (sum == num) {
        printf("%d bir mukemmel sayidir.\n", num);
    } else {
        printf("%d bir mukemmel sayi degildir.\n", num);
    }
*/
   

  /* long binary, decimal = 0, base = 1, remainder;

    printf("Ikilik tabanda bir sayi girin: ");
    scanf("%ld", &binary);

    while (binary > 0) {
        remainder = binary % 10; // Son basamağı al
        decimal = decimal + remainder * base; // Onluk değere ekle
        binary = binary / 10; // Bir sonraki basamağa geç
        base = base * 2;
    }

    printf("Onluk tabanda karsiligi: %ld\n", decimal);
*/


    return 0;
}