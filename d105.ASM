; THIS IS  TEST PROGRAM===d105.ASM

	        .INCLUDE   "INIT105.H"		;����������壬ͬ�������Լ�һЩ�ӳ���
        	.INCLUDE   "PWM.H"		;����85%��25%��������85%��������ͬ�������Լ�������΢����25%�������񣬸ñ��������������
		.INCLUDE   "PWMS105.H"		;����PWM��ʱ���ж��ӳ���
		.INCLUDE   "SHOW105.H"		;����LCD��ʾ��ͨ���ӳ���ͱ�������


                .SECT   ".VEC"
RSVECT		B	START			;��������ʼ
INT1            B       DD        		;�ж�1����ʱδ��
INT2            B       LOADCOUNT		;PWM��ʱ���ж�
INT3            B       DD			;δ��
INT4		B	CAP1			;ͬ����׽�ж�
INT5		B	RS232			;RS232ͨѶ�ж�
         
		.BSS	DIVID1,1		;�����������ڳ����ӳ���
		.BSS	DIVID2,1		;���������ڳ����ӳ���
		.BSS	DIVRESULT1,1		;�̣����ڳ����ӳ���
		.BSS	DIVRESULT2,1		;���������ڳ����ӳ���
		.BSS	MPY1,1			;�����������ڳ˷��ӳ���
		.BSS	MPY2,1			;���������ڳ˷��ӳ���
		.BSS	MPYRESULT,1		;�˻������ڳ˷��ӳ���
	       	.BSS   	PWMADDRESS,1		;PWM������ʼ���ݵ�ַ
		.BSS	PWMADDRESS1,1		;PWM9������ʼ���ݵ�ַ
		.BSS	PWMADDRESS4,1		;��������ѹ������ʼ���ݵ�ַ
		.BSS	SPWM2,1			;�͵�����ѹ���Ӧ���������Ե���������ѹ
		.BSS	SPWM1,1			;������������趨ֵ���Ӧ��PI�������ڵ���ϵ��
		.BSS	ADCALU1,1		;������ʱ�洢��������趨ֵ��Ӧ�ı������ݣ���PWMCOUNT3���Ӧ
	       	.BSS	PWMCOUNT1,1		;����ָ��1������
		.BSS	PWMCOUNT2,1		;����ָ��2������
		.BSS	PWMCOUNT3,1		;����ָ��3������
		.BSS	PWMCOUNT4,1		;����ָ��4�����ڶ������ʱ��׼��ѹ����
		.BSS	PWMADD,1		;PWM������м�ֵ��EVERY PWM PULSE ADD VALUE=T/4;WHEN T=20/150MS  PWMADD=666
		.BSS	ADDATA,1		;AC CURRENT �������������A/Dֵ
		.BSS	ADDATA1,1		;AC CURRENT ������������ĵ�һ��A/Dֵ
		.BSS	ADDATA2,1		;AC CURRENT ������������ĵڶ���A/Dֵ
		.BSS	ADDATA3,1		;ADDATA3����ѡ��AC CURRENT A/D ���̵��ݴ�ֵ
		.BSS	ADDATA4,1		;ͬ��
		.BSS	ADDATA5,1		;ͬ��
		.BSS	NEWCAMP1,1		;85%PWM�������ݣ�����ͬ������
		.BSS	NEWCAMP7,1		;�洢�����������΢��ʱ85%PWM��������
		.BSS	NEWCAMP2,1		;�����������΢��ʱ���ֵ
		.BSS	NEWCAMP21,1		;�����������΢��ʱ�����м�ֵ
		.BSS	NEWCAMP,1		;������������趨ֵ��PWM����
		.BSS	NEWCAMP3,1		;����������������м�ֵ
		.BSS	NEWCAMPT1,1		;�����������΢��ʱ���л��ּ�����м�ֵ
		.BSS	NEWCAMPT2,1		;�����������������������
		.BSS	SLOW2,1			;����ͬ�����򣬵�SLOW=8��������8��ͬ����׼�󣬲Ŵ�PWM��
		.BSS	SLOW3,1			;�������������������
		.BSS	T2TEMP,1		;������ʱ�������ͬ������֮���ʱ���� 
		.BSS	CAPTEMP1,1		;����ͬ������
		.BSS	CAPTEMP2,1		;ͬ��
		.BSS	CAPTEMP3,1		;ͬ��
		.BSS	CAPTEMP4,1		;ͬ��
		.BSS	CAPTEMP5,1		;ͬ��
		.BSS	FDATA1,1		;���ڽ���΢���Ļ��ֵ��ڻ���
		.BSS	FDATA2,1		;ͬ��
		.BSS	FDATA3,1		;ͬ��	
		.BSS	FDATA4,1		;ͬ��
		.BSS	WDATA1,1		;�洢�������������A/Dֵ����ȥ���м�ֵ��1
		.BSS	WDATA2,1		;�洢�������������A/Dֵ����ȥ���м�ֵ��2
		.BSS	WDATA3,1		;�洢�������������A/Dֵ����ȥ���м�ֵ��3
		.BSS	WDATA4,1		;�洢�������������A/Dֵ����ȥ���м�ֵ��4
		.BSS	WDATA5,1		;�����������������A/DֵԤ������	
		.BSS	WDATA6,1		;ͬ��
		.BSS	WDATA7,1		;ͬ��
		.BSS	WDATA8,1		;ͬ��
		.BSS	PWMK2,1			;���������������΢�����ּ����ϵ��
STK1		.usect "B2",1			;�����жϳ������ʱ�����ֳ�
STK2 		.usect "B2",1			;ͬ��		
STK3 		.usect "B2",1			;ͬ��
STK4 		.usect "B2",1			;ͬ��
INDCCUR1	.USECT "B2",1			;ǰ������ֱ������
INDCCUR2	.USECT "B2",1			;������ֱ������
		.BSS	LIMIT1,1		;���������޷��ӳ���
		.BSS	PWMAD1,1		;�洢������������ĵ�һ��A/Dֵ
		.BSS	PWMAD2,1		;�洢������������ĵڶ���A/Dֵ
		.BSS	PWMAD,1			;�洢�����������A/D�����������ֵ
		.BSS	TDATA1,1		;���ڷ��͵���������ѹ��������ȵ�Ԥ����1/2T������
		.BSS	TDATA2,1		;ͬ��
		.BSS	TDATA3,1		;ͬ��
		.BSS	TDATA4,1		;ͬ��
		.BSS	TDATA5,1		;ͬ��
		.BSS	TDATA6,1		;ͬ��
		.BSS	TDATA7,1		;ͬ��
		.BSS	TDATA8,1		;ͬ��
		.BSS	PWMM1,1			;���ڼ������������ѹ��������ȵ�A/Dֵ��ת��ϵ��
		.BSS	U2AD1,1			;��ֱ����ѹA/Dֵ
		.BSS	U2K1,1			;���ڼ���������������趨ֵ��PWMֵNEWCAMP��ϵ��
		.BSS	ADK1,1			;������������趨ֵ���Ӧ��PI�������ڵ���ϵ��
		.BSS	SETCURRENT1,1		;ʵ����������ĸ�������ֵ
		.BSS	AD1MID,1		;���������ѹ������������A/Dת���м�ֵAC VOL  AD BASE
		.BSS	AD2MID,1		;�����������A/Dת���м�ֵ	AC CUR  AD BASE
		.BSS	KEYTEMP1,1		;����������������
		.BSS	KEYTEMP3,1		;�趨������
		.BSS	KEYTEMP4,1		;�趨λ�ü�����
KEYTEMP2	.SET	400			;��������������
		.BSS	KEYMODE,1		;����״̬��־
		.BSS	SHOWMODE,1		;��ʾ��״̬��־	
		.BSS	OUTDATA,1		;��ʾ������ݣ�������ʾ��ʼ��
		.BSS	SHOWCOM,1		;�ӳ����е���ʾ����
		.BSS	SHOWDAT,1		;�ӳ����е���ʾ����
		.BSS	SHOWTEMP1,1		;ҳ���ַ�ݴ���
