#include <stdio.h>
/*
A program for LAB4 of EECS2032Z.
*/

main(){
    float a,b,c,winner=0; //initialize variables. 
    scanf("%f%f%f",&a,&b,&c); //read from console and dereference.
    if( a >= 0 && b >= 0 && c >= 0){ // conditional.
        printf("all positive.\n"); //expected output.
    }
    else if (a < 0 && b < 0 && c < 0){//conditional.
        printf("All negative\n"); //expected output.
    }
    else{ //every other case.
        winner = a+b+c; 
        if(winner < 0){
            printf("Negative Wins\n");
        }
        else{
            printf("Positive Wins\n");
        }
    }
}