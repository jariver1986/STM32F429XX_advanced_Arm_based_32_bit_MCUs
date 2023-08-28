#include <stdint.h>
#include "STM32F429xx.h"
//#include "usart_disc.h"

char key;
////////////////////////////Programa general
int main (void)
{
	uart1_tx_init();
	while(1)
	{
		key = uart1_read();
		if (key == '2')
		{
			uart1_write('B');
			for (int var = 0; var < 100000; ++var)
			{
			}
		}
	}
	/*uart1_tx_init();
	while(1)
	{
		uart1_write('A');
		for (int var = 0; var < 100000; ++var)
		{
		}
	}*/
}
///////////////////////////////Fin programa general

