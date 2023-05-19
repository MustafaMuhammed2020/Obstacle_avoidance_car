/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 17 May , 2023                                   **/
/** Version : V01                                             **/
/** Hint    : implementation file of ultrasonic sensor APIs   **/
/***************************************************************/

/** INCLUDE LIBRARIES **/
#include "avr/interrupt.h" /** TO HANDLE THE ISR OF INTERRUPT0 **/
#include "../../SERVICE/common_macros.h"
#include "../../SERVICE/standard_types.h"

/** INCLUDE LOWER LAYERS FILES **/
#include "../../MCAL/dio/DIO_interface.h"
#include "../../MCAL/timer0/TMR0_interface.h"

/** INCLUDE DRIVER FILES **/
#include "ultrasonic_interface.h"
#include "ultrasonic_private.h"
#include "ultrasonic_config.h"


/*******************************************************************/
/** FUNCTION TO INITIALIZE THE ULTRASONIC SENSOR                  **/
/** ARGUMENTS  : VOID                                             **/
/** RETURNS : VOID                                                **/
/*******************************************************************/
void US_init(void)
{
	/** INITIALIZE THE TRIGGER PIN AS OUTPUT PIN **/
	DIO_setpindir(US_TRIG_PORT , US_TRIG_PIN , DIO_PIN_OUTPUT);
	 
}


/*******************************************************************/
/** FUNCTION TO SEND TRIGGER SIGNAL FROM THE ULTRASONIC SENSOR    **/
/** ARGUMENTS  : u8_a_pin (PIN TO SEND TRIGGER)                   **/
/** RETURNS : EN_ultrasonicreturn                                 **/
/*******************************************************************/
EN_ultrasonicreturn US_sendtrigger(void)
{
	/** SEND PULSE OF 15 MICROSECOND **/
	DIO_setpinvalue(US_TRIG_PORT , US_TRIG_PIN , DIO_PIN_HIGH);
	TMR0_delaymicros(15);
	DIO_setpinvalue(US_TRIG_PORT , US_TRIG_PIN , DIO_PIN_LOW);
}


