#include <stdio.h>
#include <string.h>

extern int game;
extern int x1,y11,x2,y2;
extern char desk[9][9];

void check_win(){
	int Pl1=0,Pl2=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(desk[i][j]=='Q')Pl2++;
			if(desk[i][j]=='q')Pl1++;
		}
	}
	if(Pl2==0)game+=1;
	if(Pl1==0)game+=2;
}

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
int pr_Q(){
	if((x1-x2!=1&&x2-x1!=1)&&(y2-y11!=1&&y11-y2!=1))return 0;
	return 1;
}
int pr_diag(){
	int ti,tj,z1=x2,z2=x1;
	if(((x2-x1)!=(y2-y11))&&((x2-x1)!=(y11-y2)))return 0;
	if(x2>x1){
		ti=1;
		z1=x1;
		z2=x2;
	}
	else ti=-1;
	if(y2>y11)tj=1;
	else tj=-1;
	int i=x1+ti;
	int j=y11+tj;
	while(i<z2&&i>z1){
		if((desk[i][j]<91 && desk[i][j]>64)||(desk[i][j]<123 && desk[i][j]>96))return 0;
		i=i+ti;
		j=j+tj;
	}
	return 1;
}

int pr_x(){
	if(y11!=y2)return 0;
	int z1=x1,z2=x2;
	if(x1>x2){
		z2=x1;
		z1=x2;
	}
	for(int i=z1+1;i<z2;i++)
		if((desk[i][y11]<91 && desk[i][y11]>64)||(desk[i][y11]<123 && desk[i][y11]>96))return 0;
	return 1;
}

int pr_y(){
	if(x1!=x2)return 0;
	int z1=y11,z2=y2;
	if(y11>y2){
		z2=y11;
		z1=y2;
	}
	for(int i=z1+1;i<z2;i++)
		if((desk[x1][i]<91 && desk[x1][i]>64)||(desk[x1][i]<123 && desk[x1][i]>96))return 0;
	return 1;
}

int check1(){
	if(desk[x2][y2]<123 && desk[x2][y2]>96)return 0;//не рубим себя.
	switch (desk[x1][y11]){
	case 'p':
		if(desk[x2][y2]<91 && desk[x2][y2]>64 && ((y11-y2)==1||(y2-y11)==1)&&(x1-x2==1))return 1;//рубим
		if((desk[x2][y2]==(char)219||desk[x2][y2]==' ') && x1==6 && y11==y2 && x1-x2>0 && x1-x2<3 
			&&(pr_x()))return 1;//ходы по пустым клеткам с начальной позиции
		if((desk[x2][y2]==(char)219||desk[x2][y2]==' ') && y11==y2 && x1-x2==1)return 1;//по пустым
		break;
	case 'r':
		if(x2==x1&&(pr_y())) return 1;
		if(y2==y11&&(pr_x()))return 1;
	break;
	case 'h':
		if(x1-x2==2&&y11-y2==1)return 1;//3
		if(x2-x1==2&&y2-y11==1)return 1;//1
		if(x2-x1==2&&y11-y2==1)return 1;//4
		if(x1-x2==2&&y2-y11==1)return 1;//2
		if(x1-x2==1&&y2-y11==2)return 1;//5
		if(x2-x1==1&&y2-y11==2)return 1;//6
		if(x1-x2==1&&y11-y2==2)return 1;//7
		if(x2-x1==1&&y11-y2==2)return 1;//8
	break;
	case 'b':
		if(pr_diag())return 1;
		break;
	case 'k':
		if(pr_diag()||pr_x()||pr_y())return 1;
		break;
	case 'q':
		if(pr_Q())return 1;
		break;
}	
return 0;
}

int check2(){
	if(desk[x2][y2]<91 && desk[x2][y2]>64) return 0;//не рубим себя.
	switch (desk[x1][y11]){
	case 'P':
		if(desk[x2][y2]<123 && desk[x2][y2]>96 && (y11-y2==1||y11-y2==-1)&&(x2-x1==1))return 1;//рубим
		if((desk[x2][y2]==(char)219||desk[x2][y2]==' ') && x1==1 && y11==y2 && x2-x1>0 && x2-x1<3
			&&(pr_x()))return 1;//по пустым клеткам с начальной позиции
		if((desk[x2][y2]==(char)219||desk[x2][y2]==' ') && y11==y2 && x2-x1==1) return 1;//по пустым
		break;
	case 'R':
			if(x2==x1&&(pr_y()))return 1;
			if(y2==y11&&(pr_x()))return 1;
		break;
	case 'H':
		if(x1-x2==2&&y11-y2==1)return 1;//3
		if(x2-x1==2&&y2-y11==1)return 1;//1
		if(x2-x1==2&&y11-y2==1)return 1;//4
		if(x1-x2==2&&y2-y11==1)return 1;//2
		if(x1-x2==1&&y2-y11==2)return 1;//5
		if(x2-x1==1&&y2-y11==2)return 1;//6
		if(x1-x2==1&&y11-y2==2)return 1;//7
		if(x2-x1==1&&y11-y2==2)return 1;//8
		break;
	case 'B':
		if(pr_diag())return 1;
		break;
	case 'K':
		if(pr_diag()||pr_x()||pr_y())return 1;
		break;
	case 'Q':
		if(pr_Q())return 1;
		break;
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
		printf("Error,try gain:");
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


