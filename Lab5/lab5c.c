#include <stdio.h>

void main(){
    int foundConsec = 1;
    int inConsec;
    char input [30]; 
    int seq[30];
    int count = 0;
    fgets(input,sizeof(input), stdin);
    scanf("%d",&inConsec);

    for(int i =0; i < sizeof(input); i++){
        if(input[i] == input[i+1] -1){
            foundConsec++;
        }
        else{
            seq[count] = foundConsec;
            foundConsec = 1;
        }
    }
}