#include <stdio.h>

int main() {

	int kucuk[26] = {0};
	int buyuk[26] = {0};
	char kar;
	int i;
	
	printf("Karakterler gir: \n");
	
	do {
		scanf("%c",&kar);
		
		if (kar >= 'a' && kar<='z')
			kucuk[kar-'a']++;
		else if (kar >= 'A' && kar<='Z')
			buyuk[kar-'A']++;
	}
	while (kar != '%');
	
	printf("KUCUK HARF SAYACLARI\n");
	
	for (i=0; i<26; i++)
		printf("%d\t",kucuk[i]);

	printf("\nBUYUK HARF SAYACLARI\n");
	
	for (i=0; i<26; i++)
		printf("%d\t",buyuk[i]);


	return 0;
}
