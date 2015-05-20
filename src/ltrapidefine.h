#ifndef __ltrapidefine__
#define __ltrapidefine__
#if defined _MSC_VER
#define EXPORTCALL(type) type  __declspec(dllexport) WINAPI
#else
#if defined __cplusplus
#define EXPORTCALL(type) type WINAPI __declspec(dllexport)
#else
#define EXPORTCALL(type) type WINAPI __declspec(dllexport)
#endif
#endif

// ������� �����-�����������
#define LTR010DATA                (0x0000l)
#define LTR010USERDATA            (0x4000l)
#define LTR010CMD                 (0x8000l)
#define LTR010CRATE_CMD           (0xC000l)
#define LTR010_CMD_DATA_MASK      (0xC000l)

#define LTR010CMD_STOP            (LTR010CMD|0x00)
#define LTR010CMD_PROGR           (LTR010CMD|0x40)
#define LTR010CMD_RESET           (LTR010CMD|0x80)
#define LTR010CMD_INSTR           (LTR010CMD|0xC0)
#define LTR010_SLOT_MASK          (0xFl<<8)
//
#define SIGNAL_RBUF_OVF           (0xFFFFFFF0)  // ������� ������ -> ������ : ������������ ������  �������
#define SIGNAL_TSTAMP             (0xFFFFFFF1)  // ������� ������ -> ������ : ����� �������
//
#define SADDR_LOCAL               (0x7F000001L)
#define SADDR_DEFAULT             (SADDR_LOCAL)
#define SPORT_DEFAULT             (11111)
// ���� ������� ������-������
#define CC_CONTROL                 0            // ����� ��� ������ c ������� � ����� 0, �� ��
#define CC_MODULE1                 1            // ����� ��� ������ c ������� � ����� 1
#define CC_MODULE2                 2            // ����� ��� ������ c ������� � ����� 2
#define CC_MODULE3                 3            // ����� ��� ������ c ������� � ����� 3
#define CC_MODULE4                 4            // ����� ��� ������ c ������� � ����� 4
#define CC_MODULE5                 5            // ����� ��� ������ c ������� � ����� 5
#define CC_MODULE6                 6            // ����� ��� ������ c ������� � ����� 6
#define CC_MODULE7                 7            // ����� ��� ������ c ������� � ����� 7
#define CC_MODULE8                 8            // ����� ��� ������ c ������� � ����� 8
#define CC_MODULE9                 9            // ����� ��� ������ c ������� � ����� 9
#define CC_MODULE10               10            // ����� ��� ������ c ������� � ����� 10
#define CC_MODULE11               11            // ����� ��� ������ c ������� � ����� 11
#define CC_MODULE12               12            // ����� ��� ������ c ������� � ����� 12
#define CC_MODULE13               13            // ����� ��� ������ c ������� � ����� 13
#define CC_MODULE14               14            // ����� ��� ������ c ������� � ����� 14
#define CC_MODULE15               15            // ����� ��� ������ c ������� � ����� 15
#define CC_MODULE16               16            // ����� ��� ������ c ������� � ����� 16
#define CC_USERDATA               18            // ����� ��� ������ � ������������� ��� ���������������� ������
#define CC_DEBUG_FLAG             0x8000        // ���� ������� - ������ ���������� � ����� �
                                                // ��� ���� � ������� ��� �������� �� �������.
                                                // �.�. �� ���������� ������������� ������ ������.
#define CC_RAW_DATA_FLAG          0x4000        // ���� ������� - ����� �������� � ��� �����������
                                                // ������� �������� �� USB ��� �������� �� �������
#define CRATE_MAX                 16l           // ������������ ����� ������� ������������� ����� ��������
#define MODULE_MAX                16l           // ������������ ����� ������� � ����� ������

#define FLAG_RBUF_OVF             (1<<0)        // ���� ������������ ������ �������
#define FLAG_RFULL_DATA           (1<<1)        // ���� ��������� ������ � ������ ������� � ������� LTR_GetCrateRawData
#define FLAG_SIGNAL_TSTAMP        (1<<8)        // ���� ������� ������� SIGNAL_TSTAMP
// �������������� �������
#define MID_EMPTY                 0             // ������������� ���������������
#define MID_LTR11                 0x0B0B        // ������������� ������ LTR11
#define MID_LTR22                 0x1616        // ������������� ������ LTR22
#define MID_LTR27                 0x1B1B        // ������������� ������ LTR27
#define MID_LTR34                 0x2222        // ������������� ������ LTR34
#define MID_LTR41                 0x2929        // ������������� ������ LTR41
#define MID_LTR42                 0x2A2A        // ������������� ������ LTR42
#define MID_LTR43                 0x2B2B        // ������������� ������ LTR43
#define MID_LTR51                 0x3333        // ������������� ������ LTR51
#define MID_LTR114                0x7272        // ������������� ������ LTR114
#define MID_LTR212                0xD4D4        // ������������� ������ LTR212

