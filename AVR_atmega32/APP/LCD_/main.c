/*
 * LCD_.c
 *
 * Created: 03/01/2024 08:24:47
 * Author : Rania
 */ 


#include <util/delay.h>
#include "LCD.h"

int main(void) {
usint8_t Local_u8Index=0;
 LCD_init();
 LCD_enuGotoDDRAM_XY(0,0);
 LCD_enuWriteString("rania");

/*  usint8_t  Local_u8Pattern[8]={
	   0b00000000,
	   0b00000000,
	   0b00001000,
	   0b00001001,
	   0b00011110,
	   0b00001100,
	   0b00001000,
	   0b00000000
   };
     
     
    
   LCD_enuDisplaySpecialPattern(Local_u8Pattern,0,1,1);*/
while(1)
{
	for(Local_u8Index=0;Local_u8Index<NUMBER_OF_LCD_COLOUMNS-8;Local_u8Index++)
		{
			LCD_WriteCommand(CLCD_SHIFT_DISPLAY_RIGH);
			_delay_ms(1500);
		}
		if (Local_u8Index >= 15){
			
		for(Local_u8Index=0;Local_u8Index<NUMBER_OF_LCD_COLOUMNS-5;Local_u8Index++)
				{
					LCD_WriteCommand(CLCD_SHIFT_DISPLAY_LEFT);
					_delay_ms(1500);
				}
	
		}

	
		

}
	
}
