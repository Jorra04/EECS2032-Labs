#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
A C program to count the number of words in a textfile.
*/

void main(){
    char *readFile = "read4.txt";
    char *writeFile = "write4.txt";
    char c;
    FILE *reader = fopen(readFile,"r");
    FILE *writer = fopen(writeFile,"w");
    int words = 0;
    int spaces = 0;
    int characterCount = 0;
    char *line;
    while( !feof(reader)){
        c = fgetc(reader);
        if(c == ' ' || c == '\t' || c =='\0' || c == '\n' || c ==EOF){
            words++;
        }
    }
    printf("Words: %d\nSpaces: %d\nCharacters: %d\n",words,spaces,characterCount);
    // fputs("Words \t Spaces \t Characters \n",writer);
    // fprintf(writer,"===================================\n");
    // fprintf(writer, "%d \t %d \t\t %d \n",words,spaces,characterCount);
    

    // fclose(reader);
    // fclose(writer);
}