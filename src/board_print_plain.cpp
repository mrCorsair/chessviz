
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
