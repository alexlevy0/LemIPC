#!/usr/bin/zsh

i=0
./lemipc

while test $i != 5
do
    ./lemipc &
    i=$(($i + 1))
done
