#include <stdio.h>

extern int game;
extern int x1,y1,x2,y2;
extern char desk[9][9];

void printdesk (){
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
