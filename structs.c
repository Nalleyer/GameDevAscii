#ifndef _STRUCTS_C
#define _STRUCTS_C
#include "structs.h"
#include "globalVars.h"
#include "display.h"
    
char * getRandomName()
{
    char * name[3];
    name[0] = (char)(rand() % 26 + (int)'a');
    name[1] = (char)(rand() % 26 + (int)'a');
    name[2] = (char)(rand() % 9 + (int)'0');
    return name;
}


void setTimer(Timer * pTimer, int year, int month, int week, int day)
{
    pTimer -> _year = year;
    pTimer -> _month = month;
    pTimer -> _week = week;
    pTimer -> _day = day;
}

Timer * createTimer()
{
    Timer * pTimer = (Timer *) malloc( sizeof( Timer ) );
    pTimer -> _year = 0;
    pTimer -> _month = 0;
    pTimer -> _week = 0;
    pTimer -> _day = 0;
    return pTimer;
}

void addDay(Timer * timer)
{
    ++ timer -> _day;
    if ( timer -> _day == 7 )
    {
        ++ timer -> _week;
        timer -> _day = 0;
        if ( timer -> _week == 4 )
        {
            ++ timer -> _month;
            timer -> _week = 0;
            if ( timer -> _month == 12 )
            {
                timer -> _month = 0;
                ++ timer -> _year;
            }
        }
    }
}

Stuff * createStuff(char * name, int salery, Property property)
{
    Stuff * pStuff = (Stuff *) malloc( sizeof( Stuff ) );
    pStuff -> _name = name;
    pStuff -> _salery = salery;
    pStuff ->_property = property;
    return pStuff;
}


Company * createCompany()
{
    Company * pCompany = (Company *) malloc( sizeof( Company ) );
    pCompany -> _isDoingProject = FALSE;
    pCompany -> _timer = createTimer();
    pCompany -> _money = INITMONEY;
    pCompany -> _numResearch = 0;
    pCompany -> _fans = 0;
    pCompany -> _lenGameHistory = 0;
    /* first stuff */
    pCompany -> _numStuff = 1;
    pCompany -> _stuffs[0] = createStuff(getRandomName(),1, getRandomProperty(avarage));
    return pCompany;
}
void checkTimeEvents(Company * company)
{
    
}

/* in-loop func
 */
void doProject(Company * company)
{
}

int fansNum(Ad * ad)
{
	for ( int i = 0; i < LENADLIST; ++ i )
	{
		if ( adList[i]._name == ad -> _name )
			return ( adList[i]._deltaFans );
	}
}

int moneyNum(Ad * ad)
{
	for ( int j = 0;j < LENADLIST; ++ j )
	{
		if ( adList[j]._money == ad ->  _money )
			return ( adList[j]._money );
	}
}

void max(Propertytwo * pt)
{
	int a = pt -> _intrest;
		if(pt -> _uniquation >= a)
		{
			a = pt -> _uniquation;
		    if(pt -> _musics >= a)
			{
				a = pt -> _musics;
			    if(pt -> _eyes >= a)
				{
					a = pt -> _eyes;
				}
			}
		}
		return a;
}

void min(Propertytwo * pt)
{
	int b = pt -> _intrest;
		if(pt -> _uniquation <= b)
		{
			b = pt -> _uniquation;
		    if(pt -> _musics <= b)
			{
				b = pt -> _musics;
			    if(pt -> _eyes <= b)
				{
					b = pt -> _eyes;
				}
			}
		}
		return b;
}

int moneyTheme(GameTheme * theme)
{
	for ( int i = 0; i < LENTHEMELIST; ++ i )
	{
		if ( themeList[i]._themeName == theme -> _themeName )
			return ( themeList[i]._money);
	}
}

int moneyType(GameType * type)
{
	for ( int j = 0; j < LENTYPELIST; ++ j )
	{
		if ( typeList[j]._typeName == type -> _typeName )
			return ( typeList[j]._money);
	}
}

void increasemoney ( Company * company)
{
	int x,y,z;
	x = moneyNum(company -> _nowAd);
	y = moneyTheme(company -> _nowProject -> _gametheme);
	z = moneyType(company -> _nowProject -> _gametype);
}

/* create a project
 * paras, all are char *,
 */
Project * createProject(char * name, char * platform, char * theme, char * type, int timeLimit)
{
    Project * pj = (Project *) malloc ( sizeof ( Project ) );
    pj ->_platform = platform;
    pj -> _gametheme = theme;
    pj -> _gametype = type;
    pj -> _name = name;
    
    pj -> _numBugs = 0;
    pj -> _process = 0;
    pj -> _selledCopies = 0;
    
    return pj;
}

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


