//"CPR-101 Randevu Programi Projesi"
//"Yapanlar"
//"Ekin Kelleci ve Emir Dinç"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 

struct hasta{

	char tc[20];
	char ad[20];
	char soyad[20];
	char tel[10];
};

struct doktor{
	char tc[20];
	char ad[20];
	char soyad[20];
	char tel[20];
	char doktorNo[20];
	int klinikNo;

};

	struct randevu{

	char tc_hasta[20];
	char doktor_no[20];
	char tarih_ve_saati[50];
	};


int hastaKayit()
{

    system("cls");
    struct hasta h1;
    printf("Hasta kayit ekrani \n\n");
    printf("TC               : "); scanf(" %[^\n]s",&h1.tc);
    printf("Ad               : "); scanf(" %[^\n]s",&h1.ad);
    printf("Soyad            : "); scanf(" %[^\n]s",&h1.soyad);
    printf("Ornek tel yazimi =  5442421662\nTel              :  "); scanf(" %[^\n]s",&h1.tel);

    FILE *file;
    file= fopen("hasta_k.txt","a+b") ;
	
    fwrite(&h1, sizeof(struct hasta), 1 ,file);
    fclose(file);
    printf("Hasta kaydi tamam\n\n");
}

int doktorKayit()
{
    system("cls");
    struct doktor d1;
    printf("Doktor kayit ekrani \n\n");
    printf("TC                   : "); scanf(" %[^\n]s",&d1.tc);
    printf("Ad                   : "); scanf(" %[^\n]s",&d1.ad);
    printf("Soyad                : "); scanf(" %[^\n]s",&d1.soyad);
    printf("Ornek tel yazimi     = 5442421662\nTel                  : "); scanf(" %[^\n]s",&d1.tel);    
    printf("Doktor Calýsma No'su= 4 haneli calisma hanesi \nDoktor Calýsma No'su : "); scanf(" %s",&d1.doktorNo);
    printf("Klinikler= 1-KBB, 2-Fizik, 3-Cocuk, 4-Noroloji, 5-Kadin Dogum, 6-Uroloji \nKlinik no            : "); scanf(" %d",&d1.klinikNo);

    FILE *file;
    file= fopen("doktor_k.txt","a+b") ; 
    fwrite(&d1, sizeof(struct doktor), 1 ,file);
    fclose(file);
    printf("Doktor kaydi tamam \n\n");
}

int randevualma()
{
	system("cls");
	struct doktor d1;
	struct hasta h1;
	struct randevu r1;
	char lethalcompany[20];
	int sonuc=0;
	
	printf("Doktor Giris Ekrani \n");
	printf("Hasta  Tc  : ");scanf(" %[^\n]s",r1.tc_hasta);
	printf("Doktor No  : ");scanf(" %s",r1.doktor_no);
	
	FILE*file=fopen("hasta_k.txt","r+b");
	while(fread (&h1,sizeof(struct hasta),1,file) !=NULL)
	{
		if(strcmp(r1.tc_hasta,h1.tc) ==0){
			sonuc++;
			FILE*file2=fopen("doktor_k.txt","r+b");
			while(fread (&d1,sizeof(struct doktor),1,file2) !=NULL){
				if(strcmp(r1.doktor_no,d1.doktorNo) ==0){
					sonuc++;
   						switch(d1.klinikNo) {
        					case 1: 
            					strcpy(lethalcompany, "KBB");
            					break;
        					case 2: 
            					strcpy(lethalcompany, "Fizik");
           						 break;
        					case 3: 
            					strcpy(lethalcompany, "Cocuk");
            					break;
        					case 4: 
          						 strcpy(lethalcompany, "Noroloji");
           						 break;
       						case 5: 
         						 strcpy(lethalcompany, "Kadin Dogum");
           						 break;
       						 case 6: 
         						 strcpy(lethalcompany, "Uroloji");
          						 break;
       
    					}
					printf("Hasta Adi     :%s\n",h1.ad);
					printf("Hasta Soyadi  :%s\n\n",h1.soyad);
					printf("Doktor Adi    :%s\n",d1.ad);
					printf("Doktor Soyadi :%s\n",d1.soyad);
					printf("Klinik        :%s\n\n",lethalcompany);
					printf("Ornek Tarih Ve Saat        :02-02-2134-16.00\n");
					printf("Tarih ve Saati yazin lütfen:");scanf("%s",&r1.tarih_ve_saati);	
				}
				fclose(file2);	


			}

		}
	}
	switch(sonuc)
	{			
			case 0:		
				printf("Hasta Bulunamadi\n");
				break;
			case 1: 
				printf("Doktor Bulunamadi\n");
				break;
			case 2: 	
				printf("Randevu Alindi\n\n");
				FILE*file3=fopen("randevu_alma.txt","a+b");
				fwrite(&r1, sizeof(struct randevu), 1 ,file3);
				fclose(file3);
				break;
	fclose(file);


	}

	
}




