IMR     .SET    0004H
IFR     .SET    0006H
SYSCR   .SET    7018H
SYSSR   .SET    701AH
SYSIVR  .SET    701EH

RTICNTR .SET    7021H
WDCNTR  .SET    7023H
WDKEY   .SET    7025H
RTICR   .SET    7027H
WDCR    .SET    7029H

CKCR0   .SET    702BH
CKCR1   .SET    702DH


ADCTRL1	.SET	07032H
ADCTRL2	.SET	07034H
ADCFIFO1.SET	07036H
ADCFIFO2.SET	07038H

SPICCR  .SET    7040H
SPICTL  .SET    7041H
SPISTS  .SET    7042H
SPIBRR  .SET    7044H
SPIEMU  .SET    7046H
SPIBUF  .SET    7047H
SPIDAT  .SET    7049H
SPIPC1  .SET    704DH
SPIPC2  .SET    704EH
SPIPRI  .SET    704FH



SCICCR	.SET	07050H
SCICTL1	.SET	07051H
SCIHBAUD.SET	07052H
SCILBAUD.SET	07053H
SCICTL2	.SET	07054H
SCIRXST	.SET	07055H
SCITXEMU.SET	07056H
SCIRXBUF.SET	07057H
SCITXBUF.SET	07059H
SCIPC2	.SET	0705EH
SCIPRI	.SET	0705FH

XINT1CR .SET    7070H
NMICR   .SET    7072H
XINT2CR .SET    7078H
XINT3CR .SET    707AH


OCRA    .SET    07090H
OCRB    .SET    07092H
PADATDIR.SET    07098H
PBDATDIR.SET    0709AH
PCDATDIR.SET    0709CH
PDDATDIR.SET    0709EH
ISRA    .SET    07094H
ISRB    .SET    07096H

GPTCON  .SET    07400H
T1CNT   .SET    07401H
T1CMPR  .SET    07402H
T1PR    .SET    07403H
T1CON   .SET    07404H
T2CNT   .SET    07405H
T2CMPR  .SET    07406H
T2PR    .SET    07407H
T2CON   .SET    07408H
T3CNT   .SET    07409H
T3CMPR  .SET    0740AH
T3PR    .SET    0740BH
T3CON   .SET    0740CH

COMCON  .SET    07411H
ACTR    .SET    07413H
SACTR   .SET    07414H
DBTCON  .SET    07415H
CMPR1   .SET    07417H
CMPR2   .SET    07418H
CMPR3   .SET    07419H
SCMPR1  .SET    0741AH
SCMPR2  .SET    0741BH
SCMPR3  .SET    0741CH

CAPCON	.SET	7420H
CAPFIFO	.SET	7422H
CAP1FIFO.SET	7423H
CAP2FIFO.SET	7424H
CAP3FIFO.SET	7425H
CAP4FIFO.SET	7426H

EVIMRA	.SET	742CH
EVIMRB	.SET	742DH
EVIMRC	.SET	742EH
EVIFRA	.SET	742FH
EVIFRB	.SET	7430H
EVIFRC	.SET	7431H
EVIVRA	.SET	7432H
EVIVRB	.SET	7433H
EVIVRC	.SET	7434H

WSGR    .SET    0FFFFH

;Bit masks used by the SBIT0 & SBIT1 Macros
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
B15_MSK 	.set	8000h		;Bit Mask for 15
B14_MSK 	.set	4000h		;Bit Mask for 14
B13_MSK 	.set	2000h		;Bit Mask for 13
B12_MSK 	.set	1000h		;Bit Mask for 12
B11_MSK 	.set	0800h		;Bit Mask for 11
B10_MSK 	.set	0400h		;Bit Mask for 10
B9_MSK		.set	0200h		;Bit Mask for 9
B8_MSK		.set	0100h		;Bit Mask for 8
B7_MSK		.set	0080h		;Bit Mask for 7
B6_MSK		.set	0040h		;Bit Mask for 6
B5_MSK		.set	0020h		;Bit Mask for 5
B4_MSK		.set	0010h		;Bit Mask for 4
B3_MSK		.set	0008h		;Bit Mask for 3
B2_MSK		.set	0004h		;Bit Mask for 2
B1_MSK		.set	0002h		;Bit Mask for 1
B0_MSK		.set	0001h		;Bit Mask for 0

