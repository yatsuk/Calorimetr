#ifndef __ltrapitypes__
#define __ltrapitypes__
#include <windows.h>
#ifdef __cplusplus
extern "C" {
#endif
//
#ifndef COMMENT_LENGTH
#define COMMENT_LENGTH 256
#endif
#ifndef ADC_CALIBRATION_NUMBER
#define ADC_CALIBRATION_NUMBER 256
#endif
#ifndef DAC_CALIBRATION_NUMBER
#define DAC_CALIBRATION_NUMBER 256
#endif
//
#pragma pack(4)

typedef struct __ERROR_STRING_DEF__
    {
    INT code;
    LPCSTR message;
    }
    T_ERROR_STRING_DEF;

// ���������� � ���� ������
typedef struct _CRATE_INFO_
{
 BYTE CrateType;                                           // ��� ������
 BYTE CrateInterface;                                      // ��� ����������� ������
} TCRATE_INFO;

// �������� ������
typedef struct _DESCRIPTION_MODULE_                        //
{                                                          //
  BYTE   CompanyName[16];                                  //
  BYTE   DeviceName[16];                                   // �������� �������
  BYTE   SerialNumber[16];                                 // �������� ����� �������
  BYTE   Revision;                                         // ������� �������
  BYTE   Comment[COMMENT_LENGTH];                          //
} TDESCRIPTION_MODULE;                                     //
// �������� ���������� � ����������� �����������
typedef struct _DESCRIPTION_CPU_                           //
{                                                          //
  BYTE   Active;                                           // ���� ������������� ��������� ����� ���������
  BYTE   Name[16];                                         // ��������
  double ClockRate;                                        //
  DWORD  FirmwareVersion;                                  //
  BYTE   Comment[COMMENT_LENGTH];                          //
} TDESCRIPTION_CPU;                                        //
// �������� ����
typedef struct _DESCRIPTION_FPGA_                          //
{                                                          //
  BYTE   Active;                                           // ���� ������������� ��������� ����� ���������
  BYTE   Name[16];                                         // ��������
  double ClockRate;                                        //
  DWORD  FirmwareVersion;                                  //
  BYTE   Comment[COMMENT_LENGTH];                          //
} TDESCRIPTION_FPGA;                                       //
// �������� ���
typedef struct _DESCRIPTION_ADC_                           //
{                                                          //
  BYTE   Active;                                           // ���� ������������� ��������� ����� ���������
  BYTE   Name[16];                                         // ��������
  double Calibration[ADC_CALIBRATION_NUMBER];              // ���������������� ������������
  BYTE   Comment[COMMENT_LENGTH];                          //
} TDESCRIPTION_ADC;                                        //
// �������� ���
typedef struct _DESCRIPTION_DAC_                           //
{                                                          //
  BYTE   Active;                                           // ���� ������������� ��������� ����� ���������
  BYTE   Name[16];                                         // ��������
  double Calibration[DAC_CALIBRATION_NUMBER];              // ���������������� ������������
  BYTE   Comment[COMMENT_LENGTH];                          //
} TDESCRIPTION_DAC;                                        //
// �������� h-���������
typedef struct _DESCRIPTION_MEZZANINE_                     //
{                                                          //
  BYTE   Active;                                           // ���� ������������� ��������� ����� ���������
  BYTE   Name[16];                                         // �������� �������
  BYTE   SerialNumber[16];                                 // �������� ����� �������
  BYTE   Revision;                                         // ������� �������
  double Calibration[4];                                   // ���������������� ������������
  BYTE   Comment[COMMENT_LENGTH];                          // �����������
} TDESCRIPTION_MEZZANINE;                                   //
// �������� ��������� ��
typedef struct _DESCRIPTION_DIGITAL_IO_                    //
{                                                          //
  BYTE   Active;                                           // ���� ������������� ��������� ����� ���������
  BYTE   Name[16];                                         // �������� ???????
  WORD   InChannels;                                       // ����� �������
  WORD   OutChannels;                                      // ����� �������
  BYTE   Comment[COMMENT_LENGTH];                          //
} TDESCRIPTION_DIGITAL_IO;                                 //
// �������� ������������ �������
typedef struct _DESCRIPTION_INTERFACE_                     //
{                                                          //
  BYTE   Active;                                           // ���� ������������� ��������� ����� ���������
  BYTE   Name[16];                                         // ��������
  BYTE   Comment[COMMENT_LENGTH];                          //
} TDESCRIPTION_INTERFACE;                                  //

// ������� ������ IP-�������
typedef struct _IPCRATE_ENTRY_
    {
    DWORD ip_addr;                                          // IP ����� (host-endian)
    DWORD flags;                                            // ����� ������� (CRATE_IP_FLAG_...)
    CHAR serial_number[16];                                 // �������� ����� (���� ����� ���������)
    BYTE is_dynamic;                                        // 0 = ����� �������������, 1 = ������ �������������
    BYTE status;                                            // ��������� (CRATE_IP_STATUS_...)
    }
    TIPCRATE_ENTRY;

#pragma pack()
//
#ifdef __cplusplus
}
#endif
#endif
