#include <stdio.h>

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
