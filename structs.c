#ifndef _STRUCTS_C
#define _STRUCTS_C
#include "structs.h"
    
char * getRandomName()
{
    char * name[3];
    name[0] = (char)(rand() % 26 + (int)'a');
    name[1] = (char)(rand() % 26 + (int)'a');
    name[2] = (char)(rand() % 9 + (int)'0');
    return name;
}


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
    pTimer -> _year = 0;
    pTimer -> _month = 0;
    pTimer -> _week = 0;
    pTimer -> _day = 0;
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

Stuff * createStuff(char * name, int salery, Property property)
{
    Stuff * pStuff = (Stuff *) malloc( sizeof( Stuff ) );
    pStuff -> _name = name;
    pStuff -> _salery = salery;
    pStuff ->_property = property;
    return pStuff;
}


Company * createCompany()
{
    Company * pCompany = (Company *) malloc( sizeof( Company ) );
    pCompany -> _isDoingProject = FALSE;
    pCompany -> _timer = createTimer();
    /* first stuff */
    pCompany -> _numStuff = 1;
    pCompany -> _numResearch = 0;
    pCompany -> _stuffs[0] = createStuff(getRandomName(),1, getRandomProperty(avarage));
    pCompany -> _fans = 0;
    pCompany -> _lenGameHistory = 0;
    return pCompany;
}
void checkTimeEvents(Company * company)
{
    
}

void doProject(Company * company)
{
}

#endif