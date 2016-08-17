#ifndef _GLOBALVARS_H
#define _GLOBALVARS_H


#include "structs.h"

#define INITMONEY 2000
#define NUMCONTRACTCHOOSE 4
#define NUMSTUFFCHOOSE 3

#define LENPLATFORMLIST 4
#define GAMETIME 140
#define SELLDAY 100

const GamePlatform platformlist[] = {
    {"PC",100},
    {"MES",8000},
    {"Game BOy",2500},
    {"Play Gear",10500}
};

#define LENADLIST 6
const Ad adList[LENADLIST] = {
	{"NULL",0,0},
	{"magazine",5,300},
    {"online",9,500},
    {"broadcast",15,800},
    {"demo",30,1500},
    {"TVad",70,3500}
};

#define LENADLIST2 6


#define LENTHEMELIST 6
const GameTheme themeList[] = {
    {"desktop",200},
    {"action",1200},
    {"advanture",500},
    {"shoot",600},
    {"speed",800},
    {"askAnswer",300}
};


#define LENTYPELIST 11
const GameType typeList[] = {
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

//set to 4 temply
#define LENWAYFINDLIST 4
const WayToFind wayFindList[] = 
{
	{"promoteWay",500},
	{"magazineWay",2000},
};

#define LENWAYTRAINLIST 7
const WayToTrain wayTrainList[] = 
{
    //{"book",300,{1,1,0.0}},
	{"book",300,{1,1,0,0}},
	{"walk",300,{0,0,1,1}},
	{"playGame",600,{1,1,2,0}},
	{"listen",300,{0,0,0,1}},
	{"visit",600,{0,4,0,0}},
	{"study",1500,{1,12,1,1}}
};

#endif