;BIT CODES FOR TEST BIT INSTRUTION(BIT)

BIT15	.SET	0000H
BIT14	.SET	0001H
BIT13	.SET	0002H
BIT12	.SET	0003H
BIT11	.SET	0004H
BIT10	.SET	0005H
BIT9	.SET	0006H
BIT8	.SET	0007H
BIT7	.SET	0008H
BIT6	.SET	0009H
BIT5	.SET	000AH
BIT4	.SET	000BH
BIT3	.SET	000CH
BIT2	.SET	000DH
BIT1	.SET	000EH
BIT0	.SET	000FH


;INIT TRANMIT DATA FOR INTERRUPT SERVICE ROUTINE

	.DATA
TXDATA	.WORD	0052H
	.WORD	0065H
	.WORD	0061H
	.WORD	0064H
	.WORD	0079H
	.word 	000dh 		;Hex equivalent of ASCII <CR>
	.word 	0000h 		;Hex equivalent of ASCII NULL

INVALID_IP       		
	.word	0049h 		;Hex equivalent of ASCII character 'I'
	.word 	006Eh 		;Hex equivalent of ASCII character 'n'
	.word 	0076h 		;Hex equivalent of ASCII character 'v'
	.word 	0061h 		;Hex equivalent of ASCII character 'a'
	.word 	006Ch 		;Hex equivalent of ASCII character 'l'
	.word 	0069h 		;Hex equivalent of ASCII character 'i'
	.word 	0064h 		;Hex equivalent of ASCII character 'd'
	.word 	0020h 		;Hex equivalent of ASCII (SPACE)
	.word 	0069h 		;Hex equivalent of ASCII character 'i'
	.word 	006Eh 		;Hex equivalent of ASCII character 'n'
	.word 	0070h 		;Hex equivalent of ASCII character 'p'
	.word 	0075h 		;Hex equivalent of ASCII character 'u'
	.word 	0074h 		;Hex equivalent of ASCII character 't'
	.word 	000dh 		;Hex equivalent of ASCII <CR>
	.word 	0000h 		;Hex equivalent of ASCII NULL

GOOD	.word	0074h 		;Hex equivalent of ASCII character 't'
	.word 	0074h 		;Hex equivalent of ASCII character 't'
	.word 	0074h 		;Hex equivalent of ASCII character 't'
	.word 	0074h 		;Hex equivalent of ASCII character 't'
	.word 	0000h 		;Hex equivalent of ASCII NULL

NIGHT	.word	0044h 		;Hex equivalent of ASCII character 'd'
	.word 	0064h 		;Hex equivalent of ASCII character 'd'
	.word 	0064h 		;Hex equivalent of ASCII character 'd'
	.word 	0064h 		;Hex equivalent of ASCII character 'd'
	.word 	0000h 		;Hex equivalent of ASCII NULL

sss	.word	0075h 		;Hex equivalent of ASCII character 'u'
	.word 	0075h 		;Hex equivalent of ASCII character 'u'
	.word 	0075h 		;Hex equivalent of ASCII character 'u'
	.word 	0075h 		;Hex equivalent of ASCII character 'u'
	.word 	0000h 		;Hex equivalent of ASCII NULL


number1	.word	0030h		;Hex equivalent of ASCII character '0'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0031h 		;Hex equivalent of ASCII character '1'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0032h 		;Hex equivalent of ASCII character '2'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0033h 		;Hex equivalent of ASCII character '3'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0034h 		;Hex equivalent of ASCII character '4'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0035h 		;Hex equivalent of ASCII character '5'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0036h 		;Hex equivalent of ASCII character '6'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0037h 		;Hex equivalent of ASCII character '7'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0038h 		;Hex equivalent of ASCII character '8'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0039h 		;Hex equivalent of ASCII character '9'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0041h 		;Hex equivalent of ASCII character 'A'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0042h 		;Hex equivalent of ASCII character 'B'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0043h 		;Hex equivalent of ASCII character 'C'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0044h 		;Hex equivalent of ASCII character 'D'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0045h 		;Hex equivalent of ASCII character 'E'
;	.word 	0000h 		;Hex equivalent of ASCII NULL
;	.word 	0046h 		;Hex equivalent of ASCII character 'F'
	.word 	0000h 		;Hex equivalent of ASCII NULL


