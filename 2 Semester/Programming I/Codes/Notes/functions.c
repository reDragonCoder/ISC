// Author: reDragonCoder
//Show the use of functions

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//GLOBAL CONSTANT
#define SIZE 10

//PROTOTYPES (it uses memory only if is used the function in the main)
void message(); //type of function that does not receive and does not returns
int addition(); //type of function that does not recive but it returns
void showResults(int); //type of function that receives but it does not returns (paso de parametro por valor [receives a copy of the value])
void randomNumbers(int[]); //type of function that receives but it does not returns           
int sum(int[]); //type of function that receives and returns (paso de parametro por referencia [receives the direction in memory] - Ej. vector)
void showVec(int[]);

//MAIN
int main(){
    //VARIABLES
    int plus=0, vec[SIZE]={0,0,0,0,0,0,0,0,0,0}, result=0;

    srand(time(NULL)); //always write this instruction in the main after the variables (not inside functions)
    printf("Hi everybody! \n");

    //CALLBACKS
    message();
    plus=addition();
    showResults(plus);
    showVec(vec);
    randomNumbers(vec);
    showVec(vec);
    result=sum(vec);
    printf("Array sum: %d \n", result);
 
    printf("Bye \n");

    return 0;
}

//IMPLEMENTATIONS
void message(){
    printf("Welcome to another day! \n");
}

int addition(){
    int num1=0, num2=0, sum=0; //local variable means that it does not affect outside of the main (same behaivour inside a function)
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    sum=num1+num2;
    return sum;
}

void showResults(int plus){ //"plus" here is a copy
    printf("Plus value: %d \n", plus);
}

void randomNumbers(int vec[]){
    for(int i=0; i<SIZE; i++){
        vec[i]=rand()%11;
    }
}

void showVec(int vec[]){
    for(int i=0; i<SIZE; i++){
        printf(" %d ", vec[i]);
    }
    printf("\n");
}

int sum(int vec[]){
    int plus=0;
    for(int i=0; i<SIZE; i++){
        plus+=vec[i];
    }
    return plus;
}

