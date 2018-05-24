#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 
	
#define USART_REC_LEN  			200  	//定义最大接收字节数 200
#define EN_USART_switch			1		//是（1）/否（0）开启串口
#define EN_MORE_USART			1		//使能（1）/禁止（0）多串口模式
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收
#define EN_USART2_RX 			0		//使能（1）/禁止（0）串口1接收
	  	
extern u8  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	
extern u8 USART_Selet;					//选择串口标志

#define USART1_printf(string)	USART_Selet = 1;printf(string)//串口1的专用printf函数
#define USART2_printf(string)	USART_Selet = 2;printf(string)//串口2的专用printf函数
//如果想串口中断接收，请不要注释以下宏定义
void uart_init(u32 bound);
#endif


