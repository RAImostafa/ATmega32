/*
 * LCD.c
 *
 * Created: 03/01/2024 08:56:13
 *  Author: Rania
 */ 

#include "LCD.h"
#include "LCD_Cfg.h"
#include <stddef.h>

#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO.h"

extern  _LCD_strState_t LCD_Array[Num_LCDs];


/************************* Write Command ***************************************/
LCD_enuErrorStatus LCD_WriteCommand(usint8_t Copy_u8Command){
	LCD_enuErrorStatus loc_enumReturnStatus = LCD_enumNOK;
	
	
	DIO_enumSetPin( LCD_Array[0].port_RS,LCD_Array[0].pin_RS, DIO_enumLogicLow);  /* command */
	DIO_enumSetPin( LCD_Array[0].port_RW,LCD_Array[0].pin_RW, DIO_enumLogicLow); /* write */
	
	
	/*****************************************************************************/
	for(usint8_t i =0 ; i <Num_LCDs ;i++)
	{
		/* set pin output */
		DIO_enumSetPinConfig(LCD_Array[i].port_D0 ,LCD_Array[i].pin_D0,DIO_enumOutput);
		DIO_enumSetPin( LCD_Array[i].port_D0,LCD_Array[i].pin_D0,(Copy_u8Command >> 0) & 0x01);
		/* set pin output */
		DIO_enumSetPinConfig(LCD_Array[i].port_D1 ,LCD_Array[i].pin_D1,DIO_enumOutput);
		DIO_enumSetPin( LCD_Array[i].port_D1,LCD_Array[i].pin_D1,(Copy_u8Command >> 1) & 0x01);
		/* set pin output */
		DIO_enumSetPinConfig(LCD_Array[i].port_D2 ,LCD_Array[i].pin_D2,DIO_enumOutput);
		DIO_enumSetPin( LCD_Array[i].port_D2,LCD_Array[i].pin_D2,(Copy_u8Command >> 2) & 0x01);
		/* set pin output */
		DIO_enumSetPinConfig(LCD_Array[i].port_D3 ,LCD_Array[i].pin_D3,DIO_enumOutput);
		DIO_enumSetPin( LCD_Array[i].port_D3,LCD_Array[i].pin_D3,(Copy_u8Command >> 3) & 0x01);
		/* set pin output */
		DIO_enumSetPinConfig(LCD_Array[i].port_D4 ,LCD_Array[i].pin_D4,DIO_enumOutput);
		DIO_enumSetPin( LCD_Array[i].port_D4,LCD_Array[i].pin_D4,(Copy_u8Command >> 4) & 0x01);
		/* set pin output */
		DIO_enumSetPinConfig(LCD_Array[i].port_D5 ,LCD_Array[i].pin_D5,DIO_enumOutput);
		DIO_enumSetPin( LCD_Array[i].port_D5,LCD_Array[i].pin_D5,(Copy_u8Command >> 5) & 0x01);
		/* set pin output */
		DIO_enumSetPinConfig(LCD_Array[i].port_D6 ,LCD_Array[i].pin_D6,DIO_enumOutput);
		DIO_enumSetPin( LCD_Array[i].port_D6,LCD_Array[i].pin_D6,(Copy_u8Command >> 6) & 0x01);
		/* set pin output */
		DIO_enumSetPinConfig(LCD_Array[i].port_D7 ,LCD_Array[i].pin_D7,DIO_enumOutput);
		DIO_enumSetPin( LCD_Array[i].port_D7,LCD_Array[i].pin_D7,(Copy_u8Command >> 7) & 0x01);
	}
	
	DIO_enumSetPin(LCD_Array[0].port_EN,LCD_Array[0].pin_EN,DIO_enumLogicHigh);
	_delay_ms(0.1);
	DIO_enumSetPin(LCD_Array[0].port_EN,LCD_Array[0].pin_EN,DIO_enumLogicLow);
	_delay_ms(2);
	loc_enumReturnStatus = LCD_enumOK;
	return loc_enumReturnStatus;
}

