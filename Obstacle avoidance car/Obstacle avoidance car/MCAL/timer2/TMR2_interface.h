/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : Interface file of Timer 2                            */
/******************************************************************/

#ifndef TMR2_INTERFACE_H
#define TMR2_INTERFACE_H

/** DIFFERENT MACROS FOR TMR0 CONFIGURATION **/


#define F_CPU 8000000 /** DEFINE THE CLOCK SOURCE FREQUENCY **/

/** MACROS FOR THE CLOCK SOURCE  **/
#define INTERNAL_CLK_SRC                       0
#define EXTERNAL_CLK_SRC                       1


/** MACROS FOR EXTERNAL SOURCE OUNTING ACTION **/
#define FALLING_EDGE_CNT                       0
#define RISING_EDGE_CNT                        1

/** MACROS FOR DIFFERENT OPERATING MODES FOR TMR0 **/
#define TMR2_NORMAL_MODE                       0
#define TMR2_FASTPWM_NON_INVERTED_MODE         1
#define TMR2_FASTPWM_INVERTED_MODE             2
#define TMR_PHASE_CORRECT_NON_INVERTED_MODE    3
#define TMR_PHASE_CORRECT_INVERTED_MODE        4
#define TMR2_CTC_MODE                          5

/** MACROS FOR ACTION ON COMPARE  **/
#define SET_ON_COMPARE                         0
#define CLEAR_ON_COMPARE                       1
#define TOOGLE_ON_COMPARE                      2


/** MACROS TO CONFIGURE TMR0 PRESCALLER **/
#define NO_PRESCALER                           0
#define PRESCALER_8                            1
#define PRESCALER_64                           2
#define PRESCALER_256                          3
#define PRESCALER_1024                         4

typedef enum { TMR2_VALID_INIT  , TMR2_NOT_VALID_INIT} TMR2_init_error ;
typedef enum {TMR2_VALID_START ,TMR2_NOT_VALID_START } TMR2_start_error;
typedef enum {TMR2_VALID_STOP , TMR2_NOT_VALID_STOP } TMR2_stop_error;


/****************************************************************/
/** FUNCTION TO INITIALIZE TMR0 WITH SOME CONFIGURATIONS        */
/** ARGUMENTS  : VOID                                           */
/** RETURNS    : TMR0_init                                      */
/****************************************************************/
TMR2_init_error TMR2_init(void);

/*******************************************************************************/
/** FUNCTION TO LET TIMER 0 START WORK BY ASSIGN PRESCALLER OR CLOCK SOURCE    */
/** ARGUMENTS  : VOID                                                          */
/** RETURNS    : TMR0_start                                                    */
/*******************************************************************************/
TMR2_start_error TMR2_start(void);

/*******************************************************************************/
/** FUNCTION TO STOP TIMER 0                                                   */
/** ARGUMENTS  : VOID                                                          */
/** RETURNS    : TMR0_stop                                                     */
/*******************************************************************************/
TMR2_stop_error TMR2_stop(void);

/******************************************************************************/
/** FUNCTION TO CALCULATE THE NUMBER OF OVERFLOWS FOR DELAY IN MS            **/
/** ARGUMENTS  : DELAY IN MS                                                 **/
/** RETURN     : RETURNS THE NUMBER OF OVS                                   **/
/******************************************************************************/
uint32_t TMR2_getovs(uint16t u16_a_delay);


#endif