#include <stdio.h>

int asal(int sayi) {
	
	int i;
	
	if (sayi<2)
		return 0;
	
	for (i=2; i<=sayi/i; i++)
		if (sayi%i == 0)
			return 0;
	
	return 1;		
	
}

int main() {
	
	int S[10] = {20, 65, 73, 12 ,35, 1, 54, 8, 22, 125};
	int T[10] = {0};
	int C[10] = {0};
	int A[10] = {0};
	int i;
	
	for (i=0; i<10; i++) {
		if (S[i]%2 == 0)
			C[i] = 1;
		else
			T[i] = 1;
		if (asal(S[i]))
			A[i] = 1;
	}
	
	printf("Su sayilar cifttir: \n");
	for (i=0; i<10; i++)
		if (C[i])
			printf("%d ",S[i]);	
		printf("\n");
		
	printf("Su sayilar tektir: \n");
	for (i=0; i<10; i++)
		if (T[i])
			printf("%d ",S[i]);	
		printf("\n");
	
	printf("Su sayilar asaldir: \n");
	for (i=0; i<10; i++)
		if (A[i])
			printf("%d ",S[i]);	
		printf("\n");

	return 0;
}
