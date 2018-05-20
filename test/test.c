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
char txy[6];

CTEST(input,interpreter)
{
	strcpy(txy,"b2-b1");
	int c1=inter(txy);
	strcpy(txy,"b2b1");
	int c2=inter(txy);
	strcpy(txy,"a1-c9");
	int c3=inter(txy);
	strcpy(txy,"z2-b1");
	int c4=inter(txy);
	strcpy(txy,"b2eb1c");
	int c5=inter(txy);
	
	
	const int exp1 = 1;
	const int exp2 = 0;
	const int exp3 = 0;
	const int exp4 = 0;
	const int exp5 = 0;
	
	ASSERT_EQUAL(exp1, c1);
	ASSERT_EQUAL(exp2, c2);
	ASSERT_EQUAL(exp3, c3);
	ASSERT_EQUAL(exp4, c4);
	ASSERT_EQUAL(exp5, c5);
}

CTEST(move_suite, move_pawn) // Ход пешки 
{	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2)desk[i][j]=' ';
			else desk[i][j]=(char)219;
		}
	}//пустая доска.
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
	//////ход через фигуру////
	strcpy(txy,"b2-b4");
	inter(txy);
	int c7=check2();
	//THEN
	const int exp1 = 1;
	const int exp2 = 1;
	const int exp3 = 0;
	const int exp4 = 0;
	const int exp5 = 0;
	const int exp6 = 1;
	const int exp7 = 0;
	
	ASSERT_EQUAL(exp1, c1);
	ASSERT_EQUAL(exp2, c2);
	ASSERT_EQUAL(exp3, c3);
	ASSERT_EQUAL(exp4, c4);
	ASSERT_EQUAL(exp5, c5);
	ASSERT_EQUAL(exp6, c6);
	ASSERT_EQUAL(exp7, c7);
}

CTEST(move_suite, move_pawn2) // Ход пешки 2
{	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2)desk[i][j]=' ';
			else desk[i][j]=(char)219;
		}
	}//пустая доска.
	//WHEN
	strcpy(txy,"b7-b6");//ход вперед.
	inter(txy);
	desk[x1][y11]='p';
	int c1=check1();
	strcpy(txy,"b7-b5");//на 2 клетки с начала.
	inter(txy);
	int c2=check1();
	strcpy(txy,"b6-b4");//2 клетки с неначальной позиции
	inter(txy);
	desk[x1][y11]='p';
	int c3=check1();
	///////Проверка хода по диагонали//////////
	strcpy(txy,"b6-c5");
	inter(txy);
	int c4=check1();
	/////////Проверка хода назад ////////
	strcpy(txy,"b7-b8");
	inter(txy);
	int c5=check1();
	//////проверка на возможность рубить пешкой////
	strcpy(txy,"b6-c5");
	inter(txy);
	desk[x2][y2]='P';
	int c6=check1();
	//////ход через фигуру////
	strcpy(txy,"b7-b5");
	inter(txy);
	int c7=check1();
	//THEN
	const int exp1 = 1;
	const int exp2 = 1;
	const int exp3 = 0;
	const int exp4 = 0;
	const int exp5 = 0;
	const int exp6 = 1;
	const int exp7 = 0;
	
	ASSERT_EQUAL(exp1, c1);
	ASSERT_EQUAL(exp2, c2);
	ASSERT_EQUAL(exp3, c3);
	ASSERT_EQUAL(exp4, c4);
	ASSERT_EQUAL(exp5, c5);
	ASSERT_EQUAL(exp6, c6);
	ASSERT_EQUAL(exp7, c7);
}

