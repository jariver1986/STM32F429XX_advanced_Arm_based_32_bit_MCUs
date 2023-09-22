#include "SSPI.h"

#define SPI1EN		(1U<<12)
#define GPIOAEN		(1U<<0)

#define SR_TXNE		(1U<<1)
#define SR_RXNE		(1U<<0)
#define SR_BUSY		(1U<<7)

/*
 * PA5	CLK
 * PA6	MISO
 * PA7	MOSI
 * PA9	slave select
 */

void sspi_gpio_init(void)

{
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA5, PAG, PA7 mode to alternate function*/

	/*PAS*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |=(1U<<11);

	/*PA6*/
	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |=(1U<<13);

	/*PAT*/
	GPIOA->MODER &=~(1U<<14);
	GPIOA->MODER |=(1U<<15);

	/*Set PA9 as output pin*/
	GPIOA->MODER |=(1U<<18);
	GPIOA->MODER &=~(1U<<19);

	/*Set PAS, PA6,PA7 alternate function type to SPIl*/
	/*PA5*/
	GPIOA->AFR[0] |=  (1U<<20);
	GPIOA->AFR[0] &= ~(1U<<21);
	GPIOA->AFR[0] |=  (1U<<22);
	GPIOA->AFR[0] &= ~(1U<<23);

	/*PA6*/
	GPIOA->AFR[0] |=  (1U<<24);
	GPIOA->AFR[0] &= ~(1U<<25);
	GPIOA->AFR[0] |=  (1U<<26);
	GPIOA->AFR[0] &= ~(1U<<27);

	/*PA7*/
	GPIOA->AFR[0] |=  (1U<<28);
	GPIOA->AFR[0] &= ~(1U<<29);
	GPIOA->AFR[0] |=  (1U<<30);
	GPIOA->AFR[0] &= ~(1U<<31);
}

void sspil_config (void)
{
	/*Enable clock access to SPIl module*/
	RCC->APB2ENR |= SPI1EN;

	/*Set clock to fPCLK/4*/
	SPI1->CR1 |=(1U<<3);
	SPI1->CR1 &=~(1U<<4);
	SPI1->CR1 &=~(1U<<5);

	/*Set CPOL to 1 and CPHA to 1+*/
	SPI1->CR1 |=(1U<<0);
	SPI1->CR1 |=(1U<<1);

	/*Enable full duplex*/

	SPI1->CR1 &= ~(1U<<10);

	/*Set MSB first*/
	SPI1->CR1 &= ~(1U<<7);

	/*Set mode to MASTER*/
	SPI1->CR1 |= (1U<<2);

	/*Set 8 bit data mode*/
	SPI1->CR1 &= ~(1U<<11);

	/*Select software slave management by
	* setting SSM=1 and SSI=1*/
	SPI1->CR1 |= (1<<8);

	SPI1->CR1 |= (1<<9);

	/*Enable SPI module*/
	SPI1->CR1 |= (1<<6);
}

void sspil_transmit(uint8_t *data,uint32_t size)
{

	uint32_t i=0;
	uint8_t temp;

	while (i<size)
	{

	/*Wait until TXE is set*/
	while(! (SPI1->SR & (SR_TXNE))){}

	/*Write the data to the data register*/
	SPI1->DR = data[i];
	i++;

	}

	/*Wait until TXE is set*/

	while(!(SPI1->SR & (SR_TXNE))){}

	/*Wait for BUSY flag to reset*/
	while ((SPI1->SR & (SR_BUSY))){}

	/*Clear OVR flag*/
	temp = SPI1->DR;
	temp = SPI1->SR;
}

void sspil_receive(uint8_t *data,uint32_t size)
{
	while (size)
	{
		/*Send dummy data*/
		SPI1->DR =0;

		/*Mait for RXNE flag to be set*/
		while(! (SPI1->SR & (SR_RXNE))){}

	/*Read data from data register*/
	*data++ = (SPI1->DR);
	size--;
	}
}

void spi_cs_enable(void)
{
	GPIOA -> ODR &= ~(1U<<9);
}
void spi_cs_disable(void)
{
	GPIOA -> ODR |= (1U<<9);
}
