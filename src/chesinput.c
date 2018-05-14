#include <stdio.h>
#include <string.h>
#include "board_print_plain.h"
#include "plain.h"

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
	
int main(){
	printdesk();
	printf("an example of course:e2-e4\n");
	while(1){
		printf("player 1-not caps:");
		scanh(1);
		if(game!=0)break;
		muve();
		printf("\033[2J"); /* Clear the entire screen. */ 
		printf("\033[0;0f"); /* Move cursor to the top left hand corner */
		printdesk();
		printf("player 2-caps:");
		scanh(2);
		if(game!=0)break;
		muve();
		printf("\033[2J"); /* Clear the entire screen. */ 
		printf("\033[0;0f"); /* Move cursor to the top left hand corner */
		printdesk();
	}
	if(game>0)printf("Plauer%d win",game);
	else printf("Exit status:%d\n",game);
}