CTEST(move_suite, move_rook) // Ход Ладьи
{
	//GIVEN
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2)desk[i][j]=' ';
			else desk[i][j]=(char)219;
		}
	}//пустая доска.

	//Ход вперёд 
	strcpy(txy,"h1-h4");
	inter(txy);
	desk[x1][y11]='R';
	int c1=check2();

	//Ход назад
	strcpy(txy,"f7-f2");
	inter(txy);
	desk[x1][y11]='R';
	int c2=check2();

	//Ход влево
	strcpy(txy,"h1-g1");
	inter(txy);
	desk[x1][y11]='R';
	int c3=check2();	

	//Атака//вправо
	strcpy(txy,"g2-a2");
	inter(txy);
	desk[x1][y11]='R';
	desk[x2][y2]='r';
	int c4=check2();

	//Ход по диагонали
	strcpy(txy,"g2-e4");
	inter(txy);
	desk[x1][y11]='R';
	int c5=check2();
	
	
	//ход через фигугру
	strcpy(txy,"f7-f2");
	inter(txy);
	desk[x1][y11]='R';
	desk[4][5]='p';
	int c6=check2();
	
	//THEN
	const int exp1 = 1;
	const int exp2 = 1;
	const int exp3 = 1;
	const int exp4 = 1;
	const int exp5 = 0;
	const int exp6 = 0;

	ASSERT_EQUAL(exp1, c1);
	ASSERT_EQUAL(exp2, c2);
	ASSERT_EQUAL(exp3, c3);
	ASSERT_EQUAL(exp4, c4);
	ASSERT_EQUAL(exp5, c5);
	ASSERT_EQUAL(exp6, c6);
}

CTEST(move_suite, move_hourse) // Ход коня
{
	//GIVEN
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2)desk[i][j]=' ';
			else desk[i][j]=(char)219;
		}
	}//пустая доска.

	//Ход вперёд 
	strcpy(txy,"h1-h4");
	inter(txy);
	desk[x1][y11]='H';
	int c1=check2();

	//Ход назад
	strcpy(txy,"f7-f2");
	inter(txy);
	desk[x1][y11]='H';
	int c2=check2();

	//Ход влево
	strcpy(txy,"h1-g1");
	inter(txy);
	desk[x1][y11]='H';
	int c3=check2();	

	//вправо
	strcpy(txy,"g2-a2");
	inter(txy);
	desk[x1][y11]='H';
	int c4=check2();

	//Ход по диагонали
	strcpy(txy,"g2-e4");
	inter(txy);
	desk[x1][y11]='H';
	int c5=check2();
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2)desk[i][j]=' ';
			else desk[i][j]=(char)219;
		}
	}//пустая доска.
	
	//ходы Г
	strcpy(txy,"c3-d5");
	inter(txy);
	desk[x1][y11]='H';
	int c6=check2();
	
	strcpy(txy,"c3-d1");
	inter(txy);
	int c7=check2();
	
	strcpy(txy,"c3-b1");
	inter(txy);
	int c8=check2();
	
	strcpy(txy,"c3-b5");
	inter(txy);
	int c9=check2();
	
		
	strcpy(txy,"c3-e2");
	inter(txy);
	int c10=check2();
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2)desk[i][j]=' ';
			else desk[i][j]=(char)219;
		}
	}
		
	strcpy(txy,"c3-e4");
	inter(txy);
	desk[x1][y11]='H';
	int c11=check2();
	
	strcpy(txy,"c3-a2");
	inter(txy);
	int c12=check2();
	//+сруб
	strcpy(txy,"c3-a4");
	inter(txy);
	desk[x2][y2]='p';
	int c13=check2();
	
	//THEN
	const int exp1 = 0;
	const int exp2 = 0;
	const int exp3 = 0;
	const int exp4 = 0;
	const int exp5 = 0;
	const int exp6 = 1;
	const int exp7 = 1;
	const int exp8 = 1;
	const int exp9 = 1;
	const int exp10 = 1;
	const int exp11 = 1;
	const int exp12 = 1;
	const int exp13 = 1;

	ASSERT_EQUAL(exp1, c1);
	ASSERT_EQUAL(exp2, c2);
	ASSERT_EQUAL(exp3, c3);
	ASSERT_EQUAL(exp4, c4);
	ASSERT_EQUAL(exp5, c5);
	ASSERT_EQUAL(exp6, c6);
	ASSERT_EQUAL(exp7, c7);
	ASSERT_EQUAL(exp8, c8);
	ASSERT_EQUAL(exp9, c9);
	ASSERT_EQUAL(exp10, c10);
	ASSERT_EQUAL(exp11, c11);
	ASSERT_EQUAL(exp12, c12);
	ASSERT_EQUAL(exp13, c13);
}

