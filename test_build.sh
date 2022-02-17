#!/bin/env bash
# SUPER DUPER NAIVE (temp)
# run this from the same directory as cmus-stats is installed in lol
gcc -o sqlite_handler.o sqlite_handler.c
make clean
sh configure
sudo make install destdir=/tmp/cmus
