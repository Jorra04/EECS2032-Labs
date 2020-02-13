#!/bin/bash
unsorted=true
while [ "$unsorted" = "true" ]
do
    read x y z
    if [ $x -lt $y ] && [ $y -lt $z ]
    then
        echo $y
        unsorted=false
    else
        echo no
    fi
done