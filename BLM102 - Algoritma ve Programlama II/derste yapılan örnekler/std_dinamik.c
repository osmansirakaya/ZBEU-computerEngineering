#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	float *sayilar;
	int n;
	int i;
	float ort = 0.0, std = 0.0;
	
	printf("Kac sayi var?: ");
	scanf("%d",&n);
	
	while (n<1) {
		printf("Yanlis yapma\n");
		printf("Kac sayi var?: ");
		scanf("%d",&n);
	}
	
	sayilar = (float *)malloc(n*sizeof(float));
	if (sayilar == NULL)
		return -1;
	
	for (i=0; i<n; i++) {
		printf("%d. sayiyi gir: ", i+1);
		scanf("%f",&sayilar[i]);
		ort+=sayilar[i];
	}
	ort/=n;
	
	for (i=0; i<n; i++)
		std+=(sayilar[i]-ort)*(sayilar[i]-ort);
		
	std/=(n-1);
	
	std = sqrt(std);
	
	printf("ORT = %.2f, STD = %.2f\n",ort,std);	

	return 0;
}
