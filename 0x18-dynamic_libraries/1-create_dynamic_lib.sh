#!/bin/bash
gcc -wall -wextra -werror -pendatic -c -fPIC *.c
gcc -shared -o liball.so *.o

