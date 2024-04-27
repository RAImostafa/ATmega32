/*
 * KeyPad_.c
 *
 * Created: 08/01/2024 18:50:01
 * Author : Rania
 */ 


#include "KeyPad.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\HAL\LCD_\LCD.h"


#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 16
#define MAX_OPERAND_SIZE 4  // Adjust the size based on the maximum expected operand size


void extractOperand(char operator, usint8_t* inputs, usint8_t u8Index, usint8_t* operand) {
	usint8_t x = 0;

	for (usint8_t i = 0; i < u8Index; i++) {
		if (inputs[i] == operator) {
			// Find the operator, start extracting the operand
			for (usint8_t j = i + 1; j < u8Index; j++) {
				if (inputs[j] != '=' && x < MAX_OPERAND_SIZE - 1) {
					operand[x] = inputs[j];
					x++;
					} else {
					break;  // Exit the loop when '=' is encountered or operand size is reached
				}
			}
			operand[x] = '\0';  // Null-terminate the operand
			break;  // Exit the outer loop after extracting the operand
		}
	}
}

int main(void) {
	LCD_init();
	_KeyPad_init();

	usint8_t Local_u8PressedKey;
	usint8_t inputs[MAX_INPUT_SIZE];
	usint8_t u8Index = 0;
	usint8_t op1[MAX_OPERAND_SIZE];
	usint8_t op2[MAX_OPERAND_SIZE];
	usint8_t result[MAX_OPERAND_SIZE + 1];  // +1 for null terminator

	while (1) {
		for (usint8_t u8InputCntrLoc = 0; u8InputCntrLoc < MAX_INPUT_SIZE; u8InputCntrLoc++) {
			do {
				_KeyPad_GetPressedKey(&Local_u8PressedKey);
				u8Index++;
			} while (Local_u8PressedKey == 0xFF);

			inputs[u8InputCntrLoc] = Local_u8PressedKey;
			LCD_WriteData(inputs[u8InputCntrLoc]);
			_delay_ms(100);

			if (Local_u8PressedKey == 'A') {
				LCD_WriteCommand(LCD_CLEAR_DISPLAY);
				
				// Clear the entire inputs array
				for (usint8_t i = 0; i < MAX_INPUT_SIZE; i++) {
					inputs[i] = 0x00;
				}
				
				u8Index = 0;  // Reset u8Index for a new calculation
				break;  // Exit the loop to start a new input
			}

			if (Local_u8PressedKey == '=') {
				u8InputCntrLoc = MAX_INPUT_SIZE - 1;
				for (usint8_t i = 0; i < u8Index; i++) {
					if (inputs[i] == '+' || inputs[i] == '-' || inputs[i] == '*' || inputs[i] == '/') {
						extractOperand(inputs[i], inputs, u8Index, op2);
						usint8_t num1 = atoi(op1);
						usint8_t num2 = atoi(op2);

						switch (inputs[i]) {
							case '+':
							snprintf(result, sizeof(result), "%d", num1 + num2);
							break;
							case '-':
							snprintf(result, sizeof(result), "%d", num1 - num2);
							break;
							case '*':
							snprintf(result, sizeof(result), "%d", num1 * num2);
							break;
						case '/':
						if (num2 != 0) {
							snprintf(result, sizeof(result), "%d", num1 / num2);
							} else {
							LCD_WriteCommand(LCD_CLEAR_DISPLAY);
							LCD_enuWriteString("Error: Division by zero");
							break;
						}
						break;
						}

						LCD_enuWriteString(result);
						u8Index = 0;
						break;
						} else {
						op1[i] = inputs[i];
					}
				}
			}
		}
	}
}