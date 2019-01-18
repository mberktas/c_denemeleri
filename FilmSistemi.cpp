/* 			FÝLM ARÞÝV SÝSTEMÝ
	Amaç : Dosya iþlemleri ile bir film arþivi oluþturmak.
	
	Özellikler :	Film Ekleme,Film Silme,Film Güncelleme,Film Arama,Film Listeleme.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>

#define size 25 // dizilerde aldýgým sabit uzunluk.

struct filmVerisi{
	char filmAdi[size];
	char basrol[size];
	char yonetmen[size];
	char senarist[size];
	int yayinlanmaYili;
}film; // kullandigim ana struct verisi.

void filmEkle();
void filmAra();
void filmListele();
void filmSil();
void filmGuncelle();

      	
int main()
{
	int ch;
	do
	{
	system("cls");
	printf("---------------------------------- FILM ARSIV SISTEMI--------------------------------------");
	printf("\n\n");
	printf("1 -> Kayit Ekle\n");
	printf("2 -> Filmleri Listele\n");
	printf("3 -> Film Ara\n");
	printf("4 -> Film Guncelle\n");
	printf("5 -> Film Sil\n");
	printf("6 -> Cikis yap\n");
	scanf("%d",&ch);
	fflush(stdin);
	switch(ch)
	{
	case 6:
		 printf("Cikis yapiliyor.\n");
	break;
	case 1:
		filmEkle();
		fflush(stdin);
		printf("\nDevam etmek icin bir tusa basiniz.\n");
		getch();  // yazilanlar direk ekrandan silinmesin diye eklendi.
	break;

	case 2:
		filmListele();
		printf("\nDevam etmek icin bir tusa basiniz.\n");

		getch();
	break;

	case 3:
		filmAra();
		printf("\nDevam etmek icin bir tusa basiniz.\n");

		getch();
	break;

	case 4:
		filmGuncelle();
		fflush(stdin);
		printf("\nDevam etmek icin bir tusa basiniz.\n");

		getch();
	break;

	case 5:
	filmSil();
	printf("\nDevam etmek icin bir tusa basiniz.\n");

	getch();
	break;

	default:
		printf("Hatali bir secim yaptiniz.\n");
		getch();
	break;
	}
	}while(ch != 6);
return 0;}


void filmEkle() //Filmleri eklemek için.
{	system("cls");
	printf("===============================Film Kayit Sistemi==============================================\n");
	FILE *filmDosya;
	filmDosya = fopen("filmVeritabani.dat","a+");
	if(filmDosya == NULL)
	{	printf("Dosya acilamadi.\n");
	return;
	}
	fflush(stdin);
	printf("Film adi giriniz :\n");
	gets(film.filmAdi);
	printf("Basrol adini giriniz :\n");
	gets(film.basrol);
	printf("Yonetmen adini giriniz :\n");
	gets(film.yonetmen);
	printf("Senarist adini giriniz :\n");
	gets(film.senarist);
	printf("Yayinlanma yilini giriniz :\n");
	scanf("%4d",&film.yayinlanmaYili);

	fwrite(&film,sizeof(film),1,filmDosya);
	printf("Film basariyla eklendi.\n");
rewind(filmDosya);
fclose(filmDosya);
printf("\n");
return;
}


void filmListele() //filmleri yayinlanma yillarina gore listeler.
{	system("cls");
	printf("==================================Film Listesi(Yayinlanma Yillarina Gore)=========================================\n");
	FILE *filmDosya;
	filmDosya = fopen("filmVeritabani.dat","r");
	struct filmVerisi filmler[size] = {"","","","",0};
	int i = 0;
	if(filmDosya == NULL)
	{	printf("Dosya acilamadi.\n");
	return;
	}
	else{			
		printf("Film\t\tBasrol\t\tYonetmen\tSenarist\tYayinlanma Yili\n\n");

		while(fread(&filmler[i],sizeof(film),1,filmDosya))
		{ i++;
		}
	for(i = 0; i < 24; i++){	//Bubble sort ile filmler yayinlanma yillarina gore listeleniyor.
		for(int j = 0; j < 24-i; j++){
			if(filmler[j+1].yayinlanmaYili > filmler[j].yayinlanmaYili){
				film = filmler[j];
				filmler[j] = filmler[j+1];
				filmler[j+1] = film;

				}
			}
		}

	for (i = 0; i < 25; i++){
		if(filmler[i].yayinlanmaYili == 0 ){
			}
		else{
		printf("%s\t\t%s\t\t%s\t\t%s\t\t%4d\n",filmler[i].filmAdi,filmler[i].basrol,filmler[i].yonetmen,filmler[i].senarist,filmler[i].yayinlanmaYili);
			}
		}
	}
rewind(filmDosya); // imleci dosya basýna yolladým
fclose(filmDosya);
printf("\n");
return;
}


void filmAra()//film arama fonksiyonu.
{	system("cls");
	char aranacak[size];
	int aranacakyil;
	FILE *filmDosya;
	int flag = 0;
	int islem;
	filmDosya=fopen("filmVeritabani.dat","r");
	if(filmDosya == NULL)
	{	printf("Dosya acilamadi.\n");
	return;
	}
	printf("Arama turu seciniz.\n1 -> Film adina gore.\n2 -> Basrol oyuncusuna gore.\n3 -> Yonetmen adina gore.\n4 -> Senarist adina gore\n5 -> Yayinlanma yilina gore.\n");
	scanf("%d",&islem);
	fflush(stdin);
	switch(islem){
	case 1:{ // Filmler adina gore aranir.
		printf("Aranacak filmin adini giriniz :->");
		scanf("%s",&aranacak);
		while(fread(&film,sizeof(film),1,filmDosya))
		{
		if(strcmp(aranacak,film.filmAdi) == 0)
			{	flag=1;
				printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%4d\n",film.filmAdi,film.basrol,film.yonetmen,film.senarist,film.yayinlanmaYili);
			}
		}
       break;   
   		}
    case 2:{  // Filmler basrol adina gore aranir.
		printf("Aranacak basrol oyuncusunun adini giriniz :->");
		scanf("%s",&aranacak);
		while(fread(&film,sizeof(film),1,filmDosya))
		{
		if(strcmp(aranacak,film.basrol) == 0)
			{	flag=1;
			printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%4d\n",film.filmAdi,film.basrol,film.yonetmen,film.senarist,film.yayinlanmaYili);
			}
		}
        break; 
        }
    case 3:{  // Filmler yonetmen adina gore aranir.
		printf("Aranacak yonetmen adini giriniz :->");
		scanf("%s",&aranacak);
		while(fread(&film,sizeof(film),1,filmDosya))
		{
		if(strcmp(aranacak,film.yonetmen) == 0)
			{	flag=1;
				printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%4d\n",film.filmAdi,film.basrol,film.yonetmen,film.senarist,film.yayinlanmaYili);
			}
		}
		break;
	}
	case 4:{  // Filmler senarist adlarina gore aranir.
		printf("Aranacak senarist adini giriniz :->");
		scanf("%s",&aranacak);
		while(fread(&film,sizeof(film),1,filmDosya))
		{
		if(strcmp(aranacak,film.senarist)==0)
			{	flag=1;
				printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%4d\n",film.filmAdi,film.basrol,film.yonetmen,film.senarist,film.yayinlanmaYili);
			}
		}
		break;
	}
	case 5:{  //Filmler yilina gore aranir.
		printf("Aranacak yayinlanma yili giriniz :->");  
		scanf("%d",&aranacakyil);
		while(fread(&film,sizeof(film),1,filmDosya))
		{
		if(aranacakyil == film.yayinlanmaYili)
			{	flag=1;
				printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%4d\n",film.filmAdi,film.basrol,film.yonetmen,film.senarist,film.yayinlanmaYili);
			}
		}
          break;
      }
          
    default :{ 
    	printf("Hatali bir secim yaptiniz.\n");
    break;
	} 
	}
	if(flag == 0)
	{	printf("Boyle bir film bulunamadi.\n");
	}
rewind(filmDosya); // imleci dosya basýna gonderiyirum sonraki kullanýmlarda herhangi bi hata oluþmasýn diye.	
fclose(filmDosya);
printf("\n");
return; }


void filmGuncelle(){ // film güncelleme fonksiyonu ad'a göre filmi bulup yeni bilgileri alip yaziyor.
	system("cls");
	char aranacak[size];
	char secenek;
	struct filmVerisi silinecekfilm = {"","","","",0};
	FILE *filmDosya;
	int flag = 0;
	

	filmDosya=fopen("filmVeritabani.dat","r+");
	if(filmDosya == NULL)
	{	printf("Dosya acilamadi.\n");
	return;
	}
	else{
	printf("Guncellenecek filmin adini giriniz :->");
	scanf("%s",&aranacak);
	while(fread(&film,sizeof(film),1,filmDosya))
		{
		if(strcmp(aranacak,film.filmAdi) == 0)
			{	flag=1;
				printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%4d\n",film.filmAdi,film.basrol,film.yonetmen,film.senarist,film.yayinlanmaYili);
				printf("Filmi guncellemek istediginize eminmisiniz. (Devam etmek icin E , Iptal icin H)\n");
				fflush(stdin);
				scanf("%c",&secenek);

				if(secenek == 'E' || secenek == 'e'){
					fseek(filmDosya,sizeof(film)*(-1),SEEK_CUR);  // imleci bir film verisi boyutunda geri çektim.
					fwrite(&silinecekfilm,sizeof(film),1,filmDosya);  // bos veriyi yazarak film bilgilerini sildim.
					fseek(filmDosya,-sizeof(film),SEEK_CUR);		// imleci yeniden bir film verisi kadar geri aldim. Yeni verileri yazabilmek için.
					
					printf("Yeni film adini giriniz :\n");
					fflush(stdin);
					gets(film.filmAdi);
					printf("Yeni basrol oyuncusu adini giriniz :\n");
					gets(film.basrol);
					printf("Yeni senarist adini giriniz :\n");
					gets(film.senarist);
					printf("Yeni Yonetmen adini giriniz :\n");
					gets(film.yonetmen);
					printf("Yayinlanma yili giriniz :\n");
					fflush(stdin);
					scanf("%d",&film.yayinlanmaYili);

					fwrite(&film,sizeof(film),1,filmDosya);  // yeni veriler yazýldý.
					
					printf("Film guncellemesi basarilidir.\n");
					break;
			}
		}
	}

	if(flag == 0)
		{	printf("Boyle bir film bulunamadi.\n");
			return;
		}
	}
fseek(filmDosya,0,SEEK_SET);
fclose(filmDosya);
printf("\n");
return;
}


void filmSil(){  // Film silme fonksiyonu . silenecek film adi aliniyor ana filmVeritabani.dat tan silinecek veri hariç hepsi alinip yeni bir gecici.dat dosyasina yazýlýyor.
				//Sonra filmVeritabani.dat siliniyor gecici.dat ýn adi filmVeritabani.dat yapýlýyor.
	system("cls");
	FILE *filmDosya;
	FILE *filmDosya2;
	filmDosya = fopen("filmVeritabani.dat","r+");
	filmDosya2 = fopen("gecici.dat","a");
	char silAd[size];
	struct filmVerisi silinecekfilm = {"","","","",0};
	char secenek;
	if(filmDosya == NULL){
		printf("Dosya acilamadi");
	}
	else{
		printf("Silmek istediginiz filmin adini giriniz :\n");
	fflush(stdin);
	gets(silAd);

	while(fread(&film,sizeof(film),1,filmDosya)){
		if(strcmp(silAd,film.filmAdi) == 0) {
			printf("Silmek istediginize eminmisiniz (Devam icin E , iptal icin H)\n");
			scanf("%c",&secenek);
			if(secenek =='E' || secenek == 'e'){
				printf("Film basariyla silindi.\n");
				}
			else{
				printf("Islem iptal edildi.\n");
				fwrite(&film,sizeof(film),1,filmDosya2); // gecici dosyasina alinan veri yazdiriliyor.
				}
			}
		else{	fwrite(&film,sizeof(film),1,filmDosya2); // gecici dosyasina alinan veri yazdiriliyor.
		}
		}
		if(strcmp(silAd,film.filmAdi)==0){
		}
	}
fseek(filmDosya2,0,SEEK_SET);  // imleci dosya basýna geri gönderdim oluþacak imlec hatalari onlemek için.
fclose(filmDosya);
fclose(filmDosya2);
remove("filmVeritabani.dat");
rename("gecici.dat","filmVeritabani.dat");

printf("\n");
return;
}

