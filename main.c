#include <stdio.h>
#include "structs.h"
#include "structs.c"
#include "display.h"
#include <unistd.h>
#include <time.h>
#include <pthread.h>


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
    gameLoop(menu,company, &isPause);
    
    
    pthread_join(tid,NULL);
    endwin();
    return 0;
}
