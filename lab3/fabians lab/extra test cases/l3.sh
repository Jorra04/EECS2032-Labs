#!/bin/bash
#note you cant access args in  function ie $1
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

find_student_number_from_name () {
    boolean_foundname=false #check for user exits
    #here might have to go arg parser but fuck it

    while read line; 
    do
        split_names_input=$line
        split_names
       
        if [ ${#split_names_result[@]} = 3 ] #then there is a space
        then 
            if [ $find_student_number_from_name_input = "${split_names_result[0]}""${split_names_result[1]}" ]
            then 
                boolean_foundname=true
                student_number="${split_names_result[2]}"
            fi
        else #check if no space
            if [ $find_student_number_from_name_input = "${split_names_result[0]}" ]
            then 
                boolean_foundname=true
                student_number="${split_names_result[1]}"
            fi
        fi
   
    done < "names.txt"
}

if [ -f "names.txt" ] && [ -f "courses.txt" ]
then 
    if [ $1 = "-count" ]
    then 
        while read line; 
        do
            n=$((n+1))
        done < "names.txt"

        echo number of line is $n

    elif [ $1 = "-f" ]
    then
        find_student_number_from_name_input=$2$3
        find_student_number_from_name

        if [ $boolean_foundname = true ] 
        then
            while read line; 
            do
                split_course_input=$line
                split_course

                if [ $student_number = "${split_course_result[0]}" ] 
                then
                    if [ ${#split_course_result[@]} = 2 ]
                    then
                        echo "${split_course_result[1]}" in progress
                    else 
                        echo "${split_course_result[1]}" "${split_course_result[2]}"
                    fi
                fi
            done < "courses.txt"
        else
            echo No such student: $2 $3
        fi

    elif [ $1 = "-g" ]
    then 
        find_student_number_from_name_input=$2$3
        find_student_number_from_name

        if [ $boolean_foundname = true ] 
        then
            while read line; 
            do
                split_course_input=$line
                split_course

                if [ $student_number = "${split_course_result[0]}" ] 
                then
                    if [ ${#split_course_result[@]} = 3 ]
                    then
                        echo "${split_course_result[1]}" "${split_course_result[2]}" 
                    fi
                fi
            done < "courses.txt"
        else
            echo No such student: $2 $3
        fi

    elif [ $1 = "-c" ]
    then 
        #display the number of student registered for course
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

    elif [ $1 = "-list" ]
    then 
        #count=0
        #number of students who have this letter grade
        while read line; 
        do
            split_course_input=$line
            split_course

            if [ $2 = "${split_course_result[1]}" ] && [ $3 = "${split_course_result[2]}"  ] 
            then
                count=$((count+1))
            fi
        done < "courses.txt"

        echo $count

    fi

fi