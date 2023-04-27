#!/bin/bash

gcc -O0 -fopenmp -S -o daxpy_O0.s daxpy.c

gcc -Os -fopenmp -S -o daxpy_Os.s daxpy.c

gcc -O2 -fopenmp -S -o daxpy_O2.s daxpy.c

gcc -O3 -fopenmp -S -o daxpy_O3.s daxpy.c
