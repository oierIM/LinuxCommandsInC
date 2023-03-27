#include <stdio.h>
#include <stdlib.h>

int my_cp (char fitxategia1 [], char fitxategia2 [])
{
    int   c;
    FILE *f_r;
    FILE *f_w; 

    f_r = fopen (fitxategia1, "r");	  //irakurri lehenengo fitxategia
    if (f_r == NULL)
        return -1;
    f_w = fopen (fitxategia2, "w");   //sortu eta idatzi 2. fitxategian, oraingoan w jarriz, r beharrean
    if (f_w == NULL)
     {
        fclose (f_r);
        return -2;
     }    
    while ((c = fgetc(f_r)) != EOF)	  //end of file nahi du esan EOF ; fgetc-k fitxategi batetik karaktere bat irakurtzen du
        fputc (c, f_w);				  //fputc-k karaktere bat gordetzen du fitxategian
    fclose (f_r);
    fclose (f_w);

    return 0;
}