/*
 * l86.c
 *
 *  Created on: Feb 3, 2024
 *      Author: mustafa "pxsty" kok
 */

#include <pxstyl86.h>

_io uint8_t nmeaMsg[1024];

_io int pxstyL86_utcTime;

_io int pxstyL86_hours;
_io int pxstyL86_minutes;
_io int pxstyL86_seconds;

_io float pxstyL86_latitude;
_io float pxstyL86_longitude;

_io float pxstyL86_speed;

_io int pxstyL86_date;

_io int pxstyL86_day;
_io int pxstyL86_month;
_io int pxstyL86_year;

_io int proccesingData(void);

_io int proccesingData(void)
{
    const char *startTag = "$GNRMC";
    const char *endlTag = "\r\n";
    int status = 200;

    char *startPtr = strstr((char *)nmeaMsg, startTag);
    if (startPtr == NULL)
        status = 1;
    else
    {
        while (startPtr != NULL)
        {
            char *endlPtr = strstr(startPtr, endlTag);

            if (endlPtr != NULL)
            {

                size_t lineLength = endlPtr - startPtr;
                char line[lineLength + 1];
                strncpy(line, startPtr, lineLength);
                line[lineLength] = '\0';

                char *buffers[20];

                char *buffer = strtok(line, ",");
                int tokenIndex = 0;
                while (buffer != NULL)
                {
                    buffers[tokenIndex++] = buffer;
                    buffer = strtok(NULL, ",");
                }
                if (tokenIndex == 12)
                {

                    pxstyL86_utcTime = atoi(buffers[1]);

                    pxstyL86_hours = ((pxstyL86_utcTime / 10000) + 3) % 24;
                    pxstyL86_minutes = (pxstyL86_utcTime % 10000) / 100;
                    pxstyL86_seconds = pxstyL86_utcTime % 100;

                    pxstyL86_latitude = atof(buffers[3]) / 100.0;
                    pxstyL86_longitude = atof(buffers[5]) / 100.0;

                    pxstyL86_speed = atof(buffers[7]) * 1.852 / 3600.0;

                    pxstyL86_date = atoi(buffers[9]);

                    if (pxstyL86_hours <= 2)
                        pxstyL86_day = (pxstyL86_date / 10000) + 1;
                    else
                        pxstyL86_day = pxstyL86_date / 10000;

                    pxstyL86_month = (pxstyL86_date % 10000) / 100;
                    pxstyL86_year = (pxstyL86_date % 100) + 2000;
                }
                else
                    status = 1;
            }
            else
            {
                break;
            }

            startPtr = strstr(endlPtr, startTag);
        }
    }

    return status;
}

int readData(char nmea[1024])
{
    strcpy((char *)nmeaMsg, nmea);
    return proccesingData();
}

int getHours(void)
{
    return pxstyL86_hours;
};
int getMinutes(void)
{
    return pxstyL86_minutes;
};
int getSeconds(void)
{
    return pxstyL86_seconds;
};

float getLatitude(void)
{
    return pxstyL86_latitude;
};
float getLongitude(void)
{
    return pxstyL86_longitude;
};

int getSpeed()
{
    return pxstyL86_speed;
};

int getDay(void)
{
    return pxstyL86_day;
};
int getMonth(void)
{
    return pxstyL86_month;
};
int getYear(void)
{
    return pxstyL86_year;
};
