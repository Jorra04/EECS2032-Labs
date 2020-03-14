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

// int * zeroMaker(int zeros[], int size){
//     int i;
//     for(i = 0; i < size; i ++ ){
//         zeros[i] = 0;
//     }
//     return zeros;
// }


// void printer(int arr[], int size){
//     int i;
//     for(i = 0; i < size; i ++ ){
//         printf("%d\n", arr[i]);
//     }
// }

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
void fileWriter(char* writeFile,char* readFile, int num1,int num2){
    FILE *fptr;
    fptr = fopen("result.txt","w");
    int i;
    for(i = 0; i < length(readFile); i++){
        fprintf(fptr,"%c",readFile[i]);
    }
    // fprintf(fptr,"\n");
    fprintf(fptr,"%c",num1); //append to the files
    fprintf(fptr,"%c",num2); // append to the files
    // printf("%d and %d\n",num1,num2); //use this to check what the ascii values are.
    fclose(fptr);
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
    int myArr[32] = {0}; // set all values to zero, zero maker is useless, just do this.
    
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
        runSum += myArr[i] * power(2,i-16); //raise to the pow of the max.
    }
    return (65535 - runSum); //correcting for overflow.
}

int main(void) {

    char *readFile = fileReader("dat.txt");
    int i;
    int finalSum = 0;

    for(i = 0; i < length(readFile); i+=2){
        finalSum += readFile[i] * 256;
        finalSum += readFile[i+1];
    }

    int tmpSum = numberFinder(finalSum);
    int num2 = tmpSum - floor(tmpSum/256)*256;
    int num1 = (tmpSum - num2)/256;
    char *fileName = "result.txt";
    fileWriter(fileName,readFile,num1,num2);
}