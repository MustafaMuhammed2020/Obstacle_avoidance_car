/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : Implementation of Timer 2 APIs                       */
/******************************************************************/

/** INCLUDE LIBRARIES **/
#include "../../SERVICE/common_macros.h"
#include "../../SERVICE/standard_types.h"

/** INCLUDE LOWER LAYER FILES **/
#include "../dio/DIO_interface.h"

/** INCLUDE DRIVER FILES **/
#include "TMR2_interface.h"
#include "TMR2_private.h"
#include "TMR2_config.h"

/****************************************************************/
/** FUNCTION TO INITIALIZE TMR2 WITH SOME CONFIGURATIONS        */
/** ARGUMENTS  : VOID                                           */
/** RETURNS    : TMR2_init                                      */
/****************************************************************/
TMR2_init_error TMR2_init()
{
	TMR2_init_error en_a_initstatus = TMR2_VALID_INIT ; /** VARIABLE TO RETURN THE STATUS OF INITIALIZATION **/
	
	/* COUNTER MODE OF TMR0 */
	#if TIMER2_CLK_SRC == EXTERNAL_CLK_SRC
	
	/* EXTERNAL PIN AS CLOCK SOURCE */
	DIO_setpindir(DIO_PORTB , DIO_PIN0 , DIO_PIN_INPUT);
	
	#if CNT2_EXTERNAL_EDGE_MODE == FALLING_EDGE_CNT
	
	clear_bit(TCCR2 , 0);
	set_bit(TCCR2 , 1);
	set_bit(TCCR2 , 2);
	
	en_a_initstatus = TMR2_VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	
	#elif CNT2_EXTERNAL_EDGE_MODE == RISING_EDGE_CNT
	
	set_bit(TCCR2 , 0);
	set_bit(TCCR2 , 1);
	set_bit(TCCR2 , 2);
	en_a_initstatus = TMR2_VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	
	#endif
	
	/* TIMER MODE OF TMR0 */
	#elif TIMER2_CLK_SRC == INTERNAL_CLK_SRC
	
	#if TIMER2_MODE == TMR2_NORMAL_MODE
	
	clear_bit(TCCR2 , 7);
	clear_bit(TCCR2 , 6);
	clear_bit(TCCR2 , 3);
	clear_bit(TCCR2 , 4);
	clear_bit(TCCR2 , 5);
	
	/* ENABLE INTERRUPT */
	set_bit(SREG , 7);
	set_bit(TIMSK , 6);
	
	en_a_initstatus = TMR2_VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	
	#elif TIMER2_MODE == TMR2_FASTPWM_NON_INVERTED_MODE
	
	set_bit(TCCR2 , 7);
	set_bit(TCCR2 , 6);
	set_bit(TCCR2 , 3);
	clear_bit(TCCR2 , 4);
	set_bit(TCCR2 , 5);
	
	en_a_initstatus = TMR2_VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	
	#elif TIMER2_MODE == TMR2_FASTPWM_INVERTED_MODE
	
	set_bit(TCCR2 , 7);
	set_bit(TCCR2 , 6);
	set_bit(TCCR2 , 3);
	set_bit(TCCR2 , 4);
	set_bit(TCCR2 , 5);
	
	en_a_initstatus = TMR2_VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	
	#elif TIMER2_MODE == TMR_PHASE_CORRECT_NON_INVERTED_MODE
	
	set_bit(TCCR2 , 7);
	set_bit(TCCR2 , 6);
	clear_bit(TCCR2 , 3);
	clear_bit(TCCR2 , 4);
	set_bit(TCCR2 , 5);
	
	en_a_initstatus = TMR2_VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	
	#elif TIMER2_MODE == TMR_PHASE_CORRECT_INVERTED_MODE
	
	set_bit(TCCR2 , 7);
	set_bit(TCCR2 , 6);
	clear_bit(TCCR2 , 3);
	set_bit(TCCR2 , 4);
	set_bit(TCCR2 , 5);
	
	en_a_initstatus = TMR2_VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	
	#elif TIMER2_MODE == TMR2_CTC_MODE
	
	//DIO_setpindir(DIO_PORTB , DIO_PIN3 , DIO_PIN_OUTPUT); /** SET CTC BIT AS OUTPUT PIN **/
	
	clear_bit(TCCR2 , 7);
	clear_bit(TCCR2 , 6);
	set_bit(TCCR2 , 3);
	
	/* ENABLE INTERRUPT */
	//set_bit(SREG , 7);
	//set_bit(TIMSK , 6);
	
	en_a_initstatus = TMR2_VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	
	#if COMPARE_ACTION == SET_ON_COMPARE
	
	set_bit(TCCR2 , 4);
	set_bit(TCCR2 , 5);
	
	#elif COMPARE_ACTION == CLEAR_ON_COMPARE
	
	clear_bit(TCCR2 , 4);
	set_bit(TCCR2 , 5);
	
	#elif COMPARE_ACTION == TOOGLE_ON_COMPARE
	
	set_bit(TCCR2 , 4);
	clear_bit(TCCR2 , 5);
	#endif
	#endif
	#endif
	
	return en_a_initstatus ; /** RETURN THE STATUS OF INITIALIZATION **/
}


