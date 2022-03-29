#include <stdio.h>

int main() {
	
	int a = 3, b = 2, *ptr, *x, *y;
	
	ptr = &b;
	
	printf("Adres = %d\n", ptr);
	printf("Deger = %d\n", *ptr);
	
	x = ptr;
	
	printf("Adres = %d\n", x);
	printf("Deger = %d\n", *x);
	
	*ptr = a;
	printf("Deger = %d\n", ptr);
	printf("Deger = %d\n", *ptr);
	printf("Deger = %d\n", b);
	
	a = 15;
	
	y = &*x;
	printf("Deger = %d\n", y);
	printf("Deger = %d\n", *y);
	y = &a;
	printf("Deger = %d\n", y);
	printf("Deger = %d\n", *y);
	
	y--;
	printf("Deger = %d\n", y);
	printf("Deger = %d\n", *y);
	
	x+=12;
	printf("Deger = %d\n", x);
	printf("Deger = %d\n", *x);
	*x = 123;
	printf("Deger = %d\n", *x);
	
	return 0;
}
