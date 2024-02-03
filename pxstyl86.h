/*
 * l86.h
 *
 *  Created on: Feb 3, 2024
 *      Author: mustafa "pxsty" kok
 */

#ifndef PXSTYL86_H_
#define PXSTYL86_H_
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define _io static

/****************USR functions******************/

int readData(char nmea[1024]); // Reading RMC data

int getHours(void);
int getMinutes(void);
int getSeconds(void);

float getLatitude(void);
float getLongitude(void);

int getSpeed();

int getDay(void);
int getMonth(void);
int getYear(void);

/****************USR functions******************/

#endif
