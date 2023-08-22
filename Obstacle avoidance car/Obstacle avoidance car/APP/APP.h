/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 16 May , 2023                                   **/
/** Version : V01                                             **/
/***************************************************************/


#ifndef APP_H_
#define APP_H_

/** MACROS FOR ROTATION STATUS **/
#define RIGHT_ROTATION     2
#define LEFT_ROTATION      1

/** MACROS TO REPLACE MAGIC NUMBERS **/
#define SAFE_DISTANCE      70 
#define DISTANCE_30        30
#define DISTANCE_20        20
#define DISTANCE_DIV       464
#define SPEED_50_ON_TIME   50400
#define SPEED_30_ON_TIME   20560
#define START_BTN          '1'
#define MS_DELAY_50        50
#define MS_DELAY_100       100 
#define MS_DELAY_20        20
#define MS_DELAY_2000      2000
#define LCD_POS_0          0
#define LCD_POS_1          1
#define LCD_POS_2          2
#define FIRST_EDGE         1
#define SECOND_EDGE        2
#define US_DIVIDER         464
#define INITIATE_COUNTER_VAL  0


/** FUNCTION TO INITIALIZE APPLICATION MODULES **/
void APP_init(void);

/** FUNCTION TO SET DEFAULTS **/
void APP_setentry(void);

/** FUNCTION TO START THE CAR MOTION **/
void APP_start(void);

/** FUNCTION TO BE EXECUTED WHEN INT0 FIRED **/
void INT0_routine(void);

/** FUNCTION TO BE EXECUTED WHEN TMR0 OVERRFLOW FIRED **/
void TMR0_routine(void);

/** FUNCTION TO BE EXECUTED WHEN TMR1 OVERFLOW FIRED **/
void TMR1_routine(void);

/** FUNCTION TO BE EXECUTED WHEN TMR2 OVERFLOW FIRED **/
void TMR2_routine(void);

#endif /* APP_H_ */