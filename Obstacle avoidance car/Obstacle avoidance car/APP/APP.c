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
#include "../HAL/icu/ICU_interface.h"
#include "../HAL/ultrasonic/ultrasonic_interface.h"

/** INCLUDE DRIVER FILES **/
#include "APP.h"

uint16t u16_g_distance1 = 0   ;
uint16t u16_g_distance2 = 0  ;
uint32_t u32_g_distance  = 0  ;
uint16t u8_echoedge = 0 ;    /** GLOBAL VARIABLE FOR THE ECHO PULSE STATE **/


uint8_t counter = 0  ;  /** GLOBAL COUNTER FOR NUMBER OF EDGES **/
uint16t u16_g_time ; /** GLOBAL VARIABLE FOR TIME **/

void APP_init()
{
	u16_g_time = 0 ; /** INITIALIZATION FOR EDGES COUNTER **/
	
	//DIO_setpindir(DIO_PORTD , DIO_PIN2 , DIO_PIN_INPUT); /** INT0 PIN **/
	
// 	INT0_init(); /** INITIALIZE INT0 **/
// 	TMR1_init(); /** INITIALIZE TIMER1 **/

    ICU_init(); /** INITIALIZE ICU **/

	US_init(); /** INITILAIZATION ULTRASONIC MODULE **/
	
	TMR0_init(); /** INITIALIZE TIMER0 **/
	
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
	
	LCD_goto(0,1);
	LCD_writeint(23);
	TMR0_delayms(500);
}


void APP_start()
{

	US_sendtrigger(); /** SEND TRIGGER **/
	LCD_goto(0,1);
	
	u32_g_distance = (u16_g_time/464) ;
	
	LCD_writeint(u32_g_distance);

// 	if(u32_g_distance > 0 && u32_g_distance > 40)
// 	{
// 			MOTOR_turnon(MOTOR1_ID);
// 			MOTOR_turnon(MOTOR2_ID);
// 			MOTOR_turnon(MOTOR3_ID);
// 			MOTOR_turnon(MOTOR4_ID);
// 			TMR0_delaymicros(3200);
// 			
// 			MOTOR_turnoff(MOTOR1_ID);
// 			MOTOR_turnoff(MOTOR2_ID);
// 			MOTOR_turnoff(MOTOR3_ID);
// 			MOTOR_turnoff(MOTOR4_ID);
// 			TMR0_delaymicros(3200);
// 
// 	}
	
}


ISR(INT0_vect)
{
	counter++ ;
	
	if(counter == 1)
	{
		ICU_start(); /** START ICU / COUNTING **/
	}
	
	else if(counter == 2)
	{
		ICU_stop(); /** STOP ICU / COUNTING **/
		
		u16_g_time = ICU_getvalue(); /** GET PULSE LENGTH **/
		
		ICU_setcounterval(0); /** START COUNTING FROM ZERO **/
		
		counter = 0 ;
	}
}

ISR(TIMER1_OVF_vect)
{
	/** DO NOTHING **/
}