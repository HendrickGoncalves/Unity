
#ifndef __PAYMENT_H__
#define __PAYMENT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int payment(float value, char status[15]);
uint8_t validStatus(char *status);
uint8_t validValue(float value);

#endif /*__PAYMENT_H__*/
