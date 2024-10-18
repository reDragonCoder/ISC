// Author: reDragonCoder
//Recursivity function for the Ackerman function

//LIBRARIES
#include <stdio.h>

//PROTOTYPES
int acker(int, int);

//MAIN
int main(){
    int n=0, m=0, result=0;
    printf("Enter a number: ");
    scanf("%d", &m);
    printf("Enter another number: ");
    scanf("%d", &n);
    result=acker(m,n);
    printf("The result is: %d", result);
    return 0;
}

//IMPLEMENTATIONS
int acker(int m, int n){
    if(m==0){
        n++;
        return n;
    }else if(m>0 && n==0){
        return acker((m-1),1);
    }else if(m>0 && n>0){
        return acker((m-1), (acker(m,n-1)));
    }else{
        return 0;
    }
    
}