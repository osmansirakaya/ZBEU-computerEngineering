#include <stdio.h>

int degistir(int A[], int n, int deger, int yenideger) {
	
	int i;
	int sayac = 0;
	
	for (i=0; i<n; i++)
		if (A[i] ==deger) {
			A[i] = yenideger;
			sayac++;
		}
	
	return sayac;
}

int main() {
	
	int D[10] = {20, 30, 20, 30,13,17, 20, 56, 87,20};
	int i;
	int ds;
	
	printf("ESKI\n");
	for (i=0; i<10; i++)
		printf("%d\t",D[i]);
	printf("\n\n");
	
	ds = degistir(D,10,20,44);
	
	printf("YENI\n");
	for (i=0; i<10; i++)
		printf("%d\t",D[i]);
	printf("\n\n");
	
	printf("%d degisiklik yapildi\n",ds);
	
	return 0;
}
