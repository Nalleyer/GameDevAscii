#ifndef _structs_H
#define _structs_H

#include <stdlib.h>
#include <malloc.h>

#define MAXSTUFFNUM 4
#define MAXGAME 1000

typedef int BOOL;
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

typedef struct GamePlatform
{;
    char * _name;
    int _money;
}GamePlatform;



typedef struct Timer
{
    int _year;
    int _month;
    int _week;
    int _day;
} Timer;


typedef struct Property
{
	int _coding;
	int _writing;
	int _drawing;
	int _music;
}Property;

typedef struct Propertytwo
{
	int _intrest;
	int _uniquation;
	int _musics;
	int _eyes;
}Propertytwo;

typedef enum enumStuffType
{
    coder,
    writer,
    painter,
    musician,
    avarage
}enumStuffType;

Property getRandomProperty(enumStuffType stuffType)
{
    //tmp
    Property p;
    return p;
}

typedef struct Stuff
{
	 char * _name;
     int _salery;
	 Property _property;
}Stuff;


typedef struct Project
{
	char * _name;
	char _platform;
	char _gametype;
	char _gametheme;
	int _numBugs;
	int _process;
	int _selledCopies;
}Project;

typedef struct Ad
{
	char * _name;
	int _deltaFans;
	int _money;
}Ad;

typedef struct GameType
{
	char * _typeName;
	int _money;
}GameType;

typedef struct GameTheme
{
    char * _themeName;
    int _money;
}GameTheme;

typedef struct Company
{
	BOOL _isDoingProject;
	Project * _nowProject;
	Stuff * _stuffs[MAXSTUFFNUM];
    Timer * _timer;
    /* if no ad now, _nowAd is 'null' */
    Ad * _nowAd;
	int _numStuff;
    int _numResearch;
	int _fans;
    int _money;
    Project * _gameHistory[MAXGAME];
    int _lenGameHistory;
}Company;

	

#endif