
/* MODULE      : Motor drive
 * file type   : H file
 * AUTHOR      : Mohamed Ashraf Ibrahim
 * Description : Header file for controlling 1 or 2 motors
 *
 * Notes       : This driver implemented by me from scratch :)
 *
 *               Please check your connections and if it is different,
 *               redefine ports to be fit your drive connection
 *
 *               To use PWM features , you can send required voltage on MOTOR_ENABLE Macros
 *
 *
 */



#ifndef _MOTOR_H
#define _MOTOR_H

                          /*********************************************
                                       H files Included
                           *********************************************/
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"
#include "stdlib.h"
#include "timer_0.h"


              /*******************************************************************************
              *                      Preprocessor Macros                                    *
              *******************************************************************************/


#define MOTOR_PORT_DIR DDRB
#define MOTOR_PORT_OUT PORTB


#define MOTOR_INPUT_0    PB0
#define MOTOR_INPUT_1    PB1
#define MOTOR_INPUT_2    PB2
/*Pin 3 reserved for PWM by timer_0 for only one motor */
#define MOTOR_INPUT_3    PB4
#define MOTOR_ENABLE_1   PB3   /*Pin 3 reserved for PWM by timer_0 for only one motor */
#define MOTOR_ENABLE_2   PB6   /* In case of PWM , Change the pin from here to the PWM output pin */


#define motor_1   11
#define motor_2   12
#define clockWise 13
#define anticlockWise 14

/* Making the numbers represent the state of motor */

#define MOTOR_IS_STOP  0                                          /* (00) */
#define MOTOR_IS_CLOCK_WISE 1                                     /* (10) */
#define MOTOR_IS_ANTI_CLOCK_WISE 2                                /* (01) */
#define MOTOR_ERROR  5                                            /* 5 to represent out of possibilities */


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


void motor_1_init(void);
void motor_2_init(void);
void motor_runs(uint8 motor_name , uint8 direction);
void motor_stops (uint8 motor_name);
uint8 motor_statues(uint8 motor_name);
void adjust_speed_precentage(float32 precentage) ;


#endif
