SHOWPD1		.SET	0032H			;Һ����������
		.BSS	SHOWTEMP2,1		;�ַ���ģ���׵�ַ
		.BSS	SHOWCOLUMN,1		;LCD�е�ַ
		.BSS	SHOWPAGE,1		;LCDҳ��ַ
		.BSS	SHOWCODE,1		;�ַ�����Ĵ���
		.BSS	SHOWCOUNT1,1		;��ʾ������
		.BSS	SHOWTEMP3,1		;������ַ�Ĵ���
		.BSS	KEYTEMP31,1		;���ڴ洢�趨������ʾֵ��ʮλ����
		.BSS	KEYTEMP32,1		;���ڴ洢�趨������ʾֵ�ĸ�λ����
		.BSS	DCVOL1,1		;�����ֱ����ѹ
		.BSS	DCVOLLIM1,1		;�����ֱ����ѹ�Ĺ�������
		.BSS	DCVOLLIM2,1		;�����ֱ����ѹ�Ĺ�������
		.BSS	OUTTAG,1		;���������־��Ԫ,1��ʾ�������״̬,0��ʾֹͣ�������״̬
		.BSS	ACVOL2,1		;�������ʱ����Ľ�����ѹֵ
		.BSS	ACVOL21,1		;�������ʱ����Ľ�����ѹֵ��ʱ1
		.BSS	ACVOL22,1		;�������ʱ����Ľ�����ѹֵ��ʱ2		
		.BSS	AD3MID,1		;�������ʱ����Ľ�����ѹֵ�м�ֵ
		.BSS	PDATA1,1		;���ڶ�������ѹ���ڵĻ��ֻ���
		.BSS	PDATA3,1
		.BSS	ACVOLDAT1,1		;�Ӷ������ʱ����Ľ�����ѹ�����ж�����ֵ
		.BSS	ACVOLDAT2,1
		.BSS	ACVOLDAT3,1
		.BSS	ACVOLDAT4,1
		.BSS	ACVOLDAT5,1
		.BSS	ACVOLDAT6,1
		.BSS	VDATA1,1
		.BSS	VDATA2,1
		.BSS	VDATA3,1
		.BSS	VDATA4,1
		.BSS	ACVOLK1,1
		.BSS	ACVOLK2,1
		.BSS	ACVOLK4,1		;��ѹ����ʱ���ֻ��ڵ�ϵ��
		.BSS	LIMIT2,1		;�������������޷��жϸ����Ĵ���
		.BSS    ACVOLAVE,1		;�������ɼ���ѹ��ʵ��ƽ��ֵ
		.BSS	ACVOLSET,1		;�������ɼ���ѹ��ƽ��ֵ�ĸ���ֵ
		.BSS	ACVOLCOU,1		;�������ɼ���ѹ���ۻ�ֵ
		.BSS	ACLEAVE,1		;���ڶ������ʱPI����ʱ���ֻ��ڵĳ���������
		.BSS	PWMCOUNT5,1		;���ڶ������ʱÿ��75��PI����һ��
		.BSS	ACLEAVE1,1		;���ڶ������ʱPI���ڳ���������
		.BSS	DCVOL1AVE,1
		.BSS	DCVOL1NO,1
		.BSS	DCVOL1USE,1
		.BSS	DATA_S,1
		.BSS	DATA_D2,1
		.BSS	DATA_D3,1
		.BSS	DATA_D4,1
		.BSS	D_INCUR,1
		.BSS	RUNTAG,1
LENGTH1 .SET    00007H				;����RS232����ͨѶ
LENGTH2	.SET	00016H				;����RS232����ͨѶ
LENGTH3	.SET	0001BH				;����RS232����ͨѶ		
LENGTH4 .SET	00020H				;����RS232����ͨѶ
B2_SADDR.SET    00060H				;����RS232����ͨѶ
B0_SADDR.SET    00200H				;����RS232����ͨѶ
B1_SADDR.SET	00300H				;����RS232����ͨѶ
		
		
	.TEXT
	NOP
