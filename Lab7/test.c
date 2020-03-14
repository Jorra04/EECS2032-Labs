#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    int sum =0;
    char a = 'a';
    char b = 'b';
    printf("%d |  %d \n", a,b);
    sum +=a;
    printf("%d\n",sum);
    sum  = sum << 8;
    printf("%d\n",sum);
    sum+=b;
    printf("%d\n",sum);
    // sum+=5;
    // sum << 8;


    // sum+=5;

    // printf("%d\n",sum); //should not be 10, 0101 concat with 0101
    // //should be 01010101. not 1010

}