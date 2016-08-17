/*******************
* this file conclude display and control functions
*********************/
#ifndef _display_H
#define _display_H


#include <ncurses.h>
#include "globalVars.h"

WINDOW * createWin(int height, int width, int startX, int startY)
{ 
    WINDOW *local_win;
    local_win = newwin(height, width, startX, startY);
    box(local_win, 0 , 0);
    //wborder(local_win,'|','|','-','_','+','+','+','+');
    wrefresh(local_win);
    return local_win;
}

typedef struct WinPara
{
    int _height;
    int _width;
    int _startX;
    int _startY;
}WinPara;

typedef struct DisplayWins
{
    WINDOW * _mainWin;
    WinPara _mainWinPara;
    WINDOW * _infoWin;
    WinPara _infoWinPara;
}DisplayWins;

DisplayWins * createDisplayWins()
{
    DisplayWins * pDisWin = (DisplayWins *)malloc( sizeof(DisplayWins) );
    WinPara mainP = {LINES / 2, 100, 5, 0};
    pDisWin -> _mainWin = createWin(LINES / 2,100,5,0);
    pDisWin -> _mainWinPara = mainP;
    WinPara infoP = {LINES / 4, COLS - 1, LINES - LINES / 4, 0};
    pDisWin -> _infoWin = createWin(LINES / 4 , COLS -1, LINES - LINES / 4, 0);
    pDisWin -> _infoWinPara = infoP;
    
    //printMainMenu(pDisWin);
    
    return pDisWin;
}

void printMainMenu(DisplayWins *disWin)
{
    /* print main menu */
    mvwprintw(disWin ->_mainWin,1,3,"projects(p)");
    mvwprintw(disWin ->_mainWin,2,3,"stuff(s)");
    mvwprintw(disWin ->_mainWin,3,3,"actions(a)");
    mvwprintw(disWin ->_mainWin,4,3,"information(i)");
    mvwprintw(disWin ->_mainWin,5,3,"system(y)");
    mvwprintw(disWin ->_mainWin,7,3,"exit menu(e)");
    
    
    
    wrefresh(disWin ->_mainWin);
}

