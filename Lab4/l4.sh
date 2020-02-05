#!/bin/bash
####### Code starts....

declare -a myArray
count=0
while read num
do
    if [ $num -lt 0 ]
    then
        break
    else
        myArray+=($num)
        count=$((count+1))
    fi
done
isTrue=false
diff=1
for(( i=1; i<(count); i++ ))
 do
    difChecker=$((${myArray[$i]}-${myArray[$((i-1))]}))
    #echo "$difChecker ---> $diff"
    if [ $difChecker -eq 1 ]
    then 
        #echo here
        isTrue=true
    else
        isTrue=false
        break
    fi
 done
if [ "$isTrue" = "true" ]
 then
    echo YES
else
    echo NO
 fi