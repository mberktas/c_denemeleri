/* Vigenere Chiper
 
 Kullanimi : 
    Lutfen sifrelemek istediginiz metini ve sifresini giriniz. 

 Nasil calisir : 
    Kullanicidan alinan metin ve sifrenin ASCII tablosundaki sayisal karsiliklari alinir ve toplanir.
    Toplamin sonucu ASCII deki harfsel karsiligini alarak sifrelenir.

 Aciklar : 
 	Turkce karakter girildiginde ASCII tablosunda karsiliklari olmadigi icin hatali calisiyor. 

*/ 



#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int sayisal_metin[40] ; //Global degisken
char metin[40], sifre[40] , sifreMetin[40];		//Global degisken

void harf_kucultme(); 
void sayisal_sifre();
void sifreleme();

int main(){
	printf("Bir metin giriniz :");
	gets(metin);
	printf("Sifreyi giriniz :");
	gets(sifre);
	harf_kucultme();
	sayisal_sifre();	
	sifreleme();
	printf("%s",sifreMetin);
	getch();
	return 0 ;
}

void harf_kucultme(){
	for(int i = 0 ; metin[i] ; i++){ // metnin buyuk harflerini kucultmek icin yazildi
		metin[i] = tolower(metin[i]) ;
	}
	for(int i = 0 ; sifre[i] ; i++){ // sifrenin buyuk harflerini kucultmek icin yazildi
		sifre[i] = tolower(sifre[i]) ;
	}
	
}

void sayisal_sifre(){             // metin ve sifre' nin ASCII tablosundaki karsiliklari alir sayisal_metin dizisine koyulur   
	for(int i = 0 ; i<40 ; i++){
		sayisal_metin[i] = (int)sifre[i] + (int)metin[i];
		if(sifre[i] == 0 && metin[i] != 0){                     //metin veya sifrenin karakterleri bitince tekrar basa donmesini sagliyor
			int k=0;
			sayisal_metin[i] = (int)sifre[k] + (int)metin[i];
			k++;
		}
		else if (metin[i] == 0 && sifre[i] != 0 ){
			int j=0;
			sayisal_metin[i] = (int)sifre[i] + (int)metin[j];
			j++;
		} 
	}
}

void sifreleme(){ // sayisal_metin degerleri ASCII deki harf karsiliklarini alir sifreMetin dizisine koyulur
	for(int i = 0 ; sayisal_metin[i] ; i++){
		sifreMetin[i]  = sayisal_metin[i]/10 + sayisal_metin[i]%10 + 80;
	}
}
