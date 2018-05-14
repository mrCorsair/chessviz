#include <stdio.h>
#include <string.h>

extern int game;
extern int x1,y11,x2,y2;
extern char desk[9][9];

void muve(){
	desk[x2][y2]=desk[x1][y11];
	if((x1+y11)%2)desk[x1][y11]=' ';
	else desk[x1][y11]=(char)219;
}

int inter(char tempxy[6]){
	x1=(int)tempxy[1]-49;
	y11=(int)tempxy[0]-97;
	x2=(int)tempxy[4]-49;
	y2=(int)tempxy[3]-97;
	if((strlen(tempxy)==5)&&(x2<8)&&(x2>=0)&&(y2>=0)&&(y2<8)&&(x1>=0)&&(x1<8)&&(y11>=0)&&(y11<8))return 1;
	return 0;
}

int check1(){
	switch (desk[x1][y11]){
	case 'p':
		if(desk[x2][y2]<91 && desk[x2][y2]>64 && ((y11-y2)==1||(y2-y11)==1)&&(x1-x2==1))return 1;//рубим
		if((desk[x2][y2]==(char)219||desk[x2][y2]==' ') && x1==6 && y11==y2 && x1-x2>0 && x1-x2<3 
			&&(desk[(x2+x1)/2][(y2+y11)/2]==(char)219||desk[(x2+x1)/2][(y2+y11)/2]==' ')) return 1;//ходы по пустым клеткам с начальной позиции
		if((desk[x2][y2]==(char)219||desk[x2][y2]==' ') && y11==y2 && x1-x2==1) return 1;//по пустым
		break;
	return 0;
}	
return 0;
}

int check2(){
	switch (desk[x1][y11]){
	case 'P':
		if(desk[x2][y2]<123 && desk[x2][y2]>96 && (y11-y2==1||y11-y2==-1)&&(x2-x1==1))return 1;//рубим
		if((desk[x2][y2]==(char)219||desk[x2][y2]==' ') && x1==1 && y11==y2 && x2-x1>0 && x2-x1<3
			&&(desk[(x2+x1)/2][(y2+y11)/2]==(char)219||desk[(x2+x1)/2][(y2+y11)/2]==' ')) return 1;//по пустым клеткам с начальной позиции
		if((desk[x2][y2]==(char)219||desk[x2][y2]==' ') && y11==y2 && x2-x1==1) return 1;//по пустым
		break;
	return 0;	
}
return 0;
}

void scanh(int flag){
	char tempxy[6]="NULL";
	while(1){
		while(1){
		scanf("%s",tempxy);
		if(strcmp(tempxy,"exit")==0||strcmp(tempxy,"0")==0){
			game=-1;
			return;
			}
		if(inter(tempxy)) break;
		printf("Error,try gain");
		}
		if (flag==1){
			if(check1()==1)break;
			else printf("error, try again:");
			}
		if (flag==2){ 
			if(check2()==1)break;
			else printf("error, try again:");
		}
	}
}


