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
    pCompany -> _isSellingGame = FALSE;
    /* first stuff */
    pCompany -> _numStuff = 1;
    pCompany -> _stuffs[0] = createStuff(getRandomName(),1, getRandomProperty(avarage));
    return pCompany;
}
void checkTimeEvents(Company * company)
{
    
}

/* in-loop func
 * just do the pj, ingnore process
 */
void doProject(Company * company)
{
    Project * nowPj = company -> _nowProject;
    /* increase property */
    for ( int i = 0; i < company -> _numStuff; ++ i )
    {
        Property sP = company -> _stuffs[i] -> _property;
        nowPj -> _property . _intrest += ( (rand() % sP._writing) ) / (float)GAMETIME + 2;
        nowPj -> _property . _uniquation += ( (rand() % sP._coding) ) / (float)GAMETIME + 2;
        nowPj -> _property . _eyes += ( (rand() % sP._drawing) ) / (float)GAMETIME + 2;
        nowPj -> _property . _musics +=( (rand() % sP._music) ) / (float)GAMETIME + 2;
    }
    /* if is game */
    if ( nowPj -> _isGame)
    {
        /* add process */
        nowPj -> _process += 1.0 / GAMETIME;
        /* add bug */
        int tmpNumBugs = rand() % 1 - 5;
        if ( tmpNumBugs > 0 )
        {
            nowPj -> _numBugs += 1;
        }
    }
}

void sellGame(Company * company)
{
	increasemoney(company);
	company->_sellDay = company->_sellDay - 1;
	if ( company->_sellDay == 0)
		company -> _isSellingGame = FALSE;
}

int fansNum(Ad * ad)
{
	for ( int i = 0; i < LENADLIST; ++ i )
	{
		if ( adList[i]._name == ad -> _name )
			return ( adList[i]._deltaFans );
	}
}

int moneyAd(Ad * ad)
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
	int x,y,z,sum,max,min,fansNum;
	x = moneyAd( Company -> Project ->  _money );
	y = moneyTheme( Company -> Project ->  _themeName );
	z = moneyType( Company -> Project ->  _typeName );
	max = max(Propertytwo);
	min = min(Propertytwo);
	fans = fansNum( Company -> Project ->  _deltaFans );
	sum = x + y + z;
	if(0<=sum<850)
	{
		if(0<=max<30&&0<=fans<100)
		{
			if(max - min >10)
			{
				if(fans > 70)
				    money+= rand()%118+82;
			    else
				    money+= rand()%96+64;
			}
			else
			{
				if(fans > 66)
					money+= rand()%120+84;
				else
					money+= rand()%98+66;
			}
		}
		if(30<=max<60&&100<=fans<200)
		{
			if(max - min >15)
			{
				if(fans >160)
					money+= rand()%260+340;
			    else
					money+= rand()%225+315;
			}
			else
			{
				if(fans >150)
					money+= rand()%265+345;
			    else
					money+= rand()%240+330;
			}
		}
		if(60<=max<100&&200<=fans<300)
		{
			if(max - min >20)
			{
				if(fans >265)
					money+= rand()%420+520;
			    else
					money+= rand()%380+400;
			}
			else
			{
				if(fans >240)
					money+= rand()%425+526;
			    else
					money+= rand()%385+407;
			}
		}
	}
	else if(850<=sum<1050)
			{
		if(0<=max<30&&0<=fans<100)
		{
			if(max - min >10)
			{
				if(fans > 70)
				    money+= rand()%129+93;
			    else
				    money+= rand()%108+75;
			}
			else
			{
				if(fans > 66)
					money+= rand()%131+95;
				else
					money+= rand()%109+77;
			}
		}
		if(30<=max<60&&100<=fans<200)
		{
			if(max - min >15)
			{
				if(fans >160)
					money+= rand()%282+362;
			    else
					money+= rand()%247+337;
			}
			else
			{
				if(fans >150)
					money+= rand()%287+355;
			    else
					money+= rand()%262+330;
			}
		}
		if(60<=max<100&&200<=fans<300)
		{
			if(max - min >20)
			{
				if(fans >265)
					money+= rand()%442+542;
			    else
					money+= rand()%400+421;
			}
			else
			{
				if(fans >240)
					money+= rand()%447+548;
			    else
					money+= rand()%405+431;
			}
		}
	}
	else if(1050<=sum<1350)
	{
		if(0<=max<30&&0<=fans<100)
		{
			if(max - min >12)
			{
				if(fans > 70)
				    money+= rand()%154+118;
			    else
				    money+= rand()%133+100;
			}
			else
			{
				if(fans > 66)
					money+= rand()%156+120;
				else
					money+= rand()%134+102;
			}
		}
		if(30<=max<60&&100<=fans<200)
		{
			if(max - min >15)
			{
				if(fans >160)
					money+= rand()%307+387;
			    else
					money+= rand()%272+362;
			}
			else
			{
				if(fans >150)
					money+= rand()%302+380;
			    else
					money+= rand()%287+355;
			}
		}
		if(60<=max<100&&200<=fans<300)
		{
			if(max - min >20)
			{
				if(fans >265)
					money+= rand()%467+567;
			    else
					money+= rand()%425+446;
			}
			else
			{
				if(fans >240)
					money+= rand()%472+573;
			    else
					money+= rand()%430+456;
			}
		}
	}
	else if(1350<=sum<1750)
	{
		if(0<=max<30&&0<=fans<100)
		{
			if(max - min >12)
			{
				if(fans > 70)
				    money+= rand()%204+168;
			    else
				    money+= rand()%182+150;
			}
			else
			{
				if(fans > 66)
					money+= rand()%206+170;
				else
					money+= rand()%184+152;
			}
		}
		if(30<=max<60&&100<=fans<200)
		{
			if(max - min >15)
			{
				if(fans >160)
					money+= rand()%357+437;
			    else
					money+= rand()%322+412;
			}
			else
			{
				if(fans >150)
					money+= rand()%352+420;
			    else
					money+= rand()%337+405;
			}
		}
		if(60<=max<100&&200<=fans<300)
		{
			if(max - min >20)
			{
				if(fans >265)
					money+= rand()%517+617;
			    else
					money+= rand()%475+496;
			}
			else
			{
				if(fans >240)
					money+= rand()%522+623;
			    else
					money+= rand()%480+506;
			}
		}
	}
	else if(1750<=sum<2000)
	{
		if(0<=max<30&&0<=fans<100)
		{
			if(max - min >12)
			{
				if(fans > 70)
				    money+= rand()%304+268;
			    else
				    money+= rand()%282+250;
			}
			else
			{
				if(fans > 66)
					money+= rand()%306+270;
				else
					money+= rand()%284+252;
			}
		}
		if(30<=max<60&&100<=fans<200)
		{
			if(max - min >15)
			{
				if(fans >160)
					money+= rand()%457+537;
			    else
					money+= rand()%422+512;
			}
			else
			{
				if(fans >150)
					money+= rand()%452+520;
			    else
					money+= rand()%437+505;
			}
		}
		if(60<=max<100&&200<=fans<300)
		{
			if(max - min >20)
			{
				if(fans >265)
					money+= rand()%617+717;
			    else
					money+= rand()%575+596;
			}
			else
			{
				if(fans >240)
					money+= rand()%622+523;
			    else
					money+= rand()%580+606;
			}
		}
	}
	else if(sum>=2000)
	{
		if(0<=max<30&&0<=fans<100)
		{
			if(max - min >12)
			{
				if(fans > 70)
				    money+= rand()%304+268;
			    else
				    money+= rand()%282+250;
			}
			else
			{
				if(fans > 66)
					money+= rand()%306+270;
				else
					money+= rand()%284+252;
			}
		}
		if(30<=max<60&&100<=fans<200)
		{
			if(max - min >15)
			{
				if(fans >160)
					money+= rand()%457+537;
			    else
					money+= rand()%422+512;
			}
			else
			{
				if(fans >150)
					money+= rand()%452+520;
			    else
					money+= rand()%437+505;
			}
		}
		if(60<=max<100&&200<=fans<300)
		{
			if(max - min >20)
			{
				if(fans >265)
					money+= rand()%617+717;
			    else
					money+= rand()%575+596;
			}
			else
			{
				if(fans >240)
					money+= rand()%622+723;
			    else
					money+= rand()%580+606;
			}
		}
	}
}
					

