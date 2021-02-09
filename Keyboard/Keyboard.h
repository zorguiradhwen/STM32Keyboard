/*
 * Keyboard.h
 *
 *  Created on: Feb 8, 2021
 *      Author: radhwen.zorgui
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "Keyboard_conf.h"

#define KEYBOARD_REPORT_SIZE (8u)

typedef struct
{
	union
	{
		uint8_t raw[KEYBOARD_REPORT_SIZE];
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
	}report;
	uint16_t speed;
	UsbHandlerTypedef* usb_handler;

}Keyboard;



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

_Bool  Keyboard_init(void);

size_t Keyboard_write(const char *buffer);
_Bool Keyboard_shortcut(const uint8_t modifier1, const uint8_t modifier2, const uint8_t keycode);
_Bool Keyboard_press(const char ch);
//size_t press(uint8_t k);
//size_t release(uint8_t k);
_Bool Keyboard_releaseAll(void);

#endif /* KEYBOARD_H_ */
