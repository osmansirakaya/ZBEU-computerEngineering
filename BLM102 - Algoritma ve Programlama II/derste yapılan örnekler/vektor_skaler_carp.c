#include <stdio.h>

void vekt_ska_carp(float V[], float n, float skaler) {
	int i;
	
	for (i=0; i<n; i++)
		V[i]*=skaler;
}

int main() {
	
	float VKT[5] = {1.5, 2.3, 5.2, 6.125, -98.3};
	int i;
	float ska = 5.6345;
	
	for (i=0; i<5; i++)
		printf("%.2f\t",VKT[i]);
	printf("\n\n");
	
	vekt_ska_carp(VKT,5,ska);
	
	printf("CARPIM\n");
	for (i=0; i<5; i++)
		printf("%.2f\t",VKT[i]);
	printf("\n\n");
	
	
	return 0;
}