KICK_DOG	.MACRO
		LDP	#00E0H
		SPLK	#055H,WDKEY
		SPLK	#0AAH,WDKEY
		LDP	#4
		.ENDM


		.TEXT				
CAP1:		SST 	#0,STK1 			;save ST0 - Forced Page 0
		SST 	#1,STK2 			;save ST1 - Forced Page 0
		LDP	#0
		SACL 	STK3 				;save ACCL
		SACH 	STK4 				;save ACCH

		LDP	#232
		LACC	EVIVRC	
		LDP	#232
		LACC	T2CNT
		LDP	#4
		SACL	T2TEMP
		LACC	T2TEMP
		SUB	#2A00H
		BCND	DO2,LT
		LACC	T2TEMP
		SUB	#3A00H
		BCND	DO2,GT
		LACC	EVIFRC
		SACL	EVIFRC
CAPDO:		LDP	#4
		BIT	KEYMODE,BIT15
		BCND	DO17,TC
		LACC	KEYTEMP3
		BCND	DO18,EQ
		SUB	#1
		SACL	KEYTEMP3
		B	DO17
DO18:		LDP	#232
	     	SPLK	#0000111111111111B,ACTR
		SPLK    #0000100001010111B,COMCON
		
DO17:		LDP	#224
		SPLK    #1110100000001010B,ADCTRL1
	        SPLK    #0000000000000110B,ADCTRL2
		LDP	#4
		LACC	NEWCAMP1
		SACL	CAPTEMP4
		LACC	CAPTEMP4
		SUB	#2A0H
		BCND 	DO4,LT
		LDP	#4
		SACL	CAPTEMP2
		LACC	CAPTEMP2
		SUB	#10H
		BCND	DO11,LEQ
		SPLK	#0,SLOW2
		LACC	CAPTEMP2
		SUB	CAPTEMP1
		BCND	DO2,LEQ
		LDP	#232
		LACC	T1PR
		ADD	#1
		SACL	T1PR
		B	DO2	
DO4:		NEG
		LDP	#4
		SACL	CAPTEMP2
		SPLK	#0,SLOW2
		LACC	CAPTEMP2
		SUB	CAPTEMP1
		BCND	DO2,LEQ	
		LDP	#232
		LACC	T1PR
		SUB     #1	
		SACL	T1PR
		B	DO2
DO11:		LACC	SLOW2
		ADD	#1
		SACL	SLOW2
		SUB	#8
		BCND	DO16,LT

		LDP	#4
		BIT	KEYMODE,BIT15
		BCND	DO16,NTC
		LDP	#232
	        SPLK	#0000100110011001B,ACTR
		SPLK    #1000101001010111B,COMCON

DO16:		LDP	#4
		LACC	CAPTEMP4
		SUB	CAPTEMP5
		BCND	DO2,EQ
		LACC	CAPTEMP4
		SUB	#2A0H
		BCND	DO12,EQ
		LDP	#232
		LACC	T1PR
		SUB     #1	
		SACL	T1PR
		B	DO2
DO12:		LDP	#232
		LACC	T1PR
		ADD     #1	
		SACL	T1PR
DO2:		LDP	#4
		LACC	CAPTEMP2
		SACL	CAPTEMP1
		LACC	CAPTEMP4
		SACL	CAPTEMP5
		LDP	#232
		SPLK	#0,T2CNT
		LACC	T1PR
		SUB	#550H
		BCND	DO21,LT
		LACC	T1PR
 		SUB	#1
		SACL	T1PR
DO21:		LACC	T1PR
		SUB	#510H
		BCND	DO22,GT
		LACC	T1PR
		ADD	#1
		SACL	T1PR
DO22:		LDP	#232
		BIT	COMCON,BIT15
		BCND	DO25,NTC
		LDP	#4	
		LACC	SLOW3
		ADD	#1
		SACL	SLOW3
		SUB	#50
		BCND	DO25,LEQ
		LDP	#4	
		LACC	SLOW1
		SUB	#1
		SUB	#1
		BCND	DO25,LT
		ADD	#1
		SACL	SLOW1
		