// ��������� �������� ����� ������ ��� ���������� ����� ��������
// (�������� � �����, ����� ���� ��� �� ������ ������������� ������
// �������, ������� ���������� �� ���� �����, �������� "//SERVER_CONTROL"
#define CSN_SERVER_CONTROL                          "#SERVER_CONTROL"

// ������� ������-������
#define CONTROL_COMMAND_SIZE                        8
#define CONTROL_COMMAND_START                       0xFFFFFFFF
#define CONTROL_COMMAND_BASE_MASK_                  0xFFFFFF00
#define CONTROL_COMMAND_BASE_                       0xABCDEF00

#define CONTROL_COMMAND_INIT_CONNECTION             (CONTROL_COMMAND_BASE_ + 0x00)
#define CONTROL_COMMAND_SET_SERVER_PROCESS_PRIORITY (CONTROL_COMMAND_BASE_ + 0x01) //SERVER_CONTROL
#define CONTROL_COMMAND_GET_CRATE_TYPE              (CONTROL_COMMAND_BASE_ + 0x02)
#define CONTROL_COMMAND_GET_SERVER_PROCESS_PRIORITY (CONTROL_COMMAND_BASE_ + 0x03) //SERVER_CONTROL
#define CONTROL_COMMAND_PUT_ARRAY                   (CONTROL_COMMAND_BASE_ + 0x80)
#define CONTROL_COMMAND_GET_ARRAY                   (CONTROL_COMMAND_BASE_ + 0x81)
#define CONTROL_COMMAND_GET_DESCRIPTION             (CONTROL_COMMAND_BASE_ + 0x82)
#define CONTROL_COMMAND_BOOT_LOADER_GET_DESCRIPTION (CONTROL_COMMAND_BASE_ + 0x83)
#define CONTROL_COMMAND_BOOT_LOADER_SET_DESCRIPTION (CONTROL_COMMAND_BASE_ + 0x84)
#define CONTROL_COMMAND_GET_CRATES                  (CONTROL_COMMAND_BASE_ + 0x87) //SERVER_CONTROL
#define CONTROL_COMMAND_GET_MODULES                 (CONTROL_COMMAND_BASE_ + 0x88)
#define CONTROL_COMMAND_GET_CRATE_RAW_DATA          (CONTROL_COMMAND_BASE_ + 0x89)
#define CONTROL_COMMAND_GET_CRATE_RAW_DATA_SIZE     (CONTROL_COMMAND_BASE_ + 0x8A)
#define CONTROL_COMMAND_LOAD_FPGA                   (CONTROL_COMMAND_BASE_ + 0x8B)
#define CONTROL_COMMAND_IP_GET_LIST                 (CONTROL_COMMAND_BASE_ + 0x91) //SERVER_CONTROL
#define CONTROL_COMMAND_IP_ADD_LIST_ENTRY           (CONTROL_COMMAND_BASE_ + 0x92) //SERVER_CONTROL
#define CONTROL_COMMAND_IP_DELETE_LIST_ENTRY        (CONTROL_COMMAND_BASE_ + 0x93) //SERVER_CONTROL
#define CONTROL_COMMAND_IP_CONNECT                  (CONTROL_COMMAND_BASE_ + 0x94) //SERVER_CONTROL
#define CONTROL_COMMAND_IP_DISCONNECT               (CONTROL_COMMAND_BASE_ + 0x95) //SERVER_CONTROL
#define CONTROL_COMMAND_IP_CONNECT_ALL_AUTO         (CONTROL_COMMAND_BASE_ + 0x96) //SERVER_CONTROL
#define CONTROL_COMMAND_IP_DISCONNECT_ALL           (CONTROL_COMMAND_BASE_ + 0x97) //SERVER_CONTROL
#define CONTROL_COMMAND_IP_SET_FLAGS                (CONTROL_COMMAND_BASE_ + 0x98) //SERVER_CONTROL
#define CONTROL_COMMAND_IP_GET_DISCOVERY_MODE       (CONTROL_COMMAND_BASE_ + 0x99) //SERVER_CONTROL
#define CONTROL_COMMAND_IP_SET_DISCOVERY_MODE       (CONTROL_COMMAND_BASE_ + 0x9A) //SERVER_CONTROL
#define CONTROL_COMMAND_GET_SERVER_VERSION          (CONTROL_COMMAND_BASE_ + 0xAA) //SERVER_CONTROL
#define CONTROL_COMMAND_GET_LOG_LEVEL               (CONTROL_COMMAND_BASE_ + 0xF0) //SERVER_CONTROL
#define CONTROL_COMMAND_SET_LOG_LEVEL               (CONTROL_COMMAND_BASE_ + 0xF1) //SERVER_CONTROL
#define CONTROL_COMMAND_RESTART_SERVER              (CONTROL_COMMAND_BASE_ + 0xF2) //SERVER_CONTROL
#define CONTROL_COMMAND_SHUTDOWN_SERVER             (CONTROL_COMMAND_BASE_ + 0xF3) //SERVER_CONTROL
#define CONTROL_COMMAND_BOOT_LOADER_PUT_ARRAY       (CONTROL_COMMAND_BASE_ + 0xFD)
#define CONTROL_COMMAND_BOOT_LOADER_GET_ARRAY       (CONTROL_COMMAND_BASE_ + 0xFE)
#define CONTROL_COMMAND_CALL_APPLICATION            (CONTROL_COMMAND_BASE_ + 0xFF)
//#define CONTROL_COMMAND_START_ALL_CRATE_MODULES     (CONTROL_COMMAND_BASE_ + 0x90)

