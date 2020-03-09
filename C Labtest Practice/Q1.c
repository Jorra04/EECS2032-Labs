#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    printf("Enter a name: ");
    char name [20];
    fgets(name,sizeof(name), stdin);
    int i,j,index = 0;
    for(i =0; i < strlen(name); i ++ ){ //find location of last space.
        if(name[i] == ' '){
            index = i;
        }
    }

    for(j = index; j < strlen(name); j ++ ){
        printf("%c", name[j]);
    }
    printf(","); 



    for(j = 0; j < index; j ++ ){
        printf("%c", name[j]);
    }

}