DO25:		LDP	#224
ADCLOOP4:	LACC	ADCTRL1
		BIT	ADCTRL1,BIT7
		BCND    ADCLOOP4,TC 		
		LACC	ADCFIFO1
		RPT	#5
		SFR
		LDP	#4
		SACL	U2AD1
		LDP	#0
  		ZALH 	STK4 				; restore ACCH
		ADDS 	STK3 				; restore ACCL
		LST 	#1,STK2 			; restore ST1
		LST 	#0,STK1 			; restore ST0
		CLRC 	INTM 				;Enable Interrupts
		
		RET









		

LIMIT:		LDP	#4
        	LACC	LIMIT1
		ADD	PWMADD
		SUB	#1316
		BCND	LJUDGE1,LT
		SPLK	#28AH,LIMIT1
LJUDGE1:	ADD	#1316
		SUB	#16
		BCND	LJUDGE2,GT
		SPLK	#16,LIMIT1
		LACC	LIMIT1
		SUB	PWMADD
		SACL	LIMIT1
LJUDGE2:	RET					


		
DIVIDSUB:	LDP	#4
		LACC	DIVID1
		BCND	DIVIDSUB1,GT
		NEG
		SACL	DIVID1
		RPT	#15
		SUBC	DIVID2
		SACL	DIVRESULT1
		SACH	DIVRESULT2
		LACC	DIVRESULT1
		NEG	
		SACL	DIVRESULT1
		B   	DIVIDSUB2
DIVIDSUB1:	
		RPT	#15
		SUBC	DIVID2
		SACL	DIVRESULT1
		SACH	DIVRESULT2
DIVIDSUB2:	RET

MPYSUB:		LDP	#4
		LACC	MPY1
		BCND	MPYSUB1,GT
		NEG
		SACL	MPY1
		LT 	MPY1		 		
		MPY 	MPY2				
		PAC 
		NEG
		SACL	MPYRESULT
		B	MPYSUB2
MPYSUB1:	
		LT	MPY1
		MPY 	MPY2
		PAC 
		SACL	MPYRESULT
MPYSUB2:	RET

		
ADWANT05:	NOP			;0.5
		LDP	#4
		LACC	WDATA4
		ADD	WDATA1
		ADD	WDATA1
		SACL	DIVID1
		SPLK	#12,DIVID2
		CALL	DIVIDSUB
		LACC	DIVRESULT1
		SACL	WDATA6
		LACC	WDATA4
		SUB	WDATA3
		SACL	MPY1
		SPLK	#9,MPY2
		CALL	MPYSUB
		LACC	MPYRESULT
		SFR
		SFR
		SFR
		SFR
		SACL 	WDATA7
		LACC	WDATA2
		SUB	WDATA1
		SACL	MPY1
		SPLK	#3,MPY2
		CALL	MPYSUB
		LACC	MPYRESULT
		SFR
		SFR
		SFR
		SFR
		SACL 	WDATA8
		LACC	WDATA4
		ADD	WDATA6
		ADD	WDATA7
		ADD	WDATA8
		SACL	WDATA5
		RET

PWMWANT05:	NOP			;0.5
		LDP	#4
		LACC	TDATA4
		ADD	TDATA1
		ADD	TDATA1
		SACL	DIVID1
		SPLK	#12,DIVID2
		CALL	DIVIDSUB
		LACC	DIVRESULT1
		SACL	TDATA6
		LACC	TDATA4
		SUB	TDATA3
		SACL	MPY1
		SPLK	#9,MPY2
		CALL	MPYSUB
		LACC	MPYRESULT
		SFR
		SFR
		SFR
		SFR
		SACL 	TDATA7
		LACC	TDATA2
		SUB	TDATA1
		SACL	MPY1
		SPLK	#3,MPY2
		CALL	MPYSUB
		LACC	MPYRESULT
		SFR
		SFR
		SFR
		SFR
		SACL 	TDATA8
		LACC	TDATA4
		ADD	TDATA6
		ADD	TDATA7
		ADD	TDATA8
		SACL	TDATA5
		RET

KEYPRESS:	LDP	#0E1H
		LACC	PBDATDIR
		BIT	PBDATDIR,BIT6		;�жϡ�ֹͣ������
		BCND	KEYPRESS2,TC		;���δ����������ж��¸�����
		LDP	#4			;
		LACC	KEYTEMP1		;
		ADD	#1			;��KEYTEMP1�е�ֵ��1
		SACL	KEYTEMP1		;
		SUB	#KEYTEMP2		;��300�Ƚϣ������֮������Ϊ���ˡ�ֹͣ����
		BCND	STOPPRESS,GT		;����ֹͣ�����������
		B	KEYPRESS1		;�����жϣ�������KEYTEMP1��ֵ

