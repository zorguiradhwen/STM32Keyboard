/*
 * Keyboard_conf.h
 *
 *  Created on: Feb 8, 2021
 *      Author: radhwen.zorgui
 */

#ifndef KEYBOARD_CONF_H_
#define KEYBOARD_CONF_H_



#include "usbd_customhid.h"

// include HARDWARE ABSTARCTION LIBRARY IN CURRENT PLATFORM
#include "main.h" // for stm32 toolchain, main.h contains all necessary includes for the hardware



#define USB_HID_SEND_REPORT(handler, report, size) USBD_CUSTOM_HID_SendReport(handler, report, size)
#define USB_HANDLER hUsbDeviceFS
typedef USBD_HandleTypeDef UsbHandlerTypedef;

#define KEYBOARD_DELAY(a)	HAL_Delay(a)

#define KEYBOARD_DEFAULT_PRESS_SPEED 15 //

#endif /* KEYBOARD_CONF_H_ */
