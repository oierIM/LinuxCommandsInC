#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
	char buffer[512];
	
    mydir = opendir(argv[1]);
	
    while((myfile = readdir(mydir)) != NULL)
    {
        sprintf(buffer, "%s/%s", argv[1], myfile->d_name);
        stat(buffer, &mystat);
        printf("%zu",mystat.st_size);
        printf(" %s\n", myfile->d_name);
    }
    closedir(mydir);
}exit
