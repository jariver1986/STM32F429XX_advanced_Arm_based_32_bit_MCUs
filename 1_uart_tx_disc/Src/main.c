#include <stdint.h>
#include "STM32F429xx.h"

#define GPIOAEN (1U<<0)		//6.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
							//Bit 0 GPIOAEN: IO port A clock enable
							//1: IO port A clock enabled
#define GPIOGEN (1U<<6)		//6.3.10 RCC AHB1 peripheral clock register (RCC_AHB1ENR)
							//Bit 6 GPIOgEN: IO port A clock enable
							//1: IO port A clock enabled
#define GPIOG_13		(1<<13)	//lED
#define GPIOG_14		(1<<14)	//lED
#define led13			GPIOG_13
#define led14			GPIOG_14


#define UART1EN (1U<<4)    //6.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)
							//Bit 4 USART1EN: USART1 clock enable
							//1: USART1 clock enabled

#define CR1_TE		(1U<<3)  //Control register 1 (USART_CR1) Bit 3 TE: Transmitter enable
#define CR1_UE		(1U<<13) //Control register 1 (USART_CR1) Bit 13 UE: USART enable
#define SR_TXE		(1U<<7)  //30.6.1 Status register (USART_SR) // Bit 7 TXE: Transmit data register empty
#define SR_RXNE		(1U<<5)
#define CR1_RE		(1U<<2)  //Control register 1 (USART_CR1) Bit 3 RE: Receive enable


#define SYS_FREQ	16000000
#define APB2_CLK	SYS_FREQ

#define UART_BAUDRATE 	115200


static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate);
void uart1_tx_init(void);
void uart1_write(int ch);
char uart1_read(void);
char rx;

////////////////////////////Programa general
int main (void)
{

	uart1_tx_init();
	while(1)
	{
		uart1_write('@');
		for (int var = 0; var < 100000; ++var)
		{
		}
	}
}
///////////////////////////////Fin programa general

void uart1_tx_init(void)
{
	//////////////////////////////////////////////////////////////////////////////////////////
	//Programacion Puerto

	//clock to GPIOA
	RCC->AHB1ENR |= GPIOAEN; //6.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)

	//Programacion Leds G13 y G14
	RCC->AHB1ENR |= GPIOGEN; //6.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)

	//SET PA9 to alternate function mode
	//8.4.1 GPIO port mode register (GPIOx_MODER) (x = A..I/J/K)
	//10: Alternate function mode
	GPIOA->MODER &= ~(1U<<18); // set to 0
	GPIOA->MODER |=  (1U<<19); // set to 1

	//SET PA10 to alternate function mode
	//8.4.1 GPIO port mode register (GPIOx_MODER) (x = A..I/J/K)
	//10: Alternate function mode
	GPIOA->MODER &= ~(1U<<20); // set to 0
	GPIOA->MODER |=  (1U<<21); // set to 1

	//PA9 Alternate function Uart tx AF07
	//7.4.9 GPIO alternate function low register (GPIOx_AFRL) (x = A..H)
	//0111: AF7
	GPIOA->AFR[1] |= (1U<<4);
	GPIOA->AFR[1] |= (1U<<5);
	GPIOA->AFR[1] |= (1U<<6);
	GPIOA->AFR[1] &= ~(1U<<7);

	//PA10 Alternate function Uart rx AF07
	//8.4.9 GPIO alternate function low register (GPIOx_AFRL) (x = A..I/J/K)
	//0111: AF7
	GPIOA->AFR[1] |= (1U<<8);
	GPIOA->AFR[1] |= (1U<<9);
	GPIOA->AFR[1] |= (1U<<10);
	GPIOA->AFR[1] &= ~(1U<<11);

	///////////////////////////////////////////////////////////////////////////////////////////

	//SET PA9 to alternate function mode
	//8.4.1 GPIO port mode register (GPIOx_MODER) (x = A..I/J/K)
	//01: output mode
	GPIOG->MODER |=   (1U<<26); // set to 0
	GPIOG->MODER &=  ~(1U<<27); // set to 1
	GPIOG->MODER |=   (1U<<28); // set to 0
	GPIOG->MODER &=  ~(1U<<29); // set to 1

	//clock to uart2
	RCC->APB2ENR |= UART1EN;	//6.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)
								//Bit  USART1EN: USART1 clock enable
								//1: USART1 clock enabled

	///////////////////////////////////////////////////////////////////////////////////////////
	//Programacion USART

	//Configura 8audrate
	uart_set_baudrate(USART1,APB2_CLK,UART_BAUDRATE);
	//Enable UART module.
	USART1->CR1 |= CR1_UE;
	//Configure de transfer direction.
	USART1->CR1 = CR1_TE;
	//Configure de receive direction.
	USART1->CR1 = CR1_RE;



}

void uart1_write(int ch)
{
	// Asegure que tx data este vigente
	while(!(USART1->SR & SR_TXE)){}
	//Write to transmit data register
	USART1->DR = (ch & 0XFF);
}
char uart1_read(void)
{
	// Asegure que rx data este vigente
	while(!(USART1->SR & SR_RXNE)){}
	//Write to transmit data register
	return USART1->DR;
}



static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk,Baudrate);
}
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate)
{
	return((PeriphClk + (Baudrate/2U))/Baudrate);
}
