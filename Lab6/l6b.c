#include <stdio.h>
#include <string.h>
#define MAX_ARR_SIZE 24

int * zeroMaker(int arr []){
    int i;
    for(i = 0; i < MAX_ARR_SIZE; i ++){
        arr[i] = 0;
    }
    return arr;
}
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

int minSize(int s1, int s2){
    if(s1 >= s2){
        return s2;
    }
    return s1;
}

int maxOf(int first, int second){
    if(first >= second){
        return first;
    }
    return second;
}

int finder(char str1 [], char str2[],int a []){
    int i;
    int j;
    int count = 0;
    int index = 0;
    int condition = minSize(strlen(str1)-1,strlen(str2)-1);
    for(i = 0; i < condition; i++){
        int k = i;
        j = 0;

        
        while(k >= 0){
            // printf("%c ---->%c\n",str1[strlen(str1)-k-2],str2[j]);  //print the matching values.
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
        // printf("------------\n"); // lets me see where each iteration begins.
    }
    // printf("%d\n",maxOfArr(a));
    return maxOfArr(a);
}

void main(){
    char firstStr [MAX_ARR_SIZE];
    char secondStr [MAX_ARR_SIZE];
    int maxFinds [MAX_ARR_SIZE];
    int maxFinds2 [MAX_ARR_SIZE];
    zeroMaker(maxFinds2);
    zeroMaker(maxFinds);
    fgets(firstStr,sizeof(firstStr),stdin);
    fgets(secondStr,sizeof(secondStr),stdin);
    int first = finder(firstStr,secondStr,maxFinds);
    int second = finder(secondStr,firstStr,maxFinds2);
    // printf("%d\n", first);   //shows both to make sure that the flipped case is taken into account.
    // printf("%d\n", second);
    printf("%d\n",maxOf(first,second)); //gets max return of firstStr into secondStr vs secondStr into firstStr.
}