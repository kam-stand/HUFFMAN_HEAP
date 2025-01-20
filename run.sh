#!/bin/bash

bin="./bin"

gcc -Wall -Wextra ./src/main.c ./src/heap.c -o $bin/out

./$bin/out