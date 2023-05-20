/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 1 Octobre, 2021                                 **/
/** Version : V01                                             **/
/** Hint    : Configurations of motors                        **/
/***************************************************************/

/** INCLUDE LIBRARIES **/
#include "../../SERVICE/common_macros.h"
#include "../../SERVICE/standard_types.h"

/** INCLUDE LOWER LAYER DRIVERS **/
#include "../../MCAL/dio/DIO_interface.h"
#include "../../MCAL/timer0/TMR0_interface.h"

/** INCLUDE DRIVER FILES **/
#include "motor_interface.h"
#include "motor_private.h"
#include "motor_config.h"



/*****************************************************************/
/** FUNCTION TO SET THE CONFIGURATIONS OF MOTOR                 **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     : MOTOR INIT ERROR STATUS                        **/
/*****************************************************************/
MOTOR_init_status MOTOR_init(uint8_t u8_a_motorid)
{
	MOTOR_init_status en_a_initstatus = VALID_MOTOR_INIT ;  /** VARIABLE TO HOLD THE RETURN ERROR STATUS **/ 
	
	switch(u8_a_motorid)
	{
		case MOTOR1_ID : /** SET PINS OF MOTOR 1 **/
		
		DIO_setpindir(MOTOR1_PORT , MOTOR1_PIN1 , DIO_PIN_OUTPUT);
		DIO_setpindir(MOTOR1_PORT , MOTOR1_PIN2 , DIO_PIN_OUTPUT);
		
		DIO_setpindir(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_OUTPUT); /** MOTOR 1 ENABLE PIN **/
		break;
		
		case MOTOR2_ID:  /** SET PINS OF MOTOR 2 **/
		
		DIO_setpindir(MOTOR2_PORT , MOTOR2_PIN1 , DIO_PIN_OUTPUT);
		DIO_setpindir(MOTOR2_PORT , MOTOR2_PIN2 , DIO_PIN_OUTPUT);
		
		DIO_setpindir(MOTOR1_PORT , MOTOR2_ENABLE_PIN , DIO_PIN_OUTPUT);  /** MOTOR 2 ENABLE PIN **/
		break;
		
		case MOTOR3_ID:  /** SET PINS OF MOTOR 2 **/
		
		DIO_setpindir(MOTOR3_PORT , MOTOR3_PIN1 , DIO_PIN_OUTPUT);
		DIO_setpindir(MOTOR3_PORT , MOTOR3_PIN2 , DIO_PIN_OUTPUT);
		
		DIO_setpindir(MOTOR3_PORT , MOTOR3_ENABLE_PIN , DIO_PIN_OUTPUT);  /** MOTOR 2 ENABLE PIN **/
		break;
		
		case MOTOR4_ID:  /** SET PINS OF MOTOR 2 **/
		
		DIO_setpindir(MOTOR4_PORT , MOTOR4_PIN1 , DIO_PIN_OUTPUT);
		DIO_setpindir(MOTOR4_PORT , MOTOR4_PIN2 , DIO_PIN_OUTPUT);
		
		DIO_setpindir(MOTOR4_PORT , MOTOR4_ENABLE_PIN , DIO_PIN_OUTPUT);  /** MOTOR 2 ENABLE PIN **/
		break;
		
		
		default:
		/** RETURN ERROR **/
		en_a_initstatus = NOTVALID_MOTOR_INIT ; /** AN ERROR IN INITIALIZE MOTOR **/
		break;
		
	}
	
	return en_a_initstatus ; /** RETURN THE FINAL STATUS **/
}


