#ifndef _gameLoop_H
#define _gameLoop_H

#include "simpleStruct.h"
#include <unistd.h>
#include "display.h"

void gameLoop()
{
    while (true)
    {
        update();
        sleep(1);
    }
}

#endif