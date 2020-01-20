#!/bin/bash
if [ $# != 2 ]
then
echo usage: sh1.sh dir file
exit
elif [ ! -d "$1" ]
then
echo argument 1 is not a directory
fi
if [ ! -f "$1"/"$2" ]
then
echo argument 2 is not a regular file
exit
fi

if [ -e "$1"/"$2" ]
then 
echo file $2 is in directory $1
exit 
else
echo file $2 is not in directory $1
fi