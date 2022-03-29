#include <stdio.h>

void ktdolandir(int *a, int *b, int *c) {
	
	int gecici;
	
	gecici = *a;
	*a = 2 * (*c);
	*c = 4 * (*b);
	*b = 3 * gecici;

}

int main() {
	
	int a, b, c;
	
	printf("Sayilar gir: ");
	scanf("%d%d%d",&a,&b,&c);
	
	printf("a = %d, b = %d, c = %d\n",a,b,c);
	ktdolandir(&a, &b, &c);
	printf("a = %d, b = %d, c = %d\n",a,b,c);	
}
