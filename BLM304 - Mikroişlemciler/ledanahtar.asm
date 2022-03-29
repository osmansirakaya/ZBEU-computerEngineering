       
LOOP:   CLR P1.0
        ACALL DELAY
		SETB P1.0
        ACALL DELAY
        SJMP LOOP
DELAY:  NOP 
LOOPB:  MOV R2,#200
LOOPA:  MOV R3,#250
        NOP
        NOP
        DJNZ R3,LOOPA
        DJNZ R2,LOOPB
        RET
END
***************
MOV P0, # 83H 		; Basmalı düğme anahtarlarının başlatılması ve LED'in KAPALI durumunda başlatılması.
READSW: MOV A, P0 	; Port değerini Akümülatöre taşıma.
RRC A 			; Anahtar 1'in AÇIK olup olmadığını öğrenmek için Port 0'ın değerinin kontrol edilmesi
JC NXT 			; Anahtar 1 KAPALI ise, anahtar 2'nin AÇIK olup olmadığını kontrol etmek için NXT'ye atlayın
CLR P0.7 		; Anahtar 1 AÇIK olduğundan LED'i AÇIN
SJMP READSW 		; Anahtar durumunu tekrar okuyun.
NXT: RRC A		; Anahtar 2'nin AÇIK olup olmadığını bilmek için Port 0'ın değerini kontrol etme
JC READSW		; Anahtar 1'in durumunu tekrar kontrol etmek için READSW'ye atlama (anahtar 2 KAPALI ise)
SETB P0.7 		; KAPATMA LED, çünkü Anahtar 2 AÇIK
SJMP READSW 		; Anahtar 1'in durumunu tekrar okumak için READSW'ye atlar.
END