#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

void main(int argc, char *argv[]){

	char buffer[N];		//Bufferraren erazagupena
	FILE *f = fopen(argv[2], "r");	//file-a irakurri egin behar dela esan eta erazagutu
	int e = 2;			//exit-erako balioak emateko int-a
	
	if(argc == 3 && f){			//Ondo erabiltzen ari bagara my_grep true izango da
		e = 1;
		while (fgets(buffer,N,f)){				//fgets-ek testu-kate bat fitxategitik irakurtzen du
			if(strstr(buffer, argv[1])){		//strstr-k testu-kate baten barruan azpikate bat bilatzen du
				printf("%s", buffer);
				e = 0; 
			}
		}
		fclose(f);			//Dena bukatu eta gero, itxi fitxategia eta exit egin
		exit(e);
	}
	else{					//Gaizki erabili dugu my_grep
		fprintf(stderr, "ERROREA: Bi argumentu idatzi behar dira : existitzen den fitxategi bat eta fitxategi horretan bilatu nahi den patroia\n");
		exit(e);
	}
}