// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int long num1=0, num2=1;
    int long i=0;
    for(i=1; i<=50; i++){
        if (i%2==0)
        {
            printf("%ld", num2);
            printf("\n");
            num2+=num1;
        }
        else{
            printf("%ld", num1);
            printf("\n");
            num1+=num2;
        }
    }
    return 0;
}