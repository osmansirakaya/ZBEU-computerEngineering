#include <stdio.h>
#include <math.h>

#define KUCUK 0.000001
#define esit(a,b) (((a-b) < KUCUK) && ((b-a) < KUCUK)) 

float delta(float a, float b, float c) {
	return b*b - 4*a*c;
}

int denklemi_coz(float a, float b, float c, float *k1, float *k2) {
	
	float d;
	
	if (esit(a,0.0))
		return -1;
	
	d = delta(a,b,c);
	
	if (d < 0)
		return 0;
	else if (esit(d, 0.0)) {
		*k1 = (-b)/2*a;
		return 1;
	}
	else {
		*k1 = ((-b)+ sqrt(d))/(2*a);	
		*k2 = ((-b)- sqrt(d))/(2*a);
		return 2;
	}
	
}

int main() {
	
	float a, b, c;
	float kok1, kok2;
	int ss;
	
	printf("Denklemin terimlerinin katsayilarini gir (a, b, c): ");
	scanf("%f%f%f",&a,&b,&c);
	
	ss = denklemi_coz(a,b,c,&kok1,&kok2);
	
	if (ss == -1)
		printf("2. derece degil\n");
	else if (ss == 0)
		printf("Gercek kok yok\n");
	else if (ss == 1) {
		printf("BIR kok var:\n");
		printf("KOK = %.2f\n",kok1);
	}
	else {
		printf("IKI kok var:\n");
		printf("KOK1 = %.2f KOK2 = %.2f\n",kok1, kok2);
	}
	
	return 0;
}
