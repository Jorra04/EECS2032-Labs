#!/bin/bash
############## Starting lab 3.

###############

namesFile="names.txt"
coursesFile="courses.txt"


if [ ! -e $namesFile ] || [ ! -e $coursesFile ]
then

    echo "One or both files do not existing."
    exit 1
fi

if [ "$1" = "-count" ]
then
    if [ -s $namesFile ]
    then
        if [ -z "$(tail -c 1 "$namesFile")" ]
        then
            count=0
            while read line;
            do
                if [ ! -z "$line" ]
                then
                    count=$((count+1))
                fi
            done < $namesFile
            echo $((count)) 
        else
            count=1
            while read line;
            do
                if [ ! -z "$line" ]
                then
                    count=$((count+1))
                fi
            done < $namesFile
            echo $((count))
        
        fi
    else
        echo 0

    fi
fi


        
IFS=$'\t'
if [ $1 = "-f" ]
then
studentExists=false
    if [ $# -eq 3 ]
    then
        #echo 3 
        while read -a namesArr
        do
            echo "${namesArr[0]}"
            if [ "$2 $3" = "${namesArr[0]}" ]
            then
                echo here
                storedId=$SN
                #echo $storedId
                while read ID course grade
                do
                   # echo $course $grade
                    if [ "$storedId" = "$ID" ]
                    then
                        studentExists=true
                        if [ -z "$grade" ]
                        then
                            echo "$course in progress"
                        else
                            echo $course $grade
                        fi
                        
                    fi

                done < $coursesFile
            fi
        done < $namesFile

        if [ $studentExists = false ]
        then
        echo "no such student: $2 $3"
        fi

    elif [ $# -eq 2 ]
    then
        echo 2

    fi
fi