#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX 100

main(int argc, char *argv[])
{
   FILE *f;
   size_t n;
   char *buffer;

   if (argc != 2) {
      fprintf(stderr, "usage: %s filename\n", argv[0]);
      exit(1);
   }

   if ((buffer = malloc(MAX)) == NULL) {
      perror("malloc");
      exit(1);
   }

   if ((f = fopen(argv[1], "r")) == NULL) {
      perror("fopen");
      exit(1);
   }

   while ((n = fread(buffer, sizeof(char), MAX, f)) > 0) {
      fwrite(buffer, sizeof(char), n, stdout);
   }

   fclose(f);

   free(buffer);

   exit(0);
}
