/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 18 May , 2023                                   **/
/** Version : V01                                             **/
/***************************************************************/

#include "APP/APP.h"

int main(void)
{
	APP_init(); /** INITIALIZE APPLICATION MODULES **/
	
	APP_setentry(); /** SET THE ENTRY DATA **/
	
    while (1) 
    {	
		APP_start(); /** SUPER LOOP **/	
    }

	return 0 ;
}

