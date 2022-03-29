#include <stdio.h>

long faktoriyel(int n) {
	
	long sonuc = 1;
	int i;
	
	if (n<0)
		return -1;
	else {
		for (i = 2; i<=n; i++)
			sonuc *= i;
		return sonuc;
	}
}

int permutasyon(int n, int k) {
	if ((n<0) || (k<0) || (n<k))
		return -1;
	else
		return (faktoriyel(n)/faktoriyel(n-k));	
}

int kombinasyon(int n, int k) {
	if ((n<0) || (k<0) || (n<k))
		return -1;
	else
		return (faktoriyel(n)/(faktoriyel(k)*faktoriyel(n-k)));	
}

int main() {
	
	int n, k;
	
	printf("Sayilar gir: ");
	scanf("%d %d", &n, &k);
	
	printf("faktoriyel(%d) = %ld\n",n,faktoriyel(n));
	printf("permutasyon(%d, %d) = %d\n", n, k, permutasyon(n,k));
	printf("kombinasyon(%d, %d) = %d\n", n, k, kombinasyon(n,k));
	
	return 0;
}
