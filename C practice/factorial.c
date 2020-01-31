#include <stdio.h>
void main(){
    printf("Enter the Value.");
    float val = 0;
    scanf("%f",&val);
    if(&val < 0){
        printf("No factorial for negative numbers.");
        return -1;
    }
    else if(val == 1 || val == 0){
        return 1;
    }
    else{
        float x = 1;
        printf("here");
        for(int i =0; i < val; i++){
            x*=val;
        }
        printf(x);
        return x;
    }

    
}