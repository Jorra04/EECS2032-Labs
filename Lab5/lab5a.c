#include <stdio.h>
#define MAX_SIZE 30

int helper(char s[], int val){
    if(val == 1){
        return 1;
    }
    int count = 1;
    int i;
		for(i =1; i < MAX_SIZE; i++) {
			if(s[i] == s[i-1] +1) {
				count++;
				if(count == val) {
					return 1;
                    goto spot;
				}
			}
            else{
                count = 1;
            }
		}
        spot:
		return 0;
}
void main(){
    int foundConsec = 1;
    int inConsec;
    char input [30]; 
    int helperRet;
    fgets(input,sizeof(input), stdin);
    scanf("%d",&inConsec);

    helperRet = helper(input,inConsec);

    if(helperRet == 1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}