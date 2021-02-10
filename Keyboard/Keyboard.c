/*
 * Keyboard.c
 *
 *  Created on: Feb 8, 2021
 *      Author: radhwen.zorgui
 */

#include "usb_hid_keys.h"
#include "Keyboard.h"
#include <string.h>

static const KeyMap ascii2key_map[] = \
{
	{0	, 0x00, 0x00 },	  // NULL	(Null character)
	{1	, 0x00, 0x00 },   // SOH	(Start of Header)
	{2	, 0x00, 0x00 },   // STX	(Start of Text)
	{3	, 0x00, 0x00 },   // ETX	(End of Text)
	{4	, 0x00, 0x00 },   // EOT	(End of Transmission)
	{5	, 0x00, 0x00 },   // ENQ	(Enquiry)
	{6	, 0x00, 0x00 },   // ACK	(Acknowledgement)
	{7	, 0x00, 0x00 },   // BEL	(Bell)
	{8	, 0x2a, 0x00 },   // BS	(Backspace)
	{9	, 0x2b, 0x00 },   // HT	(Horizontal Tab)
	{10	, 0x28, 0x00 },   // LF	(Line feed)
	{11	, 0x00, 0x00 },   // VT	(Vertical Tab)
	{12	, 0x00, 0x00 },   // FF	(Form feed)
	{13	, 0x00, 0x00 },   // CR	(Carriage return)
	{14	, 0x00, 0x00 },   // SO	(Shift Out)
	{15	, 0x00, 0x00 },   // SI	(Shift In)
	{16	, 0x00, 0x00 },   // DLE	(Data link escape)
	{17	, 0x00, 0x00 },   // DC1	(Device control 1)
	{18	, 0x00, 0x00 },   // DC2	(Device control 2)
	{19	, 0x00, 0x00 },   // DC3	(Device control 3)
	{20	, 0x00, 0x00 },   // DC4	(Device control 4)
	{21	, 0x00, 0x00 },   // NAK	(Negative acknowledgement)
	{22	, 0x00, 0x00 },   // SYN	(Synchronous idle)
	{23	, 0x00, 0x00 },   // ETB	(End of transmission block)
	{24	, 0x00, 0x00 },   // CAN	(Cancel)
	{25	, 0x00, 0x00 },   // EM	(End of medium)
	{26	, 0x00, 0x00 },   // SUB	(Substitute)
	{27	, 0x00, 0x00 },   // ESC	(Escape)
	{28	, 0x00, 0x00 },   // FS	(File separator)
	{29	, 0x00, 0x00 },   // GS	(Group separator)
	{30	, 0x00, 0x00 },   // RS	(Record separator)
	{31	, 0x00, 0x00 },   // US	(Unit separator)
	{32	, 0x2c, 0x00 },   //  	(space)
	{33	, 0x1e, SHIFT},   // !	(exclamation mark)
	{34	, 0x34, SHIFT},   // "	(Quotation mark)
	{35	, 0x20, SHIFT},   // #	(Number sign)
	{36	, 0x21, SHIFT},   // $	(Dollar sign)
	{37	, 0x22, SHIFT},   // %	(Percent sign)
	{38	, 0x24, SHIFT},   // &	(Ampersand)
	{39	, 0x34, 0x00 },   // '	(Apostrophe)
	{40	, 0x26, SHIFT},   // (	(round brackets or parentheses)
	{41	, 0x27, SHIFT},   // )	(round brackets or parentheses)
	{42	, 0x25, SHIFT},   // *	(Asterisk)
	{43	, 0x2e, SHIFT},   // +	(Plus sign)
	{44	, 0x36, 0x00 },   // ,	(Comma)
	{45	, 0x2d, 0x00 },   // -	(Hyphen)
	{46	, 0x37, 0x00 },   // .	(Full stop , dot)
	{47	, 0x38, 0x00 },   // /	(Slash)
	{48	, 0x27, 0x00 },   // 0	(number zero)
	{49	, 0x1e, 0x00 },   // 1	(number one)
	{50	, 0x1f, 0x00 },   // 2	(number two)
	{51	, 0x20, 0x00 },   // 3	(number three)
	{52	, 0x21, 0x00 },   // 4	(number four)
	{53	, 0x22, 0x00 },   // 5	(number five)
	{54	, 0x23, 0x00 },   // 6	(number six)
	{55	, 0x24, 0x00 },   // 7	(number seven)
	{56	, 0x25, 0x00 },   // 8	(number eight)
	{57	, 0x26, 0x00 },   // 9	(number nine)
	{58	, 0x33, SHIFT},   // :	(Colon)
	{59	, 0x33, 0x00 },   // ;	(Semicolon)
	{60	, 0x36, SHIFT},   // <	(Less-than sign )
	{61	, 0x2e, 0x00 },   // =	(Equals sign)
	{62	, 0x37, SHIFT},   // >	(Greater-than sign ; Inequality)
	{63	, 0x38, SHIFT},   // ?	(Question mark)
	{64	, 0x1f, SHIFT},   // @	(At sign)
	{65	, 0x04, SHIFT},   // A	(Capital A )
	{66	, 0x05, SHIFT},   // B	(Capital B )
	{67	, 0x06, SHIFT},   // C	(Capital C )
	{68	, 0x07, SHIFT},   // D	(Capital D )
	{69	, 0x08, SHIFT},   // E	(Capital E )
	{70	, 0x09, SHIFT},   // F	(Capital F )
	{71	, 0x0a, SHIFT},   // G	(Capital G )
	{72	, 0x0b, SHIFT},   // H	(Capital H )
	{73	, 0x0c, SHIFT},   // I	(Capital I )
	{74	, 0x0d, SHIFT},   // J	(Capital J )
	{75	, 0x0e, SHIFT},   // K	(Capital K )
	{76	, 0x0f, SHIFT},   // L	(Capital L )
	{77	, 0x10, SHIFT},   // M	(Capital M )
	{78	, 0x11, SHIFT},   // N	(Capital N )
	{79	, 0x12, SHIFT},   // O	(Capital O )
	{80	, 0x13, SHIFT},   // P	(Capital P )
	{81	, 0x14, SHIFT},   // Q	(Capital Q )
	{82	, 0x15, SHIFT},   // R	(Capital R )
	{83	, 0x16, SHIFT},   // S	(Capital S )
	{84	, 0x17, SHIFT},   // T	(Capital T )
	{85	, 0x18, SHIFT},   // U	(Capital U )
	{86	, 0x19, SHIFT},   // V	(Capital V )
	{87	, 0x1a, SHIFT},   // W	(Capital W )
	{88	, 0x1b, SHIFT},   // X	(Capital X )
	{89	, 0x1c, SHIFT},   // Y	(Capital Y )
	{90	, 0x1d, SHIFT},   // Z	(Capital Z )
	{91	, 0x2f, 0x00 },   // [	(square brackets or box brackets)
	{92	, 0x31, 0x00 },   // \	(Backslash)
	{93	, 0x30, 0x00 },   // ]	(square brackets or box brackets)
	{94	, 0x23, SHIFT},   // ^	(Caret or circumflex accent)
	{95	, 0x2d, SHIFT},   // _	(underscore , understrike , underbar or low line)
	{96	, 0x35, 0x00 },   // `	(Grave accent)
	{97	, 0x04, 0x00 },   // a	(Lowercase  a )
	{98	, 0x05, 0x00 },   // b	(Lowercase  b )
	{99	, 0x06, 0x00 },   // c	(Lowercase  c )
	{100, 0x07, 0x00 },   // d	(Lowercase  d )
	{101, 0x08, 0x00 },   // e	(Lowercase  e )
	{102, 0x09, 0x00 },   // f	(Lowercase  f )
	{103, 0x0a, 0x00 },   // g	(Lowercase  g )
	{104, 0x0b, 0x00 },   // h	(Lowercase  h )
	{105, 0x0c, 0x00 },   // i	(Lowercase  i )
	{106, 0x0d, 0x00 },   // j	(Lowercase  j )
	{107, 0x0e, 0x00 },   // k	(Lowercase  k )
	{108, 0x0f, 0x00 },   // l	(Lowercase  l )
	{109, 0x10, 0x00 },   // m	(Lowercase  m )
	{110, 0x11, 0x00 },   // n	(Lowercase  n )
	{111, 0x12, 0x00 },   // o	(Lowercase  o )
	{112, 0x13, 0x00 },   // p	(Lowercase  p )
	{113, 0x14, 0x00 },   // q	(Lowercase  q )
	{114, 0x15, 0x00 },   // r	(Lowercase  r )
	{115, 0x16, 0x00 },   // s	(Lowercase  s )
	{116, 0x17, 0x00 },   // t	(Lowercase  t )
	{117, 0x18, 0x00 },   // u	(Lowercase  u )
	{118, 0x19, 0x00 },   // v	(Lowercase  v )
	{119, 0x1a, 0x00 },   // w	(Lowercase  w )
	{120, 0x1b, 0x00 },   // x	(Lowercase  x )
	{121, 0x1c, 0x00 },   // y	(Lowercase  y )
	{122, 0x1d, 0x00 },   // z	(Lowercase  z )
	{123, 0x2f, SHIFT},   // {	(curly brackets or braces)
	{124, 0x31, SHIFT},   // |	(vertical-bar, vbar, vertical line or vertical slash)
	{125, 0x30, SHIFT},    // }	(curly brackets or braces)
	{126, 0x35, SHIFT},    // ~	(Tilde ; swung dash)
	{127, 0x4c, 0x00 }	   // DEL
};