START:	SETC  	INTM				;�ر��ж�
	CLRC	SXM				;SXM��ʶ����ʱ�Ƿ�Ϊ�з�������CLRC ��ʾΪ�޷�����
	CLRC	OVM				;
	CLRC	CNF				;
	LDP	#00E0H				;
	SPLK	#006FH,WDCR			;�رտ��Ź�
        NOP
	KICK_DOG				;���Ź���������λ
	LDP     #0
	NOP
        SPLK    #001AH,IMR			;ʹ�� INT4 AND INT2 and int5
        NOP
        LACC    IFR				;
	NOP
	NOP
        SACL    IFR				;����жϼ�¼
	NOP
	NOP



	LDP	#00E1H
	SPLK	#00H,OCRA
	SPLK	#01CH,OCRB

	CALL	STARTDELAY1

	LACC	PCDATDIR
	AND	#0FEFFH
	SACL	PCDATDIR
	BIT	PCDATDIR,BIT0
	BCND	START1,NTC
	LDP	#0E0H
	LACC	SYSCR
	OR	#08000H
	SACL	SYSCR
	
	LDP	#0E1H
	BIT	PADATDIR,BIT1
	BCND	START1,NTC
	LDP	#0E0H
	LACC	SYSCR
	OR	#08000H
	SACL	SYSCR


	LDP	#0E1H
	BIT	PCDATDIR,BIT6
	BCND	START1,NTC
	LDP	#0E0H
	LACC	SYSCR
	OR	#08000H
	SACL	SYSCR



START1:	NOP
	LDP	#00E1H
	LACC	PBDATDIR
	AND	#1011100011111111B		;��PB.0(DOWN) and  PB.1(^) and PB.2(RUN) PB.6(STOP)  ��Ϊ����
	SACL	PBDATDIR

	LACC	PADATDIR
	AND	#1111001111111111B		;��PA.2(SET) and  PA.3(>)  ��Ϊ����
	SACL	PADATDIR

	LDP	#00E1H
	LACC	PCDATDIR			;��PC.5��Ϊ����ˣ�����ǰ�������
	OR	#0010000000100000B
	SACL	PCDATDIR			;����ʱ���Ϊ1,����ǰ��


	LDP	#4
	SPLK	#0,KEYMODE			;��ʼ��  keymode=00h
	SPLK	#0,KEYTEMP3			;��ʼ��  KEYTEMP3=0H	
	SPLK	#0,KEYTEMP4			;��ʼ��  KEYTEMP4=0H

	LDP	#0E0H	
	SPLK 	#0000000001100000b,CKCR1
	SPLK 	#0000000000000001b,CKCR0	; Disable PLL
	NOP
	NOP
	SPLK 	#0000000011000001b,CKCR0	; Re-enable PLL

	LDP	#224
	NOP
	NOP
	SPLK	#00H,XINT3CR			;pwm 2 the uv singal

	LDP	#0E1H
	LACC	PADATDIR
	OR	#0200H
	AND	#0FFFDH
	SACL	PADATDIR			;�������̵�����

	LDP	#0E1H
	LACC	PCDATDIR
	OR	#04000H
	AND	#0FFBFH
	SACL	PCDATDIR			;�����̵�����

	

	LDP	#0E0H
	SPLK	#00H,SPIPC2			;����SPISIMO,SPISOMI��������Ϊ��׼��������
;--------------------------------------------------------------------
;	SCI ����ͨѶ�жϵĳ�ʼ�� ��Ŀǰδʹ�ã�
;--------------------------------------------------------------------

SCI_INIT:	LDP	#00E0H
		SPLK	#0037H,SCICCR
		SPLK	#0013H,SCICTL1
		SPLK	#0002H,SCICTL2
		SPLK    #0000H,SCIHBAUD
 		SPLK    #0040H,SCILBAUD 	;RATE=19200B/S
		SPLK    #0022H,SCIPC2
		SPLK	#0033H,SCICTL1
		SPLK	#01100000B,SCIPRI
		LAR	AR0,#SCITXBUF
		LAR	AR1,#SCIRXBUF
		LAR   	AR2,#B1_SADDR 		;Load AR2 with TX data start address
 		LAR 	AR3,#B0_SADDR

