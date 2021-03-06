#ifndef _STRUCTS_C
#define _STRUCTS_C

#include "structs.h"
#include "globalVars.h"
#include "display.h"
#include <unistd.h>
    
char * getRandomName()
{
    char * name = (char *)malloc(3 * sizeof(char) );
    name[0] = (char)(rand() % 25 + (int)'a');
    name[1] = (char)(rand() % 25 + (int)'a');
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
    pCompany -> _nowAd = adList[0];
    Property tmpProperty = {10,10,10,10};
    pCompany -> _stuffs[0] = createStuff(getRandomName(),1, tmpProperty );
    return pCompany;
}

void checkTimeEvents(DisplayWins * disWin, Company * company)
{
    if ( company -> _timer -> _month == 4 && company -> _timer -> _week == 0 && company -> _timer -> _day == 0)
    {
        for ( int i = 0; i < company -> _numStuff; ++ i )
        {
            company -> _money -= company -> _stuffs[i] -> _salery;
        }
    }
}

void checkBreak(DisplayWins * disWin, Company * company)
{
    if ( company -> _money < 0 )
    {
        printInfo(disWin,"you have broken down! press any key to exit game.");
        getch();
        exit(0);
    }
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
	-- company->_sellDay ;
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

int max(const Propertytwo * pt)
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

int min(const Propertytwo * pt)
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

int moneyTheme(int indexTheme)
{
    return themeList[indexTheme]. _money;
}

int moneyType(int indexType)
{
    return typeList[indexType] . _money;
}

void increasemoney( Company * company)
{
    Project * sellingPj = company -> _gameHistory[company -> _lenGameHistory - 1];
	int x,y,z,sum,maxMoney,minMoney;
	x = company -> _nowAd . _money;
	y = moneyTheme( sellingPj -> _indexTheme );
	z = moneyType( sellingPj ->  _indexType );
	maxMoney = max(&(sellingPj -> _property));
	minMoney = min(&(sellingPj -> _property));
	int fans = company -> _fans;
	sum = x + y + z;
	if(0<=sum<850)
	{
		if(0<=maxMoney<30&&0<=fans<100)
		{
			if(maxMoney - minMoney >10)
			{
				if(fans > 70)
				    company -> _money += rand()%118+82;
			    else
				    company -> _money+= rand()%96+64;
			}
			else
			{
				if(fans > 66)
					company -> _money+= rand()%120+84;
				else
					company -> _money+= rand()%98+66;
			}
		}
		if(30<=maxMoney<60&&100<=fans<200)
		{
			if(maxMoney - minMoney >15)
			{
				if(fans >160)
					company -> _money+= rand()%260+340;
			    else
					company -> _money+= rand()%225+315;
			}
			else
			{
				if(fans >150)
					company -> _money+= rand()%265+345;
			    else
					company -> _money+= rand()%240+330;
			}
		}
		if(60<=maxMoney<100&&200<=fans<300)
		{
			if(maxMoney - minMoney >20)
			{
				if(fans >265)
					company -> _money+= rand()%420+520;
			    else
					company -> _money+= rand()%380+400;
			}
			else
			{
				if(fans >240)
					company -> _money+= rand()%425+526;
			    else
					company -> _money+= rand()%385+407;
			}
		}
	}
	else if(850<=sum<1050)
			{
		if(0<=maxMoney<30&&0<=fans<100)
		{
			if(maxMoney - minMoney >10)
			{
				if(fans > 70)
				    company -> _money+= rand()%129+93;
			    else
				    company -> _money+= rand()%108+75;
			}
			else
			{
				if(fans > 66)
					company -> _money+= rand()%131+95;
				else
					company -> _money+= rand()%109+77;
			}
		}
		if(30<=maxMoney<60&&100<=fans<200)
		{
			if(maxMoney - minMoney >15)
			{
				if(fans >160)
					company -> _money+= rand()%282+362;
			    else
					company -> _money+= rand()%247+337;
			}
			else
			{
				if(fans >150)
					company -> _money+= rand()%287+355;
			    else
					company -> _money+= rand()%262+330;
			}
		}
		if(60<=maxMoney<100&&200<=fans<300)
		{
			if(maxMoney - minMoney >20)
			{
				if(fans >265)
					company -> _money+= rand()%442+542;
			    else
					company -> _money+= rand()%400+421;
			}
			else
			{
				if(fans >240)
					company -> _money+= rand()%447+548;
			    else
					company -> _money+= rand()%405+431;
			}
		}
	}
	else if(1050<=sum<1350)
	{
		if(0<=maxMoney<30&&0<=fans<100)
		{
			if(maxMoney - minMoney >12)
			{
				if(fans > 70)
				    company -> _money+= rand()%154+118;
			    else
				    company -> _money+= rand()%133+100;
			}
			else
			{
				if(fans > 66)
					company -> _money+= rand()%156+120;
				else
					company -> _money+= rand()%134+102;
			}
		}
		if(30<=maxMoney<60&&100<=fans<200)
		{
			if(maxMoney - minMoney >15)
			{
				if(fans >160)
					company -> _money+= rand()%307+387;
			    else
					company -> _money+= rand()%272+362;
			}
			else
			{
				if(fans >150)
					company -> _money+= rand()%302+380;
			    else
					company -> _money+= rand()%287+355;
			}
		}
		if(60<=maxMoney<100&&200<=fans<300)
		{
			if(maxMoney - minMoney >20)
			{
				if(fans >265)
					company -> _money+= rand()%467+567;
			    else
					company -> _money+= rand()%425+446;
			}
			else
			{
				if(fans >240)
					company -> _money+= rand()%472+573;
			    else
					company -> _money+= rand()%430+456;
			}
		}
	}
	else if(1350<=sum<1750)
	{
		if(0<=maxMoney<30&&0<=fans<100)
		{
			if(maxMoney - minMoney >12)
			{
				if(fans > 70)
				    company -> _money+= rand()%204+168;
			    else
				    company -> _money+= rand()%182+150;
			}
			else
			{
				if(fans > 66)
					company -> _money+= rand()%206+170;
				else
					company -> _money+= rand()%184+152;
			}
		}
		if(30<=maxMoney<60&&100<=fans<200)
		{
			if(maxMoney - minMoney >15)
			{
				if(fans >160)
					company -> _money+= rand()%357+437;
			    else
					company -> _money+= rand()%322+412;
			}
			else
			{
				if(fans >150)
					company -> _money+= rand()%352+420;
			    else
					company -> _money+= rand()%337+405;
			}
		}
		if(60<=maxMoney<100&&200<=fans<300)
		{
			if(maxMoney - minMoney >20)
			{
				if(fans >265)
					company -> _money+= rand()%517+617;
			    else
					company -> _money+= rand()%475+496;
			}
			else
			{
				if(fans >240)
					company -> _money+= rand()%522+623;
			    else
					company -> _money+= rand()%480+506;
			}
		}
	}
	else if(1750<=sum<2000)
	{
		if(0<=maxMoney<30&&0<=fans<100)
		{
			if(maxMoney - minMoney >12)
			{
				if(fans > 70)
				    company -> _money+= rand()%304+268;
			    else
				    company -> _money+= rand()%282+250;
			}
			else
			{
				if(fans > 66)
					company -> _money+= rand()%306+270;
				else
					company -> _money+= rand()%284+252;
			}
		}
		if(30<=maxMoney<60&&100<=fans<200)
		{
			if(maxMoney - minMoney >15)
			{
				if(fans >160)
					company -> _money+= rand()%457+537;
			    else
					company -> _money+= rand()%422+512;
			}
			else
			{
				if(fans >150)
					company -> _money+= rand()%452+520;
			    else
					company -> _money+= rand()%437+505;
			}
		}
		if(60<=maxMoney<100&&200<=fans<300)
		{
			if(maxMoney - minMoney >20)
			{
				if(fans >265)
					company -> _money+= rand()%617+717;
			    else
					company -> _money+= rand()%575+596;
			}
			else
			{
				if(fans >240)
					company -> _money+= rand()%622+523;
			    else
					company -> _money+= rand()%580+606;
			}
		}
	}
	else if(sum>=2000)
	{
		if(0<=maxMoney<30&&0<=fans<100)
		{
			if(maxMoney - minMoney >12)
			{
				if(fans > 70)
				    company -> _money+= rand()%304+268;
			    else
				    company -> _money+= rand()%282+250;
			}
			else
			{
				if(fans > 66)
					company -> _money+= rand()%306+270;
				else
					company -> _money+= rand()%284+252;
			}
		}
		if(30<=maxMoney<60&&100<=fans<200)
		{
			if(maxMoney - minMoney >15)
			{
				if(fans >160)
					company -> _money+= rand()%457+537;
			    else
					company -> _money+= rand()%422+512;
			}
			else
			{
				if(fans >150)
					company -> _money+= rand()%452+520;
			    else
					company -> _money+= rand()%437+505;
			}
		}
		if(60<=maxMoney<100&&200<=fans<300)
		{
			if(maxMoney - minMoney >20)
			{
				if(fans >265)
					company -> _money+= rand()%617+717;
			    else
					company -> _money+= rand()%575+596;
			}
			else
			{
				if(fans >240)
					company -> _money+= rand()%622+723;
			    else
					company -> _money+= rand()%580+606;
			}
		}
	}
}
					

/* create a game project
 * paras, all are char *,
 */
Project * createGameProject(char * name, int indexPlatform, int indexTheme, int indexType)
{
    Project * pj = (Project *) malloc ( sizeof ( Project ) );
    pj -> _indexPlatform = indexPlatform;
    pj -> _indexTheme = indexTheme;
    pj -> _indexTheme = indexType;
    pj -> _name = name;
    
    pj -> _numBugs = 0;
    pj -> _process = 0;
    pj -> _selledCopies = 0;
    
    pj -> _process = 0;
    pj -> _isGame = TRUE;
    
    /* game has no reward nor timelimit */
    pj -> _reward = -1;
    pj -> _money = 0;
    
    return pj;
}

void finishGame(DisplayWins * disWin,Company * company)
{
    company -> _isDoingProject = FALSE;
    company -> _gameHistory[company -> _lenGameHistory] = company -> _nowProject;
	++ company -> _lenGameHistory;
    company -> _nowProject = NULL;
    company -> _isSellingGame = TRUE;
    /* reset time */
    company -> _sellDay = SELLDAY;
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


void debugGame(Company * company)
{
    int tmpNumBugs = rand() % 5;
    int * numBug = &(company -> _nowProject -> _numBugs);
    if ( *numBug > 0 )
    {
        *numBug -= tmpNumBugs;
        if ( *numBug < 0 )
            *numBug = 0;
    }
}

void updateCompany(DisplayWins * disWin,Company * company)
{
    /* update timer */
    addDay(company -> _timer);
    checkTimeEvents(disWin,company);
    
    /* stuff num */
    if ( company -> _numStuff <= 0 )
    {
        printInfo(disWin, "you have no stuff! game over!");
    }
    
    /* money */
    checkBreak(disWin,company);
    
    /* project */
    if ( company -> _isDoingProject )
    {
        doProject(company);
        if ( company -> _nowProject ->_process >= 1.0 )
        {
            if ( company -> _nowProject -> _isGame)
            {
                debugGame(company);
                if (company -> _nowProject ->_numBugs == 0)
                {
                    finishGame(disWin,company);
                }
            }
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
        for (counter = 0; counter < 500; ++ counter)
        {
            while(* isPause)
            {
            }
            //usleep(1000);
            usleep(10);
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
   Propertytwo tmpProperty = { rand() % 100, rand() % 100, rand() % 100, rand() % 100 };
   p -> _property = tmpProperty;
   p -> _name = getRandomName();
   p -> _money = rand()%1000+1000;
   p -> _reward = rand()%1000+1000 + p -> _money;
   return p;
}

void startContract(DisplayWins * menu, Company * company, Project * project)
{
    int cMoney = project -> _money;
    if ( company -> _money >= cMoney )
    {
        company -> _money -= cMoney;
        company -> _isDoingProject = TRUE;
        company -> _nowProject = project;
        printInfo(menu,"you have started a contract.");
    }
    else
    {
        printInfo(menu,"you don't have enough money.");
    }
}

Stuff * createRandomStuff(int indexWay)/*Stuff * createStuff(char * name, int salery, Property property)*/
{
	char * name = getRandomName();
	int salery = wayFindList[indexWay]._money + rand()%100+10;
    int average = salery/40;
	Property property = { rand()%7+(average-2), rand()%8+(average-2),rand()%5+(average-2) ,rand()%5+(average-2) };
    return createStuff(name, salery, property);
}

void hire(DisplayWins * menu, Company * company, Stuff * stuff)
{
    company -> _stuffs[company -> _numStuff] = stuff;
    ++ company -> _numStuff;
    printInfo(menu,"you have hired a new stuff~");
}

/* check money */
void train(DisplayWins * menu, Company * company ,Stuff * stuff, int indexTrainWay)
{
    if ( company -> _money >= wayTrainList[indexTrainWay]._money)
    /* enough money */
    {
        company -> _money -= wayTrainList[indexTrainWay]._money;
        /* train */
        Property * p = &(stuff -> _property);
        Property deltaP = wayTrainList[indexTrainWay]._property;
        p -> _coding += deltaP._coding;
        p -> _drawing += deltaP._drawing;
        p -> _music += deltaP._music;
        p -> _writing += deltaP._writing;
    }
    else
    {
        printInfo(menu,"you don't have enough money.");
    }
}

void fire(DisplayWins * menu, Company * company, int indexStuff)
{
    free(company -> _stuffs[indexStuff]);
    for (int i = indexStuff; i < company -> _numStuff; ++ i)
    {
        company -> _stuffs[i] = company -> _stuffs[i + 1];
    }
    -- company -> _numStuff;
    printInfo(menu,"you have fired a stuff.");
}

void useAd(DisplayWins * menu, Company * company, int indexAd)
{
    if ( company -> _money > adList[indexAd]._money )
    {
        company -> _money -= adList[indexAd]._money ; 
        company -> _fans += adList[indexAd]._deltaFans;
        printInfo(menu,"you have used an ad, your fans have increased.");
    }
    else
    {
        printInfo(menu,"you don't have enough money.");
    }
}

/* if money is enough, decrease money, and return true;
 * else return false
 */
BOOL makeAFind(Company * company, int indexWay)
{
    if ( company -> _money >= wayFindList[indexWay] . _money )
    {
        company -> _money -= wayFindList[indexWay] . _money;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void freeOtherContracts(Project ** contractList,int tmpIndex)
{
    for ( int i = 0; i < NUMCONTRACTCHOOSE; ++ i )
    {
        Project * toFreePj = contractList[i];
        if ( i != tmpIndex )
        {
            free(toFreePj);
        }
    }
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
    
    int stuffToTrainIndex = -1;
    while (nowInput = getch())
    {
        /* esc ignore state */
        if ( nowInput == 27 )
        {
            clearMainMenu(menu);
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
        else if ( (* menuState) == "main_action" )
        {
            switch(nowInput)
            {
                case 'a' :
                {
                    (* menuState) = "main_action_ad";
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
                freeOtherContracts(&contractList,tmpIndex);
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
                printStuffMenu(menu);
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
                clearMainMenu(menu);
                printChooseStuffHireMenu(menu,&stuffList);
            }
            else
            {
                printInfo(menu,"you don't have enough money for that !");
            }
        }
        else if ( (* menuState) == "main_stuff_hire_way" ) 
        {
            if ( nowInput == 'b' )
            {
                (* menuState) = "main_stuff_hire";
                clearMainMenu(menu);
                printWayToFindMenu(menu);
                continue;
            }
            int newStuffIndex = nowInput - '0' - 1;
            if ( newStuffIndex >= 0 && newStuffIndex < NUMSTUFFCHOOSE )
            {
                clearMainMenu(menu);
                hire(menu,company,stuffList[newStuffIndex]);
                return;
            }
        }
        else if ( (* menuState) == "main_stuff_fire" ) 
        {
            if ( nowInput == 'b' )
            {
                (* menuState) = "main_stuff";
                clearMainMenu(menu);
                printStuffMenu(menu);
                continue;
            }
            int fireStuffIndex = nowInput - '0' - 1;
            if ( fireStuffIndex >= 0 && fireStuffIndex < company -> _numStuff )
            {
                (* menuState) = "exit";
                clearMainMenu(menu);
                fire(menu,company,fireStuffIndex);
                return;
            }
        }
        else if ( (* menuState) == "main_stuff_train" ) 
        {
             if ( nowInput == 'b' )
            {
                (* menuState) = "main_stuff";
                clearMainMenu(menu);
                printProjectMenu(menu);
                continue;
            }
            /* choose train way */
            stuffToTrainIndex = nowInput - '0' - 1;
            if ( stuffToTrainIndex > 0 && stuffToTrainIndex < company -> _numStuff )
            {
                (* menuState) = "main_stuff_train_stuff";
                printTrainWayMenu(menu);
            }
        }
        else if ( (* menuState) == "main_action_ad" ) 
        {
            if ( nowInput == 'b' )
            {
                (* menuState) = "main_action";
                clearMainMenu(menu);
                printActionMenu(menu);
                continue;
            }
            int indexAd= nowInput - '0' - 1;
            if (indexAd > 0 && indexAd < LENADLIST)
            {
                /* check money inside */
                (* menuState) = "exit";
                clearMainMenu(menu);
                useAd(menu,company,indexAd);
            }
        }
        else if ( (* menuState) == "main_stuff_train_stuff" ) 
        {
             if ( nowInput == 'b' )
            {
                (* menuState) = "main_stuff_train";
                clearMainMenu(menu);
                printChooseStuffTrainMenu(menu, company);
                continue;
            }
            int tmpIndex = nowInput - '0' - 1;
            /* choose train way */
            if ( tmpIndex > 0 && tmpIndex < LENWAYTRAINLIST )
            {
                (* menuState) = "exit";
                /* check money in func*/
                clearMainMenu(menu);
                train(menu,company,company -> _stuffs[stuffToTrainIndex],tmpIndex);
                return;
            }
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