static Keyboard keyboard;

extern UsbHandlerTypedef USB_HANDLER;

_Bool Keyboard_init(void)
{
	memset(keyboard.report.raw, 0x00, KEYBOARD_REPORT_SIZE);
	keyboard.speed = KEYBOARD_DEFAULT_PRESS_SPEED;
	keyboard.usb_handler = &USB_HANDLER;
	return 1u;
}

size_t Keyboard_write(const char *buffer)
{
	_Bool result = 1u;
	UNUSED(result);
	uint16_t i = 0u;
	for (i = 0u; i<strlen((char*)buffer); i++)
	{
		keyboard.report.KEYCODE1 = ascii2key_map[(uint8_t)buffer[i]].key;
		keyboard.report.MODIFIER = ascii2key_map[(uint8_t)buffer[i]].shift;
		if(!USB_HID_SEND_REPORT(keyboard.usb_handler, keyboard.report.raw, KEYBOARD_REPORT_SIZE))
			{result &= 1u;}	else	{result &= 0u;}
		KEYBOARD_DELAY(keyboard.speed);
		keyboard.report.KEYCODE1 = KEY_NONE;
		keyboard.report.MODIFIER = KEY_NONE;
		if(!USB_HID_SEND_REPORT(keyboard.usb_handler, keyboard.report.raw, KEYBOARD_REPORT_SIZE))
			{result &= 1u;}	else	{result &= 0u;}
		KEYBOARD_DELAY(keyboard.speed);
	}
	return i;
}

