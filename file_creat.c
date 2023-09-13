#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
   int fd;
   fd = creat ("/home/sysdev/julio1.txt", 0644);
   return 0;
}
