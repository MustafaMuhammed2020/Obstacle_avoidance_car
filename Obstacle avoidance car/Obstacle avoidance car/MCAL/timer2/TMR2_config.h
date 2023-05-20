/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 16 , April 2023                                      */
/* Version : V01                                                  */
/* Hint    : Configuration file of Timer 2                        */
/******************************************************************/

#ifndef TMR2_CONFIG_H
#define TMR2_CONFIG_H

/*******************************************************************/
/**                 TMR2 CLOCK SOURCE                             **/
/** AVAILABLE CHOICES     1 - INTERNAL_CLK_SRC                    **/
/**                       2 - EXTERNAL_CLK_SRC                    **/
/*******************************************************************/
#define TIMER2_CLK_SRC           INTERNAL_CLK_SRC

/*******************************************************************/
/**                 TMR0 EXTERNAL EDGE COUNTING ACTION            **/
/** AVAILABLE CHOICES     1 - FALLING_EDGE_CNT                    **/
/**                       2 - RISING_EDGE_CNT                     **/
/*******************************************************************/
#define CNT2_EXTERNAL_EDGE_MODE  RISING_EDGE_CNT

/*******************************************************************/
/**                 TMR2 OERATING MODE                            **/
/** AVAILABLE CHOICES     1 - TMR2_NORMAL_MODE                    **/
/**                       2 - TMR2_FASTPWM_NON_INVERTED_MODE      **/
/**                       3 - TMR2_FASTPWM_INVERTED_MODE          **/
/**                       4 - TMR_PHASE_CORRECT_NON_INVERTED_MODE **/
/**                       5 - TMR_PHASE_CORRECT_INVERTED_MODE     **/
/**                       6 - TMR2_CTC_MODE                       **/
/*******************************************************************/
#define TIMER2_MODE             TMR2_NORMAL_MODE


/*******************************************************************/
/**                     TMR2 PRESCALLER                           **/
/** AVAILABLE CHOICES     1 - NO_PRESCALER                        **/
/**                       2 - PRESCALER_8                         **/
/**                       3 - PRESCALER_64                        **/
/**                       4 - PRESCALER_256                       **/
/**                       5 - PRESCALER_1024                      **/
/*******************************************************************/
#define TIMER2_PRESCALER_VAL  NO_PRESCALER


/*******************************************************************/
/**                     TMR2 ACTION ON COMPARE                    **/
/** AVAILABLE CHOICES     1 - SET_ON_COMPARE                      **/
/**                       2 - CLEAR_ON_COMPARE                    **/
/**                       3 - TOOGLE_ON_COMPARE                   **/
/*******************************************************************/
#define COMPARE_ACTION         TOOGLE_ON_COMPARE


#endif