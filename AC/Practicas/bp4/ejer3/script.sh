#!/bin/bash

gcc -O0 -fopenmp -o daxpy_O0 daxpy.c
echo "DAXPY O0:"
./daxpy_O0 100000000 2.25

gcc -Os -fopenmp -o daxpy_Os daxpy.c
echo "DAXPY Os:"
./daxpy_Os 100000000 2.25

gcc -O2 -fopenmp -o daxpy_O2 daxpy.c
echo "DAXPY O2:"
./daxpy_O2 100000000 2.25

gcc -O3 -fopenmp -o daxpy_O3 daxpy.c
echo "DAXPY O3:"
./daxpy_O3 100000000 2.25
