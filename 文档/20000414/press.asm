;���ǵ�Ŀǰ�ı���ٶȺ��Ѷȣ����������Ϊ����Ӧ���м��ͷ������
	.BSS	RUNNUM,1		;������������
	.BSS	STOPNUM,1		
	.BSS 	SETNUM,1		
	.BSS	RIGHTNUM,1
	.BSS	LEFTNUM,1
	.BSS	UPNUM,1
	.BSS	DOWNNUM,1
	.BSS	KEYSET,1		;���ܼ�����
	.BSS	KEYRIGHT,1
	.BSS	KEYUP,1
	.BSS	KEYDOWN,1
	.BSS	KEYDATA,1		;����������
	.BSS	KEYMODE,1		;����״̬��־����
	.BSS	KEYCOUNT,1		;������������
COSTANT1	.SET	#300		;����������

;���밴��������Щ�����
;����������ǰ����ʱ��ʾʲô���ݣ���Ӧ��Щ������
;��ӦRUN��
;����������ʱ����ӦSTOP����
;
;
;
;RUN--IOPB0   STOP--IOPB1
;
;   
;
OCRA    .SET    07090H
OCRB    .SET    07092H
PADATDIR.SET    07098H 
PBDATDIR.SET    0709AH
PCDATDIR.SET    0709CH
PDDATDIR.SET    0709EH
ISRA    .SET    07094H
ISRB    .SET    07096H

	.TEXT
START:	LDP     #0E1H                 
	SPLK	#0000H,OCRA
	SPLK	#0000H,OCRB    
MAIN:	CALL	KEYPRESS
	CALL	SHOW
	B	MAIN
	
KEYPRESS:	LDP	#0E1H
		BIT	PBDATDIR,BIT1		;�жϡ�ֹͣ������
		BCND	KEYPRESS2,NTC		;���δ����������ж��¸�����
		LDP	#04			;
		LACC	KEYCOUNT		;
		ADD	#1			;��KEYCOUNT�е�ֵ��1
		SACL	KEYCOUNT		;
		SUB	#COSTANT1		;��300�Ƚϣ������֮������Ϊ���ˡ�ֹͣ����
		BCND	STOPPRESS,GT		;����ֹͣ�����������
		B	KEYPRESS1		;�����жϣ�������KEYCOUNT��ֵ
KEYPRESS2:	LDP	#0E1H			;
		BIT	PBDATDIR,BIT0		;�жϡ����С�����
		BCND	KEYPRESS3,NTC		;���δ��������KEYPRESS3
		LDP	#04			;
		LACC	KEYCOUNT		;
		ADD	#1			;
		SUB	#CONSTANT1		;
		SACL	KEYCOUNT		;
		BCND	RUNPRESS,GT		;�������а����������
		B	KEYPRESS1		;�����жϣ�������KEYCOUNT��ֵ
KEYPRESS3:	LDP	#04			;��ʾδ���κμ�����KEYCOUNTֵ����
		SPLK	#0,KEYCOUNT		;
KEYPRESS1:	RET				;����




RUNPRESS:	LDP 	#4
		SPLK	#0,KEYCOUNT
		CALL	RUNSHOW
;;
;;;;		�˴��������е��ӳ���
;;;;
		B	MAIN


STOPPRESS:	LDP	#04
		SPLK	#0,STOPNUM
		CALL	STOPSHOW
;;
;;		�˴�����ֹͣ���е��ӳ���
;;
		B	MAIN

RUNSHOW:	SPLK   