#include <stdio.h>
#include <math.h>

int asal(int n) {
	int i;
	
	if (n < 2)
		return -1;
	
	if (n == 2)
		return 1;
	
	for (i=2; i<sqrt(n)+1; i++)
		if (n%i == 0)
			return 0;
	
	return 1;
}

int OKEK(int A, int B) {
	
	int sonuc = 1;
	int i;
	
	if ((A < 1) || (B < 1))
		return -1;
	
	if ((A==1) || (B==1))
		return A*B;
		
	for (i=2;;) {
		if (asal(i)) {
			if (A%i == 0) {
				sonuc*=i;
				A/=i;
				if (B%i == 0)
					B/=i;
			}
			else if (B%i == 0) {
				sonuc*=i;
				B/=i;
			}
			else
				i++;
			if ((A == 1) && (B==1))
				return sonuc;
		}
		else
			i++;
	}
}

int main() {
	
	int a, b;
	int s;
	
	printf("Sayilar gir: ");
	scanf("%d %d", &a, &b);
	
	s = OKEK(a, b);
	
	printf("OKEK(%d, %d) = %d\n",a,b,s);
	
	return 0;
}
