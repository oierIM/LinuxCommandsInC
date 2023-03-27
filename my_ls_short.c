#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>

	void main(int argc, char *argv[]){
	
		struct dirent *dir;		//Direktorioko sarrerei buruzko informazioa itzultzeko erabiltzen den egitura-mota bat da
		char cwd[PATH_MAX];		//cwd = current working directory
		
		getcwd(cwd, sizeof(cwd));	//uneko lan-direktorioaren izena lortzeko
		DIR *ptr = opendir(cwd);		//direktorioa irekitzeko
		
		if(argc == 2) ptr = opendir(argv[1]);	//Ondo erabiltzen badugu my_ls_short
		
		while((dir == readdir(ptr)) != NULL){		//nulua ez den bitartean, egin ondorengoa
			printf("%s\n", dir->d_name);		//
		}
		closedir(ptr);				//bukatutakoan itxi direktorioa
	}
	