Human Interface for Dynamically Controlling and Monitoring DC motor

Project Description: 

Using the module to control the speed and the direction of a dc motor, the module also allows the user to track the motor statue at running time by monitoring the statue through LCD. Module gives you the access to change speed by direct adjusting or by gradually increase / decrease the speed and also to control motor’s direction. 

About the project 

I tried in the project to apply the concept of layered code. I made standard_types.h, common_macros.h and micro_config.h as lowest layer. 
I implemented timer0 (c and h) as second layer.

Then I implemented motor driver (c and h) from scratch, this module support full controlling on DC motor in addition to feedback function. So this driver can be used in any other projects and independently from the whole project by including the previous h files (lower layer + timer layer).

I also implemented keypad driver and LCD driver as (c and h) and also each of them can be used independently.   
Next layer I named it integrated layer (c and h), I used the previous layer to make function suitable for the application using a mix of functions from previous layers by such calling it. 

Lastly the APP layer, which include the main function and the program. 

Designed on AVR ATmega16 Microcontroller

The code is fully commented.


Features: 
1-	Controlling speed by direct adjustment or by gradually increasing or decreasing. 
2-	Control the direction of the motor at run time.
3-	Human Interface for dynamically controlling. 
4-	Easy Configurable code and layered code. 

-For Simulation check GIF file. 
-For documentation check PDF file.
