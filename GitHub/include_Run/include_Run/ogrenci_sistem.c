#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100

char studentNames[MAX_STUDENTS][50];
char studentSurnames[MAX_STUDENTS][50];
double studentAvtnotes[MAX_STUDENTS];
int studentCounter = 0;

void ogrenci_ekle();
void ogrenci_sil();
void ogrenci_ara();
void ogrenci_liste();
int string_karsilastir(char str1[], char str2[]);

int main() {
    int secim;

    do {
        printf("\n**** OKUL YONETIM SISTEMI ****\n");
        printf("1 - OGRENCI EKLEME\n");
        printf("2 - OGRENCI SILME\n");
        printf("3 - OGRENCI ARAMA\n");
        printf("4 - OGRENCI LISTELEME\n");
        printf("5 - CIKIS\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                ogrenci_ekle();
                break;
            case 2:
                ogrenci_sil();
                break;
            case 3:
                ogrenci_ara();
                break;
            case 4:
                ogrenci_liste();
                break;
            case 5:
                printf("Sistemden cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim! Tekrar deneyiniz.\n");
        }
    } while (secim != 5);

    return 0;
}


void ogrenci_ekle() {
    if (studentCounter >= MAX_STUDENTS) {
        printf("Ogrenci kapasitesi doldu!\n");
        return;
    }

    printf("Ogrencinin adini giriniz: ");
    scanf("%s", studentNames[studentCounter]);
    printf("Ogrencinin soyadini giriniz: ");
    scanf("%s", studentSurnames[studentCounter]);
    printf("Ogrencinin ortalama notunu giriniz: ");
    scanf("%lf", &studentAvtnotes[studentCounter]);

    studentCounter++;
    printf("Ogrenci basariyla eklendi.\n");
}


void ogrenci_sil() {
    if (studentCounter == 0) {
        printf("Silinecek ogrenci yok.\n");
        return;
    }

    char name[50], surname[50];
    printf("Silmek istediginiz ogrencinin adini giriniz: ");
    scanf("%s", name);
    printf("Silmek istediginiz ogrencinin soyadini giriniz: ");
    scanf("%s", surname);

    for (int i = 0; i < studentCounter; i++) {
        if (string_karsilastir(studentNames[i], name) == 0 &&
            string_karsilastir(studentSurnames[i], surname) == 0) {
            for (int j = i; j < studentCounter - 1; j++) {
                for (int k = 0; k < 50; k++) { 
                    studentNames[j][k] = studentNames[j + 1][k];
                    studentSurnames[j][k] = studentSurnames[j + 1][k];
                }
                studentAvtnotes[j] = studentAvtnotes[j + 1];
            }
            studentCounter--;
            printf("Ogrenci basariyla silindi.\n");
            return;
        }
    }
    printf("Ogrenci bulunamadi.\n");
}

void ogrenci_ara() {
    if (studentCounter == 0) {
        printf("Aranacak ogrenci yok.\n");
        return;
    }

    char name[50];
    printf("Aramak istediginiz ogrencinin adini giriniz: ");
    scanf("%s", name);

    for (int i = 0; i < studentCounter; i++) {
        if (string_karsilastir(studentNames[i], name) == 0) {
            printf("Ogrenci bulundu:\n");
            printf("Ad: %s, Soyad: %s, Ortalama Not: %.2f\n",
                   studentNames[i], studentSurnames[i], studentAvtnotes[i]);
            return;
        }
    }
    printf("Ogrenci bulunamadi.\n");
}

void ogrenci_liste() {
    if (studentCounter == 0) {
        printf("Listelenecek ogrenci yok.\n");
        return;
    }

    printf("\nOgrenci Listesi:\n");
    for (int i = 0; i < studentCounter; i++) {
        printf("%d. Ad: %s, Soyad: %s, Ortalama Not: %.2f\n",
               i + 1, studentNames[i], studentSurnames[i], studentAvtnotes[i]);
    }
}


int string_karsilastir(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}
