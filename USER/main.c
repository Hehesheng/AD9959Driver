#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "adc.h"
#include "dac.h"
#include "AD9959.h"

int main(void)
{ 

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断
    delay_init(168);      //delay初始化，系统主频168MHz
    uart_init(115200);		//USART1波特率设置为115200

    Init_AD9959();        //初始化AD9959, 开始输出

    while(1)
    {
        
    }	
}

/****
    *@brief     将字符串转化为float数值
    *@name      float string_to_float(u8 *string, u16 string_num)
    *@param     字符串string,字数string_num
    *@retval    转化的数字float
    */

float string_to_float(u8 *string, u16 string_num)
{
    int i, float_flag = 0;
    float result = 0;
    for (i = 0;i < string_num;i++)
    {
        if (string[i] == '.')
        {
            float_flag = 1;//检测到小数点,开始小数部分输入
            continue;
        }
        string[i] = string[i] - 48;//转换为数字
        if (float_flag == 0)
        {
            result = result * 10 + string[i];
        }
        else if (float_flag != 0)
        {
            result = result + string[i] * powf(0.1, float_flag);
            float_flag++;
        }
    }
    return result;
}


