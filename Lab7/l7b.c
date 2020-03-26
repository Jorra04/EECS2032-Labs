#include <stdio.h>
#include <stdlib.h>
#include <math.h> //need this for floor.

int length(char str[]){
    int count = 0;
    while(str[count] != 10){ //ascii checker
        count++;
    }
    return count +1; // inc then return.
}

char* fileReader(const char *name){
    FILE *file = fopen(name, "r");  //open file for reading.
    fseek(file, 0, SEEK_END);  
    long strLen = ftell(file);  
    char *returner = malloc(strLen);  
    fseek(file, 0, SEEK_SET);  
    fread(returner, 1, strLen, file);  
    fclose(file);  
    return returner;  
} 

int power(int base, int exp){
int result=1;
int i = 0;
for (i = exp; i > 0; i--){
result = result * base;
}
return result;
}

int numberFinder(int input){
    int myArr[32] = {0};
    int counter = 0;
    int runSum = 0;
    int i;
    for(i = 0; input > 0; i++){    
        myArr[i]=input%2;    
        counter++;
        input = input/ 2; //DAQ
    } 
    for(i = 15; i >= 0; i--){ 

        runSum += myArr[i] * power(2,i);
    }
    for(i = counter-1; i >= 16; i--){    
        runSum += myArr[i] * power(2,i-16); //raise to the pow of the max then dec.
    }
    return (65535 - runSum); //correcting for overflow.
}

int main(void) {

    char *readFile = fileReader("result.txt");
    int i;
    int finalSum = 0;

    for(i = 0; i < length(readFile); i+=2){
        finalSum += readFile[i] * 256;
        finalSum += readFile[i+1];
    }
    
    
    int checkSum = 0;//((readFile[getStrLen(readFile)]+256)*256) +(readFile[getStrLen(readFile)+1]+256);
/*
need a bunch of checks to make sure that this workd for neg and pos nums.
*/
if(readFile[length(readFile)] < 0){
checkSum += ((readFile[length(readFile)]+256)*256);
}else{
checkSum += (readFile[length(readFile)]*256);
}
if(readFile[length(readFile)+1] < 0){
checkSum += (readFile[length(readFile)+1]+256);
}else{
checkSum += (readFile[length(readFile)+1]);
}

if(numberFinder(finalSum) == checkSum ){
printf("Valid\n");
}else{
printf("Invalid\n");
}
}