#include <stdio.h>
#include <stdlib.h>

int yinelenen(int A[], int n, int *sayac) {
	
	int i, j;
	int eleman;
	int *S;
	int max_sayac;
	int max_sayac_index;
	
	S = (int *)calloc(n,sizeof(int));
	
	for (i=0; i<n; i++) {
		eleman = A[i];
		S[i]++;
		for (j=0; j<i; j++)
			if (A[j]==eleman)
				S[i]++;
		for (j=i+1; j<n; j++)
			if (A[j]==eleman)
				S[i]++;
	}
	
	max_sayac = S[0];
	max_sayac_index = 0;
	
	for (i=1; i<n; i++)
		if (S[i] > max_sayac) {
			max_sayac = S[i];
			max_sayac_index = i;
		}

	*sayac = max_sayac;
	return A[max_sayac_index];
	
}

int main() {
	
	int yine;
	int syac;
	int i;
	
	int A[] = {90, 20, 90, 20, 50, 20, 50, 50, 90, 80, 20, 80, 20, 90, 20, 50, 50, 50, 10, 50};
			
	printf("A dizisi sudur:\n");
	for (i=0; i<20; i++)
		printf("%d ",A[i]);
	printf("\n\n");
	
	yine = yinelenen(A,20,&syac);
	
	printf("%d sayisi %d kez goruldu\n",yine,syac);
	
	return 0;
}