void printProjectMenu(DisplayWins * disWin)
{
    mvwprintw(disWin -> _mainWin, 1, 3, "new game(n)");
    mvwprintw(disWin -> _mainWin, 2, 3, "contract(c)");
    mvwprintw(disWin -> _mainWin, 4, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}

void printChooseContractMenu(DisplayWins * disWin, Project * *contractList, int len)
{
    int i = 0;
    for ( ; i < len; ++ i )
    {
        Project * tmpPj = contractList[i];
        Propertytwo tmpPt = tmpPj -> _property;
        mvwprintw(disWin -> _mainWin, i + 1, 3, "%d,%d,%d,%d, money:%d,reward:%d (%d)",
                  tmpPt._intrest,
                  tmpPt._uniquation,
                  tmpPt._eyes,
                  tmpPt._musics,
                  tmpPj -> _money,
                  tmpPj -> _reward,
                  i + 1
                 );
    }
    mvwprintw(disWin -> _mainWin, i + 2, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}

void printStuffMenu(DisplayWins * disWin)
{
    mvwprintw(disWin -> _mainWin, 1, 3, "hire(h)");
    mvwprintw(disWin -> _mainWin, 2, 3, "filr(f)");
    mvwprintw(disWin -> _mainWin, 3, 3, "train(t)");
    mvwprintw(disWin -> _mainWin, 5, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}

void printActionMenu(DisplayWins * disWin)
{
    mvwprintw(disWin -> _mainWin, 1, 3, "advertise(a)");
    mvwprintw(disWin -> _mainWin, 3, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}

/* information menu in main menu! */
void printInformationMenu(DisplayWins * disWin)
{
    
}

void printSystemMenu(DisplayWins * disWin)
{
    
}

void printWayToFindMenu(DisplayWins * disWin)
{
    int i = 0;
    for ( ; i < LENWAYFINDLIST; ++ i )
    {
        mvwprintw(disWin -> _mainWin, i + 1, 3, "%s\tmoney:%d(%c)",
                  wayFindList[i]._name,
                  wayFindList[i]._money,
                  '0' + i + 1);
    }
    mvwprintw(disWin -> _mainWin, i + 2, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}

void printChooseStuffFireMenu(DisplayWins * disWin,Company * company)
{
    int i = 0;
    for ( ; i < company -> _numStuff; ++ i )
    {
        Stuff * s = company -> _stuffs[i];
        mvwprintw(disWin -> _mainWin, i + 1, 3, "%s,coding:%d,writing:%d,drawing:%d,music:%d)(%c)",
                  s -> _name,
                  s -> _property ._coding,
                  s -> _property . _writing,
                  s -> _property . _drawing,
                  s -> _property . _music,
                  '0' + i + 1);
    }
    mvwprintw(disWin -> _mainWin, i + 2, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}


void printTrainWayMenu(DisplayWins * disWin)
{
    int i = 0;
    for ( ; i < LENWAYTRAINLIST; ++ i )
    {
        mvwprintw(disWin -> _mainWin, i + 1, 3, "%s\tmoney:%d(%d)",
                  wayTrainList[i]._name,
                  wayTrainList[i]._money,
                  '0' + i + 1);
    }
    mvwprintw(disWin -> _mainWin, i + 2, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}

void printChooseStuffTrainMenu(DisplayWins * disWin,Company * company)
{
    int i = 0;
    for ( ; i < company -> _numStuff; ++ i )
    {
        mvwprintw(disWin -> _mainWin, i + 1, 3, "%s(%d)",
                  company -> _stuffs[i],
                  '0' + i + 1);
    }
    mvwprintw(disWin -> _mainWin, i + 2, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}

void printChooseStuffHireMenu(DisplayWins * disWin, Stuff ** stuffList)
{
    int i = 0;
    for (; i < NUMSTUFFCHOOSE; ++ i)
    {
        Stuff * s = stuffList[i];
        mvwprintw(disWin -> _mainWin, i + 1, 3, "%s,(coding:%d,writing:%d,drawing:%d,music:%d)\tmoney:%d(%c)",
            s -> _name,
            s -> _property ._coding,
            s -> _property._writing,
            s -> _property._drawing,
            s -> _property._music,
            s -> _salery,
            '0' + i + 1
        );
    }
    mvwprintw(disWin -> _mainWin, i + 2, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}

void printAdMenu(DisplayWins * disWin)
{
    
}

void printPlatformMenu(DisplayWins * disWin)
{
    int i = 0;
    for ( ; i < LENPLATFORMLIST; ++ i )
    {
        mvwprintw(disWin -> _mainWin, i + 1, 3, "%s(%c)\tmoney:%5d",
                  platformlist[i]._name,
                  '0' + i+1,
                  platformlist[i]._money);
    }
    mvwprintw(disWin -> _mainWin, i + 2, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}

void printThemeMenu(DisplayWins * disWin)
{   
    int i = 0;
    for ( ; i < LENTHEMELIST; ++ i )
    {
        mvwprintw(disWin -> _mainWin, i + 1, 3, "%s(%c)\tmoney:%5d",
                  themeList[i]._themeName,
                  '0' + i+1,
                  themeList[i]._money);
    }
    mvwprintw(disWin -> _mainWin, i + 2, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}

void printTypeMenu(DisplayWins * disWin)
{
    int i = 0;
    for ( ; i < LENTYPELIST; ++ i )
    {
        mvwprintw(disWin -> _mainWin, i + 1, 3, "%s(%c)\tmoney:%5d",
                  typeList[i]._typeName,
                  '0' + i+1,
                  typeList[i]._money);
    }
    mvwprintw(disWin -> _mainWin, i + 2, 3, "back(b)");
    wrefresh(disWin -> _mainWin);
}


void clearMainMenu(DisplayWins * disWin)
{
    for ( int x = 0 ; x < disWin -> _mainWinPara._height; ++ x)
        for ( int y = 0 ; y < disWin -> _mainWinPara._width; ++ y )
        {
            mvwaddch(disWin->_mainWin,x,y,' ');
        }
    box(disWin->_mainWin,0,0);
    wrefresh(disWin->_mainWin);
}

void clearInfoWin(DisplayWins * disWin)
{
    for ( int x = 0; x < disWin -> _infoWinPara._height; ++ x)
        for ( int y = 0; y < disWin -> _infoWinPara._width; ++ y )
        {
            mvwaddch(disWin->_infoWin,x,y,' ');
        }
    box(disWin->_mainWin,0,0);
    wrefresh(disWin->_infoWin);
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
    if ( company -> _isDoingProject)
    {
        mvprintw(0,COLS / 2 - 15, "woking on: %s",
                     company -> _nowProject -> _name
        );
        mvprintw(2,COLS / 2 - 15, "research: %d",
                 company -> _numResearch
        );
        
        /* property */
        mvprintw(4, COLS - COLS / 4,"intrest: %d",
                 company -> _nowProject -> _property . _intrest
        );
        mvprintw(5, COLS - COLS / 4,"uniquation: %d",
                 company -> _nowProject -> _property . _uniquation
        );
        mvprintw(6, COLS - COLS / 4,"eyes: %d",
                 company -> _nowProject -> _property . _eyes
        );
        mvprintw(7, COLS - COLS / 4,"musics: %d",
                 company -> _nowProject -> _property . _musics
        );
        
        if ( company -> _nowProject -> _isGame )
        {
            mvprintw(1,COLS / 2 - 15, "bugs: %d",
                     company -> _nowProject -> _numBugs
            );
            mvprintw(3,COLS / 2 - 15, "process: %.2f%%",
                     company -> _nowProject -> _process * 100
            );
        }
        else
        {
            
        }
    }
    else
    {
        mvprintw(0,COLS / 2 - 15, "no project now");
    }
    
    
}

void updateDisplay(Company * company)
{
    /* time */
    mvprintw(1,0,"year %d, month %d, week %d\t",
             company -> _timer -> _year + 1,
             company -> _timer -> _month + 1,
             company -> _timer -> _week + 1
    );
    refreshGlobalDisplay(company);
    refresh();
}

void printInfo(DisplayWins * disWin, char * str)
{
    clearInfoWin(disWin);
    mvwprintw(disWin -> _infoWin, 1,1,"%s",str);
    box(disWin -> _infoWin,0,0);
    wrefresh(disWin -> _infoWin);
}

#endif