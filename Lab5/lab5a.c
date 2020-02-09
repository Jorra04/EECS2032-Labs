#include <stdio.h>
#define MAX_LIMIT 24

void main(){
    int foundConsec = 1;
    int inConsec;
    char input [24]; 
    fgets(input,sizeof(input), stdin);
    scanf("%d",&inConsec);

    printf("input: %s %d\n" ,input, inConsec);

    for(int i =0; i < MAX_LIMIT; i ++){
        if(input[i] == (input[i+1] -1)){
            foundConsec ++;
        }
    }
    if(foundConsec == inConsec){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    
}