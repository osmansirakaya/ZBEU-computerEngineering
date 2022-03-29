#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	float *sayilar = NULL;
	int n = 0;
	int i;
	float ort = 0.0, std = 0.0;
	float sayi;

	printf("%d. sayiyi gir: ",n+1);
	scanf("%f",&sayi);
	
	while (sayi>=0.0) {
		ort+=sayi;
		n++;
		sayilar = (float *)realloc(sayilar,n*sizeof(float));
		sayilar[n-1] = sayi;
		printf("%d. sayiyi gir: ",n+1);
		scanf("%f",&sayi);
	}
	ort/=n;
	
	for (i=0; i<n; i++)
		std+=(sayilar[i]-ort)*(sayilar[i]-ort);
		
	std/=(n-1);
	
	std = sqrt(std);
	
	printf("ORT = %.2f, STD = %.2f\n",ort,std);	

	return 0;
}
