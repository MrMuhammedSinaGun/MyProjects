#include <stdio.h>
#include <math.h> // Matematik islemleri icin

#ifndef M_PI
#define M_PI 3.14159265358979323846 // Pi sabitini manuel tanimliyoruz
#endif

// Toplama fonksiyonu
double toplama(double a, double b) {
    return a + b;
}

// Cikarma fonksiyonu
double cikarma(double a, double b) {
    return a - b;
}

// Carpma fonksiyonu
double carpma(double a, double b) {
    return a * b;
}

// Bolme fonksiyonu
double bolme(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Hata: Sifira bolme yapilamaz!\n");
        return 0;
    }
}

// Faktoriyel fonksiyonu
int faktoriyel(int n) {
    int sonuc = 1;
    for (int i = 1; i <= n; i++) {
        sonuc *= i;
    }
    return sonuc;
}

// Us alma fonksiyonu
double us_al(double taban, int us) {
    double sonuc = 1.0;
    for (int i = 1; i <= us; i++) {
        sonuc *= taban;
    }
    return sonuc;
}

// Trigonometri fonksiyonlari
double sin_deg(double derece) {
    return sin(derece * M_PI / 180.0); // Dereceyi radyana cevirerek sin hesaplar
}

double cos_deg(double derece) {
    return cos(derece * M_PI / 180.0); // Dereceyi radyana cevirerek cos hesaplar
}

double tan_deg(double derece) {
    return tan(derece * M_PI / 180.0); // Dereceyi radyana cevirerek tan hesaplar
}

// Logaritma ve karekok fonksiyonlari
double logaritma(double sayi) {
    if (sayi > 0) {
        return log(sayi);
    } else {
        printf("Hata: Logaritma sadece pozitif sayilar icin hesaplanabilir!\n");
        return 0;
    }
}

double karekok(double sayi) {
    if (sayi >= 0) {
        return sqrt(sayi);
    } else {
        printf("Hata: Negatif sayinin karekoku alinamaz!\n");
        return 0;
    }
}

int main() {
    int secim;
    double sayi1, sayi2;
    int faktoriyel_sayi, us;

    while (1) {
        // Menu
        printf("\nBilimsel Hesap Makinesi\n");
        printf("1. Toplama\n");
        printf("2. Cikarma\n");
        printf("3. Carpma\n");
        printf("4. Bolme\n");
        printf("5. Faktoriyel\n");
        printf("6. Us Alma\n");
        printf("7. Sinus\n");
        printf("8. Kosinus\n");
        printf("9. Tanjant\n");
        printf("10. Logaritma\n");
        printf("11. Karekok\n");
        printf("12. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        // Islem Secimi
        switch (secim) {
            case 1:
                printf("Iki sayiyi girin: ");
                scanf("%lf %lf", &sayi1, &sayi2);
                printf("Sonuc: %.2lf\n", toplama(sayi1, sayi2));
                break;
            case 2:
                printf("Iki sayiyi girin: ");
                scanf("%lf %lf", &sayi1, &sayi2);
                printf("Sonuc: %.2lf\n", cikarma(sayi1, sayi2));
                break;
            case 3:
                printf("Iki sayiyi girin: ");
                scanf("%lf %lf", &sayi1, &sayi2);
                printf("Sonuc: %.2lf\n", carpma(sayi1, sayi2));
                break;
            case 4:
                printf("Iki sayiyi girin: ");
                scanf("%lf %lf", &sayi1, &sayi2);
                printf("Sonuc: %.2lf\n", bolme(sayi1, sayi2));
                break;
            case 5:
                printf("Faktoriyelini hesaplamak istediginiz sayiyi girin: ");
                scanf("%d", &faktoriyel_sayi);
                if (faktoriyel_sayi >= 0) {
                    printf("Sonuc: %d\n", faktoriyel(faktoriyel_sayi));
                } else {
                    printf("Hata: Negatif sayinin faktoriyeli hesaplanamaz!\n");
                }
                break;
            case 6:
                printf("Taban ve ussu girin: ");
                scanf("%lf %d", &sayi1, &us);
                printf("Sonuc: %.2lf\n", us_al(sayi1, us));
                break;
            case 7:
                printf("Aci degerini (derece) girin: ");
                scanf("%lf", &sayi1);
                printf("Sonuc: %.2lf\n", sin_deg(sayi1));
                break;
            case 8:
                printf("Aci degerini (derece) girin: ");
                scanf("%lf", &sayi1);
                printf("Sonuc: %.2lf\n", cos_deg(sayi1));
                break;
            case 9:
                printf("Aci degerini (derece) girin: ");
                scanf("%lf", &sayi1);
                printf("Sonuc: %.2lf\n", tan_deg(sayi1));
                break;
            case 10:
                printf("Logaritmasini hesaplamak istediginiz sayiyi girin: ");
                scanf("%lf", &sayi1);
                printf("Sonuc: %.2lf\n", logaritma(sayi1));
                break;
            case 11:
                printf("Karekokunu hesaplamak istediginiz sayiyi girin: ");
                scanf("%lf", &sayi1);
                printf("Sonuc: %.2lf\n", karekok(sayi1));
                break;
            case 12:
                printf("Hesap makinesi kapatiliyor...\n");
                return 0;
            default:
                printf("Hatali secim! Lutfen tekrar deneyin.\n");
        }
    }
    return 0;
}
