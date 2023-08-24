/*
 * File:   app.c
 * Author: yusuf
 *
 * Created on April 16, 2023, 2:12 PM
 */
#include "app.h"

/* UART Interrupt Function*/
void UART_RX(){
   if (value  == 0 ){
   usart_asy_read(&Value_Recived2); 
   value = 1;
   }
   else if (value == 1){
   usart_asy_read(&Value_Recived1);
   value = 0;
   }
}

int main() {
    /* For initialization Drivers */
    initialization (); 

    lcd_4bit_send_string_pos(&lcd, 0, 1, "Temp: ");
    while (1){
    /* Display the Temp on LCD That value has been received by uart  */ 
    lcd_4bit_send_char_data_pos(&lcd, 1, 8, Value_Recived2);
    lcd_4bit_send_char_data_pos(&lcd, 1, 7, Value_Recived1);
    dc_motor_forward(&DC_Motor);   
    /* Control Fan And Led With Temp */
    if(Value_Recived1 >= '3'){
        led_off(&led_Red);
        led_off(&led_Blue);
        led_off(&led_Yellow);
        led_on(&led_Green);
        
        ccp_pwm_duty_cycle (100,&PWM);
        ccp_start_pwm (&PWM);
        
        lcd_4bit_send_string_pos(&lcd, 3, 1, "Fan Is ON (Speed 3)");
    }
    else if ((Value_Recived1 >= '2')){
        led_off(&led_Red);
        led_on(&led_Blue);
        led_off(&led_Yellow);
        led_off(&led_Green);
        
        ccp_pwm_duty_cycle (100,&PWM);
        ccp_start_pwm (&PWM);
        
        lcd_4bit_send_string_pos(&lcd, 3, 1, "Fan Is ON (Speed 2)");
    }
    else if (Value_Recived1 >= '1'){
        led_off(&led_Red);
        led_off(&led_Blue);
        led_on(&led_Yellow);
        led_off(&led_Green);
        
        ccp_pwm_duty_cycle (100,&PWM);
        ccp_start_pwm (&PWM);
        
        lcd_4bit_send_string_pos(&lcd, 3, 1, "Fan Is ON (Speed 1)");
    }
    else{
        led_on(&led_Red);
        led_off(&led_Blue);
        led_off(&led_Yellow);
        led_off(&led_Green);
        
        dc_motor_off(&DC_Motor);
        
        lcd_4bit_send_string_pos(&lcd, 3, 1, "Fan Is OFF              ");
    }
    }
}
    

void initialization (){
    
/* UART Configuration */  
    UART.baud_rate = 9600;
    UART.baudrate_gen = BAUDRATE_ASYN_8BIT_lOW_SPEED;   
    UART.usart_tx_interrupt = USART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE;
    UART.usart_rx_interrupt = USART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE; 
    UART.USART_RxInterruptHandler = UART_RX;
    
/* PMW Configuration */  
    PWM.ccp_select = CCP1_SELECT;
    PWM.ccp_mode = CCP_PWM_MODE_SELECTED;
    PWM.pmw_freq = 20000;
    PWM.pin.port = PORTC_INDEX;
    PWM.pin.pin = PIN2;
    PWM.pin.direction = dirc_OUTPUT;
    PWM.timer2_postscaler_value = 1;
    PWM.timer2_prescaler_value = 1;
    
    /* Timer Configuration */
    timer2.post_scale_value = POSTSCALER_TIMER2_DISABLE_1;
    timer2.prescale_value = PRESCALER_TIMER2_DISABLE_1;
    timer2.preload_value = 0;
    
 
/* LED Configuration */     
    led_Green.port_name = PORTE_INDEX, led_Green.pin = PIN0, led_Green.led_status = LOW;
    led_Red.port_name = PORTE_INDEX, led_Red.pin = PIN1, led_Red.led_status = LOW;
    led_Blue.port_name = PORTC_INDEX, led_Blue.pin = PIN3, led_Blue.led_status = LOW;
    led_Yellow.port_name = PORTC_INDEX, led_Yellow.pin = PIN4, led_Yellow.led_status = LOW;

/* DC Motor Configuration */ 
    DC_Motor.dc_motor_pin[0].port = PORTC_INDEX,
    DC_Motor.dc_motor_pin[0].pin = PIN0,
    DC_Motor.dc_motor_pin[0].direction = dirc_OUTPUT,
    DC_Motor.dc_motor_pin[0].logic = LOW,
    DC_Motor.dc_motor_pin[1].port = PORTC_INDEX,
    DC_Motor.dc_motor_pin[1].pin = PIN1,
    DC_Motor.dc_motor_pin[1].direction = dirc_OUTPUT,
    DC_Motor.dc_motor_pin[1].logic = LOW;
   
/* LCD Configuration */ 
    lcd.lcd_rs.port = PORTD_INDEX,
    lcd.lcd_rs.pin = PIN0,
    lcd.lcd_rs.direction = dirc_OUTPUT,
    lcd.lcd_rs.logic = LOW,
    lcd.lcd_en.port = PORTD_INDEX,
    lcd.lcd_en.pin = PIN1,
    lcd.lcd_en.direction = dirc_OUTPUT,
    lcd.lcd_en.logic = LOW,
    
    lcd.lcd_data[0].port = PORTD_INDEX,
    lcd.lcd_data[0].pin = PIN2,
    lcd.lcd_data[0].direction = dirc_OUTPUT,
    lcd.lcd_data[0].logic = LOW,
    lcd.lcd_data[1].port = PORTD_INDEX,
    lcd.lcd_data[1].pin = PIN3,
    lcd.lcd_data[1].direction = dirc_OUTPUT,
    lcd.lcd_data[1].logic = LOW,
    lcd.lcd_data[2].port = PORTD_INDEX,
    lcd.lcd_data[2].pin = PIN4,
    lcd.lcd_data[2].direction = dirc_OUTPUT,
    lcd.lcd_data[2].logic = LOW,
    lcd.lcd_data[3].port = PORTD_INDEX,
    lcd.lcd_data[3].pin = PIN5,
    lcd.lcd_data[3].direction = dirc_OUTPUT,
    lcd.lcd_data[3].logic = LOW;

/* initialization  */ 
    led_initialize(&led_Green);
    led_initialize(&led_Red);
    led_initialize(&led_Blue);
    led_initialize(&led_Yellow);
    
    dc_motor_initialize(&DC_Motor);  
    
    timer2_init(&timer2);
    
    ccp_int (&PWM);
    
    lcd_4bit_intialize(&lcd); 
    
    usart_asy_init(&UART);
}   