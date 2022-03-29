#include <stdio.h>
#include <stdlib.h>

int sirali_mi(int A[], int n, int kbbks) {
	
	int i;
	
	if (kbbks == 1) {
		for (i=0; i<n-1; i++)
			if (A[i] > A[i+1])
				return 0;
		return 1;		
	}
	else if (kbbks == 2) {
		for (i=0; i<n-1; i++)
			if (A[i] < A[i+1])
				return 0;
		return 1;	
	}
	else
		return -1;
	
}

int main() {
	
	int *A;
	int *B;
	int n;
	int i;
	
	printf("Kaclik dizi istersin? ");
	scanf("%d",&n);
	
	while (n<1 || n>100) {
		printf("1 ile 100 arasinda gir lutfen. Kaclik dizi istersin? ");
		scanf("%d",&n);
	}
	
	A = (int *)calloc(n,sizeof(int));
	B = (int *)calloc(n,sizeof(int));
	
	for (i=0; i<n/2; i++)
		A[i] = 2*i+2;
		
	for (i=n/2; i<n; i++)
		A[i] = 2*i;	
	
//	A[n-1] = 15;	
	
	for (i=0; i<n/2; i++)
		B[n-1-i] = 2*i+2;
		
	for (i=n/2; i<n; i++)
		B[n-1-i] = 2*i;	
		
	B[0] = 18;	
		
	printf("A dizisi sudur:\n");
	for (i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n\n");
	
	if (sirali_mi(A, n, 1))	
		printf("A dizisi kucukten buyuge siralidir\n");
	else	
		printf("A dizisi kucukten buyuge sirali degildir\n");
		
	printf("\n");	
		
	printf("B dizisi sudur:\n");
	for (i=0; i<n; i++)
		printf("%d ",B[i]);
	printf("\n\n");
	
	if (sirali_mi(B, n, 2))	
		printf("B dizisi buyukten kucuge siralidir\n");
	else	
		printf("B dizisi buyukten kucuge sirali degildir\n");
	
	return 0;
}