int randevuListesi()
{
	system("cls");
	struct randevu r1;

	FILE*filex=fopen("randevu_alma.txt","r+b");
	while(fread (&r1,sizeof(struct hasta),1,filex) !=NULL){

		printf("%d Nolu Randevu'nun' bilgileri \n{ \n",rand());
		printf("Randevu alan hastanin TC      :%s\n",r1.tc_hasta);
		printf("Doktor Nosu                   :%s\n",r1.doktor_no);
		printf("Tarih Ve Saati                :%s\n}\n\n",r1.tarih_ve_saati);


	}
	fclose(filex);
}

int hastaListesi()
{
	system("cls");
	struct hasta h1;

	FILE*filex=fopen("hasta_k.txt","r+b");
	while(fread (&h1,sizeof(struct hasta),1,filex) !=NULL){

		printf("%d Nolu Hasta'nin bilgileri \n{ \n",rand());
		printf("Hasta TC      :%s\n",h1.tc);
		printf("Hasta Adi     :%s\n",h1.ad);
		printf("Hasta Soyadi  :%s\n",h1.soyad);
		printf("Hasta Tel     :%s\n}\n\n",h1.tel);

	}
	fclose(filex);
}

int doktorListesi()
{
	system("cls");
	struct doktor d1;
	char hoi4[20];
	FILE*filex=fopen("doktor_k.txt","r+b");
	while(fread (&d1,sizeof(struct doktor),1,filex) !=NULL){

		printf("%d Nolu Doktor'un bilgileri \n{ \n",rand());
		printf("Doktor TC               :%s\n",d1.tc);
		printf("Doktor Adi              :%s\n",d1.ad);
		printf("Doktor Soyadi           :%s\n",d1.soyad);
		printf("Doktor Tel              :%s\n",d1.tel);
		printf("Doktor Calisma No'su    :%s\n",d1.doktorNo);
		
			switch(d1.klinikNo) {
        					case 1: 
            					strcpy(hoi4, "KBB");
            					break;
        					case 2: 
            					strcpy(hoi4, "Fizik");
           						 break;
        					case 3: 
            					strcpy(hoi4, "Cocuk");
            					break;
        					case 4: 
          						 strcpy(hoi4, "Noroloji");
           						 break;
       						case 5: 
         						 strcpy(hoi4, "Kadin Dogum");
           						 break;
       						 case 6: 
         						 strcpy(hoi4, "Uroloji");
          						 break;}
			printf("Doktor'un Buldugu Klinik:%s\n}\n\n",hoi4);
			
		

}
	fclose(filex);
}

int menu()
{
	int secim;
	printf("1- Hasta Kayit\n");
	printf("2- Doktor Kayit\n");

	printf("3- Randevu Alma\n\n");
	printf("4- Randevu Listesi\n");
	printf("5- Hasta Listesi\n");
	printf("6- Doktor Listesi\n");
	printf("0- Programi Kapat\n");
	printf("seciminiz: "); 
	scanf("%d",&secim);
	return secim;

}

int main()
{
	system("color 04");
	srand(time(NULL));
	int secim=menu();
	while(secim != 0)
	{	
		switch(secim)
		{				
			case 1: 
				hastaKayit(); 
				break;
			case 2: 
				doktorKayit(); 
				break;
			case 4: 
				randevuListesi(); 
				break;
			case 3: 
				randevualma(); 
				break;
			case 5: 
				hastaListesi(); 
				break;
			case 6: 
				doktorListesi(); 
				break;
			case 0: 
				break;
			
			default : 
				printf("\nHatali Secim !\n\n"); 
				break;

		}
		secim = menu();
	}
return 0;
}


