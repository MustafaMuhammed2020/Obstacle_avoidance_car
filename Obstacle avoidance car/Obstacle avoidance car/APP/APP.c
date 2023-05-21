/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 16 May , 2023                                   **/
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
#include "../MCAL/timer2/TMR2_interface.h"
#include "../HAL/motor/motor_interface.h"
#include "../HAL/motor/motor_config.h"
#include "../HAL/keypad/KEYPAD_interface.h"
#include "../HAL/button/button_interface.h"
#include "../HAL/button/button_config.h"
#include "../HAL/icu/ICU_interface.h"
#include "../HAL/ultrasonic/ultrasonic_interface.h"

/** INCLUDE DRIVER FILES **/
#include "APP.h"

uint8_t u8_g_distance = 0 ;         /** GLOBAL COUNTER TO CALCULATE THE DISTANCE **/
uint16t u16_g_time = 0  ;           /** GLOBAL VARIABLE FOR TIME **/
uint8_t u8_echoedge = 0 ;           /** GLOBAL VARIABLE FOR THE ECHO PULSE STATE **/
uint8_t u8_g_rotationbtn = 0 ;      /** GLOBAL VARIABLE TO HOLD THE ROTATION DIRECTION **/
uint8_t u8_g_rotationcounter = 0 ;  /** GLOBAL VARIABLE FOR THE ROTATION DIRECTION SET **/
uint32_t u32_g_delay = 0 ;          /** GLOBAL VARIABLE TO CALCULATE NUMBER OF OVERFLOWS FOR SPECIFIC DELAY **/
uint32_t u32_g_tick = 0 ;           /** GLOBAL VARIABLE TO BE COMPARED WITH DELAY TICKS **/   

/** FUNCTION TO INITIALIZE APPLICATION MODULES **/
void APP_init()
{
    ICU_init(); /** INITIALIZE ICU **/

	US_init(); /** INITILAIZATION ULTRASONIC MODULE **/
	
	TMR0_init(); /** INITIALIZE TIMER0 **/
	
	TMR2_init() ; /** INITIALIZE TIMER 2 **/
	
	KEYPAD_init() ; /** INITIALIZE KEYPAD **/
	
	Button_init(); /** INITIALIZATION OF BUTTON **/
	
	LCD_init(); /** INITIALIZE LCD **/
	
	TMR0_delayms(50); /** DELAY FOR LCD INITIALIZATION **/

	MOTOR_init(MOTOR1_ID); /** INITIALIZE 4 MOTORS **/
	MOTOR_init(MOTOR2_ID);
	MOTOR_init(MOTOR3_ID);
	MOTOR_init(MOTOR4_ID);
	
	MOTOR_rotateclkdir(MOTOR1_ID); /** DEFAULT ROTATION DIRECTION "RIGHT" **/
	MOTOR_rotateclkdir(MOTOR2_ID);
	MOTOR_rotateclkdir(MOTOR3_ID);
	MOTOR_rotateclkdir(MOTOR4_ID);

}

