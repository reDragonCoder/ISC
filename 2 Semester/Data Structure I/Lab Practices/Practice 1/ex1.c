// Author: reDragonCoder
//Write a program that captures by keyboard two integer vectors, A and B, with variable size. We want to solve this tasks:
//Order each one of the vectors (A and B); create a C vector (result) ordered by interleaving or mixing vectors A and B, and
//show it on screen; locate if a number entered by the user exists in the vector C, and must also display the message “exists”
// or “does not exist”, whether or not it is located.

//LIBRARIES
#include <stdio.h>

//GLOBAL CONSTANT
#define SIZE 5

//PROTOTYPES
void capture(int[]);
void show(int[]);
void showFinal(int[]);
void order(int[]);
void finalOrder(int[], int[], int[]);
void searchNumber(int[]);

//MAIN
int main(){
    //VARIABLES
    int vecA[SIZE], vecB[SIZE], vecC[SIZE*2];

    capture(vecA);
    printf("Original vecA is: ");
    show(vecA);
    order(vecA);
    printf("The ordered vecA is: ");
    show(vecA);
    capture(vecB);
    printf("Original vecB is: ");
    show(vecB);
    order(vecB);
    printf("The ordered vecB is: ");
    show(vecB);
    finalOrder(vecA, vecB, vecC);
    printf("The ordered vecC (vecA & vecB) is: ");
    showFinal(vecC);
    searchNumber(vecC);

    return 0;
}

//IMPLEMENTATIONS
void capture(int vec[]){
    for(int i=0; i<SIZE; i++){
        printf("Enter the value [%d]: ", i+1);
        scanf("%d", &vec[i]);
    }
}

void show(int vec[]){
    for(int i=0; i<SIZE; i++){
        printf("%d ", vec[i]);
    }
    printf("\n \n");
}

void showFinal(int vec[]){
    for(int i=0; i<SIZE*2; i++){
        printf("%d ", vec[i]);
    }
    printf("\n \n");
}

void order(int vec[]){
    int temp=0, j=0;
    for(int i=1; i<SIZE; i++){
        temp=vec[i];
        j=i-1;
        while(j>=0 && temp<vec[j]){
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=temp;
    }
}

void finalOrder(int vec1[], int vec2[], int vec3[]){
    int temp=vec1[0], j=0;
    for(int i=0; i<SIZE*2; i++){
        if(vec2[i]==temp){
            vec3[j]=temp;
            j++;
            vec3[j]=temp;
            j++;
            temp=vec1[i+1];
        }else{
            if(temp<vec2[i]){
                vec3[j]=temp;
                j++;
                vec3[j]=vec2[i];
                j++;
            }else{
                vec3[j]=vec2[i];
                j++;
                vec3[j]=temp;
                j++;
            }
        }
    }
}

void searchNumber(int vec[]){
    int num=0, cont=0;
    printf("What number do you want to search? ");
    scanf("%d", &num);
    for(int i=0; i<SIZE*2; i++){
        if(vec[i]==num){
            cont++;
        }
    }
    if(cont==0){
        printf("The numer[%d] doesn't exists in the array", num);
    }else{
        printf("The number [%d] exists in the array and it appears %d times", num, cont);
    }
    printf("\n\n");
}
