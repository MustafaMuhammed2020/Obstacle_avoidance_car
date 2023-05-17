/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 16 May , 2021                                   **/
/** Version : V01                                             **/
/***************************************************************/

/** INCLUDE LIBRARIES **/
#include "avr/interrupt.h"
#include "../SERVICE/common_macros.h"
#include "../SERVICE/standard_types.h"

/** INCLUDE LOWER LAYERS FILES **/
#include "../MCAL/dio/DIO_interface.h"
#include "../MCAL/int0/INT_interface.h"
#include "../MCAL/timer1/timer1_interface.h"
#include "../HAL/lcd/LCD_interface.h"
#include "../MCAL/timer0/TMR0_interface.h"
#include "../HAL/motor/motor_interface.h"
#include "../HAL/motor/motor_config.h"

/** INCLUDE DRIVER FILES **/
#include "APP.h"

uint8_t u8_g_edge  ;  /** GLOBAL COUNTER FOR NUMBER OF EDGES **/
uint16t u16_g_time ; /** GLOBAL VARIABLE FOR TIME **/

void APP_init()
{
	u8_g_edge = 0 ,  u16_g_time = 0 ; /** INITIALIZATION FOR EDGES COUNTER **/
	
	DIO_setpindir(DIO_PORTD , DIO_PIN2 , DIO_PIN_INPUT); /** INT0 PIN **/
	
	INT0_init(); /** INITIALIZE INT0 **/
	
	TMR0_init(); /** INITIALIZE TIMER0 **/
	
	TMR1_init(); /** INITIALIZE TIMER1 **/
	
	LCD_init(); /** INITIALIZE LCD **/
	
	TMR0_delayms(50); /** DELAY FOR LCD INITIALIZATION **/
	
	MOTOR_init(MOTOR1_ID); /** INITIALIZE 4 MOTORS **/
	MOTOR_init(MOTOR2_ID);
	MOTOR_init(MOTOR3_ID);
	MOTOR_init(MOTOR4_ID);
	
	MOTOR_rotateclkdir(MOTOR1_ID); /** ROTATION DIRECTION **/
	MOTOR_rotateclkdir(MOTOR2_ID);
	MOTOR_rotateclkdir(MOTOR3_ID);
	MOTOR_rotateclkdir(MOTOR4_ID);
	
	
}


void APP_start()
{
	//MOTOR_applyspeed(MOTOR1_ID , speed_50);
	
	DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_HIGH);
	
// 	DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_HIGH);
 	TMR0_delaymicros(64);
// 	
 	DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_LOW);
 	TMR0_delaymicros(64);
	//MOTOR_applyspeed(MOTOR2_ID , speed_50);
	//MOTOR_applyspeed(MOTOR3_ID , speed_50);
	//MOTOR_applyspeed(MOTOR4_ID , speed_50);
	
	
// 	LCD_goto(0 , 1);
// 	LCD_writeint(u16_g_time);
// 	TMR0_delayms(1000);
// 	
// 	LCD_sendcmd(LCD_CLEAR);
// 	TMR0_delayms(20);
	
}


ISR(INT0_vect) /** ISR OF INT0 **/
{
	MOTOR_turnoff(MOTOR1_ID);
	MOTOR_turnoff(MOTOR2_ID);
	MOTOR_turnoff(MOTOR3_ID);
	MOTOR_turnoff(MOTOR4_ID);
	
// 	if (u8_g_edge == 0 ) 
// 	{
// 		TMR1_start();
// 		
// 		u8_g_edge = 1 ;
// 	}
// 	
//  	else if (u8_g_edge == 1 ) 
//  	{
//  		TMR1_stop(); 
// 		 
// 		TMR1_getvalue(&u16_g_time);
// 		 
// 		u8_g_edge = 0 ; /** REINITIALIZE THE EDGES COUNTER TO 0 **/
// 	}
	
}