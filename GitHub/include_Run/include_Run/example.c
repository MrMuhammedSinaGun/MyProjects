#include<stdio.h>

int matrisToplami(int matris[][10],int satir,int sutun){
   int toplam=0;
   for(int i=1; i<=satir; i++){
    for(int j=1; j<=sutun; j++){
        toplam+=matris[i][j];
    }
   }
   return toplam;
}
int main(){
  int matris[10][10];
  int satir,sutun;
  int sonuc;

  printf("matrisin satir sayisini gir:"); scanf("%d",&satir);
  printf("matrisin sutun sayisini gir:"); scanf("%d",&sutun);

  printf("matris eleman sayilari girin:");
  for(int i=0; i<=satir;i++){
    for(int j=0; j<=sutun;j++){
        printf("matris[%d][%d]:",i,j);
        scanf("%d",&matris[i][j]);
    }
  }
  sonuc=matrisToplami(matris,satir,sutun);
  printf("matrislerin sonucu:%d\n",sonuc);
  return 0;
}
