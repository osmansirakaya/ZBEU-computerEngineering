/*-------------------------------------değişkenler--------------------------------------------

char [20]="mufettis" --> karekter boyutunu belirler
printf("%s") --> string ifade yazdırma 
printf("%d")-->int ifade yazdırma
scanf("%s", &yazdırmak istediğin değişken);
float--> tam değeri görmek icin kullan
printf("%f",)-->float ve double tipinde yazdırma
double ifadeyi kullanıcıdan alma komutu --> scanf("%lf") 

-------------------------------------karar yapıları-----------------------------------------

= atama 
== sorgulama
mod alma-->%
Ve-->&&
Veya-->||
Eşitmidir-->==
Eşit değilmidir-->!=

--------------------------------switch/case--------------------------------------------------
switch (değişken)
{
case 1: ......
case 2: ......
}

---------------------------------------dizi--------------------------------------------------
int değişken[2][3] ---> 2x3 boyutunda bir matris olusturdu
int değişken[20]={,a,b,n,m};

//satır ve sutunlarda 0 dan baslar. indexte oldugu gibi


---------------------------------------goto---------------------------------------------------
bir nevi döngü gibi bir şey
kullanımı şu şekilde---->  değişken:(değişken tanımlayıp iki
 nokta üst üste koy...
programın nerden itibaren, o değişkenın oldugu yere gidip 
calısmasını istiyorsan goto değişken adı; )


------------------------------matematik fonksiyonlari------------------------------------------

matematik kütüphanesi--->include<math.h>

sayini KAREKÖK aldırma komutu--->sqrt
kullanımı: sonuc=sqrt(kullanıcıdan aldıgımız sayi değeri);
ondalıklı taraftan kac basamak yazdırmak istiyorsan (%.5f) virgülden
sonra 5 basaamk al demek;


sayinin ÜSSÜNÜ aldırma komutu---> pow
kullanımı: sonuc=pow(x,y);   x->taban
			     y->üs


sayıyı üste ya da alta yuvarlama
ceil-->  üste yuvarla
floor--> alta yuvarla
kullanımı---> sonuc=ceil(değişken);
kullanımı---> sonuc=floor(değişken);
	

mutlak değer olarak yazdırma 
fabs-->kullanımı sonuc=fabs(değişken);

logaritma değeri bulma
log-->kullanımı sonuc=log(değişken);


sin cos kullanımı da diğerleriyle aynı
--------------------------------------------PUTS GETS KULLANIMI----------------------------------------

Gets ile kullanıcıdan bilgiyyi al
puts ile ekrana yazdır
Kullanımı-->gets(değişken); kullanıcıdan bilgiyi aldı
	    puts(değişken); ekrana yazdırdı

-----------------------string'de bicimlendirilmis kullanımlar--------------------------------------------

yazdırmada bosluk bırakıp yazdır:
%18s-->18 satır yer acar ve içine yazar(sağa dayar);
%-18s-->18 satır yer acar ve içine yazar(sola dayar);

-----------------------------------------STRLEN kullnımı---------------------------------------------------
alırken %s ile, yazdırırken %d ile***
girilen karakterin uzunlugunu verir
printf("%d",strlen(değişken));

------------------------------------------------StrCpy & CtrnCpy------------------------------------------
 strcpy-->metinin tamamını kopyalar ===> strcpy(a,b)>b'yi a'ya kopyaladı;
 strncpy--> metinden istediğiniz uzunlukta kopyalama yapar===> strncpy(a,b,7)>b'den 7 karekteri, a'ya kopyala;

-----------------------------------------------strcat-------------------------------------------------------

taşıma amaclı değişken(x) ve a,b;

strcat(x,a);         >
strcat(x,"boşluk");   > ekran cıktısı a b;
strcat(x,b);         >



-----------------------------------------ENUM KULLANIMI-----------------------------------------------------
çoklu secimlere bir alternatiftir
manin'in disinda tanımlarınır(class yapısı gibi düsün)
main icinde cagırılıp değişken türetilir.
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
Aralarinda mantıksal iliski bulunan fakat farklı türde bulunan ifadelerdir
Genellikle main dısında tanımlanıp sonradan dahil ediliyor(enum ile aynı kullanımı);



------------------------------------------POİNTER KULLANIMI------------------------------------------------
& --> degiskenin adresini tutar;
* --> degiskenin adresin'deki degeri gösterir;    

Bir degiskenin adresinde ki degeri görmen icin,
atadıgın değişken pointer tipinde olmalı yani :

int *a, b;
b=10;
a=&b;

--------------------------------------------------DEFİNE--------------------------------------------------

önişlemeci--> #define puan 2.50
main icinde puan gördüğü heryere '2.50'yi yazdıracak;

--------------------------------------------define/makro kullanım------------------------------------------
#define maksimum (s1,s2) (s1>s2) ? s1 : s2 
açıklama;
// maksimum adında fonksiyon olusturdu, s1,s2 değişkeni olusturdu, s1>s2 ise s1 i yazdır değilse s2;

-----------------------------------------------metin belgesi olusturma-------------------------------------
IO
input   --> Giriş                  Open    --> Açma 
output  --> Cıkış	           Close   --> Kapatma
File    --> Dosya / F              Write   --> Yazma / w
Put     --> Yazdırma  /putc        Read    --> Okuma / r
Add     --> Ekleme / a             Get     --> Okuma/Alma getc


FİLE *dosya;
dosya=fopen=("dosyanın uzantısı // ile ayır yolları","w");

----------------------------------------------------DİZİLER VE İŞARETÇİLERİN İLİŞKİSİ DİNAMİK BELLEK AYIRMA---------------------------------------------


  *İşaretçiler ve dizilerin gösterimleri birbirlerinin yerine kullanılabilir. Aşağıdaki örneklerde, ? sembolü “denktir (aynıdır)” anlamında kullanılıyor. 
	dizim[i]   ?  *(dizim+i) 
	dizim + i   ?  &dizim[i] 
	isaretcim[i]  ?  *(isaretcim + i) 
	isaretcim + i  ?  &isaretcim[i]

--------------------------------------------------SIRALAMA, DOĞRUSAL ARAMA VE İKİLİ ARAMA-------------------------------------------------------

*free fonksiyonu <stdlib.h> kitaplığında tanımlı, parametre olarak herhangi bir tipte işaretçi alan ve o işaretçi aracılığıyla ayrılmış bellek bloğunu serbest 
bırakan  fonksiyondur. 
 
* rand fonksiyonu <stdlib.h> kitaplığında tanımlı, rastgele bir tamsayı üreten ve ürettiği tamsayıyı dönen fonksiyondur. 
 
--------------------------------------- DİZGİLER(STRINGS)------------------------------------------------------------------------------

	     *Eğer dizgileri kullanırsak, P’nin son elemanını boş karakter (‘\0’) olarak belirlemeliyiz
	     *Aslında, C dilinde dizgiler için birçok kolaylık bulunmaktadır. Örneğin, printf() fonksiyonu
	      dizgiler üzerinde doğrudan uygulanabilir, dizgilerin dönüşüm belirteci %s’dir. Kod aşağıdadır:
	      printf(“%s”, P);



		** <string.h> kitaplıgı ile
			strlen(char *S): s dizisindeki karekter sayısını döner(bos karekter saymadan)
			strcpy(char *hedef, char *kaynak): kaynak dizisini hedef dizisine kopyalar.

			strcmp(char *s1, char *s2): s1 ve s2 dizgileri karşılaştırır ve
					s1<s2 ise < 0 döner	(alfabetik siraya göre )
					s1 == s2 ise = 0 döner  (alfabetik siraya göre )
					s1 > s2 ise > 0 döner	(alfabetik siraya göre )
			strcat(char *hedef, char *kaynak): kaynak dizgisinin bir kopyasını hedef dizgisinin
				sonuna ekler. Bu fonksiyonu çağırmadan önce, hedef dizgisinin boyunu artırmalıyız
			int atoi(char *s): Bir S dizgisini karşılık gelen tamsayısına çevirir. Eğer dizgi bir
				tamsayıya çevrilemezse 0 dönülür.	
							atoi(“345”) 345 tamsayısını döner.
							atoi(“abc”) 0 döner.
							atoi(“12ad3”) 12 döner.
	

		*** STRTOK sınavda sorumlu değiliz ***

			sprintf(): Biçimlendirilmiş çıktıyı bir dizgiye gönderir.


-------------------------------------------------------


## ÇOK BOYUTLU DİZİLER, YAPILAR:


	**çok boyutlu diziler		
	
	int a[3][4]; --> a dizisini 3satır ve 4sutun bir tablo gibi düşünebiliriz.


------------------------------------------------ YAPILAR(structure) -> veri yapıları ya da türetilmiş veri türleridir.
	
	**örnek yapı: struct vektor a,b  --> struct anahtar sözcük, vektör değişkendir(etiket) */
	
	

	
	
