/*****************************************************************/
/** FUNCTION TO ROTATE MOTOR IN CLOCK DIRECTION                 **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_rotateclkdir(uint8_t u8_a_motorid)
{
	MOTOR_init_status en_a_motordirectionstatus = VALID_MOTOR_INIT ; /** VARIABLE TO HOLD THE RETURN STATUS **/
	
	switch(u8_a_motorid)
	{
		case MOTOR1_ID : /** SET PINS OF MOTOR 1 **/
		
		DIO_setpinvalue(MOTOR1_PORT , MOTOR1_PIN1 , DIO_PIN_HIGH); /** PIN1 IS HIGH **/
		DIO_setpinvalue(MOTOR1_PORT , MOTOR1_PIN2 , DIO_PIN_LOW);  /** PIN2 IS LOW **/
		break;
		
		case MOTOR2_ID:  /** SET PINS OF MOTOR 2 **/
		
		DIO_setpinvalue(MOTOR2_PORT , MOTOR2_PIN1 , DIO_PIN_HIGH); /** PIN1 IS HIGH **/
		DIO_setpinvalue(MOTOR2_PORT , MOTOR2_PIN2 , DIO_PIN_LOW);  /** PIN2 IS LOW **/
		break;
		
		case MOTOR3_ID : /** SET PINS OF MOTOR 1 **/
		
		DIO_setpinvalue(MOTOR3_PORT , MOTOR3_PIN1 , DIO_PIN_HIGH); /** PIN1 IS HIGH **/
		DIO_setpinvalue(MOTOR3_PORT , MOTOR3_PIN2 , DIO_PIN_LOW);  /** PIN2 IS LOW **/
		break;
		
		case MOTOR4_ID:  /** SET PINS OF MOTOR 2 **/
		
		DIO_setpinvalue(MOTOR4_PORT , MOTOR4_PIN1 , DIO_PIN_HIGH); /** PIN1 IS HIGH **/
		DIO_setpinvalue(MOTOR4_PORT , MOTOR4_PIN2 , DIO_PIN_LOW);  /** PIN2 IS LOW **/
		break;
		
		
		default:
		/** RETURN ERROR **/
		en_a_motordirectionstatus = NOTVALID_MOTOR_INIT ; /** AN ERROR IN INITIALIZE MOTOR **/
		break;
		
	}
	
	return en_a_motordirectionstatus ; /** RETURN THE FINAL STATUS **/
}


/*****************************************************************/
/** FUNCTION TO ROTATE MOTOR ANTI CLOCK DIRECTION               **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_rotateanticlkdir(uint8_t u8_a_motorid)
{
	MOTOR_init_status en_a_motorrotatestatus = VALID_MOTOR_INIT ; /** VARIABLE TO HOLD THE RETURN STATUS **/
	
	switch(u8_a_motorid)
	{
		case MOTOR1_ID : /** SET PINS OF MOTOR 1 **/
		
		DIO_setpinvalue(MOTOR1_PORT , MOTOR1_PIN1 , DIO_PIN_LOW);   /** PIN1 IS LOW **/
		DIO_setpinvalue(MOTOR1_PORT , MOTOR1_PIN2 , DIO_PIN_HIGH);  /** PIN2 IS HIGH **/
		break;
		
		case MOTOR2_ID:  /** SET PINS OF MOTOR 2 **/
		
		DIO_setpinvalue(MOTOR2_PORT , MOTOR2_PIN1 , DIO_PIN_LOW);   /** PIN1 IS LOW **/
		DIO_setpinvalue(MOTOR2_PORT , MOTOR2_PIN2 , DIO_PIN_HIGH);  /** PIN2 IS HIGH **/
		break;
		
		case MOTOR3_ID : /** SET PINS OF MOTOR 1 **/
		
		DIO_setpinvalue(MOTOR3_PORT , MOTOR3_PIN1 , DIO_PIN_LOW);   /** PIN1 IS LOW **/
		DIO_setpinvalue(MOTOR3_PORT , MOTOR3_PIN2 , DIO_PIN_HIGH);  /** PIN2 IS HIGH **/
		break;
		
		case MOTOR4_ID:  /** SET PINS OF MOTOR 2 **/
		
		DIO_setpinvalue(MOTOR4_PORT , MOTOR4_PIN1 , DIO_PIN_LOW);   /** PIN1 IS LOW **/
		DIO_setpinvalue(MOTOR4_PORT , MOTOR4_PIN2 , DIO_PIN_HIGH);  /** PIN2 IS HIGH **/
		break;
		
		
		default:
		/** RETURN ERROR **/
		en_a_motorrotatestatus = NOTVALID_MOTOR_INIT ; /** AN ERROR IN INITIALIZE MOTOR **/
		break;
		
	}
	
	return en_a_motorrotatestatus ; /** RETURN THE FINAL STATUS **/
}


