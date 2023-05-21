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
#define SPEED_50_ON_TIME  50400
#define SPEED_30_ON_TIME  20560
#define START_BTN        '1'


/** FUNCTION TO INITIALIZE APPLICATION MODULES **/
void APP_init(void);

/** FUNCTION TO SET DEFAULTS **/
void APP_setentry();

/** FUNCTION TO START THE CAR MOTION **/
void APP_start(void);


#endif /* APP_H_ */