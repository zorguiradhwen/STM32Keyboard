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

#define SHIFT KEY_MOD_LSHIFT


typedef struct Keyboard_s
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


_Bool  Keyboard_init(void);
size_t Keyboard_write(const char *buffer);
_Bool  Keyboard_releaseAll(void);
_Bool  Keyboard_press(const uint8_t key);
_Bool  Keyboard_shortcut(const uint8_t modifier1, const uint8_t modifier2, const uint8_t keycode);
_Bool  Keyboard_pressMultiple(const uint8_t *buffer);

#define CTRL	KEY_MOD_LCTRL
#define ALT   	KEY_MOD_LALT
#define ALTGR 	KEY_MOD_RALT
#define META 	KEY_MOD_LMETA

#define KEYBOARD_COPY()	 \
	Keyboard_shortcut(CTRL, KEY_NONE, KEY_C)
#define KEYBOARD_PASTE() \
	Keyboard_shortcut(CTRL, KEY_NONE, KEY_V)
#define KEYBOARD_CUT() 	 \
	Keyboard_shortcut(CTRL, KEY_NONE, KEY_X)
#define KEYBOARD_SELECT_ALL() \
	Keyboard_shortcut(CTRL, KEY_NONE, KEY_A)
#define KEYBOARD_RUN() \
	Keyboard_shortcut(META, KEY_NONE, KEY_R)
#define KEYBOARD_LOCK() \
	Keyboard_shortcut(META, KEY_NONE, KEY_L)
#define KEYBOARD_UNDO() \
	Keyboard_shortcut(CTRL, KEY_NONE, KEY_Z)
#define KEYBOARD_REDO() \
	Keyboard_shortcut(CTRL, KEY_NONE, KEY_Y)
#define KEYBOARD_CLOSE() \
	Keyboard_shortcut(CTRL, KEY_NONE, KEY_W)





#endif /* KEYBOARD_H_ */
