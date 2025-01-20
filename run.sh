#!/bin/bash
source_file="./src/heap.c"
main_file="./src/main.c"
bin="./bin"

gcc -Wall -Wextra $source_file $main_file -o $bin/out

./$bin/out