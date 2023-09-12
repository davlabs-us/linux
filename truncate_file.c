#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
   int fd;
   fd = open ("/home/sysdev/julio.txt", O_WRONLY | O_TRUNC);

   printf("file opened and truncated\n");
   return 0;
}
