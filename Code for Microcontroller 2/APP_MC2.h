/* 
 * File:   app.h
 * Author: yusuf
 *
 * Created on April 16, 2023, 2:54 PM
 */

#ifndef APP_H
#define	APP_H

/* section : Includes   */

#include "MCAL_Layer/ADC/mcal_adc.h"
#include "MCAL_Layer/usart/mcal_usart.h"
#include "MCAL_Layer/Interrupt/mcal_interrupt_manager.h"

/* section : Micro Declaration  */

/* section : Micro Function Declaration  */

/* section : Data Type Declaration  */


adc_cfg_t ADC;
usart_t UART;
        
uint16 Temp = 0;
uint16 Temp_Celsius = 0;

uint8 count_char = 0;

/* section : Function Declaration  */
void initialization ();

#endif	/* APP_H */

