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
    student_found=false
    
    while read -a namesArr
    do
        #this is actually pretty good fam

        #i added remove spaces 
        if [ "${2// /}" = "${namesArr[0]// /}" ]
        then
            #this is the student number
            storedId="${namesArr[1]}"

            while read -a courseArr
            do
                #check if id matches course id
                if [ "$storedId" = "${courseArr[0]}" ]
                then
                    student_found=true

                    #kinda fucked you should check size but this works
                    if [ -z "${courseArr[2]}" ]
                    then
                        echo "${courseArr[1]}" in progress
                    else
                        echo "${courseArr[1]} ${courseArr[2]}"
                    fi
                        
                fi  

            done < $coursesFile
        fi

    done < $namesFile

    if [ $student_found = "false" ]
    then 
        echo no student_found
    fi

fi



if [ "$1" = "-c" ]
then
    if [ $# -eq 2 ]
    then
        count=0
        while read -a courseArr
        do
            if [ "$2" = "${courseArr[1]}" ]
            then
                count=$((count+1)) 
            fi
        done < $coursesFile
        echo $count
    else
        echo Incorrect number of arguments.
    fi
fi

if [ "$1" = "-list" ]
then
    count=0
    if [ $# -eq 2 ]
    then
        while read -a courseArr
        do
            #echo "$2 --> ${courseArr[1]} ${courseArr[2]}"
            if [ "$2" = "${courseArr[1]} ${courseArr[2]}" ]
            then
                count=$((count+1))
            fi

        done < $coursesFile
        echo $count


    elif [ $# -eq 3 ]
    then
        while read -a courseArr
        do
            if [ "$2" = "${courseArr[1]}" ] && [ "$3" = "${courseArr[2]}" ]
            then
                count=$((count+1))

            fi


        done < $coursesFile
        echo $count

    fi
fi