/*********************************************************************************/
/** FUNCTION TO LET TIMER 2 START WORK BY ASSIGNING PRESCALLER OR CLOCK SOURCE   */
/** ARGUMENTS  : VOID                                                            */
/** RETURNS    : TMR2_start                                                      */
/*********************************************************************************/
TMR2_start_error TMR2_start(void)
{
	TMR2_start_error en_a_startstatus = TMR2_VALID_START ; /** VARIABLE TO RETURN THE STATUS OF START **/
	
	#if TIMER2_PRESCALER_VAL == PRESCALER_1024
	
	set_bit(TCCR2 , 0);
	clear_bit(TCCR2 , 1);
	set_bit(TCCR2 , 2);
	
	en_a_startstatus = TMR2_VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER2_PRESCALER_VAL == NO_PRESCALER
	
	set_bit(TCCR2 , 0);
	clear_bit(TCCR2 , 1);
	clear_bit(TCCR2 , 2);
	
	en_a_startstatus = TMR2_VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER2_PRESCALER_VAL == PRESCALER_8
	
	clear_bit(TCCR2 , 0);
	set_bit(TCCR2 , 1);
	clear_bit(TCCR2 , 2);
	
	en_a_startstatus = TMR2_VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER2_PRESCALER_VAL == PRESCALER_64
	
	set_bit(TCCR2 , 0);
	set_bit(TCCR2 , 1);
	clear_bit(TCCR2 , 2);
	
	en_a_startstatus = TMR2_VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER2_PRESCALER_VAL == PRESCALER_256
	
	clear_bit(TCCR2 , 0);
	clear_bit(TCCR2 , 1);
	set_bit(TCCR2 , 2);
	
	en_a_startstatus = TMR2_VALID_START ; /** START DONE PROBERLY **/
	
	#endif
	
	return en_a_startstatus ; /** RETURN THE STATUS **/
}

/*******************************************************************************/
/** FUNCTION TO STOP TIMER 2                                                   */
/** ARGUMENTS  : VOID                                                          */
/** RETURNS    : TMR2_stop                                                     */
/*******************************************************************************/
TMR2_stop_error TMR2_stop(void)
{
	TMR2_stop_error en_a_stopStatus = TMR2_VALID_STOP ; /** VARIABLE TO RETURN THE STATUS **/
	
	/** SET CONFIGURATIONS AS NO CLOCK SOURCE **/
	clear_bit(TCCR2 , 0);
	clear_bit(TCCR2 , 1);
	clear_bit(TCCR2 , 2);
	
	en_a_stopStatus = TMR2_VALID_STOP ; /** STOP DONE PROPERLY **/
	
	return en_a_stopStatus ; /** RETURN THE STATUS **/
	
}

/******************************************************************************/
/** FUNCTION TO CALCULATE THE NUMBER OF OVERFLOWS FOR DELAY IN MS            **/
/** ARGUMENTS  : DELAY IN MS                                                 **/
/** RETURN     : RETURNS THE NUMBER OF OVS                                   **/
/******************************************************************************/
uint32_t TMR2_getovs(uint16t u16_a_delay)
{
	uint32_t u32_a_ovs = 0 ; /** LOCAL VARIABLE TO RETURN THE NUMBER OF OVERFLOWS **/
	
	/********************************************************************/
	/**      THIS CALCULATIONS ARE DONE ON 8 MHZ F_CPU                 **/
	/********************************************************************/
	#if TIMER2_PRESCALER_VAL ==  PRESCALER_1024   /** CHECK THE PRESCALLER FROM CONFIG FILE **/
	
	u32_a_ovs = (u16_a_delay / 32);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	

	#elif TIMER2_PRESCALER_VAL ==  PRESCALER_256

	u32_a_ovs = (u16_a_delay / 8);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	
	#elif TIMER2_PRESCALER_VAL == PRESCALER_8
	
	u32_a_ovs = (u16_a_delay / 0.256);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	

	#elif TIMER2_PRESCALER_VAL == NO_PRESCALER
	
	u32_a_ovs = (u16_a_delay / 0.032);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	#endif
	
	return u32_a_ovs ;  /** RETURN THE CALCULATED NUMBER OF OVERFLOWS **/
}
