#ifndef LTR114API_H_
#define LTR114API_H_


#define LTR114_PLD_VER

#define LTR114_HDR_VER  0x105

#include <windows.h>
#include "ltrapi.h"
#include "ltrapitypes.h"

/*================================================================================================*/
#define LTR114_CLOCK                 (15000) /* �������� ������� ������ � ��� */
#define LTR114_ADC_DIVIDER           (1875)  //�������� ������� ��� ���
#define LTR114_MAX_CHANNEL           (16)    /* ������������ ����� ���������� ������� */
#define LTR114_MAX_R_CHANNEL         (8)     /* ������������ ����� ���������� ������� ��� ��������� ������������� */
#define LTR114_MAX_LCHANNEL          (128)   /* ������������ ����� ���������� ������� */

#define LTR114_MID                   (0x7272) //id ������ LTR114


#define LTR114_ADC_RANGEQNT          (3)     //���-�� ���������� ��������� ����������
#define LTR114_R_RANGEQNT            (3)     //���-�� ���������� ��������� �������������
#define LTR114_AUTOCALIBR_STEPS      (13)     //���-�� ����� ��� ��������������
#define LTR114_MAX_SCALE_VALUE     (8000000)  //��� �����, ��������������� ������������� �������� ��������� ���������

//����� ��� ������� LTR114_ProcessData
#define LTR114_PROCF_NONE           (0x00)
#define LTR114_PROCF_VALUE          (0x01)   //������� ������������� �������� ���� � ���������� ��������
#define LTR114_PROCF_AVGR           (0x02)   //������� ������������� ���������� ���� ��������� - +I � -I
/*���� ���������� ����������*/
#define LTR114_URANGE_10        0
#define LTR114_URANGE_2         1
#define LTR114_URANGE_04        2
/*���� ���������� �������������*/
#define LTR114_RRANGE_400        0
#define LTR114_RRANGE_1200       1
#define LTR114_RRANGE_4000       2

/*������ ��������� ������*/
#define LTR114_CORRECTION_MODE_NONE      0
#define LTR114_CORRECTION_MODE_INIT      1
#define LTR114_CORRECTION_MODE_AUTO      2

/*������ �������������*/
#define LTR114_SYNCMODE_NONE            0
#define LTR114_SYNCMODE_INTERNAL        1
#define LTR114_SYNCMODE_MASTER          2
#define LTR114_SYNCMODE_EXTERNAL        4

/*������ �������� ������*/
#define LTR114_CHECKMODE_X0Y0         1
#define LTR114_CHECKMODE_X5Y0         2
#define LTR114_CHECKMODE_X0Y5         4
#define LTR114_CHECKMODE_ALL          7

/*���� ����������� ������� ���������*/
#define LTR114_MEASMODE_U      0x00
#define LTR114_MEASMODE_R      0x20
#define LTR114_MEASMODE_NR     0x28
/*���� ����������� ������� ����������*/
#define LTR114_MEASMODE_NULL         0x10     //��������� ������������ ����
#define LTR114_MEASMODE_DAC12        0x11     //��������� DAC1 - DAC2
#define LTR114_MEASMODE_NDAC12       0x12 
#define LTR114_MEASMODE_NDAC12_CBR   0x38
#define LTR114_MEASMODE_DAC12_CBR    0x30

#define LTR114_MEASMODE_DAC12_INTR    0x91     //��������� DAC1 - DAC2 ���������� ���������
#define LTR114_MEASMODE_NDAC12_INTR   0x92 
#define LTR114_MEASMODE_DAC12_INTR_CBR    0xB8     //��������� DAC1 - DAC2 ���������� ���������
#define LTR114_MEASMODE_NDAC12_INTR_CBR   0xB0 
#define LTR114_MEASMODE_X0Y0              0x40
#define LTR114_MEASMODE_X5Y0              0x50
#define LTR114_MEASMODE_X0Y5              0x70


