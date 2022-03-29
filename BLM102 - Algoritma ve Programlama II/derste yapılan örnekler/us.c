#include <stdio.h>

float us(float n, int k) {
	
	int negatif = 0, i;
	float sonuc = 1.0;
	
	if ((n == 0) && (k == 0))
		return 99999.9;
	else {
		if (k==0)
			return 1.0;
		else {
			if (k<0) {
				k*=-1;
				negatif = 1;
			}
			for (i=0; i<k; i++)
				sonuc *= n;
			if (negatif == 1)
				return (1/sonuc);
			return sonuc;	
		}
	}
}

int main() {
	
	float n;
	int k;
	float s;
	
	printf("Sayilar gir: ");
	scanf("%f %d",&n, &k);
	
	s = us(n,k);
	
	if (s > 99999)
		printf("Tanimsiz\n");
	else
		printf("SONUC = %.2f",s);
	
	return 0;
}
