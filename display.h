/*******************
* this file conclude display and control functions
*********************/
#ifndef _display_H
#define _display_H


#include <curses.h>
#include "simpleStruct.h"

typedef struct DisplayInformation
{
    int _numMoney;
    int _numBugs;
    int _numResearch;
    int _numFans;
    Timer * _time;
    //Project * _project;
}DisplayInformation;

DisplayInformation * createDisplayInformation()
{
    DisplayInformation * pInfo = (DisplayInformation *) malloc( sizeof( DisplayInformation) );
    pInfo -> _numMoney = 0;
    pInfo -> _numBugs = 0;
    pInfo -> _numResearch = 0;
    pInfo -> _numFans = 0;
    pInfo -> _time = createTimer();
    //Project * _project = createProject();
    return pInfo;
}

void initDisplay(DisplayInformation * displayInformation)
{
    /* init curses */
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    /* print info */
    mvprintw(0,0,"money: %d",displayInformation -> _numMoney);
    mvprintw(1,0,"year %d, month %d, week %d",
             displayInformation -> _time -> _year,
             displayInformation -> _time -> _month,
             displayInformation -> _time -> _week
    );
    mvprintw(2,0,"fans: %d", displayInformation -> _numFans);
    mvprintw(0,COLS / 2 - 15, "woking on: NULL");
    mvprintw(1,COLS / 2 - 15, "bugs: %d",displayInformation -> _numBugs);
    mvprintw(2,COLS / 2 - 15, "research: %d",displayInformation -> _numResearch);
    /* draw info box */
    mvprintw();
}

void update()
{
    refresh();
}

#endif