#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define KULLANICI_PIN 4747
#define BASLANGIC_BAKIYE 25000

double bakiye_goster(double bakiye);
double bakiye_yatir(double bakiye_1);
double bakiye_cek(double bakiye_1);
bool pindogrula();

int main() {
    int secim;
    double bakiye = BASLANGIC_BAKIYE;

    printf("ATM'YE HOŞGELDİNİZ!\n");
    if (!pindogrula()) {
        printf("Pin hatali! Lutfen tekrar deneyiniz.\n");
        return 0;
    }

    do {
        printf("\n..------- ISLEM MENUSU -------..\n");
        printf("1. Bakiye Goruntule\n");
        printf("2. Para Yatir\n");
        printf("3. Para Cek\n");
        printf("4. Cikis\n");
        printf("Yapmak istediginiz islemi seciniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                bakiye_goster(bakiye);
                break;
            case 2:
                bakiye = bakiye_yatir(bakiye);
                break;
            case 3:
                bakiye = bakiye_cek(bakiye);
                break;
            case 4:
                printf("Cikis yapiliyor...\n");
                break;
            default:
                printf("Gecersiz islem! Lutfen dogru bir secim yapiniz.\n");
                break;
        }
    } while (secim != 4);

    return 0;
}

double bakiye_goster(double bakiye) {
    printf("Mevcut Bakiyeniz: %.2lf TL\n", bakiye);
    return bakiye;
}


double bakiye_yatir(double bakiye) {
    double miktar;
    printf("Yatirmak istediginiz miktari giriniz: ");
    scanf("%lf", &miktar);

    if (miktar > 0) {
        bakiye += miktar;
        printf("Para yatirma basarili. Yeni bakiyeniz: %.2lf TL\n", bakiye);
    } else {
        printf("Yatirmak istediginiz tutar gecersizdir!\n");
    }
    return bakiye;
}

double bakiye_cek(double bakiye) {
    double miktar;
    printf("Cekmek istediginiz tutari giriniz: ");
    scanf("%lf", &miktar);

    if (miktar > 0 && miktar <= bakiye) {
        bakiye -= miktar;
        printf("Para cekme basarili. Yeni bakiyeniz: %.2lf TL\n", bakiye);
    } else if (miktar > bakiye) {
        printf("Yetersiz bakiye!\n");
    } else {
        printf("Gecersiz tutar girdiniz!\n");
    }
    return bakiye;
}

bool pindogrula() {
    int girilenpin;
    printf("Pin kodunuzu giriniz: ");
    scanf("%d", &girilenpin);
    if (girilenpin == KULLANICI_PIN) {
        return true;
    } else {
        return false;
    }
}
