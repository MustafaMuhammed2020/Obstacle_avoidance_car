/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 1 Octobre, 2021                                 **/
/** Version : V01                                             **/
/** Hint    : motor APIs                                      **/
/***************************************************************/
#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

/** MACROS TO BE PASSED AS MOTOR ID **/
#define MOTOR1_ID      0
#define MOTOR2_ID      1
#define MOTOR3_ID      2
#define MOTOR4_ID      3

/** MACROS TO DEFINE THE SPEED OF MOTOR **/
#define speed_30   0 /** 30 % SPEED **/
#define speed_50   1 /** 50 % SPEED **/

/*****************************************************************/
/** FUNCTION TO SET THE CONFIGURATIONS OF MOTOR                 **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
typedef enum { VALID_MOTOR_INIT , NOTVALID_MOTOR_INIT } MOTOR_init_status;
MOTOR_init_status MOTOR_init(uint8_t u8_a_motorid);


/*****************************************************************/
/** FUNCTION TO ROTATE MOTOR IN CLOCK DIRECTION                 **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_rotateclkdir(uint8_t u8_a_motorid);


/*****************************************************************/
/** FUNCTION TO ROTATE MOTOR ANTI CLOCK DIRECTION               **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_rotateanticlkdir(uint8_t u8_a_motorid);

/*****************************************************************/
/** FUNCTION TO STOP THE MOTOR                                  **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_turnoff(uint8_t u8_a_motorid);

/*****************************************************************/
/** FUNCTION TO START MOTOR ROTATION                            **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_turnon(uint8_t u8_a_motorid);

/*****************************************************************/
/** FUNCTION TO SET THE MOTOR DUTY CYCLE                        **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_applyspeed(uint8_t u8_a_motorid  , uint8_t u8_a_speed);

/*****************************************************************/
/** FUNCTION TO ROTATE MOTOR 90 DEGREE TO RIGHT                 **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_rotate90right(uint8_t u8_a_motorid);

/*****************************************************************/
/** FUNCTION TO ROTATE MOTOR 90 DEGREE TO LEFT                  **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_rotate90left(uint8_t u8_a_motorid);

/*****************************************************************/
/** FUNCTION TO STOP THE MOTOR                                  **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_stop(uint8_t u8_a_motorid);

#endif