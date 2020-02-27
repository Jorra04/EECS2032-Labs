#include <stdio.h>
/*
can uncomment the commented out code to use as a debugger.
*/
int length(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i-1;
}
void main(){ 
    //theres no white space for this problem, so we don't need to worry about that.
    char subString [50]; //Initialize to a big enough size.
    char regString [50]; 
     fgets(subString,sizeof(subString), stdin);
     fgets(regString,sizeof(regString),stdin); //read.
   
    if(length(regString) < length(subString)){ // can't be a substring if the first string is larger than the target string.
        printf("NO\n");
    }   
    else{
        int i,j,count;
        for(i = 0, j= 0; i < length(regString); i ++){ 
            /*
            go through a loop, with preverbial pointers, only increment
            the j pointer if you find a match.
            */
        //    printf("%c  ->  %c\n",regString[i], subString[j]);
            if(regString[i] == subString[j]){
                count++;
                 j ++;
                //  printf("%d %d\n",count,length(subString) );
                 if(count == length(subString)){
                    printf("YES\n");
                    return; //return; ends a void function, similar to java.
                 }
            }
            else{
                count=0; // reset both.
                j = 0;
                }
        }
        printf("NO\n"); //if none of the above conditions are met, its not a substring.
    }
    
}