KEYPRESS2:	LDP	#0E1H			;
		BIT	PBDATDIR,BIT2		;�жϡ����С�����
		BCND	KEYPRESS3,TC		;���δ��������KEYPRESS3
		LDP	#4			;
		LACC	KEYTEMP1		;
		ADD	#1			;
		SACL	KEYTEMP1		;
		SUB	#KEYTEMP2		;
		BCND	RUNPRESS,GT		;�������а����������
		B	KEYPRESS1		;�����жϣ�������KEYTEMP1��ֵ

KEYPRESS3:	LDP	#0E1H			;
		BIT	PADATDIR,BIT2		;�жϡ�SET������
		BCND	KEYPRESS4,TC		;���δ��������KEYPRESS4
		LDP	#4			;
		LACC	KEYTEMP1		;
		ADD	#1			;
		SACL	KEYTEMP1		;
		SUB	#KEYTEMP2		;
		BCND	SETPRESS,GT		;����SET�����������
		B	KEYPRESS1		;�����жϣ�������KEYTEMP1��ֵ

KEYPRESS4:	LDP	#0E1H			;
		BIT	PBDATDIR,BIT1		;�жϡ�UP������
		BCND	KEYPRESS5,TC		;���δ��������KEYPRESS5
		LDP	#4			;
		LACC	KEYTEMP1		;
		ADD	#1			;
		SACL	KEYTEMP1		;
		SUB	#KEYTEMP2			;
		BCND	UPPRESS,GT		;����UP�����������
		B	KEYPRESS1		;�����жϣ�������KEYTEMP1��ֵ

KEYPRESS5:	LDP	#0E1H			;
		BIT	PADATDIR,BIT3		;�жϡ�RIGHT������
		BCND	KEYPRESS6,TC		;���δ��������KEYPRESS6
		LDP	#4			;
		LACC	KEYTEMP1		;
		ADD	#1			;
		SACL	KEYTEMP1		;
		SUB	#KEYTEMP2			;
		BCND	RIGHTPRESS,GT		;����RIGHT�����������
		B	KEYPRESS1		;�����жϣ�������KEYTEMP1��ֵ

KEYPRESS6:	LDP	#0E1H			;
		BIT	PBDATDIR,BIT0		;�жϡ�DOWN������
		BCND	KEYPRESS7,TC		;���δ��������KEYPRESS7
		LDP	#4			;
		LACC	KEYTEMP1		;
		ADD	#1			;
		SACL	KEYTEMP1		;
		SUB	#KEYTEMP2			;
		BCND	DOWNPRESS,GT		;����DOWN�����������
		B	KEYPRESS1		;�����жϣ�������KEYTEMP1��ֵ

KEYPRESS7:	LDP	#4			;��ʾδ���κμ�����KEYTEMP1ֵ����
		SPLK	#0,KEYTEMP1		;

KEYPRESS1:	RET				;����

;		KEYMODE
;		5432109876543210
;		RS        dutlsr
;               S
;5   : RUN=1 STOP=0
;4 :   SET MODE=1 
;3:




RUNPRESS:	LDP	#0E1H
RUNPRESS1:	CALL	DELAY
		BIT	PBDATDIR,BIT2
		BCND	RUNPRESS1,NTC		;�ȴ���������
		LDP	#4
		SPLK	#0,KEYTEMP1
		SPLK	#1,RUNTAG

		LACC	KEYMODE
		OR	#8001H
		SACL	KEYMODE
		B	SHOWJUDGE

DOWNPRESS:	LDP	#0E1H
DOWNPRESS1:	CALL	DELAY
		BIT	PBDATDIR,BIT0
		BCND	DOWNPRESS1,NTC		;�ȴ���������
		LDP	#4
		SPLK	#0,KEYTEMP1
		LACC	KEYMODE
		OR	#0020H
		SACL	KEYMODE
		B	SHOWJUDGE
			