CTEST(move_suite, move_bishop) // Ход Cлона
{
		//GIVEN
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2)desk[i][j]=' ';
			else desk[i][j]=(char)219;
		}
	}//пустая доска.

	//Ход вперёд 
	strcpy(txy,"d4-d6");
	inter(txy);
	desk[x1][y11]='B';
	int c1=check2();

	//Ход назад
	strcpy(txy,"d4-d2");
	inter(txy);
	int c2=check2();

	//Ход влево
	strcpy(txy,"d4-a4");
	inter(txy);
	int c3=check2();	

	//вправо
	strcpy(txy,"d4-f4");
	inter(txy);
	int c4=check2();

	//Ход по диагонали
	strcpy(txy,"d4-b2");
	inter(txy);
	int c5=check2();
	//Ход по диагонали/обратно
	strcpy(txy,"d4-f6");
	inter(txy);
	int c6=check2();
	//другая диагональ/сруб
	strcpy(txy,"d4-b6");
	inter(txy);
	desk[x2][y2]='b';
	int c7=check2();
	//другая диагональ/revers
	strcpy(txy,"d4-f2");
	inter(txy);
	desk[x1][y11]='B';
	int c8=check2();
	//другая диагональ/revers/через пешку
	strcpy(txy,"d4-f2");
	inter(txy);
	desk[x1][y11]='B';
	desk[2][4]='P';
	int c9=check2();
	//THEN
	const int exp1 = 0;
	const int exp2 = 0;
	const int exp3 = 0;
	const int exp4 = 0;
	const int exp5 = 1;
	const int exp6 = 1;
	const int exp7 = 1;
	const int exp8 = 1;
	const int exp9 = 0;

	ASSERT_EQUAL(exp1, c1);
	ASSERT_EQUAL(exp2, c2);
	ASSERT_EQUAL(exp3, c3);
	ASSERT_EQUAL(exp4, c4);
	ASSERT_EQUAL(exp5, c5);
	ASSERT_EQUAL(exp6, c6);
	ASSERT_EQUAL(exp7, c7);
	ASSERT_EQUAL(exp8, c8);
	ASSERT_EQUAL(exp9, c9);
}

CTEST(move_suite, move_king) // Ход короля
{
		//GIVEN
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2)desk[i][j]=' ';
			else desk[i][j]=(char)219;
		}
	}//пустая доска.

	//Ход вперёд 
	strcpy(txy,"d4-d6");
	inter(txy);
	desk[x1][y11]='K';
	int c1=check2();

	//Ход назад
	strcpy(txy,"d4-d2");
	inter(txy);
	int c2=check2();

	//Ход влево
	strcpy(txy,"d4-a4");
	inter(txy);
	int c3=check2();	

	//вправо
	strcpy(txy,"d4-f4");
	inter(txy);
	int c4=check2();

	//Ход по диагонали
	strcpy(txy,"d4-b2");
	inter(txy);
	int c5=check2();
	//Ход по диагонали/обратно
	strcpy(txy,"d4-f6");
	inter(txy);
	int c6=check2();
	//другая диагональ/сруб
	strcpy(txy,"d4-b6");
	inter(txy);
	desk[x2][y2]='b';
	int c7=check2();
	//другая диагональ/revers
	strcpy(txy,"d4-f2");
	inter(txy);
	int c8=check2();
	//другая диагональ/revers/через пешку
	strcpy(txy,"d4-f2");
	inter(txy);
	desk[2][4]='P';
	int c9=check2();
	//ложный ход
	strcpy(txy,"d4-e1");
	inter(txy);
	int c10=check2();
	//THEN
	const int exp1 = 1;
	const int exp2 = 1;
	const int exp3 = 1;
	const int exp4 = 1;
	const int exp5 = 1;
	const int exp6 = 1;
	const int exp7 = 1;
	const int exp8 = 1;
	const int exp9 = 0;
	const int exp10 = 0;

	ASSERT_EQUAL(exp1, c1);
	ASSERT_EQUAL(exp2, c2);
	ASSERT_EQUAL(exp3, c3);
	ASSERT_EQUAL(exp4, c4);
	ASSERT_EQUAL(exp5, c5);
	ASSERT_EQUAL(exp6, c6);
	ASSERT_EQUAL(exp7, c7);
	ASSERT_EQUAL(exp8, c8);
	ASSERT_EQUAL(exp9, c9);
	ASSERT_EQUAL(exp10, c10);
}
	

