#include <stdio.h>

int main() {
	double dizi[5];
	printf("%p\n",dizi);
	printf("%p\n",&dizi);
	printf("%p\n",&dizi[0]);
	printf("%p\n",&dizi[2]);
	printf("%p\n",dizi+3);
	printf("\n");
	return 0;
}
