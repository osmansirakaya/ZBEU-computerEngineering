#include <stdio.h>
#include <stdlib.h>

//1: kucukten buyuge
//2: buyukten kucuge

void sirala(int A[],int n) {
	
	int i,j;
	int temp;
	
	for (i=0; i < n-1; i++)
		for (j = i+1; j<n; j++)
			if ((A[i]%2==0 && A[j]%2 == 0) || (A[i]%2==1 && A[j]%2 == 1)) {
				if (A[i] > A[j]) {
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
}

int main() {
	
	int A[20] = {87, 20, 65, 51, 80, 13, 24, 98, 45, 84, 10, 20, 2, 1, 63, 40, 18, 17, 29, 30};
	int eb2;
	int i;
		
	printf("A DIZISI SUDUR:\n");
		
	for (i=0; i<20; i++)
		printf("%d ",A[i]);
	printf("\n\n");	
		
	sirala(A,20);	
		
	printf("SIRALANMIS A DIZISI SUDUR:\n");
		
	for (i=0; i<20; i++)
		printf("%d ",A[i]);
	printf("\n\n");

	
	return 0;
}
