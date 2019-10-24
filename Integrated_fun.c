/* MODULE      : Integrated Functions
 * file type   : C file
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

                           /*********************************************
                                       H files Included
                           *********************************************/




#include "integrated_fun.h"


                                      /*******************************************************************************
                 *                    *                     Functions Definitions                                  *
                                     *******************************************************************************/




void INIT_functions (void){

	/* This function initiates the function in the lower layer that needed
	 * to be initiated in the start of the program
	   */
	LCD_init();
	motor_1_init();
}
void Request_number_from_user(const char *str){

	/*Function used to print to the user some thing we need to be supplied
	 * The function returns void and accepts constant string to be shown
	 * to the user .
	 * The function not used to get any data , just for printing
	 *
	 * */

	LCD_clearScreen();
	LCD_displayString("Hello,");
	LCD_goToRowColumn(Second_ROW,First_Char);
	LCD_displayString("Please enter");
	LCD_goToRowColumn(Third_ROW,First_Char);
	LCD_displayString(str);
	LCD_goToRowColumn(Fourth_ROW,First_Char);
	LCD_displayString("_ _ _");
	_delay_ms(500);


}

void Menu_of_options(void){
	/* Void function with void argument
	 * the Function used to print some option to the user
	 * to make operations on the motor during the runtime
	 * The function not used to get any data , just for printing
	 * */
	    LCD_clearScreen();
		LCD_displayString("(+,-):ctrl.speed");
		LCD_goToRowColumn(Second_ROW,First_Char);
		LCD_displayString("(=):adj.speed");
		LCD_goToRowColumn(Third_ROW,First_Char);
		LCD_displayString("(%,X):START/STOP");
		LCD_goToRowColumn(Fourth_ROW,First_Char);
		LCD_displayString("(1):inv.direction");


}

void Current_state (uint8 speed , uint8 direction){
	/*Function accepts two arguments
	 * The function not used to get any data , just for printing
	 * it printing the speed and the direction of rotation
	 * it updated continuously

	 *
	 * */
	    LCD_clearScreen();
		LCD_displayString("Current state");
		LCD_goToRowColumn(Second_ROW,First_Char);
		LCD_displayString("Speed:");
		LCD_intgerToString(speed);
		LCD_displayCharacter('%');
		LCD_goToRowColumn(Third_ROW,First_Char);

	if(direction == MOTOR_IS_CLOCK_WISE){
		LCD_displayString("direction:");
		LCD_displayString("CW");
	}
	if(direction == MOTOR_IS_ANTI_CLOCK_WISE){
		LCD_displayString("direction:");
			LCD_displayString("anti_CW");
		}
	if(direction == MOTOR_IS_STOP){
		LCD_displayString("Statue:");
				LCD_displayString("STOP");
			}

	LCD_goToRowColumn(Fourth_ROW,First_Char);
	LCD_displayString("Any key:Menu");


}


uint16 Take_number_from_user (void){
	/*
	 * The function take number through the keypad and returns is as
	 * uint16 ( unsigned long ) to be used by any function in the code
	 * Mainly , Function algorithm is to accepts the data in array and
	 * then convert it to uint16
	 * you can change #define MAX_NUMBER_OF_PRECENTAGE to get more or less character
	 *
	 * The function can returns to you any number in the range of uint16
	 * As in application , user may enter 999 which will exceed borders of the uint8
	 * The function will pass only lower byte so we make it uint16 and by casting after adjusting
	 * in (adjust_number_from_user ) function , we will be able to use uint8 number (0 - 100 )

	 * */
    LCD_clearScreen();
    LCD_displayString("Speed:");
    LCD_goToRowColumn(Fourth_ROW,First_Char);
    LCD_displayString("'=':confirm");
    LCD_goToRowColumn(Third_ROW,First_Char);
    LCD_displayString("___");
    LCD_goToRowColumn(Third_ROW,First_Char);

	uint16 result ;
	uint8 Key ;
	precentage_array[0]=0 ;
	precentage_array[1]=0 ;
	precentage_array[2]=0 ;
    uint8 digit_counter =0 ;


	//for(int i=0 ;i<MAX_NUMBER_OF_PRECENTAGE ;i++){

/*	Key = KeyPad_getPressedKey();
if(  (   Key>=0 && Key<=9   )  || ( Key =='=' ) ){

	if(Key >=0 && Key<=9 ){
	        precentage_array[i]=Key;
			_delay_ms(200);
			LCD_intgerToString(precentage_array[i]);
			digit_counter ++ ;

	} */

		do {
			Key = KeyPad_getPressedKey();


				if(Key >=0 && Key<=9 ){
				        precentage_array[digit_counter]=Key;
						_delay_ms(300);
						LCD_intgerToString(precentage_array[digit_counter]);
						digit_counter ++ ;
				}

		}

	while ((digit_counter != MAX_NUMBER_OF_PRECENTAGE) && (Key != '=' ));




if(digit_counter == MAX_NUMBER_OF_PRECENTAGE){


	result = 100* precentage_array[0] + 10* precentage_array[1] + precentage_array[2] ;

}
if(digit_counter ==  MAX_NUMBER_OF_PRECENTAGE-1){
	result = (10 *precentage_array[0])+ (precentage_array[1]) ;

}
if(digit_counter == MAX_NUMBER_OF_PRECENTAGE-2){
	result = precentage_array[0] ;

}

return result ;

}


uint16 adjust_number_from_user(uint16 number){
/* A uint16 function that accepts one uint16 argument
 * This function is made to make the previous function more general
 * This function is application specified
 * This function made to save the limit of the percentage in the application
 * If I get number more than 100 , the number will be 100
 *
 *
 * */
if(number > MAX_PRECENTAGE){
	return MAX_PRECENTAGE ;
}
else {
	return number ;
}

}

void Control_function (uint8 key_read ,uint8 *INPUT){

	/*A void function with two arrguments : uint8 variable and pointer
	 * Function accepts a control option :
	 * 1-increase / decrease speed
	 * 2- stop motor
	 * 3-start motor again
	 * 4- adjust speed numerically
	 * 5- inverse the motor direction
	 *
	 * */

	if(key_read=='+'){

	*INPUT =*INPUT + MOTOR_INC_DEC_RATE ;
	      if(*INPUT > MAX_INC_DEC_RATE){
		*INPUT = MAX_INC_DEC_RATE ;
	    }

	 }
	if(key_read=='-'){

	*INPUT =*INPUT - MOTOR_INC_DEC_RATE ;
	      if(INPUT <= MIN_INC_DEC_RATE){
		*INPUT = MIN_INC_DEC_RATE ;
	    }

	 }
	if(key_read=='*'){

		motor_stops(motor_1);

	 }

	if(key_read=='%'){

		  motor_runs(motor_1 , clockWise);

	 }
	if(key_read=='='){
		const char *a_str = "edit speed" ;
		Request_number_from_user(a_str);
		_delay_ms(200);
		uint8 read_number =  (uint8) adjust_number_from_user(Take_number_from_user());
		*INPUT = read_number ;

	}

if (key_read ==1){
	if(motor_statues(motor_1)==MOTOR_IS_ANTI_CLOCK_WISE) {
		motor_runs(motor_1 , clockWise);

	}
	else if (motor_statues(motor_1)==MOTOR_IS_CLOCK_WISE){

		motor_runs(motor_1 , anticlockWise);
	}
	_delay_ms(300);
}




}




