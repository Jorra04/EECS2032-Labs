#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

char* readFileBytes(const char *name)  {  
    FILE *fl = fopen(name, "r");  
    fseek(fl, 0, SEEK_END);  
    long len = ftell(fl);  
    char *ret = malloc(len);  
    fseek(fl, 0, SEEK_SET);  
    fread(ret, 1, len, fl);  
    fclose(fl);  
    return ret;  
} 
int power(int base, int exp){
int result=1;
int i = 0;
for (i = exp; i > 0; i--){
result = result * base;
}
return result;
}

int getStrLen(char str[]){//dans change this
    int len = 0;
    while(str[len] != 10){
        len++;
    }
    return ++len;
}

int finaNum(int input){
    int foo[32] = {0};
    int counter = 0;
    int returnSum = 0;
    int i;
    for(i = 0; input > 0; i++){    
        foo[i]=input%2;    
        input /= 2;    
        counter++;
    } 
    for(i = 15; i >= 0; i--){    
        returnSum += foo[i] * power(2,i);
    }
    for(i = counter-1; i >= 16; i--){    
        returnSum += foo[i] * power(2,i-16);
    }
    return (65535 - returnSum);
}

int main(void) {
   
    char *string = readFileBytes("result.txt");
    
    int i;
    int sum = 0;

    for(i = 0; i < getStrLen(string); i+=2){
        sum += string[i]*256;
        sum += string[i+1];
    }

    int checkSum = ((string[getStrLen(string)]+256)*256) + (string[getStrLen(string)+1]+256);
    printf("%d\n",checkSum);
    printf("%d\n",finaNum(sum));
    if(finaNum(sum) == checkSum){
       printf("Valid\n");
    }else{
        printf("Invalid\n");
    }

}