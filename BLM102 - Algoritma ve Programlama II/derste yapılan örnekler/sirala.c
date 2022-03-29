#include <stdio.h>

void siralama(int D[],int n) {
	
	int i,j;
	int gec;
	
	for (i=0; i<n-1;i++)
		for (j=i+1; j<n; j++)
			if (D[i] > D[j]) {
				gec = D[i];
				D[i] = D[j];
				D[j] = gec;
			}
}

int main() {
	
	int A[10] = {20,65,13,43,11,56,32,78,16,51};
	int i;
	
	
	siralama(A,10);
	
	for (i = 0; i<10; i++)
		printf("%d ",A[i]);
	printf("\n");
	
	return 0;
	}
	
