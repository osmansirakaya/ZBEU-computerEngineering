#include <stdio.h>
#include <math.h>

int carpanlar(int n) {
	int i;
	int carpan = 1;
	
	for (i=2; i<n/2+1; i++)
		if (n%i == 0)
			carpan +=i;
			
	return carpan;	
}

int main() {
	
	int sayi;
	
	printf("Sayi gir: ");
	scanf("%d",&sayi);
	
	if (sayi < 1)
		printf("Hata\n");
	else
		printf("Carpanlar toplami = %d",carpanlar(sayi));
	
	return 0;
}