/*��������� ������ ��-���������*/
#define LTR114_DEF_DIVIDER            2
#define LTR114_DEF_INTERVAL           0
#define LTR114_DEF_OSR                0
#define LTR114_DEF_SYNC_MODE          LTR114_SYNCMODE_INTERNAL

/*���� ������ ������ LTR114*/
#define LTR114_TEST_INTERFACE         1   /*�������� ���������� PC-LTR114*/
#define LTR114_TEST_DAC               2   /*�������� DAC*/
#define LTR114_TEST_DAC1_VALUE        3   /*�������� ��������� �������� ��� DAC1*/
#define LTR114_TEST_DAC2_VALUE        4  /*�������� ��������� �������� ��� DAC2*/
#define LTR114_TEST_SELF_CALIBR       5  /*���������� ��������� ������� ���� ��� ����������*/

/*��������� ������������� �������� ���������� PC-LTR114*/
#define LTR114_TEST_INTERFACE_DATA_L (0x55)
#define LTR114_TEST_INTERFACE_DATA_H (0xAA)

//���� �������������� ������������
#define LTR114_FEATURES_STOPSW       0x01   //������������ ����� ��������������
#define LTR114_FEATURES_THERM        0x02   //���������
#define LTR114_FEATURES_CBR_DIS      0x04   //������ ��������� ����������
#define LTR114_MANUAL_OSR            0x08   //������ ��������� OSR


/* ���� ������, ������������ ��������� ���������� */
#define LTR114_ERR_INVALID_DESCR        (-10000) /* ��������� �� ��������� ������ ����� NULL */
#define LTR114_ERR_INVALID_SYNCMODE     (-10001) /* ������������ ����� ������������� ������ ��� */
#define LTR114_ERR_INVALID_ADCLCHQNT    (-10002) /* ������������ ���������� ���������� ������� */
#define LTR114_ERR_INVALID_ADCRATE      (-10003) /* ������������ �������� ������� ������������� ���
                                                * ������
                                                */
#define LTR114_ERR_GETFRAME             (-10004) /* ������ ��������� ����� ������ � ��� */
#define LTR114_ERR_GETCFG               (-10005) /* ������ ������ ������������ */
#define LTR114_ERR_CFGDATA              (-10006) /* ������ ��� ��������� ������������ ������ */
#define LTR114_ERR_CFGSIGNATURE         (-10007) /* �������� �������� ������� ����� ����������������
                                                * ������ ������
                                                */
#define LTR114_ERR_CFGCRC               (-10008) /* �������� ����������� ����� ����������������
                                                * ������
                                                */
#define LTR114_ERR_INVALID_ARRPOINTER   (-10009) /* ��������� �� ������ ����� NULL */
#define LTR114_ERR_ADCDATA_CHNUM        (-10010) /* �������� ����� ������ � ������� ������ �� ��� */
#define LTR114_ERR_INVALID_CRATESN      (-10011) /* ��������� �� ������ � �������� ������� ������
                                                * ����� NULL
                                                */
#define LTR114_ERR_INVALID_SLOTNUM      (-10012) /* ������������ ����� ����� � ������ */
#define LTR114_ERR_NOACK                (-10013) /* ��� ������������� �� ������ */
#define LTR114_ERR_MODULEID             (-10014) /* ������� �������� ������, ��������� �� LTR114 */
#define LTR114_ERR_INVALIDACK           (-10015) /* �������� ������������� �� ������ */
#define LTR114_ERR_ADCDATA_SLOTNUM      (-10016) /* �������� ����� ����� � ������ �� ��� */
#define LTR114_ERR_ADCDATA_CNT          (-10017) /* �������� ������� ������� � ������ �� ��� */
#define LTR114_ERR_INVALID_LCH          (-10018) /*�������� ����� ���. ������*/
#define LTR114_ERR_CORRECTION_MODE      (-10019) /*�������� ����� ��������� ������*/
#define LTR114_ERR_GET_PLD_VER          (-10020) /*������ ��� ������ ������ �����*/
#define LTR114_ERR_ALREADY_RUN          (-10021) /*������ ��� ������� ������� ����� ������, ���� �� ��� �������*/
#define LTR114_ERR_MODULE_CLOSED        (-10022) /*������ ��� ������� ������ � �������� �������*/


