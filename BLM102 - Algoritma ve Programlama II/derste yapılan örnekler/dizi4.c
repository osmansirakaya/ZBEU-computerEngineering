#include <stdio.h>
#include <stdlib.h>

//1: kucukten buyuge
//2: buyukten kucuge

int enb2(int A[],int n) {
	
	int max, max2;
	int i;
	
	if (n < 2)
		return -1;
		
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
		if (A[i] > max) {
			max2 = max;
			max = A[i];
		}
		else if (A[i] > max2 && A[i]!=max)
			max2 = A[i];
	
	return max2;			
		
	
}

int main() {
	
	int A[20] = {3,3,3, 70,70, 5, 2, 3, 3, 5, 2, 5, 2, 3, 40, 50, 5, 5, 5, 21};
	int eb2;
	int i;
		
	printf("A DIZISI SUDUR:\n");
		
	for (i=0; i<20; i++)
		printf("%d ",A[i]);
	printf("\n\n");	
		
	eb2 = enb2(A,20);
	
	printf("%d elemani en buyuk ikinci sayidir.\n", eb2);	
	
	return 0;
}
