/* MODULE      : Integrated Functions
 * file type   : H file
 * AUTHOR      : Mohamed Ashraf Ibrahim
 * Description : Header file for Integrated functions by using
 *               motors , LCD and keypad
 *
 * Notes       : This driver implemented by me from scratch :)
 *
 *               Please check your connections and if it is different,
 *               redefine ports to be fit your drive connection
 *
 *
 */



#ifndef INTEGRATED_FUN_H
#define INTEGRATED_FUN_H


                           /*********************************************
                                       H files Included
                           *********************************************/


#include "motor.h"
#include "lcd.h"
#include "keypad.h"


              /*******************************************************************************
              *                      Preprocessor Macros                                    *
              *******************************************************************************/


#define MAX_NUMBER_OF_PRECENTAGE 3
#define MOTOR_INC_DEC_RATE 10
#define MAX_INC_DEC_RATE 100
#define MIN_INC_DEC_RATE 0
#define MAX_PRECENTAGE 100

           /*******************************************************************************
               *                      Variables definition                                 *
              *******************************************************************************/



uint8 precentage_array[MAX_NUMBER_OF_PRECENTAGE];

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void INIT_functions (void);
uint16 Take_number_from_user (void) ;
uint16 adjust_number_from_user(uint16 number);
void Request_number_from_user(const char *str);
void Menu_of_options(void);
void Current_state (uint8 speed , uint8 direction);
void Control_function (uint8 key_read , uint8 *INPUT);












#endif