/*================================================================================================*/


/*================================================================================================*/
/* ���������� � ������ */
typedef struct
{
    CHAR Name[8];                          /* �������� ������ (������) */
    CHAR Serial[16];                        /* �������� ����� ������ (������) */

    WORD VerMCU;                               /* ������ �� ������ (������� ���� - ��������,
                                             * ������� - ��������
                                             */
	CHAR Date[14];                          /* ���� �������� �� (������) */
	BYTE VerPLD;                            //������ �������� ����
    struct
    {
        float U[LTR114_ADC_RANGEQNT];       /*�������� ��� ��� ���������� ��������� ����������*/             
        float I[LTR114_R_RANGEQNT];         /*�������� ����� ��� ���������� ��������� �������������*/
        float UIntr[LTR114_ADC_RANGEQNT];   /*�������� ������������� ����������*/
    } CbrCoef;                             /* ��������� ������������� ������������ */
} TINFO_LTR114, *PTINFO_LTR114;           

/*���������� �������� ����� �� ������ ��������������*/
typedef struct 
{
    INT Null;        //�������� ����                    
    INT Ref;         //�������� +�����
    INT NRef;       //�������� -�����
    INT Interm;
    INT NInterm;
} TSCALE_LTR114, *PTSCALE_LTR114; 

#define LTR114_SCALE_INTERVALS 3

typedef struct
{
    struct                                  
    {
        double Offset;                      /* �������� ���� */
        double Gain;                        /* ���������� ����������� */
    } Coef[LTR114_SCALE_INTERVALS];         /*����������� �� ����� �������������� �������� Gain � Offset*/
    TSCALE_LTR114* TempScale;       /*������ ��������� ��������� �����/���� */
    TSCALE_LTR114 Index;           /*���������� ��������� � TempScale*/
    TSCALE_LTR114 LastVals;       /*��������� ���������*/

    INT HVal;
    INT LVal;
    
} TCBRINFO;                  /*���������� ��� �������������� ������ �� ������ ���������*/

typedef struct
{
    BYTE MeasMode;       /*����� ���������*/
    BYTE Channel;       /*���������� �����*/
    BYTE Range;         /*�������� ���������*/
} LTR114_LCHANNEL;            /*��������� ����������� ������*/


/* ��������� ��������� ������ LTR114 � ��������� �� ���� */
typedef struct
{
    INT size;                               /* ������ ��������� � ������ */
    TLTR Channel;                           /* ��������� ������ ����� � ������� */

    TCBRINFO AutoCalibrInfo[LTR114_ADC_RANGEQNT];      /* ������ ��� ���������� ������������� ����. ��� ������� ��������� */

    INT LChQnt;                              // ���������� �������� ���������� ������� 
    LTR114_LCHANNEL LChTbl[LTR114_MAX_LCHANNEL];        // ����������� ������� � ����������� ���������� �������

    WORD Interval;                          //����� ������������ ���������    

    BYTE SpecialFeatures;                   //�������������� ����������� ������ (����������� ����������, ���������� ����������)
    BYTE AdcOsr;                             //�������� ���������. ��� - ����������� � ������������ � �������� �������������
    BYTE SyncMode;                           /*����� ������������� 
                                                  000 - ��� �������������
                                                  001 - ���������� �������������
                                                  010 - ���������� ������������� - �������
                                                  100 - ������� ������������� (�������)
                                                  */

    INT FreqDivider;                       // �������� ������� ��� (2..8000)
                                           // ������� ������������� ����� F = LTR114_CLOCK/(LTR114_ADC_DIVIDER*FreqDivider)

    INT FrameLength;                       //������ ������, ������������ ������� �� ���� ���� 
                                           //��������������� ����� ������ LTR114_SetADC
    BOOL Active;                           //��������� �� ������ � ������ ����� ������
    void* Reserve;
    TINFO_LTR114 ModuleInfo;                 /* ���������� � ������ LTR114 */

} TLTR114, *PTLTR114;

