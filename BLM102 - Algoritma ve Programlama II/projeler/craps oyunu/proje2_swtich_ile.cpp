#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() { 
  int sayi,a2;
  char cvp,cvp2; a: 
  	srand(time(NULL));
	sayi = rand() % 6 + 1 + rand() % 6 + 1;
  		printf("Zarlar atiliyor...");
  switch(sayi){
  	case 7:
  	case 11:
  	    printf("%d Kazandiniz\n",sayi);	
		goto b;				 
		break;
  	case 2:
  	case 3:
  	case 12:
  	    printf("%d Kaybettiniz\n",sayi);
  		goto b; 	
  	    break; 
  	case 4:
  	case 5:
  	case 6:
  	case 8:
  	case 9:
  	case 10: 
	  	printf("%d Sonuc belirsiz, tekrar zar atilacak. At (a/A)? ",sayi);	
	  	scanf("%s",&cvp2);
	  	z:
	  		if(cvp2=='a' || cvp2=='A'){	
				srand(time(NULL));
				a2= rand() % 6 + 1 + rand() % 6 + 1;						
				printf("Zarlar atiliyor...");			
				if(a2==7){
					printf("%d Kaybettiniz\n",a2);
					goto b;
				}			
			if(sayi!=a2){
				srand(time(NULL));
				a2= rand() % 6 + 1 + rand() % 6 + 1;
				printf("%d Sonuc belirsiz, tekrar zar atilacak. At (a/A)? ",a2);
				scanf("%s",&cvp2);
				goto z;				
			 }
			 else
			 	printf("%d Kazandiniz\n",a2);
				 goto b;	  	
  		break;
		}				     	
				b:	
				printf("Yeni oyun oynansin mi (e/E - h/H)? ");
				scanf("%s",&cvp);
			if (cvp!='e' && cvp!='E' && cvp!='h' && cvp!='H')
				goto b;
 			else if(cvp=='e' || cvp=='E')
				goto a;	
			else if(cvp=='h' || cvp=='H')
				printf("CRAPS sona erdi.\n");	
	system ("pause");
    return 0;
	}
}
