/* 
 * File:   app.h
 * Author: yusuf
 *
 * Created on April 16, 2023, 2:54 PM
 */

#ifndef APP_H
#define	APP_H

/* section : Includes   */

#include "ECU_Layer/LED/ecu_led.h"
#include "ECU_Layer/DC_MOTOR/ecu_motor.h"
#include "ECU_Layer/LCD/Ecu_LCD.h"
#include "MCAL_Layer/ADC/mcal_adc.h"
#include "MCAL_Layer/CCP1/mcal_ccp1.h"
#include "MCAL_Layer/Timers/Timer2/mcal_timer2.h"
#include "MCAL_Layer/usart/mcal_usart.h"
#include "MCAL_Layer/Interrupt/mcal_interrupt_manager.h"

/* section : Micro Declaration  */

/* section : Micro Function Declaration  */

/* section : Data Type Declaration  */

led_t led_Green;
led_t led_Red;
led_t led_Blue;
led_t led_Yellow;

dc_motor_t DC_Motor;
lcd_4bit_t lcd;

adc_cfg_t ADC;
ccp_t PWM;
timer2_t timer2;
usart_t UART;
   
/* (volatile) because they use in the ISR Function */
volatile uint16 Value_Recived1 = 0;
volatile uint16 Value_Recived2 = 0;
volatile uint8 value = 0;

uint8 count_char = 0;

/* section : Function Declaration  */
void initialization ();

#endif	/* APP_H */

