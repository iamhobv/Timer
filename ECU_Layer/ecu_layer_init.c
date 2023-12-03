#include "ecu_layer_init.h"


seven_segment_t seven_seg1={
.segment_pins[0].port=PORTC_INDEX,
.segment_pins[0].pin=PIN0,
.segment_pins[0].logic=GPIO_LOGIC_LOW,
.segment_pins[0].direction=GPIO_DIRECTION_OUTPUT,

.segment_pins[1].port=PORTC_INDEX,
.segment_pins[1].pin=PIN1,
.segment_pins[1].logic=GPIO_LOGIC_LOW,
.segment_pins[1].direction=GPIO_DIRECTION_OUTPUT,

.segment_pins[2].port=PORTC_INDEX,
.segment_pins[2].pin=PIN2,
.segment_pins[2].logic=GPIO_LOGIC_LOW,
.segment_pins[2].direction=GPIO_DIRECTION_OUTPUT,

.segment_pins[3].port=PORTC_INDEX,
.segment_pins[3].pin=PIN3,
.segment_pins[3].logic=GPIO_LOGIC_LOW,
.segment_pins[3].direction=GPIO_DIRECTION_OUTPUT,

.segment_type=SEGMENT_COMMON_ANODE,

};

button_t hr_btn={
.button_pin.port=PORTB_INDEX,
.button_pin.pin=PIN0,
.button_pin.direction=GPIO_DIRECTION_INPUT,
.button_pin.logic=GPIO_LOGIC_LOW,
.button_active=BUTTON_ACTIVE_HIGH,
.button_state=BUTTON_RELEASED 
};


button_t min_btn={
.button_pin.port=PORTB_INDEX,
.button_pin.pin=PIN1,
.button_pin.direction=GPIO_DIRECTION_INPUT,
.button_pin.logic=GPIO_LOGIC_LOW,
.button_active=BUTTON_ACTIVE_HIGH,
.button_state=BUTTON_RELEASED 
};


led_t led1={
.port_name=PORTA_INDEX,
.pin=PIN3,
.led_status=GPIO_LOGIC_LOW,
};


void ecu_layer_intialize(void) {
    Std_ReturnType ret = E_NOT_OK;
    ret = seven_segment_intialize(&seven_seg1);
    ret = gpio_port_direction_initialize(PORTD_INDEX, 0xc0);

    ret = button_initialize(&hr_btn);
    ret = button_initialize(&min_btn);
  
    ret= led_intialize(&led1);
    
   
}
