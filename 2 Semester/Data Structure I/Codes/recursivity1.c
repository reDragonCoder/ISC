// Author: reDragonCoder
//Factorial of a number using recursivity

//LIBRARIES
#include <stdio.h>

//PROTOTYPES
int factorial(int);

//MAIN
int main(){
    //VARIABLES
    int n=0;

    printf("Enter a number: ");
    scanf("%d", &n);
    
    printf("Factorial: %d", factorial(n));

    return 0;
}

//IMPLEMENTATIONS
int factorial(int n){
    int r=0;
    if(n==0 || n==1){
        printf("f(%d)=1 \n", n);
        return 1;
    }else{
        printf("f(%d)=%d*f(%d) \n", n,n,n-1);
        r=n*factorial(n-1);
        printf("f(%d)=%d \n", n, r);
        return r;
    }
}