#include <stdio.h>
#include <stdlib.h>

int enbuyuk_2(int A[], int n) {
	
	int max, max2;
	int i;
	
	if (n<2)
		return -99999;
		
	if (A[0] > A[1]) {
		max = A[0];
		max2 = A[1];
	}
	else if (A[1] > A[0]) {
		max = A[1];
		max2 = A[0];
	}
	else {
		max = A[0];
		max2 = -99999;
	}
		
	for (i=2; i<n; i++)
		if (A[i] > max)	{
			max2 = max;
			max = A[i];
		}
		else if (A[i] > max2 && A[i] < max)
			max2 = A[i];
			
	return max2;		
}

int main() {
	
	int i;
	int enb2;
	
	int A[] = {90, 82, 90, 20, 50, 20, 50, 50, 90, 80, 20, 80, 20, 90, 20, 50, 50, 50, 10, 50};
			
	printf("A dizisi sudur:\n");
	for (i=0; i<20; i++)
		printf("%d ",A[i]);
	printf("\n\n");
	
	enb2 = enbuyuk_2(A, 20);
	
	printf("%d sayisi en buyuk 2. elemandir.\n",enb2);
	
	return 0;
}
