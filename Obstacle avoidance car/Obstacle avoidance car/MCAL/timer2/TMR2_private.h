/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : Private file of Timer 0                              */
/******************************************************************/

#ifndef TMR2_PRIVATE_H
#define TMR2_PRIVATE_H


/*************** TIMER2 Registers ********************/

#define SREG  (* (volatile uint8_t *) (0x5F))
#define TCCR2 (* (volatile uint8_t *) (0x45))
#define TCNT2 (* (volatile uint8_t *) (0x44))
#define OCR2  (* (volatile uint8_t *) (0x43))
#define TIMSK (* (volatile uint8_t *) (0x59))
#define TIFR  (* (volatile uint8_t *) (0x58))



#endif