RIGHTPRESS:	LDP	#0E1H
RIGHTPRESS1:	CALL	DELAY
		BIT	PADATDIR,BIT3
		BCND	RIGHTPRESS1,NTC		;�ȴ���������
		LDP	#4
		SPLK	#0,KEYTEMP1
		LACC	KEYMODE
		OR	#0004H
		SACL	KEYMODE
		B	SHOWJUDGE
	

UPPRESS:	LDP	#0E1H
UPPRESS1:	CALL	DELAY
		BIT	PBDATDIR,BIT1
		BCND	UPPRESS1,NTC		;�ȴ���������
		LDP	#4
		SPLK	#0,KEYTEMP1
		LACC	KEYMODE
		OR	#0010H
		SACL	KEYMODE
		B	SHOWJUDGE

STOPPRESS:	LDP	#0E1H
STOPPRESS1:	CALL	DELAY
		BIT	PBDATDIR,BIT6
		BCND	STOPPRESS1,NTC		;�ȴ���������
		LDP	#4
		SPLK	#0,KEYTEMP1
		SPLK	#1,STOPTAG
	
		LACC	KEYMODE
		OR	#8002H
		SACL	KEYMODE
		B	SHOWJUDGE

SETPRESS:	LDP	#0E1H
SETPRESS1:	CALL	DELAY
		BIT	PADATDIR,BIT2
		BCND	SETPRESS1,NTC		;�ȴ���������
		LDP	#4
		SPLK	#0,KEYTEMP1
		LACC	KEYMODE
		XOR	#4008H			;ʹ�����ָ��Ӷ����Դ�SET�������Ƴ�
		SACL	KEYMODE
		
		B	SHOWJUDGE

;		RUN     #0001H
;		STOP	#0002H
;		UP	#0010H
;		DOWN	#0020H
;		RIGHT   #0004H
;		SET	#0008H

SHOWJUDGE:	LDP	#4
		LACC	KEYMODE
		
		BCND	STOPSHOW,EQ

		SUB	#8000H
		BCND	RUNSHOW1,EQ
		
		ADD	#8000H
		SUB	#8008H
		BCND	RUNSHOW1,EQ

		ADD	#8008H
		SUB	#0008H
		BCND	STOPSHOW,EQ

		ADD	#0008H
		SUB	#8002H			;JUDGE IF PRESS STOP IN RUN MODE
		BCND	STOPSHOW,EQ

		ADD	#8002H
		SUB	#8001H			;JUDGE IF PRESS RUN
		BCND    RUNSHOW1,EQ
		
	
		ADD	#8001H			;JUDGE	IF PRESS SET IN STOP MODE
		SUB	#4008H
		BCND	SETSHOW1,EQ		
		
		ADD	#4008H			;JUDGE IF PRESS SET IN RUN MODE
		SUB	#0C008H
		BCND	SETSHOW5,EQ



		ADD	#0C008H			;
		SUB	#8020H			;JUDGE IF PRESS DOWN IN RUN MODE
		BCND	RUNSHOW2,EQ		;SHOW SECOND DATA
		
		ADD	#8020H
		SUB     #4020H			;JUDGE IF PRESS DOWN IN  SET(STOP) MODE
		BCND	SETSHOW2,EQ


		ADD	#4020H
		SUB	#0C020H
		BCND	SETSHOW2,EQ


		ADD	#0C020H
		SUB     #8010H			;JUDGE IF PRESS UP  IN RUN MODE
		BCND	RUNSHOW1,EQ		;SHOW  FIRST DATA
		
		ADD	#8010H			
		SUB 	#4010H			;JUDGE IF PRESS UP IN SET MODE
		BCND 	SETSHOW3,EQ

		ADD	#4010H
		SUB	#0C010H
		BCND	SETSHOW3,EQ

		ADD	#0C010H
		SUB	#4004H			;JUDGE IF PRESS RIGHT IN SET MODE
		BCND	SETSHOW4,EQ

		ADD	#4004H
		SUB	#0C004H
		BCND	SETSHOW4,EQ

		ADD	#0C004H
		AND	#0FF00H			;LET THE KEYMODE LOW 8 BITS=0
		SACL	KEYMODE		
		B	KEYPRESS1
		
		
		
RUNSHOW1:	CALL	CLEAR
		CALL	RUN_SHOW1
