// Author: reDragonCoder
//Handling of breaks and random numbers

//LIBRARIES
#include <stdio.h>
#include <time.h> //time
#include <stdlib.h>  //rand, srand

//MAIN
int main(){
    //activate random generation
    srand(time(NULL));

    //variables
    int totNum, num=0, even=0, odd=0, limit;

    printf("How many values do you want?: ");
    scanf("%d", &totNum);
    printf("Enter the limit: ");
    scanf("%d", &limit);

    //loop to generate the totNum
    for(int i=1; i<=totNum; i++){
        num=rand()%(limit+1);
        printf("%d \n", num);
        if(num%2==0){
            even++;
        }
        else{
            odd++;
        }
        if(num==13){ //if the num is value 13, the loop ends
            printf("Leaving, goodbye!...");
            break;
        }
    }
    printf("Total even: %d \n", even);
    printf("Total odd: %d \n", odd);
    return 0;
}