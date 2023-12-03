/* 
 * File:   application.h
 * Author: Hobvv
 *
 * Created on September 11, 2023, 8:42 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/*Section : Includes*/
#include "ECU_Layer/ecu_layer_init.h"
/*Section : Macros declaration*/
#define _XTAL_FREQ 8000000UL

/*Section : Macros Function Declaration*/

/*Section : DataTypes Declaration*/

extern seven_segment_t seven_seg1;
extern button_t hr_btn;
extern button_t min_btn;

extern led_t led1;


/*Section : Functions Declaration*/
void application_intialize(void);



#endif	/* APPLICATION_H */