;		CALL	DATA_SHOW1
		LDP	#4
		SPLK	#8000H,KEYMODE		;NOW IS IN RUN MODE
		B	KEYPRESS1

RUNSHOW2:	CALL	CLEAR
		CALL	RUN_SHOW2
;		CALL	DATA_SHOW2
		LDP	#4
		SPLK	#8000H,KEYMODE		;NOW IS IN RUN MODE
		B	KEYPRESS1



STOPSHOW:	CALL 	CLEAR
		CALL 	STOP_SHOW
		LDP	#4
		SPLK	#0000H,KEYMODE		;NOW IS IN STOP MODE
		B	KEYPRESS1

SETSHOW5:	CALL	CLEAR
		CALL	SET_SHOW1
		CALL	DATA_SHOW1
		LDP	#4
		SPLK	#0C000H,KEYMODE
		B	KEYPRESS1



SETSHOW1:	CALL	CLEAR
		CALL	SET_SHOW1
		CALL	DATA_SHOW1
		LDP	#4
		SPLK	#4000H,KEYMODE
		B	KEYPRESS1

SETSHOW2:	CALL	CLEAR
		CALL	SET_SHOW1
		LDP	#4
		LACC	KEYTEMP3
		BCND	SETSHOW21,EQ
		SUB	#1
		SACL	KEYTEMP3
SETSHOW21:	CALL	DATA_SHOW1
		B	KEYPRESS1



SETSHOW3:	CALL	CLEAR
		CALL	SET_SHOW1
		LDP	#4
		LACC	KEYTEMP3
		ADD	#01H
		SUB	#30
		BCND	SETSHOW31,GT
		ADD	#30
		SACL	KEYTEMP3
SETSHOW31:	CALL	DATA_SHOW1
		B	KEYPRESS1

SETSHOW4:	CALL	CLEAR
		CALL	SET_SHOW1	
		CALL	DATA_SHOW1
		B	KEYPRESS1


INT1_ISR:	LDP 	#00E0h 		;DP = 224 Address 7000h-707Fh
		LACL 	SYSIVR 		;Load peripheral INT vector address
		LDP 	#0000h 		;DP = 0 Addresses 0000h-007Fh
		SUB	#0006h 		;Subtract RXINT offset from above
		BCND 	RX_ISR,EQ 	;verify RXINT initiated interrupt
		B 	BAD_INT 	;Else, bad interrupt occurred

RX_ISR: 	LDPK    #224
	        NOP
	        SPLK    #0000000000000111B,ADCTRL2
		MAR 	*,AR1 		;ARP = AR1
		LACC 	* 		;Load ACC w/RX buffer character
		BIT 	*,BIT6,AR3 	;Determine if the character is a letter
		BCND 	NUMBER,NTC
		AND 	#01011111b 	;If a letter, capitalize the letter
NUMBER:	 	SACL 	*+ 		;Store the character/number
IP_VALUE:	SUB 	#000Dh 		;Check to see if <CR>
		BCND 	CHECK_IP,EQ 	;If value entered is a <CR>, then process input
		B 	NO_IP 		;else, wait until <CR> is pressed
CHECK_IP:	LAR 	AR3,#B0_SADDR 	;AR3 = Address of first value entered
		LACC 	*+ 		;ACC = ASCII equivalent of value
		SUB  	#0046h 		;Check to see if ASCII letter 'F'
		BCND 	FREQ_CHG,EQ 	;If 'F' goto routine to change frequency
		ADD 	#0046h
		SUB 	#0050h 		;Check to see if ASCII letter 'P'
		BCND 	PHASE_CHG,EQ 	;If 'P' goto routine to change frequency
		ADD 	#0050h
		SUB 	#004Dh 		;Check to see if ASCII letter 'M'
		BCND 	MAG_CHG,EQ 	;If 'M' goto routine to change frequency
		ADD 	#004Dh
		SUB 	#000Dh 		;Check to see if ASCII <CR>
		BCND 	SCI_ISR,EQ 	;If <CR>, output "Ready"
		B 	BAD_IP
		B 	ISR_END 	;If neither a 'F','P','M',or<CR>,then do nothing

BAD_IP:		LAR 	AR2,#(B1_SADDR+LENGTH1) ;Address to output "Invalid Input"

