#include <stdio.h>
#include <string.h>
#include "board_print_plain.h"
#include "plain.h"

int game=0;
int x1,y1,x2,y2;
char desk[9][9]={
	{'R','H','B','Q','K','B','H','R'},
	{'P','P','P','P','P','P','P','P'},
	{(char)219,' ',(char)219,' ',(char)219,' ',(char)219,' '},
	{' ',(char)219,' ',(char)219,' ',(char)219,' ',(char)219},
	{(char)219,' ',(char)219,' ',(char)219,' ',(char)219,' '},
	{' ',(char)219,' ',(char)219,' ',(char)219,' ',(char)219},
	{'p','p','p','p','p','p','p','p'},
	{'r','h','b','k','q','b','h','r'}};
	
int main(){
	printdesk();
	printf("an example of course:e2-e4\n");
	while(1){
		printf("player 1-not caps:");
		scanh(1);
		if(game!=0)break;
		desk[x2][y2]=desk[x1][y1];
		if((x1+y1)%2)desk[x1][y1]=' ';
		else desk[x1][y1]=(char)219;
		printdesk();
		printf("player 2-caps:");
		scanh(2);
		if(game!=0)break;
		desk[x2][y2]=desk[x1][y1];
		if((x1+y1)%2)desk[x1][y1]=' ';
		else desk[x1][y1]=(char)219;
		printdesk();
	}
	printf("Exit stsyus:%d\n",game);
}