void gameLoop(Company * company, BOOL  * isPause)
{
    /*main loop*/
    while (TRUE)
    {
        updateCompany(company);
        updateDisplay(company);
        /* sleep */
        int counter = 0;
        for (counter = 0; counter < 50; ++ counter)
        {
            while(* isPause);
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

/* ch: '0' ~ '9'
 * */
int char2int(char ch)
{
    return (int)(ch - '0');
}

int getGameMoney(int indexPlatform, int indexTheme, int indexType)
{
    return platformlist[indexPlatform]._money + themeList[indexTheme]._money + typeList[indexType]._money;
}

void startNewGame(DisplayWins * disWin,Company * company, int indexPlatform, int indexTheme, int indexType)
{
    /* whether money if enough ? */
    int money = getGameMoney(indexPlatform,indexTheme,indexType);
    if ( money <= (company -> _money) )
    /* enough, make it */
    {
        company -> _nowProject = createProject("gameName",indexPlatform, indexTheme, indexType, -1);
        company -> _isDoingProject = true;
        /* decrease money */
        company -> _money -= money;
        printInfo(disWin,"staring making new game");
    }
    else
    {
        printInfo(disWin,"you don't have enough money");
    }
    /* not enough, do nothing */
}

/* create a random project for choosing */
Project * createRandomProject()
{
    
}

void startContract(DisplayWins * menu, Company * company, Project * project)
{
    
}

Stuff * createRandomStuff()
{
    
}

void hire(DisplayWins * menu, Company * company, Stuff * stuff)
{
    
}

void train(DisplayWins * menu, Stuff * stuff)
{
    
}

void fire(DisplayWins * menu, Company * company, Stuff * sutff)
{
    
}

void useAd(DisplayWins * menu, Company * company, int indexAd)
{
    
}

void processMenu(DisplayWins * menu, char ** menuState, const Company * company)
{
    char nowInput;
    int indexPlatform = -1;
    int indexTheme = -1;
    int indexType = -1;
    while (nowInput = getch())
    {
        /* esc ignore state */
        if ( nowInput == 27 )
        {
            return;
        }
        mvprintw(21,20,"nowInput: got ch %c",nowInput);
        if ( (* menuState) == "main" )
        {
            switch (nowInput)
            {
                /*projects*/
                case 'p' :
                {
                    clearMainMenu(menu);
                    printProjectMenu(menu);
                    (* menuState) = "main_pj";
                    break;
                }
                /*stuff*/
                case 's' :
                {
                    clearMainMenu(menu);
                    printStuffMenu(menu);
                    (* menuState) = "main_stuff";
                    break;
                }
                /*action*/
                case 'a' :
                {
                    clearMainMenu(menu);
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
                case 'e' :
                {
                    clearMainMenu(menu);
                    (* menuState) = "exit";
                    return;
                }
                /*none sense*/
                default :
                {
                    break;
                }
            }
        }
        else if ( (* menuState) == "main_pj" )
        {
            /* new game */
            switch(nowInput)
            {
                case 'n' :
                {
                    (* menuState) = "main_pj_platform";
                    clearMainMenu(menu);
                    printPlatformMenu(menu);
                    break;
                }
                /*contract*/
                case 'c' :
                {
                    (* menuState) = "main_pj_contract";
                    clearMainMenu(menu);
                    break;
                }
                /*back*/
                case 'b' :
                {
                    (* menuState) = "main";
                    clearMainMenu(menu);
                    printMainMenu(menu);
                    break;
                }
                default:
                    break;
            }
        }
        else if ( (* menuState) == "main_stuff" )
        {
            /*hire*/
            switch(nowInput)
            {
                case 'h' :
                {
                    (* menuState) = "main_stuff_hire";
                    clearMainMenu(menu);
                    break;
                }
                case 'f' :
                {
                    (* menuState) = "main_stuff_fire";
                    clearMainMenu(menu);
                    break;
                }
                case 'b' :
                {
                    (* menuState) = "main";
                    clearMainMenu(menu);
                    printMainMenu(menu);
                    break;
                }
                default:
                    break;
            }
        }
        else if ( (* menuState) == "sub_action" )
        {}
        else if ( (* menuState) == "main_pj_platform" )
        {
            if ( nowInput == 'b' )
            {
                (* menuState) = "main_pj";
                clearMainMenu(menu);
                printProjectMenu(menu);
                continue;
            }
            int tmpIndex = nowInput - '0' - 1;
            if ( 0 <= tmpIndex && tmpIndex < LENPLATFORMLIST)
            {
                (* menuState) = "main_pj_platform_theme";
                indexPlatform = tmpIndex;
                clearMainMenu(menu);
                printThemeMenu(menu);
            }
            else
                continue;
        }
        else if ( (* menuState) == "main_pj_platform_theme" )
        {
            if ( nowInput == 'b' )
            {
                (* menuState) = "main_pj_platform";
                clearMainMenu(menu);
                printPlatformMenu(menu);
                continue;
            }
            int tmpIndex = nowInput - '0' - 1;
            if ( 0 <= tmpIndex && tmpIndex < LENTHEMELIST)
            {
                (* menuState) = "main_pj_platform_theme_type";
                indexTheme = tmpIndex;
                clearMainMenu(menu);
                printTypeMenu(menu);
            }
            else
                continue;
        }
        else if ( (* menuState) == "main_pj_platform_theme_type" )
        {
            if ( nowInput == 'b' )
            {
                (* menuState) = "main_pj_platform_theme";
                clearMainMenu(menu);
                printThemeMenu(menu);
                continue;
            }
            int tmpIndex = nowInput - '0' - 1;
            if ( 0 <= tmpIndex && tmpIndex < LENTYPELIST)
            {
                (* menuState) = "exit";
                indexType= tmpIndex;
                clearMainMenu(menu);
                /* call func: start a new game */
                startNewGame(menu,company, indexPlatform, indexTheme, indexType);
                return;
            }
            else
                continue;
        }
        mvprintw(22,20,"state: %s",*menuState);
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

#endif