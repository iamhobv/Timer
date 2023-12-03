/* 
 * File:   7_segment.h
 * Author: Hobvv
 *
 * Created on October 22, 2023, 4:57 PM
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H


 /*Section : Includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "7_segments_cfg.h"

/*Section : Macros declaration*/
#define SEGMENT_PIN0 0
#define SEGMENT_PIN1 1
#define SEGMENT_PIN2 2
#define SEGMENT_PIN3 3

/*Section : Macros Function Declaration*/

/*Section : DataTypes Declaration*/
typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE            
}seven_segment_type_t;
typedef struct {
    pin_config_t segment_pins[4];
    seven_segment_type_t segment_type;
}seven_segment_t;
/*Section : Functions Declaration*/
Std_ReturnType seven_segment_intialize(const seven_segment_t* segment);
Std_ReturnType seven_segment_write_number(const seven_segment_t* segment,uint8 number);
#endif	/*SEVEN_SEGMENT_H */

