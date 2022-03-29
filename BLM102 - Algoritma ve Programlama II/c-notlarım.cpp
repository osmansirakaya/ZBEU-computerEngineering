/*-------------------------------------deðiþkenler--------------------------------------------

char [20]="mufettis" --> karekter boyutunu belirler
printf("%s") --> string ifade yazdýrma 
printf("%d")-->int ifade yazdýrma
scanf("%s", &yazdýrmak istediðin deðiþken);
float--> tam deðeri görmek icin kullan
printf("%f",)-->float ve double tipinde yazdýrma
double ifadeyi kullanýcýdan alma komutu --> scanf("%lf") 

-------------------------------------karar yapýlarý-----------------------------------------

= atama 
== sorgulama
mod alma-->%
Ve-->&&
Veya-->||
Eþitmidir-->==
Eþit deðilmidir-->!=

--------------------------------switch/case--------------------------------------------------
switch (deðiþken)
{
case 1: ......
case 2: ......
}

---------------------------------------dizi--------------------------------------------------
int deðiþken[2][3] ---> 2x3 boyutunda bir matris olusturdu
int deðiþken[20]={,a,b,n,m};

//satýr ve sutunlarda 0 dan baslar. indexte oldugu gibi


---------------------------------------goto---------------------------------------------------
bir nevi döngü gibi bir þey
kullanýmý þu þekilde---->  deðiþken:(deðiþken tanýmlayýp iki
 nokta üst üste koy...
programýn nerden itibaren, o deðiþkenýn oldugu yere gidip 
calýsmasýný istiyorsan goto deðiþken adý; )


------------------------------matematik fonksiyonlari------------------------------------------

matematik kütüphanesi--->include<math.h>

sayini KAREKÖK aldýrma komutu--->sqrt
kullanýmý: sonuc=sqrt(kullanýcýdan aldýgýmýz sayi deðeri);
ondalýklý taraftan kac basamak yazdýrmak istiyorsan (%.5f) virgülden
sonra 5 basaamk al demek;


sayinin ÜSSÜNÜ aldýrma komutu---> pow
kullanýmý: sonuc=pow(x,y);   x->taban
			     y->üs


sayýyý üste ya da alta yuvarlama
ceil-->  üste yuvarla
floor--> alta yuvarla
kullanýmý---> sonuc=ceil(deðiþken);
kullanýmý---> sonuc=floor(deðiþken);
	

mutlak deðer olarak yazdýrma 
fabs-->kullanýmý sonuc=fabs(deðiþken);

logaritma deðeri bulma
log-->kullanýmý sonuc=log(deðiþken);


sin cos kullanýmý da diðerleriyle ayný
--------------------------------------------PUTS GETS KULLANIMI----------------------------------------

Gets ile kullanýcýdan bilgiyyi al
puts ile ekrana yazdýr
Kullanýmý-->gets(deðiþken); kullanýcýdan bilgiyi aldý
	    puts(deðiþken); ekrana yazdýrdý

-----------------------string'de bicimlendirilmis kullanýmlar--------------------------------------------

yazdýrmada bosluk býrakýp yazdýr:
%18s-->18 satýr yer acar ve içine yazar(saða dayar);
%-18s-->18 satýr yer acar ve içine yazar(sola dayar);

-----------------------------------------STRLEN kullnýmý---------------------------------------------------
alýrken %s ile, yazdýrýrken %d ile***
girilen karakterin uzunlugunu verir
printf("%d",strlen(deðiþken));

------------------------------------------------StrCpy & CtrnCpy------------------------------------------
 strcpy-->metinin tamamýný kopyalar ===> strcpy(a,b)>b'yi a'ya kopyaladý;
 strncpy--> metinden istediðiniz uzunlukta kopyalama yapar===> strncpy(a,b,7)>b'den 7 karekteri, a'ya kopyala;

-----------------------------------------------strcat-------------------------------------------------------

taþýma amaclý deðiþken(x) ve a,b;

strcat(x,a);         >
strcat(x,"boþluk");   > ekran cýktýsý a b;
strcat(x,b);         >



-----------------------------------------ENUM KULLANIMI-----------------------------------------------------
çoklu secimlere bir alternatiftir
manin'in disinda tanýmlarýnýr(class yapýsý gibi düsün)
main icinde cagýrýlýp deðiþken türetilir.
ör:
enum sehirler
{
  ankara,adana,amasya
};
int main(){
enum sehirler il;
il=ankara; gibi........
}

-------------------------------------------STRUCT----------------------------------------------------------
Aralarinda mantýksal iliski bulunan fakat farklý türde bulunan ifadelerdir
Genellikle main dýsýnda tanýmlanýp sonradan dahil ediliyor(enum ile ayný kullanýmý);



------------------------------------------POÝNTER KULLANIMI------------------------------------------------
& --> degiskenin adresini tutar;
* --> degiskenin adresin'deki degeri gösterir;    

Bir degiskenin adresinde ki degeri görmen icin,
atadýgýn deðiþken pointer tipinde olmalý yani :

int *a, b;
b=10;
a=&b;

--------------------------------------------------DEFÝNE--------------------------------------------------

öniþlemeci--> #define puan 2.50
main icinde puan gördüðü heryere '2.50'yi yazdýracak;

--------------------------------------------define/makro kullaným------------------------------------------
#define maksimum (s1,s2) (s1>s2) ? s1 : s2 
açýklama;
// maksimum adýnda fonksiyon olusturdu, s1,s2 deðiþkeni olusturdu, s1>s2 ise s1 i yazdýr deðilse s2;

-----------------------------------------------metin belgesi olusturma-------------------------------------
IO
input   --> Giriþ                  Open    --> Açma 
output  --> Cýkýþ	           Close   --> Kapatma
File    --> Dosya / F              Write   --> Yazma / w
Put     --> Yazdýrma  /putc        Read    --> Okuma / r
Add     --> Ekleme / a             Get     --> Okuma/Alma getc


FÝLE *dosya;
dosya=fopen=("dosyanýn uzantýsý // ile ayýr yollarý","w");

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------##  DÝZÝLER VE ÝÞARETÇÝLERÝN ÝLÝÞKÝSÝ DÝNAMÝK BELLEK AYIRMA:


  *Ýþaretçiler ve dizilerin gösterimleri birbirlerinin yerine kullanýlabilir. Aþaðýdaki örneklerde, ? sembolü “denktir (aynýdýr)” anlamýnda kullanýlýyor. 
	dizim[i]   ?  *(dizim+i) 
	dizim + i   ?  &dizim[i] 
	isaretcim[i]  ?  *(isaretcim + i) 
	isaretcim + i  ?  &isaretcim[i]

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------## SIRALAMA, DOÐRUSAL ARAMA VE ÝKÝLÝ ARAMA :

*free fonksiyonu <stdlib.h> kitaplýðýnda tanýmlý, parametre olarak herhangi bir tipte iþaretçi alan ve o iþaretçi aracýlýðýyla ayrýlmýþ bellek bloðunu serbest 	býrakan  fonksiyondur. 
 
* rand fonksiyonu <stdlib.h> kitaplýðýnda tanýmlý, rastgele bir tamsayý üreten ve ürettiði tamsayýyý dönen fonksiyondur. 
 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
## DÝZGÝLER(STRINGS)

	     *Eðer dizgileri kullanýrsak, P’nin son elemanýný boþ karakter (‘\0’) olarak belirlemeliyiz
	     *Aslýnda, C dilinde dizgiler için birçok kolaylýk bulunmaktadýr. Örneðin, printf() fonksiyonu
	      dizgiler üzerinde doðrudan uygulanabilir, dizgilerin dönüþüm belirteci %s’dir. Kod aþaðýdadýr:
	      printf(“%s”, P);



		** <string.h> kitaplýgý ile
			strlen(char *S): s dizisindeki karekter sayýsýný döner(bos karekter saymadan)
			strcpy(char *hedef, char *kaynak): kaynak dizisini hedef dizisine kopyalar.

			strcmp(char *s1, char *s2): s1 ve s2 dizgileri karþýlaþtýrýr ve
					s1<s2 ise < 0 döner	(alfabetik siraya göre )
					s1 == s2 ise = 0 döner  (alfabetik siraya göre )
					s1 > s2 ise > 0 döner	(alfabetik siraya göre )
			strcat(char *hedef, char *kaynak): kaynak dizgisinin bir kopyasýný hedef dizgisinin
				sonuna ekler. Bu fonksiyonu çaðýrmadan önce, hedef dizgisinin boyunu artýrmalýyýz
			int atoi(char *s): Bir S dizgisini karþýlýk gelen tamsayýsýna çevirir. Eðer dizgi bir
				tamsayýya çevrilemezse 0 dönülür.	
							atoi(“345”) 345 tamsayýsýný döner.
							atoi(“abc”) 0 döner.
							atoi(“12ad3”) 12 döner.
	

		*** STRTOK sýnavda sorumlu deðiliz ***

			sprintf(): Biçimlendirilmiþ çýktýyý bir dizgiye gönderir.


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


## ÇOK BOYUTLU DÝZÝLER, YAPILAR:


	**çok boyutlu diziler		
	
	int a[3][4]; --> a dizisini 3satýr ve 4sutun bir tablo gibi düþünebiliriz.


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------## YAPILAR(structure) -> veri yapýlarý ya da türetilmiþ veri türleridir.
	
	**örnek yapý: struct vektor a,b  --> struct anahtar sözcük, vektör deðiþkendir(etiket) */
	
	

	
	
























