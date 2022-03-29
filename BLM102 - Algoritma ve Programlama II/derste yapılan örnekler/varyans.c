#include <stdio.h>

int main() {
	
	float X[1000];
	float ort = 0, var;
	int i = 0, j;
	
	printf("Sayi gir: ");
	scanf("%f",&X[i]);
	
	while (X[i] != -1) {
		ort += X[i];
		i++;
		printf("Sayi gir: ");
		scanf("%f",&X[i]);
	}
	
	ort/=i;
	
	for (j = 0; j < i; j++)
		var += (X[j]-ort) * (X[j]-ort);
		
	var/=(i-1);
	
	printf("ORT = %.2f, VAR = %.2f\n",ort,var);
	
	return 0;
}
