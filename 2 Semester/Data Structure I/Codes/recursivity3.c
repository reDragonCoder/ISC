// Author: reDragonCoder
//Define a recursive function for the Fibonacci serie: 0,1,2,3,5,8,13,21,...
//and code the C function that can get the n term of the serie
//f(0)=0, f(1)=1, f(2)=f(0)+f(1), f(3)=f(1)+f(2)
//f(n)=f(n-1)+f(n-2)

//LIBRARIES
#include <stdio.h>

//PROTOTYPES
int fibonacci(int);

//MAIN
int main(){
    //VARIABLES
    int n=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The %d term is %d\n", n, fibonacci(n));
    return 0;
}

//IMPLEMENTATIONS
int fibonacci(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}


