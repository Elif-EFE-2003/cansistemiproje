#include <stdio.h>
#include <stdlib.h>

   struct ogrenci
   {
   	char ad[20];
   	char soyad[20];
   	int numara;
   	int note;
   }ogr;
   FILE *fp1,*fp2,*fp3;
   //Sinif ortalamasi hesaplama
   float ort(){
   	float toplam=0;
   	int sayac=0;
   	fp1=fopen("Sinif.txt","r");
	while(fscanf(fp1,"%s %s %d %d",ogr.ad,ogr.soyad,&ogr.numara,&ogr.note)!=EOF){
	toplam+=ogr.note;
	sayac++;
	}
	fclose(fp1);
	toplam=toplam/(float)sayac;
	return toplam;
   } 
   //a karakterinden kac adet var
   int sayi(FILE *x){
   	char a;
   	int sayac=0;
   	while(fscanf(x,"%c",&a)!=EOF){
   		if(a=='a')
   		 sayac++;
	   }
	fclose(x);
	return sayac;
   }
   float can(){
   	float toplam=0;
   	int sayac=0;
   	fp3=fopen("Canadahil.txt","r");
	while(fscanf(fp3,"%s %s %d %d",ogr.ad,ogr.soyad,&ogr.numara,&ogr.note)!=EOF){
	toplam+=ogr.note;
	sayac++;
	}
	fclose(fp3);
	toplam=toplam/(float)sayac;
	return toplam;
   }
int main(int argc, char *argv[]) {
	fp1=fopen("Sinif.txt","w");
	//Dosya kontrolu
	if(!fp1)
	 printf("Dosya acýlamadý\n");
	else
	 printf("Dosya acildi\n");
	int i,k;
	//20 kisilik sinif icin
	for(i=0;i<20;i++){
		printf("Ogrenci bilgileri giriniz:\n\n");
		fflush(stdin);
		printf("Ad giriniz: ");
		gets(ogr.ad);
		printf("Soyad giriniz: ");
		gets(ogr.soyad);
		printf("Numara giriniz: ");
		scanf("%d",&ogr.numara);
		printf("Not giriniz: ");
		scanf("%d",&ogr.note);
		fprintf(fp1,"%s %s %d %d",ogr.ad,ogr.soyad,ogr.numara,ogr.note);
		fprintf(fp1,"\n");
	}
	fclose(fp1);
	printf("Ders ortalama: %f",ort());
	printf("\n");
	fp1=fopen("Sinif.txt","r");
	if(k=sayi(fp1))
	printf("Dosyada %d kadar %c var",sayi(fp1),'a');
	else
	printf("Karakter  yoktur");
	fp1=fopen("Sinif.txt","r");
	fp2=fopen("Canadahiledilmeyeckler.txt","w");
	while(fscanf(fp1,"%s %s %d %d",ogr.ad,ogr.soyad,&ogr.numara,&ogr.note)!=EOF){
		if(ogr.note<=20 || ogr.note>=85)
		fprintf(fp2,"%s %s %d %d",ogr.ad,ogr.soyad,ogr.numara,ogr.note);
	}
	fclose(fp1);
	fclose(fp2);
	fp1=fopen("Sinif.txt","r");
	fp3=fopen("Canadahil.txt","w");
	while(fscanf(fp1,"%s %s %d %d",ogr.ad,ogr.soyad,&ogr.numara,&ogr.note)!=EOF){
		if(ogr.note>20 && ogr.note<85)
		fprintf(fp3,"%s %s %d %d",ogr.ad,ogr.soyad,ogr.numara,ogr.note);
	}
	fclose(fp1);
	fclose(fp3);
	printf("\n");
	printf("Can: %f",can());
	return 0;
}
