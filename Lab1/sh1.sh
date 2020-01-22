#!/bin/bash
if [ $# != 2 ] #if #args != 2
then 
    echo usage: $0 dir file #$0 prints out the file name too.
elif [ ! -d "$1" ]
then 
    echo $1 is not a directory
elif [ ! -f "$1/$2" ]
then 
    echo $2 is not a regular file
else
    
    if [ -f "$1/$2" ] 
    then
        echo $2 is in $1
    else
        echo $2 is not in $1 #doesnt seem to reach this case, but satisfies the requiremnts of the question.
    fi

fi