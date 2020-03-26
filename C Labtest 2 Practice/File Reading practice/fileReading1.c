#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}


void main(){
    char *fileName = "vowelReader.txt";
    char *writeFile = "FoundVowels.txt";
    char c;

    FILE *fileReader = fopen(fileName,"r");
    FILE *fileWriter = fopen(writeFile,"w");

    if(!fileReader){
        printf("The file does not exist or cannot be opened\n");
        return;
    }

    while(!(feof(fileReader))){
        c = fgetc(fileReader);
        // printf()
        if(!isVowel(c) && c != EOF){
            fputc(c,fileWriter);
        }
    }
}