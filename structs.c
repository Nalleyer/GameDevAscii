#ifndef _STRUCTS_C
#define _STRUCTS_C
#include "structs.h"
#include "globalVars.h"
    
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
    /* first stuff */
    pCompany -> _numStuff = 1;
    pCompany -> _numResearch = 0;
    pCompany -> _stuffs[0] = createStuff(getRandomName(),1, getRandomProperty(avarage));
    pCompany -> _fans = 0;
    pCompany -> _lenGameHistory = 0;
    return pCompany;
}
void checkTimeEvents(Company * company)
{
    
}

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

int moneyAd(Ad * ad)
{
	for ( int j = 0;j < LENADLIST; ++ j )
	{
		if ( adList[j]._money == ad ->  -money )
			return ( adList[i]._money );
	}
}

void max(Propertytwo)
{
	int a = Propertytwo._intrest;
		if(Propertytwo._uniquation >= a)
		{
			a=Propertytwo._uniquation;
		    if(Propertytwo._musics >= a)
			{
	
				a=Propertytwo._musics;
			    if(Propertytwo._eyes >= a)
				{
					a=Propertytwo._eyes;
				}
			}
		}
		return a;
}

void min(Propertytwo)
{
	int b = Propertytwo._intrest;
		if(Propertytwo._uniquation <= b)
		{
			b=Propertytwo._uniquation;
		    if(Propertytwo._musics <= b)
			{
				b=Propertytwo._musics;
			    if(Propertytwo._eyes <= b)
				{
					b=Propertytwo._eyes;
				}
			}
		}
		return b;
}

int moneyTheme(GameTheme * theme)
{
	for ( int i = 0; i < LENADLIST2; ++ i )
	{
		if ( themeList[i]._themeName == theme -> _themeName )
			return ( themeList[i]._themeName );
	}
}

int moneyType(GameType * type)
{
	for ( int j = 0; j < LENADLIST3; ++ j )
	{
		if ( typeList[j]._typeName == type -> _typeName )
			return ( typeList[j]._typeName );
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
					
#endif