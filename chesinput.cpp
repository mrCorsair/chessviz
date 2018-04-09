#include <stdio.h>
void printdesk (char desk[9][9]){
	for(int i=0;i<8;i++){
	printf("%d|",i+1);
	for(int j=0;j<8;j++){
			printf("%c",desk[i][j]);
		}
			printf("\n");
	}
	printf("  ");
	for(int i=0;i<8;i++)printf("%c",i+97);
	printf("\n");
}

int main(){
	char desk[9][9]={
	{'R','H','B','Q','K','B','H','R'},
	{'P','P','P','P','P','P','P','P'},
	{219,' ',219,' ',219,' ',219,' '},
	{' ',219,' ',219,' ',219,' ',219},
	{219,' ',219,' ',219,' ',219,' '},
	{' ',219,' ',219,' ',219,' ',219},
	{'p','p','p','p','p','p','p','p'},
	{'r','h','b','k','q','b','h','r'}};
	for(int i=0;i<256;i++){
		printf("%d=%c\n",i,i);
	}
	printdesk(desk);
	printf("an example of course:e2-e4\n");
	while(1){
		int flag=1;
		char tempxy[7],tempc;
		printf("player 1-not caps:");
		while(1){
			scanf("%s",tempxy);
			if(desk[(int)tempxy[1]-49][(int)tempxy[0]-97]>122 or desk[(int)tempxy[1]-49][(int)tempxy[0]-97]<97)printf("error");
			else break;
			}
		tempc=desk[(int)tempxy[1]-49][(int)tempxy[0]-97];
		desk[(int)tempxy[1]-49][(int)tempxy[0]-97]=desk[(int)tempxy[4]-49][(int)tempxy[3]-97];
		desk[(int)tempxy[4]-49][(int)tempxy[3]-97]=tempc;
		printdesk(desk);
				printf("player 2-caps:");
		while(1){
			scanf("%s",tempxy);
			if(desk[(int)tempxy[1]-49][(int)tempxy[0]-97]>90 or desk[(int)tempxy[1]-49][(int)tempxy[0]-97]<65)printf("error");
			else break;
			}
		tempc=desk[(int)tempxy[1]-49][(int)tempxy[0]-97];
		desk[(int)tempxy[1]-49][(int)tempxy[0]-97]=desk[(int)tempxy[4]-49][(int)tempxy[3]-97];
		desk[(int)tempxy[4]-49][(int)tempxy[3]-97]=tempc;
		printdesk(desk);
		//printf("%c",tempc);
	}
}
