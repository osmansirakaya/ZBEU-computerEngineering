#include <stdio.h>

int main() {
	
	int A[100];
	int i;
	
	for (i=0; i<50; i++) {
		A[i] = i*2;
		A[99-i] = i*2;
	}
	
	printf("ORIJINAL DIZI\n");
	for (i=0; i<100; i++)
		printf("%d\t", A[i]);
	printf("\n");
	
	for (i=0; i<50; i++)
		if (A[i]!=A[99-i])
			break;
	
	if (i == 50)
		printf("Simetrik\n");
	else {
		printf("Simetrik degil\n");
		printf("CUNKU A[%d] != A[%d]\n",i,99-i);
	}
		
	
	A[78] = 15;	
	
	printf("ORIJINAL DIZI\n");
	for (i=0; i<100; i++)
		printf("%d\t", A[i]);
	printf("\n");
	
	for (i=0; i<50; i++)
		if (A[i]!=A[99-i])
			break;
	
	if (i == 50)
		printf("Simetrik\n");
	else{
		printf("Simetrik degil\n");
		printf("CUNKU A[%d] != A[%d]\n",i,99-i);
	}	
	return 0;
}
