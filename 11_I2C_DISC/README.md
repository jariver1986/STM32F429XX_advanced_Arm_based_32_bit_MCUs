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


## Práctica I2C
**I2C (Inter-Integrated Circuit) and STM32**

**I2C Overview:**
I2C, or Inter-Integrated Circuit, is a widely used synchronous serial communication protocol that enables data transfer between microcontrollers and peripheral devices. It's known for its simplicity and efficiency, making it suitable for various embedded applications. I2C uses a master-slave architecture, where a master device initiates communication with one or more slave devices over a two-wire bus (SCL for the clock signal and SDA for the data signal).

**STM32 Microcontrollers:**
STM32 microcontrollers, developed by STMicroelectronics, are a popular family of 32-bit ARM Cortex-M based microcontrollers. They offer a wide range of peripherals, including I2C interfaces, making them suitable for applications that require I2C communication.

**Using I2C with STM32:**
To use I2C with an STM32 microcontroller, follow these steps:

1. **Hardware Configuration:**
   - Connect the SCL and SDA pins of the STM32 microcontroller to the corresponding pins on the I2C peripheral or external I2C devices.
   - Ensure appropriate pull-up resistors are connected to both SCL and SDA lines.

2. **Software Initialization:**
   - Enable the clock for the I2C peripheral you intend to use.
   - Configure the I2C pins and set them as alternate function mode for I2C communication.
   - Set the clock speed and addressing mode for the I2C bus.

3. **Writing Data:**
   - To send data from the STM32 to an I2C device, use the I2C_Write() function. This function prepares and sends data to the target device.

4. **Reading Data:**
   - To receive data from an I2C device, use the I2C_Read() function. This function initiates a read operation and retrieves data from the target device.

5. **Error Handling (Optional):**
   - Implement error handling mechanisms to manage potential issues during I2C communication, such as bus collisions, arbitration loss, or communication timeouts.

6. **Interrupt Handling (Optional):**
   - If necessary, set up and handle interrupts for I2C events like data reception complete, transmission complete, or error conditions.

7. **Testing and Debugging:**
   - Test your I2C communication thoroughly, and use debugging tools like logic analyzers or serial output to diagnose and resolve any communication problems.

8. **Advanced Features (Optional):**
   - STM32 microcontrollers offer advanced features like multi-master support, DMA (Direct Memory Access) for data transfer, and clock stretching management, which can be utilized as needed.

## Steps
## Seleccion de la tarjeta de desarrollo STM32F446RE
![uart2](https://github.com/vasanza/STM32/assets/12642226/e1780153-6cae-4052-9bd4-7303efe4d19a)
![uart3](https://github.com/vasanza/STM32/assets/12642226/7884bf80-70e2-4a80-9320-936fa2ab9de8)
## Incorporar las achivos .h de los devices y los drivers
![uart4](https://github.com/vasanza/STM32/assets/12642226/61b44ee5-37c9-46fd-9eb7-1eba41dea17b)
## Escribir el codigo a utilizar





