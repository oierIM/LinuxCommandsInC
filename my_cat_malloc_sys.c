#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#define MAX 100

main(int argc, char *argv[])
{
   int f;
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

   if ((f = open(argv[1], O_RDONLY)) == -1) {
      perror("open");
      exit(1);
   }

   while ((n = read(f, buffer, MAX)) > 0) {
      if (write(1, buffer, n) != n) {
         perror("write");
         exit(1);
      }
   }

   close(f);

   free(buffer);

   if (n == -1) {
      perror("read");
      exit(1);
   }

   exit(0);
}
