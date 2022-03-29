#include <stdio.h>

int main() {
	
	char son, son2, son3;
	
	son = 'a';
	son2 = 'a';
	son3 = 'a';
	
	for (;;) {
		
		son3 = son2;
		son2 = son;
		
		printf("Karakter gir: ");
		scanf("\n%c",&son);
		
		if ((son3 == 'e') && (son2 == 'n') && (son == 'd')) {
			printf("HOSCAKAL");
			break;
		}
		else
			printf("%c\n",son);
	}
	
	return 0;
}