/* create a game project
 * paras, all are char *,
 */
Project * createGameProject(char * name, char * platform, char * theme, char * type)
{
    Project * pj = (Project *) malloc ( sizeof ( Project ) );
    pj ->_platform = platform;
    pj -> _gametheme = theme;
    pj -> _gametype = type;
    pj -> _name = name;
    
    pj -> _numBugs = 0;
    pj -> _process = 0;
    pj -> _selledCopies = 0;
    
    pj -> _isGame = TRUE;
    
    /* game has no reward nor timelimit */
    pj -> _reward = -1;
    
    return pj;
}

void finishGame(DisplayWins * disWin,Company * company)
{
    company -> _isDoingProject = FALSE;
    company -> _gameHistory[company -> _lenGameHistory] = company -> _nowProject;
	++ company -> _lenGameHistory;
    company -> _nowProject = NULL;
    company -> _isSellingGame = TRUE;
    printInfo(disWin,"you have finished your new game, it'll be selling now");
}


void finishContract(DisplayWins * disWin,Company *  company)
{
    company -> _isDoingProject = FALSE;
    company -> _money += company -> _nowProject -> _reward;
    /* free memory */
    free(company -> _nowProject);
    company -> _nowProject = NULL;
    printInfo(disWin,"you have finished a contract, reward have added to your company");
}

void updateCompany(DisplayWins * disWin,Company * company)
{
    /* update timer */
    addDay(company -> _timer);
    checkTimeEvents(company);
    
    /* project */
    if ( company -> _isDoingProject )
    {
        doProject(company);
        if ( company -> _nowProject ->_process >= 100 )
        {
            if ( company -> _nowProject -> _isGame)
                finishGame(disWin,company);
            else
                finishContract(disWin,company);
        }
    }
    /* sale */
    if ( company -> _isSellingGame)
    {
        sellGame(company);
    }
}


