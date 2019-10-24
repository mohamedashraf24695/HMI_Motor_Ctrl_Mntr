#ifndef _TIMER_0_H_
#define _TIMER_0_H_


                           /*********************************************
                                       H files Included
                           *********************************************/
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"
#include "stdlib.h"


              /*******************************************************************************
              *                      Preprocessor Macros                                    *
              *******************************************************************************/

#define PMW_TIMER0_DDR DDRB
#define PMW_TIMER0_BIT PB3
#define MAX_PWM_REGISTER_NUMBER 255

 /*********************************************
                                      Functions prototypes
                        *********************************************/

void PWM_Timer0_Init(uint8 set_duty_cycle);

#endif
