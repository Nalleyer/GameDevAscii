#include <malloc.h>
typedef struct Timer
{
    int _year;
    int _month;
    int _week;
    int _day;
} Timer;

Timer * createTimer(int year, int month, int week, int day)
{
    Timer * pTimer = (Timer *) malloc( sizeof( Timer ) );
    pTimer -> _year = year;
    pTimer -> _month = month;
    pTimer -> _week = week;
    pTimer -> _day = day;
    return pTimer;
}

void deleteTiemr(Timer * timer)
{
    free(timer);
}

void addDay(Tiemr * timer)
{
    ++ timer -> _day;
    if ( timer -> _day == 7 )
    {
        ++ timer -> _week;
        if ( timer -> _week == 4 )
        {
            ++ timer -> _month;
            if ( timer -> _month == 12 )
            {
                ++ timer -> _year;
            }
        }
    }
}