/** FUNCTION TO SET DEFAULTS **/
void APP_setentry()
{
	uint8_t u8_a_btnstatus = 0 , u8_a_pressednum = 0 ;
	
 	u32_g_tick = 0 ;
	 
 	u32_g_delay =  TMR2_getovs(5000) ; /** GET THE NUMBER OF OVERFLOWS NEEDED FOR 5 SECONDS **/

 	TMR2_start() ; /** START TIMER 2 **/

 	while ( u32_g_tick < u32_g_delay) /** UNTILL TICKS OF 5 SECONDS **/
	{
 		LCD_goto(0 , 1);
 		LCD_writestr("Set Def. Rot");

 		Is_pressed(BUTTON1_PORT , BUTTON1_PIN , &u8_a_btnstatus); /** CHECK IF THE BUTTON PRESSED **/
 		TMR0_delayms(100); /** WAIT 100 MS FOR BUTTON TO SETTLE **/
 		Is_pressed(BUTTON1_PORT , BUTTON1_PIN , &u8_a_btnstatus); /** CHECK IF THE BUTTON IS STILL PRESSED **/

		if (u8_a_btnstatus) /** IF THE BUTTON PRESSED **/
 		{
 			u8_g_rotationcounter++ ; /** INCREASE ROTATION COUNTER BY 1 **/

 			if (u8_g_rotationcounter == LEFT_ROTATION) /** LEFT ROTATION **/
 			{
				LCD_goto(1 , 1);
				LCD_writestr("LEFT ROTATION");
			}
	 		else if(u8_g_rotationcounter == RIGHT_ROTATION) /** RIGHT ROTATION **/
	 		{
 				LCD_goto(1 , 1);
 				LCD_writestr("RIGHT ROTATION");
 			}
			u8_a_btnstatus = 0 ; /** REINITIALIZE THE BUTTON STATE **/
 		}
 	}
	
 	TMR2_stop(); /** STOP TIMER 2 **/
		
	do /** ACCEPT KEYPAD BUTTON 1 FROM USER **/
	{
 		KEYPAD_read(&u8_a_pressednum);
 	} while (u8_a_pressednum != START_BTN);

 	 LCD_sendcmd(LCD_CLEAR);
	 TMR0_delayms(20);
	 
	 LCD_goto(0 ,2 );
	 LCD_writestr("Waiting");
	 
	 TMR0_delayms(2000); /** WAIT 2 SECONDS **/
	 
	 LCD_sendcmd(LCD_CLEAR);
	 TMR0_delayms(20);
	 
}

