#include <stdio.h>
#include <string.h>
#include "../src/board_print_plain.h"
#include "../src/plain.h"
#include "../thirdparty/ctest.h"

int game=0;
int x1,y11,x2,y2;
char desk[9][9]={
	{'R','H','B','Q','K','B','H','R'},
	{'P','P','P','P','P','P','P','P'},
	{(char)219,' ',(char)219,' ',(char)219,' ',(char)219,' '},
	{' ',(char)219,' ',(char)219,' ',(char)219,' ',(char)219},
	{(char)219,' ',(char)219,' ',(char)219,' ',(char)219,' '},
	{' ',(char)219,' ',(char)219,' ',(char)219,' ',(char)219},
	{'p','p','p','p','p','p','p','p'},
	{'r','h','b','k','q','b','h','r'}};

CTEST(move_suite, move_pawn) // Ход пешки 
{	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2)desk[i][j]=' ';
			else desk[x1][y11]=(char)219;
		}
	}//пустая доска.
	char txy[6];
	//WHEN
	strcpy(txy,"b2-b3");//ход вперед.
	inter(txy);
	desk[x1][y11]='P';
	int c1=check2();
	strcpy(txy,"b2-b4");//на 2 клетки с начала.
	inter(txy);
	int c2=check2();
	strcpy(txy,"b3-b5");//2 клетки с неначальной позиции
	inter(txy);
	desk[x1][y11]='P';
	int c3=check2();
	///////Проверка хода по диагонали//////////
	strcpy(txy,"b3-c4");
	inter(txy);
	int c4=check2();
	/////////Проверка хода назад ////////
	strcpy(txy,"b2-b1");
	inter(txy);
	int c5=check2();
	//////проверка на возможность рубить пешкой////
	strcpy(txy,"b3-c4");
	inter(txy);
	desk[x2][y2]='p';
	int c6=check2();
	//THEN
	const int exp1 = 1;
	const int exp2 = 1;
	const int exp3 = 0;
	const int exp4 = 0;
	const int exp5 = 0;
	const int exp6 = 1;
	//if(c1==exp1)printf("1");
	ASSERT_EQUAL(exp1, c1);
	ASSERT_EQUAL(exp2, c2);
	ASSERT_EQUAL(exp3, c3);
	ASSERT_EQUAL(exp4, c4);
	ASSERT_EQUAL(exp5, c5);
	ASSERT_EQUAL(exp6, c6);
}
