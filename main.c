
#include "integrated_fun.h"
const char *str = "Motor's speed %";
uint8 g_speed ;
uint8 * ptr_gspeed =& g_speed ;
uint8 key_read ;
int main (void){



/*Initiating code :
 * 1- Initiate all functions needed to be initiated (motors , LCD )
 * 2- Request from the user to enter the initial speed of motor
 * 3- take the number and make it as PWM output on OC0
 * 4- make the motor runs clockwise as initial move
 *

 * */
	 INIT_functions();
	 Request_number_from_user(str);
	 g_speed = adjust_number_from_user (Take_number_from_user() );
	 _delay_ms(300);
	 LCD_clearScreen();
	 LCD_displayString("Speed is :");
	 LCD_goToRowColumn(1,4);
     LCD_intgerToString(g_speed);
     LCD_displayCharacter('%');
     adjust_speed_precentage(g_speed);
     motor_runs(motor_1 , clockWise);



	while(1){

           /* This function will print the current states of the motor
            * 1- The speed of motor
            *  2- The direction of the motor
 */
		     Current_state (g_speed ,motor_statues(motor_1));



		     /* This function has 2 advantages
		      * 1- It accepts the key reading
		      * 2- Polling to show the current state if the user dont want to change any system parameter */

		     key_read =KeyPad_getPressedKey();


			 /*If the user press any Key , It will appear to him Menu of options
			  *  1-increase / decrease speed
            	 * 2- stop motor
	               * 3-start motor again
	                  * 4- adjust speed numerically
	                    * 5- inverse the motor direction
			  */
		     Menu_of_options();



		     /* Get from the user the option to be activated
		      * If user don't make any option , function will polling
		      * The system will have not any effect by this polling ,
		      * Motors is running  */


		     key_read =KeyPad_getPressedKey();


		     /*This function modifies the motor settings according to the chose in the Menu
		      * Function will modify
		       1- The speed of motor
                   2- The direction of the motor
		      * */
		     Control_function (key_read ,ptr_gspeed);

		     /*Send the new speed to OC0 pin */
		     adjust_speed_precentage(g_speed);

	}




}
