#include <stdio.h>

void main(){
    int foundConsec = 1;
    int inConsec;
    char input [30]; 
    fgets(input,sizeof(input), stdin);
    scanf("%d",&inConsec);
    
    for(int i =0; i < 30; i ++){
        if(input[i] != 10){ //lf handling.
            if(input[i] == input[i+1] -1  || input[i] == input[i+1] -33 || input[i] == input[i+1] +31 ){
                foundConsec ++;
                if(foundConsec == inConsec){
                    printf("YES\n");
                    break;
                }
        }
        else{
            foundConsec=1;
        }
        }
        else{
            printf("NO\n");
            break;
        }
    }
}