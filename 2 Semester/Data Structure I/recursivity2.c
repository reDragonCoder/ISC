// Author: reDragonCoder
//M(n,m) = m+M(m,n-1)

//LIBRARIES
#include <stdio.h>

//PROTOTYPES
int mult(int, int);

//MAIN
int main(){
    //VARIABLES
    int m=0, n=0, res=0;
    printf("Enter a number: ");
    scanf("%d", &m);
    printf("Insert another number: ");
    scanf("%d", &n);
    res=mult(m,n);
    printf("%d \n", res);
    return 0;
}

//IMPLEMENTATIONS
int mult(int m, int n){
    if(n==1){
        return m;
    }else{
        return m+mult(m,n-1);
    }
}