// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <string.h>

//MAIN
int main(){
    //NOTE: the variable pile is used but the compiler says that it is not, so you can just ignore the warning
    char exp[30], pile[30];
    int tope=-1;
    printf("Enter your expression: ");
    scanf("%s", exp);
    //NOTE: instead of declaring i as int, size_t is used because is the type returned by strlen. 
    //This ensures that i is unsigned and avoids the warning.
    for(size_t i=0; i<strlen(exp); i++){ 
        if(exp[i]=='(' || exp[i]=='['){
            pile[++tope]=exp[i];
        }
        if(exp[i]==')' || exp[i]==']'){
            if(tope!=-1){ //not empty pile  
                tope--;
                continue;
            }else{
                pile[tope++]=exp[i];
            }
        }
    }
    if(tope==-1){
        printf("Balanced");
    }else{
        printf("It's not balanced");
    }
    
    return 0;
}