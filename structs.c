#ifndef _STRUCTS_C
#define _STRUCTS_C
#include "structs.h"
#include "globalVars.h"
    
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

int fansNum(Ad * ad)
{
	for ( int i = 0; i < LENADLIST; ++ i )
	{
		if ( adList[i]._name == ad -> _name )
			return ( adList[i]._deltaFans );
	}
}

int moneyNum(Ad * ad)
{
	for ( int j = 0;j < LENADLIST; ++ j )
	{
		if ( adList[j]._money == ad ->  -money )
			return ( adList[i]._money );
	}
}

void max(Propertytwo)
{
	int a = Propertytwo._intrest;
		if(Propertytwo._uniquation >= a)
		{
			a=Propertytwo._uniquation;
		    if(Propertytwo._musics >= a)
			{
				a=Propertytwo._musics;
			    if(Propertytwo._eyes >= a)
				{
					a=Propertytwo._eyes;
				}
			}
		}
		return a;
}

void min(Propertytwo)
{
	int b = Propertytwo._intrest;
		if(Propertytwo._uniquation <= b)
		{
			b=Propertytwo._uniquation;
		    if(Propertytwo._musics <= b)
			{
				b=Propertytwo._musics;
			    if(Propertytwo._eyes <= b)
				{
					b=Propertytwo._eyes;
				}
			}
		}
		return b;
}

int moneyTheme(GameTheme * theme)
{
	for ( int i = 0; i < LENADLIST2; ++ i )
	{
		if ( themeList[i]._themeName == theme -> _themeName )
			return ( themeList[i]._themeName );
	}
}

int moneyType(GameType * type)
{
	for ( int j = 0; j < LENADLIST3; ++ j )
	{
		if ( typeList[j]._typeName == type -> _typeName )
			return ( typeList[j]._typeName );
	}
}

void increasemoney ( Company * company)
{
	int x,y,z;
	x = moneyNum();
	y = moneyTheme(GameTheme * theme);
	z = moneyType(GameType * type);
#endif