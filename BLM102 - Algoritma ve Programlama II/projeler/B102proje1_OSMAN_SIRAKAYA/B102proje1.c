									/*  Osman SIRAKAYA 192106206005 */
#include<stdio.h>
#include<string.h>		
#include<stdlib.h>					
int main(){
	char karakter[50]={""};
	char result[50]={""};
	int i=0, k;
	char answer='D'; a:
		for(;;)	{	
			if(answer=='b' || answer=='B')
				break;
			else if(answer=='d' || answer=='D'){
		printf("Karakterler girin:");
		scanf("%s",&karakter);		
				do{					
					if(karakter[i]==karakter[i+1]){    		
						int j=1;                            			
							while(karakter[i]==karakter[i+1]){  
								j++, i++;								  								
							}				
							char c = '0'+j;                              
							char temp[3];								 
						temp[0] = c;								  
						temp[1] = karakter[i];                    
						temp[2] = '\0';
						strcat(result,temp);                          
						i++;						
					}
					else {                           			      				
							char c = '1';                          
							char temp[3];
						temp[0] = c;
						temp[1] = karakter[i];
						temp[2] = '\0';
						strcat(result,temp);
						i++;									
						}																												
					}		while(karakter[i]!='\0');
								printf("Sonuc: %s\n",result);							 
							for(k=0;k<i;k++){								 
								result[k] = '\0';
						}
						i=0;	
			}			for(;;){										
					printf("Devam (d/D-b/B)?:");
					scanf("%s",&answer);	
						printf("\n");							
						if(answer=='d' || answer=='D'){					
								goto a;
						}
						else if(answer=='b' || answer=='B'){
							printf("program sonlandi...\n\n");
								goto a;
						}								
						else if(answer!='b' && answer!='B' && answer!='d' && answer!='D')
								goto a;																									
				}						
			}			system("pause");
						return 0;								
	}
	
