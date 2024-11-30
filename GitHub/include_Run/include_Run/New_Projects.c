#include <stdio.h>
int toplama(int a,int b){
    return a+b;
}
int main(){
int say1,say2;
int sonuc;
printf("1.sayi gir: "); scanf("%d",&say1);
printf("2.sayi gir: "); scanf("%d",&say2);
sonuc=toplama(say1,say2);
printf("Toplama Sonucu:%d\n",sonuc);
return 0;
}