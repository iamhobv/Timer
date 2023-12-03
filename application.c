/* 
 * File:   application.c
 * Author: Hobvv
 *
 * Created on September 11, 2023, 8:48 PM
 */


#include "application.h"

Std_ReturnType ret = E_NOT_OK;

    uint8 sec = 55, min = 59, hr = 23;
    uint8 counter = 0;
   button_state_t hr_value;
   button_state_t min_value;
 
int main() {
    application_intialize();
     
    while (1) {
        ret = button_read_state(&hr_btn,&hr_value);
        ret = button_read_state(&min_btn,&min_value);
        
        if(BUTTON_PRESSED == hr_value){
           
           hr++;
        }
         if(BUTTON_PRESSED == min_value){
           
           min++;
           sec = 0;
        }
         
      
      
        for(counter =0;counter<50;counter++)
{
            ret = gpio_port_write_logic(PORTD_INDEX, 0x3E);
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (hr / 10)));
            __delay_us(3333);

            ret = gpio_port_write_logic(PORTD_INDEX, 0x3D);
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (hr % 10)));
            __delay_us(3333);

            ret = gpio_port_write_logic(PORTD_INDEX, 0x3B);
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (min / 10)));
            __delay_us(3333);

            ret = gpio_port_write_logic(PORTD_INDEX, 0x37);
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (min % 10)));
            __delay_us(3333);

            ret = gpio_port_write_logic(PORTD_INDEX, 0x2F);
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (sec / 10)));
            __delay_us(3333);

            ret = gpio_port_write_logic(PORTD_INDEX, 0x1F);
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (sec % 10)));
            __delay_us(3333);
        }

        
        sec++;
        if(sec==60){
            min++;
            sec=0;
        }
        if(min==60){
            hr++;
            min=0;
        }
        if(hr==24)
        {
            hr=0;
        }
        
       
               

      
            }

    return (EXIT_SUCCESS);
}

void application_intialize(void) {
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
  
}