/************************* Write Data ***************************************/
LCD_enuErrorStatus LCD_WriteData(usint8_t Copy_u8Data){
	LCD_enuErrorStatus loc_enumReturnStatus = LCD_enumNOK;
	
	
	DIO_enumSetPin( LCD_Array[0].port_RS,LCD_Array[0].pin_RS, DIO_enumLogicHigh); /* Data */
	DIO_enumSetPin( LCD_Array[0].port_RW,LCD_Array[0].pin_RW, DIO_enumLogicLow);/* write */
	
/* set pin output */
	DIO_enumSetPinConfig(LCD_Array[0].port_D0 ,LCD_Array[0].pin_D0,DIO_enumOutput);
	DIO_enumSetPin( LCD_Array[0].port_D0,LCD_Array[0].pin_D0,(Copy_u8Data >> 0) & 0x01);
	/* set pin output */
	DIO_enumSetPinConfig(LCD_Array[0].port_D1 ,LCD_Array[0].pin_D1,DIO_enumOutput);
	DIO_enumSetPin( LCD_Array[0].port_D1,LCD_Array[0].pin_D1,(Copy_u8Data >> 1) & 0x01);
	/* set pin output */
	DIO_enumSetPinConfig(LCD_Array[0].port_D2 ,LCD_Array[0].pin_D2,DIO_enumOutput);
	DIO_enumSetPin( LCD_Array[0].port_D2,LCD_Array[0].pin_D2,(Copy_u8Data >> 2) & 0x01);
	/* set pin output */
	DIO_enumSetPinConfig(LCD_Array[0].port_D3 ,LCD_Array[0].pin_D3,DIO_enumOutput);
	DIO_enumSetPin( LCD_Array[0].port_D3,LCD_Array[0].pin_D3,(Copy_u8Data >> 3) & 0x01);
	/* set pin output */
	DIO_enumSetPinConfig(LCD_Array[0].port_D4 ,LCD_Array[0].pin_D4,DIO_enumOutput);
	DIO_enumSetPin( LCD_Array[0].port_D4,LCD_Array[0].pin_D4,(Copy_u8Data >> 4) & 0x01);
	/* set pin output */
	DIO_enumSetPinConfig(LCD_Array[0].port_D5 ,LCD_Array[0].pin_D5,DIO_enumOutput);
	DIO_enumSetPin( LCD_Array[0].port_D5,LCD_Array[0].pin_D5,(Copy_u8Data >> 5) & 0x01);
	/* set pin output */
	DIO_enumSetPinConfig(LCD_Array[0].port_D6 ,LCD_Array[0].pin_D6,DIO_enumOutput);
	DIO_enumSetPin( LCD_Array[0].port_D6,LCD_Array[0].pin_D6,(Copy_u8Data >> 6) & 0x01);
	/* set pin output */
	DIO_enumSetPinConfig(LCD_Array[0].port_D7 ,LCD_Array[0].pin_D7,DIO_enumOutput);
	DIO_enumSetPin( LCD_Array[0].port_D7,LCD_Array[0].pin_D7,(Copy_u8Data >> 7) & 0x01);
	
	
	DIO_enumSetPin(LCD_Array[0].port_EN,LCD_Array[0].pin_EN,DIO_enumLogicHigh);
	_delay_ms(0.1);
	DIO_enumSetPin(LCD_Array[0].port_EN,LCD_Array[0].pin_EN,DIO_enumLogicLow);
	_delay_ms(2);
	loc_enumReturnStatus = LCD_enumOK;
	return loc_enumReturnStatus;
}


