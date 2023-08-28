#include <stdint.h>
#include <stdio.h>
#include "STM32F429xx.h"
//#include "STM32F4.h"

#define GPIOGEN (1<<6)

int main (void)
{
	RCC->AHB1ENR |= GPIOGEN;
	GPIOG->MODER |= (1U<<26); // set to 0
	GPIOG->MODER &=  ~(1U<27); // set to 1
	GPIOG->MODER |= (1U<<28); // set to 0
	GPIOG->MODER &=  ~(1U<29); // set to 1
	while(1)
	{
		GPIOG -> ODR |= (1<<13);
		GPIOG -> ODR |= (1<<14);
		for (int var = 0; var < 100000; ++var){}
		GPIOG -> ODR &= ~(1<<13);
		GPIOG -> ODR &= ~(1<<14);
		for (int var = 0; var < 100000; ++var){}
	}
}
