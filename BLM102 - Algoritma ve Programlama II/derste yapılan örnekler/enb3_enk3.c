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

int main() {
	
	int i;
	int enk = 0, enb = 0;
	int enks = 0, enbs = 0;
	
	for (i=10; i<100; i++) {
		if (asal(i)) {
			enk+=i;
			enks++;
			if (enks == 3) {
				printf ("En kucuk 3 asal sayinin toplami = %d\n", enk);
				break;
			}
		}
	}
	
	for (i=99; i>9; i--) {
		if (asal(i)) {
			enb+=i;
			enbs++;
			if (enbs == 3) {
				printf ("En buyuk 3 asal sayinin toplami = %d\n", enb);
				break;
			}
		}
	}
	
	return 0;
}