SCI_ISR: 	MAR 	*,AR2 		;ARP = AR2
		LDP 	#00E0h 		;DP = 224 Addresses 7000h-707Fh
XMIT_CHAR: 	LACC 	*+,AR0 		;Load char to be xmitted into ACC
		BCND 	ISR_END,EQ 	;Check for Null Character YES? Return from INT1_ISR.
		SACL 	*,AR2 		;NO? Load char into xmit buffer.

XMIT_RDY: 	BIT 	SCICTL2, BIT7 	;Test TXRDY bit
		BCND 	XMIT_RDY, NTC 	;If TXRDY=0,then repeat loop
		B 	XMIT_CHAR 	;else xmit next character

ISR_END: 	LAR 	AR2, #B1_SADDR 	;Reload AR2 w/ TX data start address
		LAR 	AR3, #B0_SADDR 	;Reload AR3 w/ RX data start address
           	LDP 	#00E0h 		;DP = 224 Addresses 7000h-707Fh
		LACC 	#0Ah 		;Cause a line feed in the terminal
		SACL 	SCITXBUF 	;transmit the line feed
		LDP 	#0 		;DP = 0 Addresses 0000h-007Fh
		CLRC 	INTM 		;Enable Interrrupts
		RET 			;Return from INT1_ISR

NO_IP: 		LAR 	AR2, #B1_SADDR 	;Reload AR2 w/ TX data start address
		LDP 	#0 		;DP = 0 Addresses 0000h-007Fh
		CLRC 	INTM 		;Enable Interrupts
		RET 			;Return from interrupt

BAD_INT: 	LACC 	#0BADh 		;Load ACC with "bad"
		B 	BAD_INT 	;Repeat loop

;ISR    PHANTOM


FREQ_CHG:	LDP	#224
		SPLK    #1111110001110001B,ADCTRL1
WAITAD1:	LACC    ADCTRL1
    		LACC    ADCTRL2
		BIT	ADCTRL1,BIT7
		BCND    WAITAD1,NTC 
		NOP
		LDP	#224
		LACC	ADCFIFO1
		RPT     #9
		SFR
		LDP     #00E0H
		SACL	SCITXBUF
XMIT_RDY1: 	BIT 	SCICTL2, BIT7 	;Test TXRDY bit
		BCND 	XMIT_RDY1, NTC 	;If TXRDY=0,then repeat loop
		
		LDP	#224
		LACC	ADCFIFO1
		AND	#0000001111111111B
		RPT	#5
		SFR
		LDP     #00E0H
		SACL	SCITXBUF
XMIT_RDY2: 	BIT 	SCICTL2, BIT7 	;Test TXRDY bit
		BCND 	XMIT_RDY2, NTC 	;If TXRDY=0,then repeat loop

		LAR 	AR2,#(B1_SADDR+LENGTH3) ;Address to output "Invalid Input"
		B 	SCI_ISR

PHASE_CHG:	LDP	#224
		SPLK    #1111110001110001B,ADCTRL1
WAITAD2:	LACC    ADCTRL1
    		LACC    ADCTRL2
		BIT	ADCTRL1,BIT7
		BCND    WAITAD2,NTC 
		NOP
		LDP	#224
		LACC	ADCFIFO2
		RPT     #9
		SFR
		LDP     #00E0H
		SACL	SCITXBUF
XMIT_RDY3: 	BIT 	SCICTL2, BIT7 	;Test TXRDY bit
		BCND 	XMIT_RDY3, NTC 	;If TXRDY=0,then repeat loop
		
		LDP	#224
		LACC	ADCFIFO2
		AND	#0000001111111111B
		RPT	#5
		SFR
		LDP     #00E0H
		SACL	SCITXBUF
XMIT_RDY4: 	BIT 	SCICTL2, BIT7 	;Test TXRDY bit
		BCND 	XMIT_RDY4, NTC 	;If TXRDY=0,then repeat loop


		NOP
		LAR 	AR2,#(B1_SADDR+LENGTH3) ;Address to output "dddd"
		B 	SCI_ISR


MAG_CHG:	NOP
		LAR 	AR2,#(B1_SADDR+LENGTH4) ;Address to output "tttt"
		B 	SCI_ISR


DELAY:		NOP
		LACC	#5000
DELAY1:		SUB	#1
		BCND	DELAY1,GT
		RET