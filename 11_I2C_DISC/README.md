# ⭐⭐⭐⭐⭐ (Arm Cortex-M4) SDIO
## ✅ Developed by: [John Rivera Burgos](https://www.linkedin.com/in/john-rivera-burgos-bb703079/)
## ➡️ Device:
- Development Board: [NUCLEO-F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html)
- Processor: [STM32F446RE MCU, Arm® Cortex®-M4 core at 180 Mhz](https://www.st.com/en/microcontrollers-microprocessors/stm32f446re.html)
## ➡️ Compiler:
- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
## ⭐ Device provided by:
- [EcuaPlus](https://www.facebook.com/Ecuapluss/?locale=es_LA)
## ⭐ When using this resource, please cite the original publication:
- [Avilés-Mendoza, K., Gaibor-León, N. G., Asanza, V., Lorente-Leyva, L. L., & Peluffo-Ordóñez, D. H. (2023). A 3D Printed, Bionic Hand Powered by EMG Signals and Controlled by an Online Neural Network. Biomimetics, 8(2), 255.](https://www.mdpi.com/2313-7673/8/2/255)

![nucleo](https://github.com/vasanza/STM32/assets/12642226/d1d58c13-dedf-4f7f-9a4d-3b7176690220)
![image](https://github.com/jariver1986/STM32F429XX_advanced_Arm_based_32_bit_MCUs/assets/62295761/e481d363-7d3c-4233-b5a8-427262f23545)


## Práctica SDIO
SDIO Overview:
SDIO, which stands for Secure Digital Input/Output, is a communication interface used to transfer data between a microcontroller and SD memory cards. It is an extension of the standard SD card interface, allowing for both data input and output. SDIO cards are commonly used in applications like digital cameras, GPS receivers, and microcontroller-based systems.

STM32 Microcontrollers:
STM32 microcontrollers are a family of 32-bit ARM Cortex-M based microcontrollers developed by STMicroelectronics. They are widely used in various embedded applications due to their flexibility, performance, and rich set of peripherals. STM32 microcontrollers support various communication interfaces including UART, SPI, I2C, and SDIO.

Using SDIO with STM32:
To use SDIO with an STM32 microcontroller, you'll need to follow these steps:

Hardware Configuration:

Connect the SDIO pins (D0-D3, CLK, CMD) of the SD card to the corresponding pins on the STM32 microcontroller.
Ensure the SDIO pins are properly configured as alternate function mode.
Software Initialization:

Enable the clock for SDIO peripheral and associated GPIO ports.
Configure the SDIO pins and set them as alternate function for SDIO communication.
Set up the clock and bus width for SDIO communication.
Sending Commands:

Use the SDIO_SendCommand() function to send commands to the SD card. This function sets up the command register and waits for the command to complete.
Reading and Writing Data:

For reading data, use the SDIO_ReadBlock() function. This function sends a read command to the SD card, waits for the data transfer to complete, and reads data from the SDIO FIFO.
For writing data, use the SDIO_WriteBlock() function. This function sends a write command to the SD card, waits for the data transfer to complete, and writes data to the SDIO FIFO.
Error Handling (Optional):

Implement error handling mechanisms to handle potential issues during SDIO communication, such as timeouts or CRC errors.
Interrupt Handling (Optional):

If needed, set up and handle interrupts for SDIO events like data transfer complete or command complete.
Testing and Debugging:

Test the SDIO communication thoroughly and use debugging tools like breakpoints, UART output, or LED indicators to diagnose any issues.

## Steps
## Seleccion de la tarjeta de desarrollo STM32F446RE
![uart2](https://github.com/vasanza/STM32/assets/12642226/e1780153-6cae-4052-9bd4-7303efe4d19a)
![uart3](https://github.com/vasanza/STM32/assets/12642226/7884bf80-70e2-4a80-9320-936fa2ab9de8)
## Incorporar las achivos .h de los devices y los drivers
![uart4](https://github.com/vasanza/STM32/assets/12642226/61b44ee5-37c9-46fd-9eb7-1eba41dea17b)
## Escribir el codigo a utilizar
![image](https://github.com/jariver1986/STM32F429XX_advanced_Arm_based_32_bit_MCUs/assets/62295761/a4030e2a-d96d-483d-84f2-7fe1717a5c31)





