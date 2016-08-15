#ifndef _simpleStruct_H
#define _simpleStruct_H

#include <stdlib.h>
#include <malloc.h>

typedef struct Timer
{
    int _year;
    int _month;
    int _week;
    int _day;
} Timer;

void setTimer(Timer * pTimer, int year, int month, int week, int day)
{
    pTimer -> _year = year;
    pTimer -> _month = month;
    pTimer -> _week = week;
    pTimer -> _day = day;
}

Timer * createTimer()
{
    Timer * pTimer = (Timer *) malloc( sizeof( Timer ) );
    pTimer -> _year = 1;
    pTimer -> _month = 1;
    pTimer -> _week = 1;
    pTimer -> _day = 1;
    return pTimer;
}

void addDay(Timer * timer)
{
    ++ timer -> _day;
    if ( timer -> _day == 7 )
    {
        ++ timer -> _week;
        timer -> _day = 0;
        if ( timer -> _week == 4 )
        {
            ++ timer -> _month;
            timer -> _week = 0;
            if ( timer -> _month == 12 )
            {
                timer -> _month = 0;
                ++ timer -> _year;
            }
        }
    }
}

#endif