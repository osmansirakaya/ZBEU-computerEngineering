#include <stdio.h>
#define MAX 25

int main() {
	
	float p1[MAX+1] = {0}, p2[MAX+1] = {0};
	
	float s_toplam[MAX+1] = {0};
	float s_carpim[2*MAX+1] = {0};
	
	int n1, n2, nmax;
	int i,j;
	
	printf("Birinci polnomun derecesi?: ");
	scanf("%d",&n1);
	
	while (n1<0 || n1>MAX) {
		printf("0 ile %d arasýnda deger girin:",MAX);
		scanf("%d",&n1);
	}
	
	for (i=n1; i>=0; i--) {
		printf("x^%d teriminin katsayisini girin: ",i);
		scanf("%f",&p1[i]);
	}

	printf("Ikinci polnomun derecesi?: ");
	scanf("%d",&n2);
	
	while (n2<0 || n2>MAX) {
		printf("0 ile %d arasýnda deger girin:",MAX);
		scanf("%d",&n2);
	}
	
	for (i=n2; i>=0; i--) {
		printf("x^%d teriminin katsayisini girin: ",i);
		scanf("%f",&p2[i]);
	}
	
	if (n1>n2)
		nmax = n1;
	else
		nmax = n2;
		
	printf("ILK POLI\n");
	for (i=n1; i>0; i--)
		printf("%.2f x^%d + ",p1[i],i);
	printf("%.2f\n",p1[0]);
		printf("IKINCI POLI\n");
	for (i=n2; i>0; i--)
		printf("%.2f x^%d + ",p2[i],i);
	printf("%.2f\n",p2[0]);
	
	/*TOPLAMA*/
	
	for (i=0; i<=nmax; i++)
		s_toplam[i] = p1[i]+ p2[i];
	
	/*CARPMA*/
	
	for (i=0; i<=n1; i++)
		for (j=0; j<=n2; j++)
			s_carpim[i+j]+= p1[i] * p2[j];
		
	/*SONUCLAR*/
	printf("TOPLAM\n");
	for (i=nmax; i>0; i--)
		printf("%.2f x^%d + ",s_toplam[i],i);
	printf("%.2f\n",s_toplam[0]);
		printf("CARPIM\n");
	for (i=n1+n2; i>0; i--)
		printf("%.2f x^%d + ",s_carpim[i],i);
	printf("%.2f\n",s_carpim[0]);	
		
	return 0;
}
