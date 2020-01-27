#!/bin/bash
whiteSpaceNames () {
   while read -n 1; do 
        space_separated=$(printf "$whiteSpaceNames_input $REPLY")
    done <<< "$whiteSpaceNames_input" 

    whiteSpaceNames_result=($space_separated)  
}

whiteSpaceCourses () {
    while read -n 1; do 
        space_separated=$(printf "$whiteSpaceCourses_input $REPLY")
    done <<< "$whiteSpaceCourses_input" 

    whiteSpaceCourses_result=($space_separated) 
}

namesFile="names.txt"
coursesFile="courses.txt"


if [ ! -e $namesFile ] || [ ! -e $coursesFile ]
then

    echo "One or both files do not existing."
    exit 1


fi




if [ $1 = "-count" ]
then
    while read line;
    do
    count=$((count+1))
    
    done < $namesFile
    echo $count
fi

if [ $1 = "-f" ]
then
    #this while loop takes in the student name, and outputs the corresponding student number.
    student_exists=false
    while read line;
    do
    whiteSpaceNames_input=$line
    whiteSpaceNames
    if [ "${#whiteSpaceNames_result[@]}" = 2 ]
    then
        if [ $2$3 = "${whiteSpaceNames_result[0]}" ]
        then
            student_number="${whiteSpaceNames_result[1]}"
            student_exists=true
        fi
    fi
    if [ "${#whiteSpaceNames_result[@]}" = 3 ]
    then
        if [ $2$3 = "${whiteSpaceNames_result[0]}""${whiteSpaceNames_result[1]}" ]
        then
            student_number="${whiteSpaceNames_result[2]}"
            student_exists=true
        fi
    fi
    

    done < $namesFile
    #Now looking through courses to get the courses and grades associated with SN
    #echo $student_exists
    if [ $student_exists = true ]
    then
    while read line;
    do
    whiteSpaceCourses_input=$line
    whiteSpaceCourses

    if [ $student_number = "${whiteSpaceCourses_result[0]}" ]

    then
        if [ "${#whiteSpaceCourses_result[@]}" = 2 ]
        then
            echo here
            echo "${whiteSpaceCourses_result[1]}" in progress
        else
            echo "${whiteSpaceCourses_result[1]}" "${whiteSpaceCourses_result[2]}"

        fi
    fi
    
    
    done < $coursesFile
    else
        echo student doesnt exist
    fi

fi

if [ $1 = "-g" ]
then
student_exists=false
while read line;
    do
    whiteSpaceNames_input=$line
    whiteSpaceNames
    if [ "${#whiteSpaceNames_result[@]}" = 2 ]
    then
        if [ $2$3 = "${whiteSpaceNames_result[0]}" ]
        then
            student_number="${whiteSpaceNames_result[1]}"
            student_exists=true
        fi
    fi
    if [ "${#whiteSpaceNames_result[@]}" = 3 ]
    then
        if [ $2$3 = "${whiteSpaceNames_result[0]}""${whiteSpaceNames_result[1]}" ]
        then
            student_number="${whiteSpaceNames_result[2]}"
            student_exists=true
        fi
    fi
    

    done < $namesFile
    #Now looking through courses to get the courses and grades associated with SN
    if [ $student_exists = true ]
    then
    while read line;
    do
    whiteSpaceCourses_input=$line
    whiteSpaceCourses
    if [ $student_number = "${whiteSpaceCourses_result[0]}" ]
    then
        if [ "${#whiteSpaceCourses_result[@]}" = 3 ]
        then
            echo "${whiteSpaceCourses_result[1]}" "${whiteSpaceCourses_result[2]}" 

        fi

    fi
    
    
    done < $coursesFile
    else
        echo student doesnt exist
    fi

fi

if [ "$1" = "-c" ]
then
    while read line;
    do
    whiteSpaceCourses_input=$line
    whiteSpaceCourses
    if [ "$2" = "${whiteSpaceCourses_result[1]}" ]
    then
        count=$((count+1))

    fi
    
    
    done < $coursesFile
    echo $count
fi

if [ "$1" = "-list" ]

then
    count=0
    while read line;
    do
        whiteSpaceCourses_input=$line
        whiteSpaceCourses
        #echo ${whiteSpaceCourses_result[@]}
        #echo 12345 $2 $3
        if [ "$2" = ${whiteSpaceCourses_result[1]} ] #&& [ "$3" = ${whiteSpaceCourses_result[2]} ]
        then
            #echo $3
            #echo ${whiteSpaceCourses_result[2]}
            if [ "$3" = ${whiteSpaceCourses_result[2]} ]
            then
                #echo got here
                count=$((count+1))
            fi
        fi

    done < $coursesFile
    echo $count
fi

#abc def gef
#arr[0]=abc