void gameLoop(DisplayWins * disWin,Company * company, BOOL  * isPause)
{
    /*main loop*/
    while (TRUE)
    {
        updateCompany(disWin,company);
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
        company -> _nowProject = createGameProject("gameName",indexPlatform, indexTheme, indexType);
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
Project * createRandomContractProject()
{
   Project * p = ( Project * ) malloc ( sizeof ( Project ) );
   p -> project ->_name = 'A' + rand()%26;
   p -> project ->_money = rand()%1000+1000;
   p -> project ->_reward = rand()%1000+2000;
}

void startContract(DisplayWins * menu, Company * company, Project * project)
{
    
}

Stuff * createRandomStuff(int indexWay)/*Stuff * createStuff(char * name, int salery, Property property)*/
{
	char * name = 'a'+rand()%26;
	int salery = wayFindList[indexWay]._money + rand()%100+10;
    int average = salery/40;
	Property property = { rand()%7+(average-2), rand()%8+(average-2),rand()%5+(average-2) ,rand()%5+(average-2); };
    return createStuff(name, salery, property);
}

void hire(DisplayWins * menu, Company * company, Stuff * stuff)
{
    
}

void train(DisplayWins * menu, Stuff * stuff)
{
    
}

void fire(DisplayWins * menu, Company * company, int indexStuff)
{
    
}

void useAd(DisplayWins * menu, Company * company, int indexAd)
{
    
}

/* if money is enough, decrease money, and return true;
 * else return false
 */
BOOL makeAFind(Company * company, int indexWay)
{
    
}

void processMenu(DisplayWins * menu, char ** menuState, const Company * company)
{
    char nowInput;
    int indexPlatform = -1;
    int indexTheme = -1;
    /*used to save generated contracts*/
    Project * contractList[NUMCONTRACTCHOOSE];
    /*used to save generated stuff*/
    Stuff * stuffList[NUMSTUFFCHOOSE];
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
                    /* generate contracts */
                    for ( int i = 0; i < NUMCONTRACTCHOOSE; ++ i)
                    {
                        contractList[i] = createRandomContractProject();
                    }
                    printChooseContractMenu(menu,contractList,NUMCONTRACTCHOOSE);
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
                    printWayToFindMenu(menu);
                    break;
                }
                case 'f' :
                {
                    (* menuState) = "main_stuff_fire";
                    clearMainMenu(menu);
                    printChooseStuffFireMenu(menu,company);
                    break;
                }
                case 't' :
                {
                    (* menuState) = "main_stuff_train";
                    clearMainMenu(menu);
                    printChooseStuffTrainMenu(menu,company);
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
        {
            switch(nowInput)
            {
                case 'a' :
                {
                    (* menuState) = "sub_action_ad";
                    clearMainMenu(menu);
                    printAdMenu(menu);
                }
                default: 
                    break;
            }
        }
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
                clearMainMenu(menu);
                /* call func: start a new game */
                startNewGame(menu,company, indexPlatform, indexTheme, tmpIndex);
                return;
            }
            else
                continue;
        }
        else if ( (* menuState) == "main_pj_contract" ) 
        {
            if ( nowInput == 'b' )
            {
                (* menuState) = "main_pj";
                clearMainMenu(menu);
                printProjectMenu(menu);
                continue;
            }
            int tmpIndex = nowInput - '0' - 1;
            if ( 0 <= tmpIndex && tmpIndex < NUMCONTRACTCHOOSE)
            {
                (* menuState) = "exit";
                clearMainMenu(menu);
                /* call func: start a contract*/
                startContract(menu,company,contractList[tmpIndex]);
                return;
            }
            else
                continue;
        }
        else if ( (* menuState) == "main_stuff_hire" ) 
        {
            if ( nowInput == 'b' )
            {
                (* menuState) = "main_stuff";
                clearMainMenu(menu);
                printProjectMenu(menu);
                continue;
            }
            int wayIndex = nowInput - '0' - 1;
            /* decrease money */
            if ( makeAFind(company,wayIndex) )
            {
                (* menuState) = "main_stuff_hire_way";
                /* generate stuff for choosing */
                for (int i = 0; i < NUMSTUFFCHOOSE; ++ i)
                {
                    stuffList[i] = createRandomStuff(wayIndex);
                }
            }
            else
            {
                printInfo(menu,"you don't have enough money for that !");
            }
        }
        else if ( (* menuState) == "main_stuff_hire_way" ) 
        {
            int newStuffIndex = nowInput - '0' - 1;
            hire(menu,company,stuffList[newStuffIndex]);
        }
        else if ( (* menuState) == "main_stuff_fire" ) 
        {
            int fireStuffIndex = nowInput - '0' - 1;
            fire(menu,company,fireStuffIndex);
        }
        else if ( (* menuState) == "main_stuff_train" ) 
        {
            int trainStuffIndex = nowInput - '0' - 1;
            train(menu,company -> _stuffs[trainStuffIndex]);
        }
        else if ( (* menuState) == "sub_action_ad" ) 
        {
            int indexAd= nowInput - '0' - 1;
            useAd(menu,company,indexAd);
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