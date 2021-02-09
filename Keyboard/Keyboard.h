/*
 * Keyboard.h
 *
 *  Created on: Feb 8, 2021
 *      Author: radhwen.zorgui
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "Keyboard_conf.h"

typedef struct
{
	union
	{
		uint8_t report[8];
		struct
		{
			uint8_t MODIFIER;
			uint8_t RESERVED;
			uint8_t KEYCODE1;
			uint8_t KEYCODE2;
			uint8_t KEYCODE3;
			uint8_t KEYCODE4;
			uint8_t KEYCODE5;
			uint8_t KEYCODE6;
		};
	};
}KeyboardHID;



typedef struct KeyMap_s
{
	char ascii_char;
	struct
	{
		uint8_t key;
		uint8_t shift;
	};
}KeyMap;

#define SHIFT (0x02)


//void begin(void);
//void end(void);
////size_t write(uint8_t k);
size_t Keyboard_write(const uint8_t *buffer/*, size_t size*/);
//size_t press(uint8_t k);
//size_t release(uint8_t k);
//void releaseAll(void);

#endif /* KEYBOARD_H_ */
