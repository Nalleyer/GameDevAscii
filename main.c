#include <stdio.h>
#include "structs.h"
#include "structs.c"
#include "display.h"
#include <unistd.h>
#include <time.h>
#include <pthread.h>


void updateCompany(Company * company)
{
    /* update timer */
    addDay(company -> _timer);
    checkTimeEvents(company);
    
    /* project */
    if ( company -> _isDoingProject )
    {
        doProject(company);
    }
}


void gameLoop(Company * company)
{
    /*main loop*/
    while (true)
    {
        updateCompany(company);
        updateDisplay(company);
        /* sleep */
        int counter = 0;
        for (counter = 0; counter < 50; ++ counter)
        {
            
            usleep(10000);
        }
    }
}

int main(int argc, char *argv[]) {
    /* init curses */
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    refresh();
    
    /* 
    
    /* init random */
    srand((unsigned)time(NULL));
    
    /* init company */
    Company * company = createCompany();
    refreshGlobalDisplay(company);
    DisplayWins * menu = createDisplayWins();
    gameLoop(company);
    
    
    endwin();
    return 0;
}
