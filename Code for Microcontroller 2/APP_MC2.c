/*
 * File:   APP_MC2.c
 * Author: yusuf
 *
 * Created on April 16, 2023, 2:12 PM
 */
#include "APP_MC2.h"


int main() {
    /* For initialization Drivers */
    initialization (); 

    while (1){
    /* to get temperature value*/	
    adc_conv_value(&ADC, ADC_CHANNEL_AN0, &Temp);
    Temp_Celsius = Temp * (4.88f);        /* Step_size = 4.88 */
    Temp_Celsius /= 10;                   /* The sensitivity of LM35 is 10 mV/degree Celsius */
    /* send the command to the Microcontroller 1 */
    count_char = '0' + (Temp_Celsius % 10);
    usart_asy_write(count_char);
    count_char = '0' + ((Temp_Celsius/10) % 10);
    usart_asy_write(count_char);
    }
}
    

void initialization (){
    
/* UART Configuration */ 
    UART.baud_rate = 9600;
    UART.baudrate_gen = BAUDRATE_ASYN_8BIT_lOW_SPEED;   
    UART.usart_tx_interrupt = USART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE;
    UART.usart_rx_interrupt = USART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE;  
    

   
/* ADC Configuration */
    ADC.acq_time = ADC_12_TAD,
    ADC.conv_clock = ADC_div_FOSC_16,
    ADC.channel = ADC_CHANNEL_AN0,
    ADC.set_pins_analog = ADC_AN0_0_ANALOG_FUNCTION,
    ADC.conf_volt_ref = ADC_VOLT_MC;


/* initialization  */  
    adc_init(&ADC);
       
    usart_asy_init(&UART);
}   
