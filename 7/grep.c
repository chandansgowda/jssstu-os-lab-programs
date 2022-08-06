#include <stdio.h>
#include <string.h>

void main(){
	
	FILE *fp;
	char filename[10], pattern[10], temp[100];
	
	printf("Enter FileName>> ");
	scanf("%s",filename);
	printf("Enter Pattern>> ");
	scanf("%s",pattern);
	
	fp=fopen(filename,"r");
	
	while(!feof(fp)){
		fgets(temp,100,fp);
		if(strstr(temp,pattern))  printf("%s",temp);
	}
}