;--------------------------------------------------------------------
;	����PWMģ��
;--------------------------------------------------------------------

	LDP     #232
	NOP
	SPLK	#03H,T2CNT			;�趨T2Ϊͬ��������ʱ�䣬��Ϊ�����ĵ�ѹ����
	SPLK	#0FFFFH,T2PR
	SPLK	#07FFFH,T2CMPR			;20MS =30D4H(1/32 CPUCLK)
	NOP
	NOP
	SPLK    #1001010101000000B,T2CON	;T2��ʱ���Ŀ����趨
	NOP
	SPLK	#1010000010000000B,CAPCON	;ʹ�ܲ�׽�ж�
	SPLK	#0000100110011001B,ACTR		;�趨�ĸ�PWM������ŵ���Ч��ƽ
	NOP
	NOP
        SPLK    #1110000000101010B,GPTCON	;�趨GP��ʱ�����ƼĴ���	
	NOP
	NOP
	SPLK	#0000010111111000B,DBTCON	;�����趨��ʹ����X/8��CPUʱ��Ƶ�ʣ�����Ϊ2ms
	NOP
	NOP
	SPLK	#0535H,T1PR			;�趨PWM��ʱ��������ʱ�䣬��Ϊʹ�����ĶԳƵ�PWM��ʽ��������ֵΪʵ��ֵ��1/2
	NOP
	NOP
	SPLK    #0081H,EVIMRA			;ʹ�� the int of cmpr1 and pdpint.
	SPLK	#0001B,EVIMRC			;ʹ��CAP1�ж�		
	NOP
        SPLK    #0A802H,T1CON			;T1��ʱ���Ŀ����趨
	NOP
        SPLK    #0A842H,T1CON			;����T1��ʱ��
	NOP
	NOP
        SPLK    #0000100001010111B,COMCON	;�����趨ȫ�ȽϹ��ܼĴ���
	NOP
	NOP
;--------------------------------------------------------------------
;	������е�EV�¼��ж�
;--------------------------------------------------------------------

	LDP	#232
	NOP
	LACC	EVIFRA
	NOP
	SACL	EVIFRA
	NOP
	LACC	EVIFRB
	NOP
	SACL	EVIFRB
	NOP
	LACC	EVIFRC
	NOP
	SACL	EVIFRC
	NOP
;--------------------------------------------------------------------
;	��ʾ�ĳ�ʼ������ʾͣ����Ϣ
;------------------------------------------------------------------


	CALL	SHOWINT			;������ʾ��ʼ���ӳ���
	CALL	CLEAR			;���������ӳ���
	CALL    STOP_SHOW		;����ֹͣ״̬��ʾ�ӳ���

;--------------------------------------------------------------------
;	�����ĳ�ʼ��
;--------------------------------------------------------------------

	LDP	#4
	SPLK	#0,SLOW2
	SPLK	#0,VDATA1
	SPLK	#0,VDATA2
	SPLK	#0,VDATA3
	SPLK	#0,VDATA4
	SPLK	#0,ACVOLDAT1
	SPLK	#0,ACVOLDAT2
	SPLK	#0,ACVOLDAT3
	SPLK	#0,ACVOLDAT4
	SPLK	#0,ACVOLDAT5
	SPLK	#0,ACVOLDAT6
	SPLK	#0,FDATA1
	SPLK	#0,FDATA2
	SPLK	#0,FDATA3
	SPLK	#0,FDATA4
	SPLK	#0,WDATA1
	SPLK	#0,WDATA2
	SPLK	#0,WDATA3
	SPLK	#0,WDATA4
	SPLK	#0,WDATA5	
	SPLK	#0,WDATA6
	SPLK	#0,WDATA7
	SPLK	#0,WDATA8
	SPLK	#0,ADDATA1
	SPLK	#0,ADDATA2
	SPLK	#0,ADDATA3
	SPLK	#0,ADDATA4
	SPLK	#0,ADDATA5
	SPLK	#0,SPWM2
	SPLK	#0,ADCALU1
	SPLK	#0,LIMIT1
	SPLK	#0,PWMAD1
	SPLK	#0,PWMAD2
	SPLK	#0,PWMAD
	SPLK	#0,TDATA1
	SPLK	#0,TDATA2
	SPLK	#0,TDATA3
	SPLK	#0,TDATA4
	SPLK	#0,TDATA5
	SPLK	#0,TDATA6
	SPLK	#0,TDATA7
	SPLK	#0,TDATA8
	SPLK	#0,VDATA1
	SPLK	#0,VDATA2
	SPLK	#0,VDATA3
	SPLK	#0,VDATA4
	SPLK	#0,U2AD1
	SPLK	#0,SETCURRENT1
	SPLK	#0,NEWCAMP2
	SPLK	#0,NEWCAMP21
	SPLK	#0,NEWCAMP7
	SPLK	#0,NEWCAMP3
	SPLK	#0,NEWCAMPT1
	SPLK	#0,KEYTEMP31
	SPLK	#0,KEYTEMP32
	SPLK	#0,T2TEMP			;T2TEMP������ʱ�������ͬ������֮���ʱ���� 
	SPLK	#0,ACVOLAVE			;�������ɼ���ѹ��ʵ��ƽ��ֵ
	SPLK	#0,DCVOL1AVE
	SPLK	#0,DCVOL1NO
	SPLK	#198,ACVOLSET			;�������ɼ���ѹ��ƽ��ֵ�ĸ���ֵ
	SPLK	#0,ACVOLCOU			;�������ɼ���ѹ���ۻ�ֵ

	SPLK	#666,PWMADD	
	SPLK	#6,SPWM1	
	SPLK	#45,ADK1
	SPLK	#504,AD1MID
	SPLK	#513,AD2MID	
	SPLK	#507,AD3MID
	SPLK	#7,U2K1
	SPLK	#0100H,PWMK2
	SPLK	#25,PWMM1
	SPLK    #0,PWMCOUNT1			;ָ��1��ʼֵ
	SPLK	#103,PWMCOUNT3			;ָ��3��ʼֵ
	SPLK	#142,PWMCOUNT2			;ָ��2��ʼֵ
	SPLK	#0,PWMCOUNT4
	SPLK	#0,PWMCOUNT5
	SPLK	#SINWAVE,PWMADDRESS		;����1�ĵ�ַ
	SPLK	#SINWAVE1,PWMADDRESS1		;����2�ĵ�ַ
	SPLK	#ACVDAT,PWMADDRESS4		;����4�ĵ�ַ
	SPLK	#635,DCVOLLIM1			;ֱ����ѹ�Ĺ�������
	
	SPLK	#840,DCVOLLIM2			;ֱ����ѹ�Ĺ�������
	
	SPLK	#1,ACVOLK1
	SPLK	#8,ACVOLK2

	SPLK	#16,ACVOLK4
	SPLK	#0,OUTTAG			;��������һ��Ϊֹͣ�������״̬

	SPLK	#0,ACLEAVE
	SPLK	#0,ACLEAVE1
	SPLK	#0,PDATA1

	SPLK	#0,PDATA3

	SPLK	#0,LIMIT2
	
	SPLK	#35H,D_INCUR
	
	SPLK	#0,RUNTAG
	
;--------------------------------------------------------------------
;	��ʱ���̵�������
;--------------------------------------------------------------------

	CALL	STARTDELAY1			;��ʱʱ���ԼΪ1S

	LDP	#0E1H
	LACC	PCDATDIR
	OR	#08080H
	SACL	PCDATDIR			;������������
		
	CLRC	INTM				;���ж�

