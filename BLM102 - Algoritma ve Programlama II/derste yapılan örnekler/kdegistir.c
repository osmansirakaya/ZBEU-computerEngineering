#include <stdio.h>

void kdegistir(int a, int b) {
	
	int gecici;
	
	gecici = a;
	a = b;
	b = gecici;

}

void kdegistir2(int *a, int *b) {
	
	int gecici;
	
	gecici = *a;
	*a = *b;
	*b = gecici;
}

int main() {
	
	int a, b;
	
	printf("Sayilar gir: ");
	scanf("%d%d",&a,&b);
	
	printf("eski a = %d, eski b = %d\n",a,b);
	kdegistir(a, b);
	printf("yeni a = %d,yeni b = %d\n",a,b);
	printf("\n\n");
	
	printf("*eski a = %d, *eski b = %d\n",a,b);
	kdegistir2(&a, &b);
	printf("*yenia = %d, *yeni b = %d\n",a,b);
	
}
