#ifndef __HC_SR04_H__
#define __HC_SR04_H__

/*
USART BAUD Speed supported for Atmega328P :


 * 1200
 * 2400
 * 4800
 * 9600
 * 19200
 * 38400
 * 57600
 * 115200

*/
#define B1200 1200
#define B2400 2400
#define B4800 4800
#define B9600 9600
#define B19200 19200
#define B38400 38400
#define B57600 57600
#define B115200 115200


#include <avr/io.h>
#include "atmega328p-lib/include/uart.h"
#include "atmega328p-lib/include/timer.h"
#include "atmega328p-lib/include/util_pin.h"
#include "atmega328p-lib/include/utils.h"

void initHcSr04(int trig, int echo, int uart_baud);
unsigned long distanceCm(void);
#endif