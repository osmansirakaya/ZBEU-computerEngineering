infix- postfix
1-Soldan Saða tara
2-Karþýlaþýlan sembol operand ise çýktýya gönder
3-Karþýlaþýlan sembol operatör veya parantez ise yýðýna ekle(push)
4-Karþýlaþýlan sembol '(' ise yýðýna ekle(push)
	Sonra ')' e kadar yýðýndan çýkar(pop)
5-Eðer Karþýlaþýlan operatörün önceliði yýðýn en üstündeki operatörden küçük eþitse 
	yýðýndan operatörleri çýkar(pop) koþul saðlanmayana kadar
6- else operatörü yýðýna ekle(push) 
7-iþlem bittiðin yýðýn boþ deðilse yýðýn boþalana kadar sembolleri çýkar (pop)