CTEST(move_suite, move_queen) // Ход королева
{
		//GIVEN
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2)desk[i][j]=' ';
			else desk[i][j]=(char)219;
		}
	}//пустая доска.

	//Ход вперёд /+
	strcpy(txy,"d4-d5");
	inter(txy);
	desk[x1][y11]='Q';
	int c1=check2();

	strcpy(txy,"d4-d6");
	inter(txy);
	int c12=check2();
	
	//Ход назад/+
	strcpy(txy,"d4-d3");
	inter(txy);
	int c2=check2();

	strcpy(txy,"d4-d2");
	inter(txy);
	int c22=check2();
	
	//Ход влево/+
	strcpy(txy,"d4-c4");
	inter(txy);
	int c3=check2();	

	strcpy(txy,"d4-b4");
	inter(txy);
	int c32=check2();
	
	//вправо/+
	strcpy(txy,"d4-e4");
	inter(txy);
	int c4=check2();
	
	strcpy(txy,"d4-f4");
	inter(txy);
	int c42=check2();

	//Ход по диагонали/+
	strcpy(txy,"d4-c3");
	inter(txy);
	int c5=check2();
	
	strcpy(txy,"d4-b2");
	inter(txy);
	int c52=check2();
	//Ход по диагонали/обратно
	strcpy(txy,"d4-e5");
	inter(txy);
	int c6=check2();
	
	strcpy(txy,"d4-f6");
	inter(txy);
	int c62=check2();
	//другая диагональ/сруб
	strcpy(txy,"d4-c5");
	inter(txy);
	desk[x2][y2]='b';
	int c7=check2();
	
	strcpy(txy,"d4-b6");
	inter(txy);
	int c72=check2();
	//другая диагональ/revers
	strcpy(txy,"d4-e3");
	inter(txy);
	int c8=check2();
	
	strcpy(txy,"d4-f2");
	inter(txy);
	int c82=check2();
	//THEN
	const int exp1 = 1;
	const int exp2 = 1;
	const int exp3 = 1;
	const int exp4 = 1;
	const int exp5 = 1;
	const int exp6 = 1;
	const int exp7 = 1;
	const int exp8 = 1;
	const int exp12 = 0;
	const int exp22 = 0;
	const int exp32 = 0;
	const int exp42 = 0;
	const int exp52 = 0;
	const int exp62 = 0;
	const int exp72 = 0;
	const int exp82 = 0;
	
	ASSERT_EQUAL(exp12, c12);
	ASSERT_EQUAL(exp22, c22);
	ASSERT_EQUAL(exp32, c32);
	ASSERT_EQUAL(exp42, c42);
	ASSERT_EQUAL(exp52, c52);
	ASSERT_EQUAL(exp62, c62);
	ASSERT_EQUAL(exp72, c72);
	ASSERT_EQUAL(exp82, c82);
	ASSERT_EQUAL(exp1, c1);
	ASSERT_EQUAL(exp2, c2);
	ASSERT_EQUAL(exp3, c3);
	ASSERT_EQUAL(exp4, c4);
	ASSERT_EQUAL(exp5, c5);
	ASSERT_EQUAL(exp6, c6);
	ASSERT_EQUAL(exp7, c7);
	ASSERT_EQUAL(exp8, c8);
}
