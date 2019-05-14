



BSHI_0	DATA	0ACH
BSHI_1	DATA	0ADH
BSHI_2	DATA	0AEH
BSHI_3	DATA	0AFH
BSHO_0	DATA	0BCH
BSHO_1	DATA	0BDH
BSHO_2	DATA	0BEH
BSHO_3	DATA	0BFH
BSHCTL	DATA	0ABH
MD0     DATA    0E9H
MD1     DATA    0EAH	
MD2     DATA    0EBH	
MD3     DATA    0ECH	
ARCON   DATA    0EFH	

?PR?_BarrelShift?IQMATHASM 				SEGMENT CODE 
?DT?_BarrelShift?IQMATHASM 				SEGMENT DATA  
?PR?_Normalize?IQMATHASM                SEGMENT CODE 
?DT?_Normalize?IQMATHASM                SEGMENT DATA 
?PR?__IQabs?IQMATHASM                	SEGMENT CODE 
?DT?__IQabs?IQMATHASM                	SEGMENT DATA 	
	
	
EXTRN   CODE (?C?LNEG)
	
PUBLIC	?_BarrelShift?BYTE
PUBLIC	_BarrelShift
PUBLIC  _Normalize	
PUBLIC  __IQabs	
	
	
RSEG  ?DT?_BarrelShift?IQMATHASM 
	
?_BarrelShift?BYTE:
         in?040:   DS   4
	ORG  4
        cmd:   DS   1


RSEG  ?DT?_Normalize?IQMATHASM

?_Normalize?BYTE:
		A?142:DS   4
			
RSEG  ?DT?__IQabs?IQMATHASM

?__IQabs?BYTE:
		A?143:DS   4
						
			

; //barrel shift
; /***************************************************
;  * Implements
;  */
; /*
;  * @fn		BarrelShift
;  *
;  * @brief	BarrelShift
;  * 
;  * @param	none
;  *
;  * @return 	none
;  */

	

; S32 BarrelShift(S32 in, S8 cmd)

RSEG  ?PR?_BarrelShift?IQMATHASM
_BarrelShift:
	USING	0
		
	MOV  	BSHCTL,cmd
	MOV 	BSHI_3, R4
	MOV 	BSHI_2, R5
	MOV 	BSHI_1, R6
	MOV 	BSHI_0, R7
	MOV 	R4,BSHO_3
	MOV 	R5,BSHO_2
	MOV 	R6,BSHO_1
	MOV 	R7,BSHO_0
	RET  

		

; //barrel shift
; /***************************************************
;  * Implements
;  */
; /*
;  * @fn		Normaloize
;  *
;  * @brief	Normalize
;  * 
;  * @param	none
;  *
;  * @return 	
;  */ index=ARCON;

	

; S32 Normalize(S32 in)


RSEG  ?PR?_Normalize?IQMATHASM
 _Normalize:
	MOV     MD0,R7
	MOV     MD1,R6
	MOV		MD2,R5
	MOV		MD3,R4
	MOV     ARCON,#00H
?C0002:
 
    MOV     A,MD3
    JNB     ACC.7,?C0004
    MOV     R7,#01H
    SJMP    ?C0005
?C0004:
    MOV     R7,#00H
?C0005:
    MOV     A,R7
    JZ      ?C0002
?C0003:	
	MOV     R7,MD0
	MOV		R6,MD1
	MOV		R5,MD2
	MOV		R4,MD3
	RET
	

RSEG  ?PR?__IQabs?IQMATHASM
 __IQabs:
	  MOV     A,R4
	  JNB     ACC.7,?C0007
	  LCALL   ?C?LNEG

?C0007:		
	  RET
END
