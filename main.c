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


void gameLoop(Company * company, BOOL isPause)
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
            while(isPause);
            usleep(10000);
        }
    }
}

typedef struct InputThreadArgs
{
    Company * _company;
    BOOL * _isPause;
    DisplayWins * _disWin;
}InputThreadArgs;

InputThreadArgs * createInputThreadArgs(Company * company, BOOL * b, DisplayWins * disWin)
{
    InputThreadArgs * args = ( InputThreadArgs * )malloc( sizeof (InputThreadArgs) );
    args -> _company = company;
    args -> _isPause = b;
    args -> _disWin = disWin;
    return args;
}

void pauseGame(BOOL * pIsPause)
{
    (*pIsPause) = TRUE;
}

void resumeGame(BOOL * pIsPause)
{
    (*pIsPause) = FALSE;
}

void processMenu(DisplayWins * menu, char ** menuState, const Company * company)
{
    char nowInput;
    int choosedPlatform = -1;
    while (nowInput = getch())
    {
        mvprintw(21,20,"nowInput: got ch %c",nowInput);
        if ( (* menuState) == "main" )
        {
            /*projects*/
            switch (nowInput)
            {
                case 'p' :
                {
                    clearMainWin(menu);
                    printProjectMenu(menu);
                    (* menuState) = "main_pj";
                    break;
                }
                /*stuff*/
                case 's' :
                {
                    clearMainWin(menu);
                    printStuffMenu(menu);
                    (* menuState) = "main_stuff";
                    break;
                }
                /*action*/
                case 'a' :
                {
                    clearMainWin(menu);
                    printActionMenu(menu);
                    (* menuState) = "main_action";
                    break;
                }
                /*info*/
                case 'i' :
                {
                    break;
                }
                /*system*/
                case 'y' :
                {
                    break;
                    
                }
                /*none sense*/
                default :
                {
                    break;
                }
            }
        }
        if ( (* menuState) == "main_pj" )
        {
            /* new game */
            switch(nowInput)
            {
                case 'n' :
                {
                    (* menuState) = "main_pj_platform";
                    clearMainWin(menu);
                    printPlatformMenu(menu);
                    break;
                }
                /*contract*/
                case 'c' :
                {
                    (* menuState) = "main_pj_contract";
                    clearMainWin(menu);
                    break;
                }
                /*back*/
                case 'b' :
                {
                    (* menuState) = "main";
                    clearMainWin(menu);
                    printMainMenu(menu);
                    break;
                }
            }
        }
        if ( (* menuState) == "main_stuff" )
        {
            /*hire*/
            switch(nowInput)
            {
                case 'h' :
                {
                    (* menuState) = "main_stuff_hire";
                    clearMainWin(menu);
                    break;
                }
                case 'f' :
                {
                    (* menuState) = "main_stuff_fire";
                    clearMainWin(menu);
                    break;
                }
                case 'b' :
                {
                    (* menuState) = "main";
                    clearMainWin(menu);
                    printMainMenu(menu);
                    break;
                }
            }
        }
        if ( (* menuState) == "sub_action" )
        {}
        if ( (* menuState) == "main_pj_platform" )
        {
            choosedPlatform = 
        }
    }
}

void inputThread(InputThreadArgs * args)
{
    /* when input firstCh, stop game, until exit menu or call any function */
    char firstCh;
    while(firstCh = getch())
    {
        mvprintw(20,20,"firstch: got ch %c",firstCh);
        pauseGame(args->_isPause);
        
        /* print main menu if any input */
        printMainMenu(args -> _disWin);
        char * menuState = "main";
        /* menu interface
         * need to know company info
         * and call specific function in it
        */
        processMenu(args->_disWin, &menuState, args -> _company);
        
        resumeGame(args->_isPause);
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
    
    
    /* init random */
    srand((unsigned)time(NULL));
    
    /* init company */
    Company * company = createCompany();
    refreshGlobalDisplay(company);
    DisplayWins * menu = createDisplayWins();
    
    /* init vars */
    BOOL isPause = FALSE;
    InputThreadArgs * iTArgs = createInputThreadArgs(company,&isPause, menu);
    
    /* input thread */
    pthread_t tid;
    pthread_create(&tid,NULL, (void*)inputThread, (void *)iTArgs);
    
    /* main loop */
    gameLoop(company, isPause);
    
    
    pthread_join(tid,NULL);
    endwin();
    return 0;
}
