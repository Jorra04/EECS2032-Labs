#!/bin/bash
IFS=$'\t'

if [ -f "names3.txt" ] || [ -f "courses2.txt" ]
then
    #what you had was pointless since you never did it for -f -g -c -list 
    count=0
    if [ "$1" = "-count" ]
    then
        while read -a names3Arr
        do
            count=$((count+1))
        done < "names3.txt"
        
        echo $count
    fi
            
    if [ $1 = "-f" ]
    then
        student_found=false

        while read -a names3Arr
        do
            if [ "${2// /}" = "${names3Arr[0]// /}" ]
            then
                storedId="${names3Arr[1]}"

                while read -a courseArr
                do
                    #echo "${courseArr[@]}"
                    
                    echo "${courseArr[0]}"

                    if [ "$storedId" = "${courseArr[0]}" ]
                    then
                        student_found=true
                        
                        if [ "${#courseArr[@]}" = 2 ]
                        then
                            echo "${courseArr[1]}" in progress
                        else
                            echo "${courseArr[1]}" "${courseArr[2]}"
                        fi 
                    fi 
                done < "courses2.txt"
            fi
        done < "names3.txt"

        if [ $student_found = "false" ]
        then 
            echo no student_found
        fi
    fi

    if [ $1 = "-g" ]
    then
        student_found=false

        while read -a names3Arr
        do
            if [ "${2// /}" = "${names3Arr[0]// /}" ]
            then
                storedId="${names3Arr[1]}"

                while read -a courseArr
                do
                    if [ "$storedId" = "${courseArr[0]}" ]
                    then
                        student_found=true

                        if [ "${#courseArr[@]}" = 3 ]
                        then
                            echo "${courseArr[1]}" "${courseArr[2]}" 
                        fi 
                    fi 
                done < "courses2.txt"
            fi
        done < "names3.txt"

        if [ $student_found = "false" ]
        then 
            echo no student_found
        fi
    fi

    if [ "$1" = "-c" ]
    then
        count=0
        while read -a courseArr
        do
            if [ "$2" = "${courseArr[1]}" ]
            then
                count=$((count+1)) 
            fi
        done < $courses2File
        echo $count
    fi

    if [ "$1" = "-list" ]
    then
        count=0
        
        while read -a courseArr
        do
            if [ "$2" = "${courseArr[1]}" ] && [ "$3" = "${courseArr[2]}" ]
            then
                count=$((count+1))
            fi
        done < "courses2.txt"
        echo $count
    
    fi

else
    echo "One or both files do not existing."
fi