/*****************************************************************/
/** FUNCTION TO STOP THE MOTOR                                  **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_turnoff(uint8_t u8_a_motorid)
{
	MOTOR_init_status en_a_motoroffstatus = VALID_MOTOR_INIT ; /** VARIABLE TO HOLD THE RETURN STATUS **/
	
	switch(u8_a_motorid)
	{
		case MOTOR1_ID : /** SET PINS OF MOTOR 1 **/
		DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_LOW); /** SET ENABLE PIN TO LOW **/
		break;
		
		case MOTOR2_ID:  /** SET PINS OF MOTOR 2 **/
		DIO_setpinvalue(MOTOR2_PORT , MOTOR2_ENABLE_PIN , DIO_PIN_LOW); /** SET ENABLE PIN TO LOW **/
		break;
		
		case MOTOR3_ID:  /** SET PINS OF MOTOR 2 **/
		DIO_setpinvalue(MOTOR3_PORT , MOTOR3_ENABLE_PIN , DIO_PIN_LOW); /** SET ENABLE PIN TO LOW **/
		break;
		
		case MOTOR4_ID:  /** SET PINS OF MOTOR 2 **/
		DIO_setpinvalue(MOTOR4_PORT , MOTOR4_ENABLE_PIN , DIO_PIN_LOW); /** SET ENABLE PIN TO LOW **/
		break;
		
		default:
		/** RETURN ERROR **/
		en_a_motoroffstatus = NOTVALID_MOTOR_INIT ; /** AN ERROR IN INITIALIZE MOTOR **/
		break;
		
	}
	
	return en_a_motoroffstatus ; /** RETURN THE FINAL STATUS **/
}

/*****************************************************************/
/** FUNCTION TO START MOTOR ROTATION                            **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_turnon(uint8_t u8_a_motorid)
{
	MOTOR_init_status en_a_motoroffstatus = VALID_MOTOR_INIT ; /** VARIABLE TO HOLD THE RETURN STATUS **/
	
	switch(u8_a_motorid)
	{
		case MOTOR1_ID : 
		DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_HIGH); /** SET ENABLE PIN TO HIGH **/
		break;
		
		case MOTOR2_ID:  /** SET PINS OF MOTOR 2 **/
		DIO_setpinvalue(MOTOR2_PORT , MOTOR2_ENABLE_PIN , DIO_PIN_HIGH); /** SET ENABLE PIN TO HIGH **/
		break;
		
		case MOTOR3_ID:  /** SET PINS OF MOTOR 2 **/
		DIO_setpinvalue(MOTOR3_PORT , MOTOR3_ENABLE_PIN , DIO_PIN_HIGH); /** SET ENABLE PIN TO HIGH **/
		break;
		
		case MOTOR4_ID:  /** SET PINS OF MOTOR 2 **/
		DIO_setpinvalue(MOTOR4_PORT , MOTOR4_ENABLE_PIN , DIO_PIN_HIGH); /** SET ENABLE PIN TO HIGH **/
		break;
		
		default:
		/** RETURN ERROR **/
		en_a_motoroffstatus = NOTVALID_MOTOR_INIT ; /** AN ERROR IN INITIALIZE MOTOR **/
		break;
		
	}
	
	return en_a_motoroffstatus ; /** RETURN THE FINAL STATUS **/
}


