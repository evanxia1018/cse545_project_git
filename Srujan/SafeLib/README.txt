Run this in the Terminal: 

1. Complie string.c as string.so
   + gcc -shared -fPIC string.c -o string.so
2. Complie main.c as test
   + gcc main.c -o test
3. Run teh test with the created libraries
   + LD_PRELOAD=$PWD/string.so ./test