// ������� �� ������� �������
#define CONTROL_ACKNOWLEDGE_SIZE                    4
#define CONTROL_ACKNOWLEDGE_MODULE_IN_USE           0xABCDEFDD
#define CONTROL_ACKNOWLEDGE_GOOD                    0xABCDEFEE
#define CONTROL_ACKNOWLEDGE_BAD                     0xABCDEFFF

// �������� ������ (��� TCRATE_INFO)
#define CRATE_TYPE_UNKNOWN                      0
#define CRATE_TYPE_LTR010                       10
#define CRATE_TYPE_LTR021                       21
#define CRATE_TYPE_LTR030                       30
#define CRATE_TYPE_LTR031                       31
#define CRATE_TYPE_BOOTLOADER                   99

// ��������� ������ (��� TCRATE_INFO)
#define CRATE_IFACE_UNKNOWN                     0
#define CRATE_IFACE_USB                         1
#define CRATE_IFACE_TCPIP                       2

// ��������� ������ (��� TIPCRATE_ENTRY)
#define CRATE_IP_STATUS_OFFLINE                 0
#define CRATE_IP_STATUS_CONNECTING              1
#define CRATE_IP_STATUS_ONLINE                  2
#define CRATE_IP_STATUS_ERROR                   3

// ����� ���������� ������ (��� TIPCRATE_ENTRY � ������� CONTROL_COMMAND_IP_SET_FLAGS)
#define CRATE_IP_FLAG_AUTOCONNECT               0x00000001
#define CRATE_IP_FLAG__VALID_BITS_              0x00000001

// ������������� ��������� ������������ LTR010
#define SEL_AVR_DM                              0x82000000
#define SEL_AVR_PM                              0x83000000
#define SEL_DMA_TEST_FLAG                       0x84000000
#define SEL_FLASH_BUFFER                        0x85000000
#define SEL_FPGA_DATA                           0x86000000
#define SEL_FPGA_FLAGS                          0x87000000
#define SEL_FLASH_DSP                           0x88000000
#define SEL_FLASH_STATUS                        0x89000000
#define SEL_SDRAM	                            0x8A000000
#define SEL_SRAM	                            0x8B000000
#define SEL_DSP                                 0x90000000
#define SEL_DSP_SPI                             0x91000000
#define SEL_DSP_SPI_BOOT                        0x92000000
#define SEL_DSP_MEM                             0x93000000



//
#define LTR010_FIRMWARE_SIZE                    (0x3000)
#define LTR010_BOOT_LOADER_SIZE                 (0x1000)
#define LTR010_FIRMWARE_VERSION_ADDRESS         (SEL_AVR_PM|0x2FF0)
#define LTR010_BOOT_LOADER_VERSION_ADDRESS      (SEL_AVR_PM|0x3FF0)
#define LTR010_MODULE_DESCRIPTOR_ADDRESS        (SEL_AVR_PM|0x3000)
#define LTR010_FIRMWARE_START_ADDRESS           (SEL_AVR_PM|0x0000)
#define LTR010_BOOT_LOADER_START_ADDRESS        (SEL_AVR_PM|0x3C00)
//
#define EP1K100_SIZE                            (164*1024+100)
#define EP1K50_SIZE                             ( 96*1024+100)
#define EP1K30_SIZE                             ( 58*1024+100)
#define EP1K10_SIZE                             ( 22*1024+100)
#define FPGA_INFO_SIZE                          250
#define NAME_SIZE                               16
#define SERIAL_NUMBER_SIZE                      16
#endif
