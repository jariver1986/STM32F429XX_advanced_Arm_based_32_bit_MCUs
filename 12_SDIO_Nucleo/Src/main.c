//#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "STM32F446xx.h"

//void SDIO_Init() {
int main() {
    // Habilitar reloj para SDIO y GPIO
    //RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_SDIOEN;

    // Configurar pines GPIO para SDIO
    GPIOD->MODER |= GPIO_MODER_MODER2_1; // PD2 como AF
    GPIOD->MODER |= GPIO_MODER_MODER3_1; // PD3 como AF
    GPIOC->MODER |= GPIO_MODER_MODER8_1; // PC8 como AF
    GPIOC->MODER |= GPIO_MODER_MODER9_1; // PC9 como AF

    /*GPIOD->AFRL[0] |= (0x02 << GPIO_AFRL_AFRL4_Pos); // PD2 AF2 (SDIO)
    GPIOD->AFRL[0] |= (0x02 << GPIO_AFRL_AFRL5_Pos); // PD3 AF2 (SDIO)
    GPIOC->AFRH[1] |= (0x02 << GPIO_AFRH_AFRH0_Pos); // PC8 AF2 (SDIO)
    GPIOC->AFRH[1] |= (0x02 << GPIO_AFRH_AFRH1_Pos); // PC9 AF2 (SDIO)
	*/
    // Configurar el reloj para SDIO
    //RCC->DCKCFGR &= ~RCC_DCKCFGR_SDIOSEL; // Fuente de reloj SDIO: Sistema
    //RCC->DCKCFGR &= ~RCC_DCKCFGR_SDMMC1SEL; // Fuente de reloj SDMMC1: Sistema
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLQ; // Limpiar configuración de PLLQ
    RCC->PLLCFGR |= (0x07 << RCC_PLLCFGR_PLLQ_Pos); // PLLQ = 8
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLR; // Limpiar configuración de PLLR
    RCC->PLLCFGR |= (0x02 << RCC_PLLCFGR_PLLR_Pos); // PLLR = 4

    // Inicializar SDIO
    SDIO->POWER = 0x00000003; // Habilitar el reloj SDIO
    SDIO->CLKCR |= SDIO_CLKCR_CLKEN; // Habilitar el reloj
    SDIO->CLKCR |= (0x00 << SDIO_CLKCR_CLKDIV_Pos); // Configurar el divisor de frecuencia del reloj (SDIOCLK = HCLK/2)

    // Configurar el modo de bus ancho y la velocidad del bus
    SDIO->CLKCR |= SDIO_CLKCR_WIDBUS_0; // 4 bits de bus ancho
    //SDIO->CLKCR |= SDIO_CLKCR_CLKDIV_0; // Divisor de frecuencia del reloj = 2

    // Configurar la longitud de datos y habilitar el DMA
    SDIO->DCTRL |= (0x09 << SDIO_DCTRL_DBLOCKSIZE_Pos) | SDIO_DCTRL_DMAEN | SDIO_DCTRL_DTDIR; // DMA en modo de flujo y dirección de transferencia desde la tarjeta SD

    // Habilitar interrupciones (si es necesario)
    // NVIC_EnableIRQ(SDIO_IRQn);
}

void SDIO_SendCommand(uint32_t cmd, uint32_t arg, uint32_t flags) {
    SDIO->ARG = arg;
    SDIO->CMD = cmd | flags;
    while (!(SDIO->STA & (1 << 6))); // Esperar hasta que se complete la operación de comando
}

void SDIO_ReadBlock(uint8_t *buf, uint32_t addr, uint16_t size) {
    SDIO_SendCommand(17, addr, 0x00000000); // Comando de lectura de bloque
    while (!(SDIO->STA & (1 << 5))); // Esperar hasta que se complete la operación de datos

    for (int i = 0; i < size; i++) {
        *(buf + i) = SDIO->FIFO;
    }
}

void SDIO_WriteBlock(uint8_t *buf, uint32_t addr, uint16_t size) {
    SDIO_SendCommand(24, addr, 0x00000000); // Comando de escritura de bloque
    while (!(SDIO->STA & (1 << 5))); // Esperar hasta que se complete la operación de datos

    for (int i = 0; i < size; i++) {
        SDIO->FIFO = *(buf + i);
    }
}