/*****************************************************************/
/** FUNCTION TO SET THE MOTOR DUTY CYCLE                        **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_applyspeed(uint8_t u8_a_motorid  , uint8_t u8_a_speed)
{
	MOTOR_init_status en_a_motoroffstatus = VALID_MOTOR_INIT ; /** VARIABLE TO HOLD THE RETURN STATUS **/
	
	switch (u8_a_motorid)
	{
		case MOTOR1_ID:
		
		/**************************************************************************************/
		/**          WE HAVE 16 MHZ CRYSTAL AS CLOCK SOURCE AND 1024 PRESCALLER              **/
		/** tick time = (1024) / (16MHZ)   = 64 Micro second                                 **/
		/** IF WE NEED 50% DUTY CYCLE THEN 1 TICK_TIME ON THEN  1 TICK_TIME OFF              **/
		/** IF WE NEED 70% DUTY CYCLE THEN 7 TICK_TIMES ON THEN 3 TICK_TIMES OFF             **/
		/** IF WE NEED 90% DUTY CYCLE THEN 9 TICK_TIMES ON THEN 1 TICK_TIMES OFF             **/
		/**************************************************************************************/
		if (u8_a_speed == speed_50) /** APPLY SPEED MODE 1 ON MOTOR 1 50 % DUTY CYCLE **/
		{
			DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_HIGH);
			TMR0_delaymicros(50);
			
			DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_LOW);
			TMR0_delaymicros(50);
			
		}
		
		else if (u8_a_speed == speed_30) /** APPLY SPEED MODE 2 ON MOTOR 1 30 % DUTY CYCLE **/
		{
			DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_HIGH);
			TMR0_delaymicros(64);
			
			DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_LOW);
			TMR0_delaymicros(576);
		}
		break;
		
		case MOTOR2_ID:
		
		if (u8_a_speed == speed_50) /** APPLY SPEED MODE 1 ON MOTOR 2 50 % DUTY CYCLE **/
		{
			DIO_setpinvalue(MOTOR2_PORT , MOTOR2_ENABLE_PIN , DIO_PIN_HIGH);
			TMR0_delaymicros(64);
			
			DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_LOW);
			TMR0_delaymicros(64);
			
		}
		
		else if (u8_a_speed == speed_30) /** APPLY SPEED MODE 2 ON MOTOR 2 30 % DUTY CYCLE **/
		{
			DIO_setpinvalue(MOTOR2_PORT , MOTOR2_ENABLE_PIN , DIO_PIN_HIGH);
			TMR0_delaymicros(192);
			
			DIO_setpinvalue(MOTOR2_PORT , MOTOR2_ENABLE_PIN , DIO_PIN_LOW);
			TMR0_delaymicros(448);
		}
		
	}
}

/*****************************************************************/
/** FUNCTION TO ROTATE MOTOR 90 DEGREE TO RIGHT                 **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_rotate90right(uint8_t u8_a_motorid)
{
	/** STOP THE RIGHT SIDE **/
	/** **/
}

/*****************************************************************/
/** FUNCTION TO ROTATE MOTOR 90 DEGREE TO LEFT                  **/
/** ARGUMENTS  : MOTOR ID                                       **/
/** RETURN     :  MOTOR INIT ERROR STATUS                       **/
/*****************************************************************/
MOTOR_init_status MOTOR_rotate90left(uint8_t u8_a_motorid);

MOTOR_init_status MOTOR_stop(uint8_t u8_a_motorid)
{
	MOTOR_init_status en_a_motoroffstatus = VALID_MOTOR_INIT ; /** VARIABLE TO HOLD THE RETURN STATUS **/
	
	switch(u8_a_motorid)
	{
		case MOTOR1_ID :
		DIO_setpinvalue(MOTOR1_PORT , MOTOR1_PIN1 , DIO_PIN_LOW); /** SET MOTOR PINS TO LOW PIN TO HIGH **/
		DIO_setpinvalue(MOTOR1_PORT , MOTOR1_PIN2 , DIO_PIN_LOW); 
		break;
		
		case MOTOR2_ID:  /** SET PINS OF MOTOR 2 **/
		DIO_setpinvalue(MOTOR2_PORT , MOTOR2_PIN1 , DIO_PIN_LOW); /** SET MOTOR PINS TO LOW PIN TO HIGH **/
		DIO_setpinvalue(MOTOR2_PORT , MOTOR2_PIN2 , DIO_PIN_LOW);
		break;
		
		case MOTOR3_ID:  /** SET PINS OF MOTOR 2 **/
		DIO_setpinvalue(MOTOR3_PORT , MOTOR3_PIN1 , DIO_PIN_LOW); /** SET MOTOR PINS TO LOW PIN TO HIGH **/
		DIO_setpinvalue(MOTOR3_PORT , MOTOR3_PIN2 , DIO_PIN_LOW);
		break;
		
		case MOTOR4_ID:  /** SET PINS OF MOTOR 2 **/
		DIO_setpinvalue(MOTOR4_PORT , MOTOR4_PIN1 , DIO_PIN_LOW); /** SET MOTOR PINS TO LOW PIN TO HIGH **/
		DIO_setpinvalue(MOTOR4_PORT , MOTOR4_PIN2 , DIO_PIN_LOW);
		break;
		
		default:
		/** RETURN ERROR **/
		en_a_motoroffstatus = NOTVALID_MOTOR_INIT ; /** AN ERROR IN INITIALIZE MOTOR **/
		break;
		
	}
	
	return en_a_motoroffstatus ; /** RETURN THE FINAL STATUS **/
}