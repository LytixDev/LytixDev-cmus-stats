#!/bin/env bash
# SUPER DUPER NAIVE (temp)
# run this from the same directory as cmus-stats is installed in lol

mkdir -p "$HOME/.local/share/cmus-stats/"
touch "$HOME/.local/share/cmus-stats/cmus-stats.db"
gcc -o sqlite_handler.o sqlite_handler.c
gcc -o stat_taking.o stat_taking.c
make clean
sh configure
sudo make install
