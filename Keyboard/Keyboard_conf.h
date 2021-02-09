/*
 * Keyboard_conf.h
 *
 *  Created on: Feb 8, 2021
 *      Author: radhwen.zorgui
 */

#ifndef KEYBOARD_CONF_H_
#define KEYBOARD_CONF_H_

#include "usbd_hid.h"
#include "main.h"


#define USB_HID_SEND_REPORT(handler, report, size) USBD_HID_SendReport(handler, report, size)
#define UsbHandler hUsbDeviceFS
#define UsbHandlerTypedef USBD_HandleTypeDef

extern UsbHandlerTypedef UsbHandler;
#define DELAY_MS(a)	HAL_Delay(a)

#define KEY_SPEED 15

#endif /* KEYBOARD_CONF_H_ */
