#include <stdio.h>
#include <stdlib.h>

//1: kucukten buyuge
//2: buyukten kucuge

int sirali_mi(int A[],int n,int sinyal) {
	
	int i;
	
	if (sinyal == 1) {
		for (i=0; i<n-1; i++)
			if (A[i] > A[i+1])
				return 0;
		return 1;		
	}
	else if (sinyal == 2) {
		for (i=0; i<n-1;i++)
			if (A[i] < A[i+1])
				return 0;
		return 1;
	}
	
}

int main() {
	
	int n;
	int *A, *B;
	int i;
	
	printf("Kac elemanli olsun? ");
	scanf("%d",&n);
	
	while (n < 1 || n>100) {
		printf("0-100 arasi gir. Kac elemanli olsun? ");
		scanf("%d",&n);
	}
	
	A = (int *)calloc(n,sizeof(int));
	B = (int *)calloc(n,sizeof(int));
	
	for (i=0; i<n/2; i++)
		A[i] = i*2+2;
		
	for (i=n/2; i<n; i++)
		A[i] = 2*i;
		
	for (i=0; i<n/2; i++)
		B[n-1-i] = i*2+2;
		
	for (i=n/2; i<n; i++)
		B[n-1-i] = 2*i;
		
	A[n-1] = 0;
	B[n-1] = 0;
		
	printf("A DIZISI SUDUR:\n");
		
	for (i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n\n");	
		
	printf("B DIZISI SUDUR:\n");
		
	for (i=0; i<n; i++)
		printf("%d ",B[i]);
	printf("\n\n");	
		
	if (sirali_mi(A,n, 1))
		printf("A Dizisi siralidir.\n");
	else
		printf("A Dizisi sirali degildir\n");
		
	if (sirali_mi(B,n, 2))
		printf("B Dizisi siralidir.\n");
	else
		printf("B Dizisi sirali degildir\n");	
	
	return 0;
}
