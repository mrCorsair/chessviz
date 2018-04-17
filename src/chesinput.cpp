#include <stdio.h>
#include <string.h>
#include "board_print_plain.cpp"

void scanh(int &x1, int &y1, int &x2, int &y2,char desk[][9],int flag){
	char tempxy[6];
	while(1){
		scanf("%s",tempxy);
		x1=(int)tempxy[1]-49;
		y1=(int)tempxy[0]-97;
		x2=(int)tempxy[4]-49;
		y2=(int)tempxy[3]-97;
		if (flag==1){
			if(desk[x1][y1]<123 && desk[x1][y1]>96&&strlen(tempxy)==5)break;
			else printf("error, try again:");
			}
		if (flag==2){ 
			if(desk[x1][y1]<91 && desk[x1][y1]>64&&strlen(tempxy)==5)break;
			else printf("error, try again:");
		}
	}
}


int main(){
	int x1,y1,x2,y2;
	char desk[9][9]={
	{'R','H','B','Q','K','B','H','R'},
	{'P','P','P','P','P','P','P','P'},
	{219,' ',219,' ',219,' ',219,' '},
	{' ',219,' ',219,' ',219,' ',219},
	{219,' ',219,' ',219,' ',219,' '},
	{' ',219,' ',219,' ',219,' ',219},
	{'p','p','p','p','p','p','p','p'},
	{'r','h','b','k','q','b','h','r'}};
	printdesk(desk);
	printf("an example of course:e2-e4\n");
	while(1){
		printf("player 1-not caps:");
		scanh(x1,y1,x2,y2,desk,1);
		desk[x2][y2]=desk[x1][y1];
		if((x1+y1)%2)desk[x1][y1]=' ';
		else desk[x1][y1]=219;
		printdesk(desk);
		printf("player 2-caps:");
		scanh(x1,y1,x2,y2,desk,2);
		desk[x2][y2]=desk[x1][y1];
		if((x1+y1)%2)desk[x1][y1]=' ';
		else desk[x1][y1]=219;
		printdesk(desk);
	}
}
