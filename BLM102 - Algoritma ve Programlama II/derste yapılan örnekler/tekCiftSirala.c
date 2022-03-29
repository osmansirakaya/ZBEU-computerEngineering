#include <stdio.h>
#include <stdlib.h>

void tc_sirala(int A[], int n) {
	
	int i, j;
	int temp;
	
	for (i=0; i<n-1; i++)
		for (j = i+1; j<n; j++)
			if ((A[i]%2 == 0 && A[j]%2 == 0) || (A[i]%2 == 1 && A[j]%2 == 1))
				if (A[i] > A[j]) {
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
}

int main() {
	
	int i;
	int enb2;
	
	int A[] = {20, 10, 97, 13, 12, 5, 17, 40, 34, 1, 133, 122, 94, 89, 54, 900, 24, 127};
			
	printf("A dizisi sudur:\n");
	for (i=0; i<18; i++)
		printf("%d ",A[i]);
	printf("\n\n");
	
	tc_sirala(A, 18);
	
	printf("SIRALI A dizisi sudur:\n");
	for (i=0; i<18; i++)
		printf("%d ",A[i]);
	printf("\n\n");
	
	return 0;
}
