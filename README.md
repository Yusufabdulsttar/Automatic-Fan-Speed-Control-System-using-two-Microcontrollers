# Automatic Fan Speed Control System using two Microcontrollers and simulated in Proteus

### In this project, I used the driver I implemented for the PIC18F4620 microcontroller. This driver allowed me to control the following Modules: LCD, LED, DC motor, interrupt, ADC, CCP, UART, Timer, GPIO, and Temperature sensor.
- ### The First microcontroller receives the temperature value from the second microcontroller using UART.
- ### The First microcontroller compares the temperature value to a set threshold value.
- ### Based on the temperature value, the First microcontroller generates a PWM signal with a duty cycle that corresponds to the desired speed.
- ### The PWM signal is then used to control the speed of the DC motor using a CCP module.
- ### The First microcontroller also controls the LEDs. For example, a low speed turn on the yellow LED, a medium speed turn on the Blue LED, and a high speed turn on the green LED.
- ### The First microcontroller also displays the temperature value and fan speed level on an LCD.
  
![Yusuf Abdulsttar](https://github.com/Yusufabdulsttar/Automatic-Fan-Speed-Control-System-using-two-Microcontrollers/assets/134774623/3171682e-cbdd-4301-92d2-03fc854927ec)
