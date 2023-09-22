/*
 * SSPI.h
 *
 *  Created on: 16 sep. 2023
 *      Author: HP VICTUS
 */

#ifndef SSPI_H_
#define SSPI_H_

#include "STM32F446xx.h"
#include <stdint.h>

void sspi_gpio_init(void);
void sspil_config (void);
void sspil_transmit(uint8_t *data,uint32_t size);
void sspil_receive(uint8_t *data,uint32_t size);
void spi_cs_enable(void);
void spi_cs_disable(void);



#endif /* SSPI_H_ */
