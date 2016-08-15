/*******************
* this file conclude display and control functions
*********************/
#ifndef _display_H
#define _display_H


#include <ncurses.h>
#include "structs.h"
#include "structs.c"

WINDOW * createWin(int height, int width, int startX, int startY)
{ 
    WINDOW *local_win;
    local_win = newwin(height, width, startX, startY);
    box(local_win, 0 , 0);
    //wborder(local_win,'|','|','-','_','+','+','+','+');
    wrefresh(local_win);
    return local_win;
}


typedef struct DisplayWins
{
    WINDOW * mainWin;
    WINDOW * subWin;
    WINDOW * infoWin;
}DisplayWins;

DisplayWins * createDisplayWins()
{
    DisplayWins * pDisWin = (DisplayWins *)malloc( sizeof(DisplayWins) );
    pDisWin -> mainWin = createWin(9,20,5,0);
    pDisWin -> infoWin = createWin(LINES / 4 , COLS -1, LINES - LINES / 4, 0);
    /* print main menu */
    mvwprintw(pDisWin->mainWin,1,3,"projects(p)");
    mvwprintw(pDisWin->mainWin,2,3,"stuff(s)");
    mvwprintw(pDisWin->mainWin,3,3,"actions(a)");
    mvwprintw(pDisWin->mainWin,4,3,"information(i)");
    mvwprintw(pDisWin->mainWin,5,3,"system(y)");
    
    
    wrefresh(pDisWin->mainWin);
    return pDisWin;
}


void refreshGlobalDisplay(Company * company)
{
    
    /* print info */
    mvprintw(0,0,"money: %d", company -> _money);
    mvprintw(1,0,"year %d, month %d, week %d\t",
             company -> _timer -> _year + 1,
             company -> _timer -> _month + 1,
             company -> _timer -> _week + 1
    );
    mvprintw(2,0,"fans: %d", company -> _fans );
    mvprintw(0,COLS / 2 - 15, "woking on: NULL");
    mvprintw(1,COLS / 2 - 15, "bugs: 0");
    mvprintw(2,COLS / 2 - 15, "research: %d", company -> _numResearch);
}

void updateDisplay(Company * company)
{
    /* time */
    mvprintw(1,0,"year %d, month %d, week %d\t",
             company -> _timer -> _year + 1,
             company -> _timer -> _month + 1,
             company -> _timer -> _week + 1
    );
    refresh();
}

#endif