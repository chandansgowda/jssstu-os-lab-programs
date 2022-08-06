#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

void main(int argc, char* argv[]){

	DIR *dp;
	struct dirent *dirp; //used for directory traversal
	
	if (argc<2){
		printf("Didn't pass directory!\n");
		exit(0);
	}
	
	if ((dp=opendir(argv[1]))==NULL){
		printf("Cannot access directory!\n");
		exit(0);
	}
	
	while(dirp=readdir(dp)){
		printf("%s\n",dirp->d_name);
	}
}