void APP_start()
{	
	u32_g_tick = 0 , u32_g_delay = 0 ; /** VARIABLES TO HANDLE THE DELAY **/
	
	US_sendtrigger(); /** SEND TRIGGER **/
		
	u32_g_delay =  TMR2_getovs(5000) ; /** GET THE NUMBER OF OVERFLOWS NEEDED FOR 5 SECONDS **/
	
	while((u16_g_time/DISTANCE_DIV) > SAFE_DISTANCE) /** DISTANCE GREATER THAN 70 **/
		{		
			u8_g_distance = (u16_g_time/DISTANCE_DIV) ; /** CALCULATE THE DISTANCE **/
			
			TMR2_start() ; /** START TIMER 2 **/
		
			while (u32_g_tick < u32_g_delay)
			{
				/** MOVE WITH 50% SPEED FOR 5 MIN **/
				MOTOR_turnon(MOTOR1_ID);
				MOTOR_turnon(MOTOR2_ID);
				MOTOR_turnon(MOTOR3_ID);
				MOTOR_turnon(MOTOR4_ID);
				LCD_goto(0,1) ;
				TMR0_delaymicros(SPEED_50_ON_TIME);
				
				MOTOR_turnoff(MOTOR1_ID);
				MOTOR_turnoff(MOTOR2_ID);
				MOTOR_turnoff(MOTOR3_ID);
				MOTOR_turnoff(MOTOR4_ID);
				LCD_writestr("Distance :");
				LCD_writeint(u8_g_distance);
			}
					
			TMR2_stop() ; /** STOP TIMER2 AFTER THE 5 SECONDS **/
					
			/** CONTINUE WITH 30% **/
			MOTOR_turnon(MOTOR1_ID);
			MOTOR_turnon(MOTOR2_ID);
			MOTOR_turnon(MOTOR3_ID);
			MOTOR_turnon(MOTOR4_ID);
			LCD_goto(0,1) ;
			TMR0_delaymicros(SPEED_30_ON_TIME);
			
			MOTOR_turnoff(MOTOR1_ID);
			MOTOR_turnoff(MOTOR2_ID);
			MOTOR_turnoff(MOTOR3_ID);
			MOTOR_turnoff(MOTOR4_ID);
			LCD_writestr("Distance :");
			LCD_writeint(u8_g_distance);
			
			US_sendtrigger(); /** SEND TRIGGER **/
		}

	while((u16_g_time/DISTANCE_DIV) >= DISTANCE_30) /** DISTANCE BETWEEN 70 AND 30 **/
	{
		/** CONTINUE WITH 30% **/
		MOTOR_turnon(MOTOR1_ID);
		MOTOR_turnon(MOTOR2_ID);
		MOTOR_turnon(MOTOR3_ID);
		MOTOR_turnon(MOTOR4_ID);
		LCD_goto(0,1) ;
		TMR0_delaymicros(SPEED_30_ON_TIME);
		
		MOTOR_turnoff(MOTOR1_ID);
		MOTOR_turnoff(MOTOR2_ID);
		MOTOR_turnoff(MOTOR3_ID);
		MOTOR_turnoff(MOTOR4_ID);
		LCD_writestr("Distance :");
		LCD_writeint(u8_g_distance);
		US_sendtrigger(); /** SEND TRIGGER **/
	}
	
	u32_g_tick = 0 ;
	u32_g_delay =  TMR2_getovs(500) ; /** GET THE NUMBER OF OVERFLOWS NEEDED FOR 5 SECONDS **/
	
	while((u16_g_time/DISTANCE_DIV) >= DISTANCE_20) /** DISTANCE FROM 20 TO 30 CM **/
	{
		/** STOP THEN ROTATE **/
		MOTOR_turnoff(MOTOR1_ID);
		MOTOR_turnoff(MOTOR2_ID);
		MOTOR_turnoff(MOTOR3_ID);
		MOTOR_turnoff(MOTOR4_ID);
		
		TMR2_start() ; /** START TIMER 2 **/
		while (u32_g_tick < u32_g_delay)
		{
			/** ROTATION **/
			MOTOR_turnon(MOTOR3_ID);
			MOTOR_turnon(MOTOR4_ID);
		}
		TMR2_stop(); /** STOP TIMER 2 **/
			
		while((u16_g_time/DISTANCE_DIV) >= DISTANCE_30) /** WHEN DISTANCE BECOME MORE THAN 30 CM **/
		{
			/** CONTINUE WITH 30% **/
			MOTOR_turnon(MOTOR1_ID);
			MOTOR_turnon(MOTOR2_ID);
			MOTOR_turnon(MOTOR3_ID);
			MOTOR_turnon(MOTOR4_ID);
			LCD_goto(0,1) ;
			TMR0_delaymicros(SPEED_30_ON_TIME);
			
			MOTOR_turnoff(MOTOR1_ID);
			MOTOR_turnoff(MOTOR2_ID);
			MOTOR_turnoff(MOTOR3_ID);
			MOTOR_turnoff(MOTOR4_ID);
			LCD_writestr("Distance :");
			LCD_writeint(u8_g_distance);
			US_sendtrigger(); /** SEND TRIGGER **/
		}
		US_sendtrigger(); /** SEND TRIGGER **/
	}

	while((u16_g_time/DISTANCE_DIV) < DISTANCE_20) /** WHEN DISTANCE IS LESS THAN 20 **/
	{
		MOTOR_rotateanticlkdir(MOTOR1_ID); /** MOVE BACKWORDS  **/
		MOTOR_rotateanticlkdir(MOTOR2_ID);
		MOTOR_rotateanticlkdir(MOTOR3_ID);
		MOTOR_rotateanticlkdir(MOTOR4_ID);
		
		while ((u16_g_time/DISTANCE_DIV) <= DISTANCE_20)
		{
			/** GO BACKWARDS WITH 30% SPEED **/
			MOTOR_turnon(MOTOR1_ID);
			MOTOR_turnon(MOTOR2_ID);
			MOTOR_turnon(MOTOR3_ID);
			MOTOR_turnon(MOTOR4_ID);
			LCD_goto(0,1) ;
			TMR0_delaymicros(SPEED_30_ON_TIME);
			
			MOTOR_turnoff(MOTOR1_ID);
			MOTOR_turnoff(MOTOR2_ID);
			MOTOR_turnoff(MOTOR3_ID);
			MOTOR_turnoff(MOTOR4_ID);
			LCD_writestr("Distance :");
			LCD_writeint(u8_g_distance);
			US_sendtrigger(); /** SEND TRIGGER **/
		}
		
		u32_g_tick = 0 ;
		u32_g_delay =  TMR2_getovs(500) ; /** GET THE NUMBER OF OVERFLOWS NEEDED FOR 5 SECONDS **/
		TMR2_start() ; /** START TIMER 2 **/
		
		MOTOR_rotateclkdir(MOTOR1_ID); /** MOVE BACKWORDS  **/
		MOTOR_rotateclkdir(MOTOR2_ID);
		MOTOR_rotateclkdir(MOTOR3_ID);
		MOTOR_rotateclkdir(MOTOR4_ID);
		
		while ((u16_g_time/DISTANCE_DIV) > DISTANCE_20)
		{
			/** STOP THEN ROTATE **/
			MOTOR_turnoff(MOTOR1_ID);
			MOTOR_turnoff(MOTOR2_ID);
			MOTOR_turnoff(MOTOR3_ID);
			MOTOR_turnoff(MOTOR4_ID);
			
			while (u32_g_tick < u32_g_delay)
			{
				/** ROTATION **/
				MOTOR_turnon(MOTOR3_ID);
				MOTOR_turnon(MOTOR4_ID);
			}
			US_sendtrigger(); /** SEND TRIGGER **/
			TMR2_stop() ; /** START TIMER 2 **/
			
			while((u16_g_time/DISTANCE_DIV) >= DISTANCE_30)
			{
				MOTOR_turnon(MOTOR1_ID);
				MOTOR_turnon(MOTOR2_ID);
				MOTOR_turnon(MOTOR3_ID);
				MOTOR_turnon(MOTOR4_ID);
				LCD_goto(0,1) ;
				TMR0_delaymicros(SPEED_30_ON_TIME);
				
				MOTOR_turnoff(MOTOR1_ID);
				MOTOR_turnoff(MOTOR2_ID);
				MOTOR_turnoff(MOTOR3_ID);
				MOTOR_turnoff(MOTOR4_ID);
				LCD_writestr("Distance :");
				LCD_writeint(u8_g_distance);
				US_sendtrigger(); /** SEND TRIGGER **/
			}
		}
		
	}
}


/** EXTI0 **/
ISR(INT0_vect)
{
	u8_echoedge++ ; /** INCREASE THE ECHO BY 1 **/
	
	if(u8_echoedge == 1) /** FIRST CHANGE (RISING EDGE) **/
	{
		ICU_start(); /** START ICU / COUNTING **/
	}
	
	else if(u8_echoedge == 2) /** SECOND CHANGE (FALLING EDGE) **/
	{
		ICU_stop(); /** STOP ICU / COUNTING **/
		
		u16_g_time = ICU_getvalue(); /** GET PULSE LENGTH **/
		
		ICU_setcounterval(0); /** START COUNTING FROM ZERO **/
				
		u8_echoedge = 0 ; /** REINITIALIZE ECHO EDGE TO 0 TO REPEAT IN ANY CHANGE AGAIN **/
		
		u8_g_distance = (u16_g_time/464) ; /** CALCULATE THE DISTANCE **/
	}
}

/** TIMER 1 OVERFLOW **/
ISR(TIMER1_OVF_vect)
{
	/** DO NOTHING **/
}

/** TIMER 0 OVERFLOW **/
ISR(TIMER2_OVF_vect)
{
	u32_g_tick++ ; /** INCREASE TICKS  **/
}


