#ifndef __AD9959_H 
#define __AD9959_H 
#include "sys.h"

#define CSR_ADD   0x00   //CSR 通道选择寄存器
#define FR1_ADD   0x01   //FR1 功能寄存器1
#define FR2_ADD   0x02   //FR2 功能寄存器2
#define CFR_ADD   0x03   //CFR 通道功能寄存器
#define CFTW0_ADD 0x04   //CTW0 通道频率转换字寄存器
#define CPOW0_ADD 0x05   //CPW0 通道相位转换字寄存器
#define ACR_ADD   0x06   //ACR 幅度控制寄存器
#define LSRR_ADD  0x07   //LSR 通道线性扫描寄存器
#define RDW_ADD   0x08   //RDW 通道线性向上扫描寄存器
#define FDW_ADD   0x09   //FDW 通道线性向下扫描寄存器
//AD9959管脚宏定义
#define CS          PAout(6)
#define SCLK		PBout(1)
#define UPDATE 		PBout(0)
#define PS0 		PAout(7)
#define PS1			PAout(2)
#define PS2			PBout(10)
#define PS3			PCout(0)
#define SDIO0       PAout(5)
#define SDIO1		PAout(4)
#define SDIO2		PAout(3)
#define SDIO3 		PAout(8)
#define AD9959_PWR	PAout(9)
#define Reset		PAout(10)

/**
 * 一些参数的调整
 */
#define AD9959SYS_CLK 500 //单位M, 必须是25的整数倍25~500

void Init_AD9959(void);
void delay_9959(u32 length);
void InitIO_9959(void);
void InitReset(void);
void IO_Updata(void);
void WriteData_AD9959(u8 RegisterAddress, u8 NumberofRegisters, u8 *RegisterData,u8 temp);
void Write_frequence(u8 Channel,u32 Freq);
void Write_Amplitude(u8 Channel, u16 Ampli);
void Write_Phase(u8 Channel,u16 Phase);

#endif /* AD9959_H */ 
