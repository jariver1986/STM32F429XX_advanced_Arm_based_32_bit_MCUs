//#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "STM32F446xx.h"

//void CAN_Init() {
int main()
{
    // Habilitar reloj para CAN1 y GPIO
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_CAN1EN;

    // Configurar pines GPIO para CAN1
    GPIOA->MODER |= GPIO_MODER_MODER11_1; // PA11 como AF
    GPIOA->MODER |= GPIO_MODER_MODER12_1; // PA12 como AF
    //GPIOA->AFR[1] |= (0x09 << GPIO_AFRH_AFRH3_Pos); // PA11 AF9 (CAN1_RX)
    //GPIOA->AFR[1] |= (0x09 << GPIO_AFRH_AFRH4_Pos); // PA12 AF9 (CAN1_TX)

    // Configurar CAN1
    CAN1->MCR |= CAN_MCR_RESET; // Resetear el módulo CAN
    CAN1->MCR &= ~CAN_MCR_SLEEP; // Desactivar modo de bajo consumo

    // Configurar la velocidad de transmisión (por ejemplo, 500 kbps)
    CAN1->BTR = (4 << 0) | (2 << 10) | (1 << 16) | (3 << 20);

    // Habilitar CAN1
    CAN1->MCR &= ~CAN_MCR_INRQ; // Salir del modo de inicialización
    while (CAN1->MSR & CAN_MSR_INAK); // Esperar a que CAN1 salga del modo de inicialización
}

void CAN_SendMessage(uint32_t id, uint8_t* data, uint8_t length) {
    CAN_TxMailBox_TypeDef* TxMailBox;

    // Esperar a que un buzón de transmisión esté disponible
    while (!(CAN1->TSR & (CAN_TSR_TME0 | CAN_TSR_TME1 | CAN_TSR_TME2)));

    // Seleccionar el buzón de transmisión
    if (CAN1->TSR & CAN_TSR_TME0)
        TxMailBox = CAN1->sTxMailBox;
    else if (CAN1->TSR & CAN_TSR_TME1)
        TxMailBox = CAN1->sTxMailBox + 1;
    else if (CAN1->TSR & CAN_TSR_TME2)
        TxMailBox = CAN1->sTxMailBox + 2;
    else
        return; // Todos los buzones están ocupados

    // Configurar identificador y longitud de datos
    TxMailBox->TIR = (id << 21) | CAN_TI0R_TXRQ;
    TxMailBox->TDTR = length;

    // Cargar los datos en el buzón de transmisión
    for (int i = 0; i < length; i++) {
        TxMailBox->TDLR = (TxMailBox->TDLR & ~(0xFF << (8 * i))) | (data[i] << (8 * i));
    }

    // Esperar a que la transmisión se complete
    while (!(CAN1->TSR & CAN_TSR_TXOK0 | CAN_TSR_TXOK1 | CAN_TSR_TXOK2));
}