/*----------------------------------------------------------------------------------------------*/
/*��������������� ������� ��� ����������� ���������� ����������� ������ �� ����� � ���������� �������*/
#define LTR114_TABLE_SWMODE(Word) (BYTE) (Word)
#define LTR114_TABLE_GAIN(Word)        (BYTE) ((Word >> 8) & 0x3)
#define LTR114_TABLE_SRC(Word)           (BYTE) ((Word >> 10) & 0x7)

//#define LTR114_CREATE_VCHANNEL(SwitchMode, GAIN, Channel, Src) (WORD)(((WORD)Src<<10) | ((WORD)GAIN) << 8 | SwitchMode | Channel)
#define LTR114_CREATE_LCHANNEL(LChannel, MeasMode, Channel, Scale) LChannel.MeasMode = MeasMode; LChannel.Channel = Channel; LChannel.Scale = Scale;//(WORD)(((WORD)Src<<10) | ((WORD)GAIN) << 8 | SwitchMode | Channel)






#define LTR114_FREQ(hltr) ((float)LTR114_CLOCK*1000/(LTR114_ADC_DIVIDER*hltr.FreqDivider))
#define LTR114_FREQ_CHANNEL(hltr) (LTR114_FREQ(hltr)/(hltr.LChQnt + hltr.Interval))


#define LTR114_START_CONFIG_ADDR     (0x80)   
#define LTR114_START_SERIAL_ADDR     (0x99)
#define LTR114_CONFIG_DATA_SIZE      (79)     //������ ������ ������������




/*������ ������ ��������� ������ ��� ���. ������� ������� � 2-� �������� ������*/
#define LTR114_MODULE_MODE_BASE_SIZE  6 
/*������ ������ ��������� ������ � 2-� �������� ������*/
#define LTR114_MODULE_MODE_SIZE      (LTR114_MODULE_MODE_BASE_SIZE + LTR114_MAX_LCHANNEL)  

/*================================================================================================*/

/*================================================================================================*/
INT LTR114_Init(PTLTR114 hnd);
INT LTR114_Open(PTLTR114 hnd, DWORD net_addr, WORD net_port, CHAR *crate_sn,
    INT slot_num);
INT LTR114_Close(PTLTR114 hnd);

INT LTR114_GetConfig(PTLTR114 hnd);
INT LTR114_Calibrate(PTLTR114 hnd);

INT LTR114_SetADC(PTLTR114 hnd);
INT LTR114_Start(PTLTR114 hnd);
INT LTR114_Stop(PTLTR114 hnd);

LPCSTR LTR114_GetErrorString(INT err);
INT LTR114_GetFrame(PTLTR114 hnd, DWORD *buf);

INT LTR114_Recv(PTLTR114 hnd, DWORD *data, DWORD *tmark, DWORD size, DWORD timeout);
INT LTR114_ProcessData(PTLTR114 hnd, DWORD *src, double *dest, INT *size, INT correction_mode, INT flags);
INT LTR114_ProcessDataTherm(PTLTR114 hnd, DWORD *src, double *dest, double *therm, INT *size, INT *tcnt, INT correction_mode, INT flags);

INT LTR114_CheckInputs(PTLTR114 hnd, INT ChannelsMask, INT CheckMode, double *res_data, INT *size);

INT LTR114_SetRef(PTLTR114 hnd, INT range, BOOL middle);
WORD LTR114_GetDllVer(void);

LTR114_LCHANNEL LTR114_CreateLChannel(INT MeasMode, INT Channel, INT Range);

INT LTR114_ConvertToValue(PTLTR114 hnd, double *data, INT size, INT correction_mode, INT flags);
INT LTR114_ProcessDataCb(PTLTR114 hnd, DWORD *src, double *dest, double *therm, INT *size, INT *tcnt, INT correction_mode, INT flags, INT (* cb_func)(PTLTR114 hnd, double* data));
/*================================================================================================*/

#endif                      /* #ifndef LTR11API_H_ */
