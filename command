#!/bin/bash

rm safe_lib.o

rm safe_lib.so

gcc -Wall -fPIC -c -o safe_lib.o safe_lib.c

gcc -shared -fPIC -Wl,-soname -Wl,safe_lib.so -o safe_lib.so safe_lib.o -ldl

#gcc -shared -fPIC -Wl,-soname -Wl,safe_lib.so -o safe_lib.so safe_lib.c -ldl

#gcc test.c -o test

#LD_PRELOAD=./safe_lib.so ./test
