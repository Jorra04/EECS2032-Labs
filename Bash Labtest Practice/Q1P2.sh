#!/bin/bash

count=0
while read ID name
do
    #echo "${1// /} = ${ID// /}"
    if [ "${1// /}" = "${ID// /}" ]
    then
        storedName=$name
        while read ID2 name
        do
            #echo "$name --> $storedName"
            if [ "$name" = "$storedName" ]
            then
                count=$((count+1))
            fi
        done < "NameCourses.txt"
    fi
done < "NameID.txt"
echo $count