// Author: reDragonCoder
//Write a function that sorts an array of characters.

//LIBRARIES
#include <stdio.h>

//PROTOTYPES
void sortArray(char* array);

//MAIN
int main(){
    //VARIABLES
    char array[5];

    for(int i=0; i<5; i++){
        printf("Enter the [%d] character: ", i);
        scanf(" %c", &array[i]); //space after %c to skip any leading whitespaces characters
    }

    printf("Initial array: ");
    for(int i=0; i<5; i++){
        printf("%c", array[i]);
    }
    printf("\n");
    sortArray(array);

    return 0;
}

//IMPLEMENTATIONS
void sortArray(char* array){ //char* array points to the memory address where the first character of the string is located
    char temp;
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(array[i]>array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    printf("The ordered array is: ");
    for(int i=0; i<5; i++){
        printf("%c", array[i]);
    }
}



