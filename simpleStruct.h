#include <string.h>
#include "util.h"


#define MAXSTUFFNUM 4

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

void addDay(Timer * timer)
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

typedef struct Property
{
	int _coding;
	int _writing;
	int _drawing;
	int _music;
}Property;

typedef struct Stuff
{
	 char * _name;
     int _salery;
	 Property _property;
}Stuff;

Stuff * createStuff(char * name, int salery, Property property)
{
	Stuff * pStuff = (Stuff *) malloc( sizeof( Stuff ) );
	pStuff -> name = name;
	pStuff -> salery = salery;
	pStuff ->_property = property;
	return pStuff;
}

typedef struct Project
{
	char * _name;
	char _platform;
	char _gametype;
	char * _gametheme;
	int _numBugs;
	int _process;
	int _selledCopies;
}Project;

typedef struct Ad
{
	char * _name;
	int deltaFans;
	int money;
}Ad;

const Ad adList[5] = {
	{"magazine",5,300},
	{"online",9,500},
	{"broadcast",15,800},
	{"demo",30,1500},
	{"TVad",70,3500}
};

typedef struct GameType
{
	char * _typeName;
	int money;
}GameType;

const GameTheme themeList[] = {
	{"desktop",200},c
	{"action",1200},
	{"advanture",500},
	{"shoot",600},
	{"speed",800},
	{"askAnswer",300}
};

const GameType typelist[] = {
	{"naruto",365},
	{"mestery",380},
	{"chess",155},
	{"golf",400},
	{"marathon",225},
	{"PE",200},
	{"treature",225},
	{"animal",275},
	{"robot",250},
	{"history",425},
	{"art",700}
};

typedef struct Company
{
	bool _isDoingProject;
	Project * _nowProject;
	Stuff * _stuffs[MAXSTUFFNUM];
	int _numStuff;
	char _system;
	int _fans;
}Company;

char * getRandomName()
{
	srand(time(0));
	stuff[0] = {"("%c",rand()%z+a)("%d",rand()%9+0)"};
	return 0;
}

Company * creatcompany()
{
    Company * pCompany = (Company *) malloc( sizeof( Company ) );
	pCompany -> _isDoingProject = false;
    pCompany -> _numStuff = 1;
	pCompany -> _stuffs[0] = createStuff(getRandomName(),1,1);
	pcompany -> _system = system;
	pcompany -> _fans = fans;
	return pcompany;
}

const GamePlatform platformlist[] = {
	{"PC",100},
	{"MES",8000},
	{"Game BOy",2500},
	{"Play Gear",10500}
};
	
	