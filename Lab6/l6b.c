#include <stdio.h>
#include <string.h>

int * zeroMaker(int arr []){
    int i;
    for(i = 0; i < 24; i ++){
        arr[i] = 0;
    }
    return arr;
}
int maxOfArr(int arr []){
    int k;
    int max = arr[0];
    for(k = 0; k < 24; k ++){
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
            // printf("%c ---->%c\n",str1[strlen(str1)-k-2],str2[j]);
            if(str1[strlen(str1)-k-2] == str2[j]){
                count++;
                a[index] = count;
                index++;
            }
            else{
                count = 0;
                break;
            }
            k--;
            j++;
           
        }
    }
    // printf("%d\n",maxOfArr(a));
    return maxOfArr(a);
}

void main(){
    char firstStr [24];
    char secondStr [24];
    int maxFinds [24];
    int maxFinds2 [24];
    zeroMaker(maxFinds2);
    zeroMaker(maxFinds);
    fgets(firstStr,sizeof(firstStr),stdin);
    fgets(secondStr,sizeof(secondStr),stdin);
    int first = finder(firstStr,secondStr,maxFinds);
    int second = finder(secondStr,firstStr,maxFinds2);
    // printf("%d\n", first);   //shows both to make sure.
    // printf("%d\n", second);
    printf("max overlap: %d\n",maxOf(first,second));
}