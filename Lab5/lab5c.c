#include <stdio.h>

int getEndingIndex(char str[], int n, int i) { 
    i++; 
    while (i < n){ 
        char curr = str[i]; 
        char prev = str[i-1]; 
        if ((curr - prev == 1)){
             i++; 
        } 
        else{
            break;
        }
                 
    } 
  
    return i - 1; 
    } 
    int max(int num1, int num2){
        if(num1>= num2){
            return num1;
        }
        return num2;

    }
    int largestSubStr(char str[], int n) { 
        int len = 0; 
  
        int i = 0; 
        while (i < n){ 
            int end = getEndingIndex(str, n, i); 
            len = max(end - i + 1, len); 
            i = end + 1; 
        } 
  
        return len; 
    } 
    int main() { 
    int foundConsec = 1;
    int inConsec;
    char input [30]; 
    int helperRet;
    fgets(input,sizeof(input), stdin);

    int num = largestSubStr(input,sizeof(input));
    printf("%d\n", num);
    }