#include <stdio.h>
#include "simpleStruct.h"
#include "display.h"
#include "gameLoop.h"

int main(int argc, char **argv) {
    //Company * company = createCompany();
    DisplayInformation * disInfo = createDisplayInformation();
    initDisplay(disInfo);
    gameLoop();
    
    
    endwin();
    return 0;
}
