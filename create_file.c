#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
   int fd;
   #if file not exist, create with permissions 0664
   fd = open ("/home/sysdev/julio.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);

   return 0;
}
