# pxsty.stm32.l86.lib

With Pxsty L86 GPS Library, you can convert your GPS data in NMEA Format into an easily readable format.

## Kullanım/Örnekler

```c
#include "pxstyl86.h"


uint8_t rxData[1024];

status = readData((char*)rxData);

int hours = getHours();
int minutes = getMinutes();
int seconds = getSeconds();

float latitude = getLatitude();
float longitude = getLongitude();

float speed = getSpeed();

int day = getDay();
int month = getMonth();
int year = getYear();

```

  
## Lisans

[MIT](https://choosealicense.com/licenses/mit/)

  [![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
