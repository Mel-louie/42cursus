#!/bin/bash

clang -Wall -Wextra -O3 -D_REENTRANT -c pthread2.1.c
clang -lpthread -o pthread2.1 pthread2.1.o
