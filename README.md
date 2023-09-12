# linux
linux kernel system programming

# compile
gcc -Wall -Wextra -O2 -g -o snippet snippet.c


# create a shared object, and call function from ptyhon
gcc -c -fPIC hello.c -o hello.o
gcc -shared -o libhello.so -fPIC hello.c

from ctypes import *
libhello = cdll.LoadLibrary("/home/sysdev/julio/libhello.so")
print(libhello.main())
