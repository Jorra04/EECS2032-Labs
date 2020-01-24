#!/bin/bash
split_names () {
   while read -n 1; do 
        space_separated=$(printf "$split_names_input $REPLY")
    done <<< "$split_names_input" 

    split_names_result=($space_separated)  
}

split_course () {
    while read -n 1; do 
        space_separated=$(printf "$split_course_input $REPLY")
    done <<< "$split_course_input" 

    split_course_result=($space_separated) 
}





if [ $1 = "-count" ]
then
    while read line;
    do
    count=$((count+1))
    
    done < "names.txt"
    echo $count
fi

if [ $1 = "-f" ]
then
    #this while loop takes in the student name, and outputs the corresponding student number.
    student_exists=false
    while read line;
    do
    split_names_input=$line
    split_names
    if [ "${#split_names_result[@]}" = 2 ]
    then
        if [ $2$3 = "${split_names_result[0]}" ]
        then
            student_number="${split_names_result[1]}"
            student_exists=true
        fi
    fi
    if [ "${#split_names_result[@]}" = 3 ]
    then
        if [ $2$3 = "${split_names_result[0]}""${split_names_result[1]}" ]
        then
            student_number="${split_names_result[2]}"
            student_exists=true
        fi
    fi
    

    done < "names.txt"
    #Now looking through courses to get the courses and grades associated with SN
    
    if [ $student_exists = true ]
    then
    while read line;
    do
    
    split_course_input=$line
    split_course

    if [ $student_number = "${split_course_result[0]}" ]
    then
        if [ "${#split_course_result[@]}" = 2 ]
        then
            echo "${split_course_result[1]}" in progress
        else
            echo "${split_course_result[1]}" "${split_course_result[2]}"

        fi
    fi
    
    
    done < "courses.txt"
    else
        echo student doesnt exist
    fi

fi

if [ $1 = "-g" ]
then
student_exists=false
while read line;
    do
    split_names_input=$line
    split_names
    if [ "${#split_names_result[@]}" = 2 ]
    then
        if [ $2$3 = "${split_names_result[0]}" ]
        then
            student_number="${split_names_result[1]}"
            student_exists=true
        fi
    fi
    if [ "${#split_names_result[@]}" = 3 ]
    then
        if [ $2$3 = "${split_names_result[0]}""${split_names_result[1]}" ]
        then
            student_number="${split_names_result[2]}"
            student_exists=true
        fi
    fi
    

    done < "names.txt"
    #Now looking through courses to get the courses and grades associated with SN
    
    if [ $student_exists = true ]
    then
    while read line;
    do
    split_course_input=$line
    split_course
    if [ $student_number = "${split_course_result[0]}" ]
    then
        if [ "${#split_course_result[@]}" = 3 ]
        then
            echo "${split_course_result[1]}" "${split_course_result[2]}" 

        fi

    fi
    
    
    done < "courses.txt"
    else
        echo student doesnt exist
    fi

fi

if [ $1 = "-c" ]
then
    while read line;
    do
    split_course_input=$line
    split_course
    if [ $2 = "${split_course_result[1]}" ]
    then
        count=$((count+1))

    fi
    
    
    done < "courses.txt"
    echo $count
fi

if [ $1 = "-list" ]

then
count=0
    while read line;
    do
    split_course_input=$line
    split_course
    if [ $2 = "${split_course_result[1]}" ] && [ $3 = "${split_course_result[2]}" ]
    then
        count=$((count+1))
    fi

    done < "courses.txt"
    echo $count
fi

#abc def gef
#arr[0]=abc