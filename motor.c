/* MODULE      : Motor drive
 * file type   : H file
 * AUTHOR      : Mohamed Ashraf Ibrahim
 * Description : Source file for controlling 1 or 2 motors
 *
 * Notes       : This driver implemented by me from scratch :)
 *               Please check your connections and if it is different,
 *               redefine ports to be fit your drive connection
 *
 */


                           /*********************************************
                                       H files Included
                           *********************************************/





#include "motor.h"
#include "timer_0.h"

               /*******************************************************************************
                *                      Functions Definitions                                  *
               *******************************************************************************/




void motor_1_init(void){

	SET_BIT(MOTOR_PORT_DIR , MOTOR_INPUT_0);  /*Make direction as output for motor */
	SET_BIT(MOTOR_PORT_DIR , MOTOR_INPUT_1);

	/* Make Stop as initial position of Motor */

	CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_0);
	CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_1);

	/* Making initial condition without PMW */

	SET_BIT(MOTOR_PORT_OUT , MOTOR_ENABLE_1);
}


void motor_2_init(void){

	SET_BIT(MOTOR_PORT_DIR , MOTOR_INPUT_2);  /*Make direction as output for motor */
	SET_BIT(MOTOR_PORT_DIR , MOTOR_INPUT_3);

	/* Make Stop as initial position of Motor */

	CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_2);
	CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_3);

	/* Making initial condition without PMW */

	SET_BIT(MOTOR_PORT_OUT , MOTOR_ENABLE_2);
}

void motor_runs(uint8 motor_name , uint8 direction){

	/*
	 * This function accepts two parameters , name of the motor and direction.

	 * motors names are included at ( motor_1 and motor_2 )
	   Any other parameters will give you an error.

	 * motors directions are included at (CW "Clock_Wise ) and (ACW "Anti_Clock_Wise")
	   Any other parameters will give you an error.
	 *
	 * */

	if(motor_name == motor_1){
		if(direction == clockWise){
			SET_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_0);
			CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_1);
		}
		if(direction == anticlockWise){
			SET_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_1);
			CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_0);

				}
	}
	if(motor_name == motor_2){
			if(direction == clockWise){
				SET_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_2);
				CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_3);


			}
			if(direction == anticlockWise){
				CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_2);
				SET_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_3);
					}
		}

}

void motor_stops (uint8 motor_name){

	/*
		 * This function accepts one parameter ; name of the motor.

		 * motors names are included at ( motor_1 and motor_2 )
		   Any other parameters will give you an error.

		 * The function stops the motor which is given.
		 *
		 * */
	if(motor_name == motor_1){
		CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_0);
			CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_1);

	}

	if(motor_name == motor_2){
		CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_2);
		CLEAR_BIT(MOTOR_PORT_OUT , MOTOR_INPUT_3);
	}


}

uint8 motor_statues(uint8 motor_name){

	/*
		 * This function accepts one parameter ; name of the motor.
		 * This function returns a number indicating the status of the motor

		 * motors names are included at ( motor_1 and motor_2 )
		   Any other parameters will give you an error.

		 * The returns of the function
		 *
		 *     #define MOTOR_IS_STOP  0                    (00)
               #define MOTOR_IS_CLOCK_WISE 1               (01)
               #define MOTOR_IS_ANTI_CLOCK_WISE 2          (10)
               #define MOTOR_ERROR  5                      (can't be represented)
		 *
		 * */
	if(motor_name == motor_1){
			if( BIT_IS_CLEAR(MOTOR_PORT_OUT , MOTOR_INPUT_0) && BIT_IS_CLEAR(MOTOR_PORT_OUT , MOTOR_INPUT_1)   ){


             return  MOTOR_IS_STOP ;


			}
			if( BIT_IS_CLEAR(MOTOR_PORT_OUT , MOTOR_INPUT_0) && BIT_IS_SET(MOTOR_PORT_OUT , MOTOR_INPUT_1)   ){


				return MOTOR_IS_ANTI_CLOCK_WISE ;

						}
			if( BIT_IS_CLEAR(MOTOR_PORT_OUT , MOTOR_INPUT_1) && BIT_IS_SET(MOTOR_PORT_OUT , MOTOR_INPUT_0)   ){

                 return MOTOR_IS_CLOCK_WISE ;
					}
			else {
				return MOTOR_ERROR ;
			}
		}

	if(motor_name == motor_2){
				if( BIT_IS_CLEAR(MOTOR_PORT_OUT , MOTOR_INPUT_2) && BIT_IS_CLEAR(MOTOR_PORT_OUT , MOTOR_INPUT_3)   ){


	             return  MOTOR_IS_STOP ;


				}
				if( BIT_IS_CLEAR(MOTOR_PORT_OUT , MOTOR_INPUT_2) && BIT_IS_SET(MOTOR_PORT_OUT , MOTOR_INPUT_3)   ){


					return MOTOR_IS_CLOCK_WISE ;

							}
				if( BIT_IS_CLEAR(MOTOR_PORT_OUT , MOTOR_INPUT_3) && BIT_IS_SET(MOTOR_PORT_OUT , MOTOR_INPUT_2)   ){


	                 return MOTOR_IS_ANTI_CLOCK_WISE ;

							}
				else {
					return MOTOR_ERROR ;
				}

			}
	else {
		return MOTOR_ERROR ;
	}

}

void adjust_speed_precentage(float32 precentage){
if(precentage >=0 && precentage <=100){

	uint8 speed = (uint8) ( (precentage/100.0) * MAX_PWM_REGISTER_NUMBER) ;
    PWM_Timer0_Init(speed);
}
else {
	PWM_Timer0_Init(MAX_PWM_REGISTER_NUMBER);
}

}
