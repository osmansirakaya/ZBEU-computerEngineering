#include <stdio.h>
#include <stdlib.h>

//1: kucukten buyuge
//2: buyukten kucuge

int yinelenen(int A[],int n, int *s) {
	
	int *S;
	int i, j;
	int eleman;
	int max_sayac;
	int max_sayac_index = 0;
	
	S = (int *)calloc(n,sizeof(int));
	
	for (i=0; i<n; i++) {
		eleman = A[i];
		S[i]++;
		for (j=0; j<i; j++)
			if (A[j] == eleman)
				S[i]++;
		for (j=i+1; j<n; j++)
			if (A[j] == eleman)
				S[i]++;		
	}
	
	max_sayac = S[0];
	
	for (i=1; i<n; i++) {
		if (S[i] > max_sayac) {
			max_sayac = S[i];
			max_sayac_index = i;
		}
	}
	
	*s = max_sayac;
	return A[max_sayac_index];
}

int main() {
	
	int A[20] = {3,3,3, 60,70, 5, 2, 3, 3, 5, 2, 5, 2, 3, 40, 50, 5, 5, 5, 21};
	int i;
	int sayac = 0;
	int eleman;
		
	printf("A DIZISI SUDUR:\n");
		
	for (i=0; i<20; i++)
		printf("%d ",A[i]);
	printf("\n\n");	
		
	eleman = yinelenen(A,20,&sayac);
	
	printf("%d elemani %d kere yinelenmistir.\n", eleman, sayac);	
	
	return 0;
}
