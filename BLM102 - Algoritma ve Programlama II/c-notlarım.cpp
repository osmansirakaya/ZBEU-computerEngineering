/*-------------------------------------de�i�kenler--------------------------------------------

char [20]="mufettis" --> karekter boyutunu belirler
printf("%s") --> string ifade yazd�rma 
printf("%d")-->int ifade yazd�rma
scanf("%s", &yazd�rmak istedi�in de�i�ken);
float--> tam de�eri g�rmek icin kullan
printf("%f",)-->float ve double tipinde yazd�rma
double ifadeyi kullan�c�dan alma komutu --> scanf("%lf") 

-------------------------------------karar yap�lar�-----------------------------------------

= atama 
== sorgulama
mod alma-->%
Ve-->&&
Veya-->||
E�itmidir-->==
E�it de�ilmidir-->!=

--------------------------------switch/case--------------------------------------------------
switch (de�i�ken)
{
case 1: ......
case 2: ......
}

---------------------------------------dizi--------------------------------------------------
int de�i�ken[2][3] ---> 2x3 boyutunda bir matris olusturdu
int de�i�ken[20]={,a,b,n,m};

//sat�r ve sutunlarda 0 dan baslar. indexte oldugu gibi


---------------------------------------goto---------------------------------------------------
bir nevi d�ng� gibi bir �ey
kullan�m� �u �ekilde---->  de�i�ken:(de�i�ken tan�mlay�p iki
 nokta �st �ste koy...
program�n nerden itibaren, o de�i�ken�n oldugu yere gidip 
cal�smas�n� istiyorsan goto de�i�ken ad�; )


------------------------------matematik fonksiyonlari------------------------------------------

matematik k�t�phanesi--->include<math.h>

sayini KAREK�K ald�rma komutu--->sqrt
kullan�m�: sonuc=sqrt(kullan�c�dan ald�g�m�z sayi de�eri);
ondal�kl� taraftan kac basamak yazd�rmak istiyorsan (%.5f) virg�lden
sonra 5 basaamk al demek;


sayinin �SS�N� ald�rma komutu---> pow
kullan�m�: sonuc=pow(x,y);   x->taban
			     y->�s


say�y� �ste ya da alta yuvarlama
ceil-->  �ste yuvarla
floor--> alta yuvarla
kullan�m�---> sonuc=ceil(de�i�ken);
kullan�m�---> sonuc=floor(de�i�ken);
	

mutlak de�er olarak yazd�rma 
fabs-->kullan�m� sonuc=fabs(de�i�ken);

logaritma de�eri bulma
log-->kullan�m� sonuc=log(de�i�ken);


sin cos kullan�m� da di�erleriyle ayn�
--------------------------------------------PUTS GETS KULLANIMI----------------------------------------

Gets ile kullan�c�dan bilgiyyi al
puts ile ekrana yazd�r
Kullan�m�-->gets(de�i�ken); kullan�c�dan bilgiyi ald�
	    puts(de�i�ken); ekrana yazd�rd�

-----------------------string'de bicimlendirilmis kullan�mlar--------------------------------------------

yazd�rmada bosluk b�rak�p yazd�r:
%18s-->18 sat�r yer acar ve i�ine yazar(sa�a dayar);
%-18s-->18 sat�r yer acar ve i�ine yazar(sola dayar);

-----------------------------------------STRLEN kulln�m�---------------------------------------------------
al�rken %s ile, yazd�r�rken %d ile***
girilen karakterin uzunlugunu verir
printf("%d",strlen(de�i�ken));

------------------------------------------------StrCpy & CtrnCpy------------------------------------------
 strcpy-->metinin tamam�n� kopyalar ===> strcpy(a,b)>b'yi a'ya kopyalad�;
 strncpy--> metinden istedi�iniz uzunlukta kopyalama yapar===> strncpy(a,b,7)>b'den 7 karekteri, a'ya kopyala;

-----------------------------------------------strcat-------------------------------------------------------

ta��ma amacl� de�i�ken(x) ve a,b;

strcat(x,a);         >
strcat(x,"bo�luk");   > ekran c�kt�s� a b;
strcat(x,b);         >



-----------------------------------------ENUM KULLANIMI-----------------------------------------------------
�oklu secimlere bir alternatiftir
manin'in disinda tan�mlar�n�r(class yap�s� gibi d�s�n)
main icinde cag�r�l�p de�i�ken t�retilir.
�r:
enum sehirler
{
  ankara,adana,amasya
};
int main(){
enum sehirler il;
il=ankara; gibi........
}

-------------------------------------------STRUCT----------------------------------------------------------
Aralarinda mant�ksal iliski bulunan fakat farkl� t�rde bulunan ifadelerdir
Genellikle main d�s�nda tan�mlan�p sonradan dahil ediliyor(enum ile ayn� kullan�m�);



------------------------------------------PO�NTER KULLANIMI------------------------------------------------
& --> degiskenin adresini tutar;
* --> degiskenin adresin'deki degeri g�sterir;    

Bir degiskenin adresinde ki degeri g�rmen icin,
atad�g�n de�i�ken pointer tipinde olmal� yani :

int *a, b;
b=10;
a=&b;

--------------------------------------------------DEF�NE--------------------------------------------------

�ni�lemeci--> #define puan 2.50
main icinde puan g�rd��� heryere '2.50'yi yazd�racak;

--------------------------------------------define/makro kullan�m------------------------------------------
#define maksimum (s1,s2) (s1>s2) ? s1 : s2 
a��klama;
// maksimum ad�nda fonksiyon olusturdu, s1,s2 de�i�keni olusturdu, s1>s2 ise s1 i yazd�r de�ilse s2;

-----------------------------------------------metin belgesi olusturma-------------------------------------
IO
input   --> Giri�                  Open    --> A�ma 
output  --> C�k��	           Close   --> Kapatma
File    --> Dosya / F              Write   --> Yazma / w
Put     --> Yazd�rma  /putc        Read    --> Okuma / r
Add     --> Ekleme / a             Get     --> Okuma/Alma getc


F�LE *dosya;
dosya=fopen=("dosyan�n uzant�s� // ile ay�r yollar�","w");

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------##  D�Z�LER VE ��ARET��LER�N �L��K�S� D�NAM�K BELLEK AYIRMA:


  *��aret�iler ve dizilerin g�sterimleri birbirlerinin yerine kullan�labilir. A�a��daki �rneklerde, ? sembol� �denktir (ayn�d�r)� anlam�nda kullan�l�yor. 
	dizim[i]   ?  *(dizim+i) 
	dizim + i   ?  &dizim[i] 
	isaretcim[i]  ?  *(isaretcim + i) 
	isaretcim + i  ?  &isaretcim[i]

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------## SIRALAMA, DO�RUSAL ARAMA VE �K�L� ARAMA :

*free fonksiyonu <stdlib.h> kitapl���nda tan�ml�, parametre olarak herhangi bir tipte i�aret�i alan ve o i�aret�i arac�l���yla ayr�lm�� bellek blo�unu serbest 	b�rakan  fonksiyondur. 
 
* rand fonksiyonu <stdlib.h> kitapl���nda tan�ml�, rastgele bir tamsay� �reten ve �retti�i tamsay�y� d�nen fonksiyondur. 
 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
## D�ZG�LER(STRINGS)

	     *E�er dizgileri kullan�rsak, P�nin son eleman�n� bo� karakter (�\0�) olarak belirlemeliyiz
	     *Asl�nda, C dilinde dizgiler i�in bir�ok kolayl�k bulunmaktad�r. �rne�in, printf() fonksiyonu
	      dizgiler �zerinde do�rudan uygulanabilir, dizgilerin d�n���m belirteci %s�dir. Kod a�a��dad�r:
	      printf(�%s�, P);



		** <string.h> kitapl�g� ile
			strlen(char *S): s dizisindeki karekter say�s�n� d�ner(bos karekter saymadan)
			strcpy(char *hedef, char *kaynak): kaynak dizisini hedef dizisine kopyalar.

			strcmp(char *s1, char *s2): s1 ve s2 dizgileri kar��la�t�r�r ve
					s1<s2 ise < 0 d�ner	(alfabetik siraya g�re )
					s1 == s2 ise = 0 d�ner  (alfabetik siraya g�re )
					s1 > s2 ise > 0 d�ner	(alfabetik siraya g�re )
			strcat(char *hedef, char *kaynak): kaynak dizgisinin bir kopyas�n� hedef dizgisinin
				sonuna ekler. Bu fonksiyonu �a��rmadan �nce, hedef dizgisinin boyunu art�rmal�y�z
			int atoi(char *s): Bir S dizgisini kar��l�k gelen tamsay�s�na �evirir. E�er dizgi bir
				tamsay�ya �evrilemezse 0 d�n�l�r.	
							atoi(�345�) 345 tamsay�s�n� d�ner.
							atoi(�abc�) 0 d�ner.
							atoi(�12ad3�) 12 d�ner.
	

		*** STRTOK s�navda sorumlu de�iliz ***

			sprintf(): Bi�imlendirilmi� ��kt�y� bir dizgiye g�nderir.


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


## �OK BOYUTLU D�Z�LER, YAPILAR:


	**�ok boyutlu diziler		
	
	int a[3][4]; --> a dizisini 3sat�r ve 4sutun bir tablo gibi d���nebiliriz.


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------## YAPILAR(structure) -> veri yap�lar� ya da t�retilmi� veri t�rleridir.
	
	**�rnek yap�: struct vektor a,b  --> struct anahtar s�zc�k, vekt�r de�i�kendir(etiket) */
	
	

	
	
