/************************* LCD INIT  ***************************************/
void LCD_init(void)
{
	
	DIO_enumSetPinConfig(LCD_Array[0].port_RS ,LCD_Array[0].pin_RS,DIO_enumOutput);
	DIO_enumSetPinConfig(LCD_Array[0].port_RW ,LCD_Array[0].pin_RW,DIO_enumOutput);
	DIO_enumSetPinConfig(LCD_Array[0].port_EN ,LCD_Array[0].pin_EN,DIO_enumOutput);
	
	// Function set command with 2-lines and font 5*8
	 LCD_WriteCommand(0x38);
	_delay_ms(1);

	// Display ON/OFF control: Display on, Cursor on, Blink off
	 LCD_WriteCommand(0xE);
	_delay_ms(39);

	// Clear Display
	 LCD_WriteCommand( 0x01);
	_delay_ms(2);

	// Entry mode set: Increment cursor position, No display shift
LCD_WriteCommand(0x06);
_delay_ms(1);
}


/************************* LCD Write Number ***************************************/
LCD_enuErrorStatus LCD_enuWriteNumber(usint8_t Copy_u8Number)
{
	LCD_enuErrorStatus loc_enumReturnStatus = LCD_enumNOK;
  
    if (Copy_u8Number == 0) {
	    return LCD_enumOK;
    }

    // Extract the last digit                /*228*/
    usint8_t lastDigit = Copy_u8Number % 10; /*8*/     /*2*/  /*2*/
    LCD_enuWriteNumber(Copy_u8Number / 10);  /*228*/   /*22*/ /*2*/
    LCD_WriteData(lastDigit + '0');

	return LCD_enumOK;
}


/************************* LCD Write Srting ***************************************/
LCD_enuErrorStatus LCD_enuWriteString(char* Copy_pchPattern)
{

	LCD_enuErrorStatus loc_enumReturnStatus = LCD_enumNOK;
    if (Copy_pchPattern == NULL) 
	{
	    return loc_enumReturnStatus;
	}
	else{	
    for (usint8_t i = 0; Copy_pchPattern[i] != '\0'; i++) {
	    LCD_WriteData(Copy_pchPattern[i]);
    }
	
	}
	loc_enumReturnStatus = LCD_enumOK;
	return loc_enumReturnStatus;
}



/************************* GotoDDRAM_XY ***************************************/
LCD_enuErrorStatus LCD_enuGotoDDRAM_XY(usint8_t Copy_u8X, usint8_t Copy_u8Y){

	LCD_enuErrorStatus loc_enumReturnStatus = LCD_enumNOK;
usint8_t address;
	if(Copy_u8X>2 || Copy_u8Y >16)
	{
		return loc_enumReturnStatus;
	}
	
	else if (Copy_u8X ==0){ // first line
		address = Copy_u8Y;
	}
	else if (Copy_u8X == 1){ //sec line
		address = Copy_u8Y+64; // start from sec line
	}
	else {/*MISRA rules */}
   LCD_WriteCommand(address + LCD_SET_DDRAM_ADDRESS);

	return  LCD_enumOK;
	
}


/*************************DisPlay special characters ***************************************/
LCD_enuErrorStatus LCD_enuDisplaySpecialPattern(usint8_t* Copy_pu8Pattern, usint8_t Copy_u8CGRAMBlockNumber, usint8_t Copy_u8X, usint8_t Copy_u8Y)
{
	LCD_enuErrorStatus loc_enumReturnStatus = LCD_enumNOK;
	usint8_t Loc_U8CGRAMAddress = Copy_u8CGRAMBlockNumber* LCD_NUMBER_OF_CGRAM_BYTES ;
	
	
	/*send CGRAM address command to LCD , with setting bit 6 */
	LCD_WriteCommand(Loc_U8CGRAMAddress+64);
	
	
	for(usint8_t i =0;i <LCD_NUMBER_OF_CGRAM_BYTES;i++)
	{
		LCD_WriteData(Copy_pu8Pattern[i]);
	}
	
	LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);

	LCD_WriteData(Copy_u8CGRAMBlockNumber);
	loc_enumReturnStatus = LCD_enumOK;
	return loc_enumReturnStatus;
	
}