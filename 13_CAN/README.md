# ⭐⭐⭐⭐⭐ (Arm Cortex-M4) CAN (Controller Area Network) and STM32
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


## Práctica CAN (Controller Area Network) and STM32
**CAN (Controller Area Network) and STM32**

**CAN Overview:**
Controller Area Network (CAN) is a widely used communication protocol in automotive and industrial applications. It allows microcontrollers and devices to communicate with each other in a networked environment. CAN is known for its robustness, reliability, and ability to operate in noisy environments. It supports both high-speed and low-speed communication, making it suitable for a wide range of applications.

**STM32 Microcontrollers:**
STM32 microcontrollers, developed by STMicroelectronics, are a family of 32-bit ARM Cortex-M based microcontrollers. They are widely used in various embedded applications due to their flexibility, performance, and rich set of peripherals. STM32 microcontrollers offer built-in CAN controllers, making them suitable for applications that require CAN communication.

**Using CAN with STM32:**
To use CAN with an STM32 microcontroller, follow these steps:

1. **Hardware Configuration:**
   - Connect the CAN controller pins (CAN_RX and CAN_TX) of the STM32 microcontroller to the corresponding pins on other CAN devices in the network.
   - Ensure appropriate termination resistors are used at both ends of the CAN bus.

2. **Software Initialization:**
   - Enable the clock for the CAN peripheral.
   - Configure the CAN pins and set them as alternate function mode for CAN communication.
   - Set up the CAN controller with the desired parameters, such as bitrate, mode, and filter settings.

3. **Sending CAN Messages:**
   - Use the `CAN_SendMessage()` function to send messages on the CAN bus. This function prepares and sends a CAN frame with the specified identifier and data payload.

4. **Receiving CAN Messages:**
   - Set up an interrupt handler to handle incoming CAN messages. When a message is received, the interrupt handler can process the received data.

5. **Error Handling (Optional):**
   - Implement error handling mechanisms to manage potential issues during CAN communication, such as bus errors, error frames, or error states.

6. **Testing and Debugging:**
   - Test the CAN communication by sending and receiving messages. Use tools like oscilloscopes or dedicated CAN analyzers for in-depth analysis.

7. **Advanced Features (Optional):**
   - STM32 microcontrollers offer advanced CAN features like loopback mode, silent mode, and error detection mechanisms. These features can be utilized as needed.

## Steps
## Seleccion de la tarjeta de desarrollo STM32F446RE
![uart2](https://github.com/vasanza/STM32/assets/12642226/e1780153-6cae-4052-9bd4-7303efe4d19a)
![uart3](https://github.com/vasanza/STM32/assets/12642226/7884bf80-70e2-4a80-9320-936fa2ab9de8)
## Incorporar las achivos .h de los devices y los drivers
![uart4](https://github.com/vasanza/STM32/assets/12642226/61b44ee5-37c9-46fd-9eb7-1eba41dea17b)
## Escribir el codigo a utilizar
![image](https://github.com/jariver1986/STM32F429XX_advanced_Arm_based_32_bit_MCUs/assets/62295761/6a7b3b53-d1f0-4bb5-a4fb-21a66bb1dfc2)