_Bool Keyboard_releaseAll(void)
{
	_Bool result = 1u;
	memset(keyboard.report.raw, 0x00, KEYBOARD_REPORT_SIZE);
	if(!USB_HID_SEND_REPORT(keyboard.usb_handler, keyboard.report.raw, KEYBOARD_REPORT_SIZE))
		{result &= 1u;}	else	{result &= 0u;}
	KEYBOARD_DELAY(keyboard.speed);
	return result;
}

_Bool Keyboard_shortcut(const uint8_t modifier1, const uint8_t modifier2, const uint8_t keycode)
{
	_Bool result = 1u;
	// TODO : check for integrity of modifiers ex can t press 2 shifts at the same time
	keyboard.report.KEYCODE1 = keycode;
	keyboard.report.MODIFIER = modifier1|modifier2;
	if(!USB_HID_SEND_REPORT(keyboard.usb_handler, keyboard.report.raw, KEYBOARD_REPORT_SIZE))
		{result &= 1u;}	else	{result &= 0u;}
	KEYBOARD_DELAY(keyboard.speed);
	keyboard.report.KEYCODE1 = KEY_NONE;
	keyboard.report.MODIFIER = KEY_NONE;
	if(!USB_HID_SEND_REPORT(keyboard.usb_handler, keyboard.report.raw, KEYBOARD_REPORT_SIZE))
		{result &= 1u;}	else	{result &= 0u;}
	KEYBOARD_DELAY(keyboard.speed);

	return result;
}


_Bool  Keyboard_press(const uint8_t keycode)
{
	_Bool result = 1u;
	keyboard.report.KEYCODE1 = keycode;
	keyboard.report.MODIFIER = KEY_NONE;
	if(!USB_HID_SEND_REPORT(keyboard.usb_handler, keyboard.report.raw, KEYBOARD_REPORT_SIZE))
		{result &= 1u;}	else	{result &= 0u;}
	KEYBOARD_DELAY(keyboard.speed);
	keyboard.report.KEYCODE1 = KEY_NONE;
	if(!USB_HID_SEND_REPORT(keyboard.usb_handler, keyboard.report.raw, KEYBOARD_REPORT_SIZE))
		{result &= 1u;}	else	{result &= 0u;}
	KEYBOARD_DELAY(keyboard.speed);
	return result;
}
















