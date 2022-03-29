#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main(){
	int a,a2;
	char answer,answer2;	
	c:
	srand(time(NULL));
	a = rand() % 6 + 1 + rand() % 6 + 1;	
		printf("Zarlar atiliyor...");
		if(a==7 || a==11){
			printf("%d Kazandiniz\n",a);
		}
		else if(a==2 || a==3 || a==12){		 
			printf("%d Kaybettiniz\n",a);
		} 
		else if(a==4 || a==5 || a==6 || a==8 || a==9 || a==10){
			printf("%d Sonuc belirsiz, tekrar zar atilacak. At (a/A)? ",a);
			scanf("%s",&answer2);					
			z:
			if(answer2=='a' || answer2=='A'){	
				srand(time(NULL));
				a2= rand() % 6 + 1 + rand() % 6 + 1;						
				printf("Zarlar atiliyor...");
				
				if(a2==7){
					printf("%d Kaybettiniz\n",a2);
					goto v;
				}			
			if(a!=a2){
				srand(time(NULL));
				a2= rand() % 6 + 1 + rand() % 6 + 1;
				printf("%d Sonuc belirsiz, tekrar zar atilacak. At (a/A)? ",a2);
				scanf("%s",&answer2);
				goto z;				
			 }
			 else{
			 	printf("%d Kazandiniz\n",a2);
			  }
		   }				
		}	v:		
		printf("Yeni oyun oynansin mi (e/E - h/H)? ");
		scanf("%s",&answer);					
					if (answer!='e' && answer!='E' && answer!='h' && answer!='H')
						goto v;
					else if(answer=='e' || answer=='E')
						goto c;	
					else if(answer=='h' || answer=='H')
						printf("CRAPS sona erdi.");			
	printf("\n");		
	system("pause");	
	return 0;
}
