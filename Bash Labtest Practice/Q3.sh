#!/bin/bash
squaresChecker(){
    read x
    isHyp=false
    for((i=0;i<=$x;i++))
    do
        for((j=0;j<=$x;j++))
        do
            if [ $(($((i * i)) + $((j * j)))) -eq  $x  ]
            then
                echo YES
                exit 1
            fi
        done
    done
    echo NO
}
if [ $# -ne 0 ]
then
    echo "No command arguments please"
    squaresChecker
else
    squaresChecker
fi