;--------------------------------------------------------------------
;	Ϊ����ǿ�����ŵ����������뿴�Ź�
;--------------------------------------------------------------------
;	NOP
;	LDP	#00E0H
;	SPLK	#002FH,WDCR			;ʹ���Ź���Ч����λʱ�����Ϊ1S
;	NOP
	

LOOP:	NOP
	NOP
	NOP
	CALL	KEYPRESS			;���ð����ж��ӳ���
	NOP
	CALL	OUTSET
        NOP
	CALL	RUNJUDGE
        NOP
	B       LOOP



OUTSET:	LDP	#4
	LACC	RUNTAG
	BCND	OUTSET4,EQ

	LDP	#4
	BIT	KEYMODE,BIT15
	BCND	OUTSET1,TC
	

OUTSET4:LDP	#232				;ֹͣ״̬
     	SPLK	#0000100110011001B,ACTR
	SPLK    #1000100001010111B,COMCON
	LDP	#00E1H
	LACC	PCDATDIR			;��PC.5��Ϊ����ˣ�����ǰ�������
	OR	#0010000000100000B
	SACL	PCDATDIR			;���Ϊ1,����ǰ��

	LDP	#0E1H
	LACC	PADATDIR
	OR	#0200H
	AND	#0FFFDH
	SACL	PADATDIR			;�������̵�����

	LDP	#0E1H
	LACC	PCDATDIR
	OR	#04000H
	AND	#0FFBFH
	SACL	PCDATDIR			;�����̵�����

	LDP	#4
	
	
	B	OUTSET2

		

OUTSET1:LDP	#00E1H
	LACC	PCDATDIR			;��PC.5��Ϊ����ˣ�����ǰ�������
	OR	#0010000000000000B
	AND	#1111111111011111B
	SACL	PCDATDIR			;���Ϊ0,��ǰ��
	

	LDP	#4
	LACC	U2AD1
	SUB	#620
	BCND	OUTSET2,LT

	LDP	#0E0H
	BIT	SPIPC2,BIT7			;���SPISIMO=1 Ϊ�������״̬;SPISIMO=0 Ϊ����״̬
	BCND	OUTSET3,NTC
	
	LDP	#0E1H
	LACC	PCDATDIR
	OR	#04000H
	AND	#0FFBFH
	SACL	PCDATDIR			;�����̵�����


	LDP	#0E1H
	LACC	PADATDIR
	OR	#0202H
	SACL	PADATDIR			;�������̵�������

	B	OUTSET2

OUTSET3:LDP	#0E1H
	LACC	PADATDIR
	OR	#0200H
	AND	#0FFFDH
	SACL	PADATDIR			;�������̵�����



	LDP	#0E1H
	LACC	PCDATDIR
	OR	#04040H
	SACL	PCDATDIR			;�����̵�������
	

OUTSET2:NOP
	NOP
	RET







STARTDELAY1:					;������ʱ�ӳ���1
	SETC	SXM
	LACC	#07FFEH
STD1:	SUB	#1
	RPT	#0BFH
	NOP
	BCND	STD1,GT
	RET

STARTDELAY3:					;������ʱ�ӳ���3
	CLRC	SXM
	LACC	#0FFFEH
STD3:	SUB	#1
	RPT	#04FH
	NOP
	BCND	STD3,GT
	RET

STARTDELAY2:					;������ʱ�ӳ���2
	CLRC	SXM
	LACC	#0FFFEH
STD2:	SUB	#1
	RPT	#0FFH
	NOP
	RPT	#0FFH
	NOP
	BCND	STD2,GT
	RET

RUNJUDGE:	NOP
	SETC	SXM
	LDP	#4
	LACC	DCVOL1USE
	SUB	DCVOLLIM1
	BCND	ST1,LT
	LACC	DCVOL1USE
	SUB	DCVOLLIM2
	BCND	ST2,GT	
	B	ST3

ST1:	LDP	#4
	SPLK	#0,RUNTAG
	B	ST3

ST2:	LDP	#4
	SPLK	#1,RUNTAG
	B	ST3

ST3:	NOP
	RET

	.END

