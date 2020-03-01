#include <stdio.h>
#include <string.h>
#define MAX_ARR_SIZE 35

int maxOfArr(int arr []){
    int k;
    int max = arr[0];
    for(k = 0; k < MAX_ARR_SIZE; k ++){
        if(arr[k] > max){
            max = arr[k];
        }
    }
    return max;
}

int finder(char str1 [], char str2[],int a []){
    int i,j,count,index = 0;
    int condition = (strlen(str1)-1 > strlen(str2)-1) ? strlen(str2)-1 : strlen(str1)-1;
    for(i = 0; i < condition; i++){
        int k = i;
        j = 0;

        while(k >= 0){ // printf("%c ---->%c\n",str1[strlen(str1)-k-2],str2[j]);  //print the matching values.
            if(str1[strlen(str1)-k-2] == str2[j]){
                count++; 
            }
            else{
                count = 0;
                break;
            }
            k--;
            j++;
        }
        a[index] = count; //having this happen outside the loop means that only consecutive counts are added.
        index++;
        count = 0;
    }
    return maxOfArr(a);
}

void main(){
    char firstStr [MAX_ARR_SIZE]; 
    char secondStr [MAX_ARR_SIZE]; 
    int maxFinds [MAX_ARR_SIZE] = {0}; 
    int maxFinds2 [MAX_ARR_SIZE] = {0};
    fgets(firstStr,sizeof(firstStr),stdin);
    fgets(secondStr,sizeof(secondStr),stdin);
    int first = finder(firstStr,secondStr,maxFinds); // can print these to show both steps.
    int second = finder(secondStr,firstStr,maxFinds2);
    printf("%d\n",(first>second) ? first : second); //gets max return of firstStr into secondStr vs secondStr into firstStr.
}