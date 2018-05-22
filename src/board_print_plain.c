#include <stdio.h>

extern int game;
extern int x1,y11,x2,y2;
extern char desk[9][9];

void printdesk (){
	int i,j;
	for(i=0;i<8;i++){
	printf("%d|",i+1);
	for(j=0;j<8;j++){
			printf("%c",desk[i][j]);
		}
			printf("\n");
	}
	printf("  ");
	for(i=0;i<8;i++)printf("%c",i+65);
	printf("\n");
}
