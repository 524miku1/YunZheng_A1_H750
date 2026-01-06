程序讲解：
#include "stdio.h"											//添加头文件stdio.h，keil的Options设置中勾选Use Microlib

MX_USART1_UART_Init();									//MX初始化USART，波特率115200

printf("HELLO WORLD!\n");								//打印语句

#ifdef __GNUC__												//printf重定向
int _write(int fd, char *ptr, int len)  
{  
  HAL_UART_Transmit(&huart1, (uint8_t*)ptr, len, 0xFFFF);
  return len;
}
#else
int fputc(int ch, FILE *f)									//重定向c库函数printf到串口USART1，重定向后可使用printf函数
{
    /* 发送一个字节数据到串口USARTx */
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
	return (ch);
}

int fgetc(FILE *f)											//重定向c库函数scanf到串口USART1，重写向后可使用scanf、getchar等函数
{	
	int ch;
	/* 等待串口输入数据 */
	while(__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == RESET);
	__HAL_UART_CLEAR_OREFLAG(&huart1);
	HAL_UART_Receive(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
	return (ch);
}

其他：
添加头文件#include "stdio.h"来调用printf，需先在魔法棒Target中启用微库MicroLIB以启用printf

添加以下函数来重定向printf 到usart1

#ifdef __GNUC__
int _write(int fd, char *ptr, int len)  
{  
  HAL_UART_Transmit(&huart1, (uint8_t*)ptr, len, 0xFFFF);
  return len;
}
#else
int fputc(int ch, FILE *f)			//重定向c库函数printf到串口USART1，重定向后可使用printf函数
{
    /* 发送一个字节数据到串口USARTx */
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
	return (ch);
}

int fgetc(FILE *f)			//重定向c库函数scanf到串口USART1，重写向后可使用scanf、getchar等函数
{	
	int ch;
	/* 等待串口输入数据 */
	while(__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == RESET);
	__HAL_UART_CLEAR_OREFLAG(&huart1);
	HAL_UART_Receive(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
	return (ch);
}

#endif

