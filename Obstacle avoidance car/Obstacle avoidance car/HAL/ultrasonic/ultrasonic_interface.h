/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 17 May , 2023                                   **/
/** Version : V01                                             **/
/** Hint    : interface file of ultrasonic sensor             **/
/***************************************************************/
 
#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

typedef enum {VALID_RETURN , NOT_VALID_RETURN } EN_ultrasonicreturn ;

/*******************************************************************/
/** FUNCTION TO INITIALIZE THE ULTRASONIC SENSOR                  **/
/** ARGUMENTS  : VOID                                             **/
/** RETURNS : VOID                                                **/
/*******************************************************************/
void US_init(void);


/*******************************************************************/
/** FUNCTION TO SEND TRIGGER SIGNAL FROM THE ULTRASONIC SENSOR    **/
/** ARGUMENTS  : u8_a_pin (PIN TO SEND TRIGGER)                   **/
/** RETURNS : EN_ultrasonicreturn                                 **/
/*******************************************************************/
EN_ultrasonicreturn US_sendtrigger(void);

#endif /* ULTRASONIC_INTERFACE_H_ */