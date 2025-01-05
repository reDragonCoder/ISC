// Author: reDragonCoder
//Write a code that implements the bool function validId (int Id[]); where the id array is size=10 and it conteins a digit in each position of 
//the id. This function returns "true" if the id and "false" if it's not valid.
//The id is valid if the 2 first positions corresponds to the province where it was issued, these first to digits form a number that will not be
//greater than 24 or less than 1. The thirs digit is less than 6 and the last digit (verifier) must be equal to the result (number obtained
//applying the civil register formula). 

//LIBRARIES
#include <stdio.h>

//GLOBAL CONSTANT
#define SIZE 10

//PROTOTYPES
void getId(int []);  
bool validateTwoDigits(int[]); 
bool validateThirdDigit(int[]);
bool validateId(int[]);

//MAIN
int main(){
    //VARIABLES
    int idNumber[SIZE];
    bool result[3];
    getId(idNumber);

    result[0]=validateTwoDigits(idNumber);
    result[1]=validateThirdDigit(idNumber);
    result[2]=validateId(idNumber);
    if(result[0]==true && result[1]==true && result[2]==true){
        printf("The ID number is valid");
    }
    else{
        printf("It's not a valid ID");
    }

    return 0;
}


//IMPLEMENTATIONS
void getId(int idNumber[]){
    for(int i=0; i<SIZE; i++){
        printf("Introduce the id number [%d]: ", i+1);
        scanf("%d", &idNumber[i]);
    }
}

bool validateTwoDigits(int idNumber[]){
    int res=0;
    bool validate=false;
    res=(idNumber[0]*10)+idNumber[1];
    if(res>=1 && res<=24){
        validate=true;
    }
    return validate;
}

bool validateThirdDigit(int idNumber[]){
    if(idNumber[2]<6){
        return true;
    }
    return false;
}

bool validateId(int idNumber[]){
    int coeff[SIZE]={2,1,2,1,2,1,2,1,2,0}, multi[SIZE];
    int auxNum=0, addition=0, sum=0, residue=0, result=0;
    bool validation=false;
    for(int i=0; i<SIZE; i++){
        multi[i]=coeff[i]*idNumber[i];
        if(multi[i]>9){
            auxNum=multi[i];
            while(auxNum!=0){
                addition+=auxNum%10;
                auxNum/=10;
            }
            multi[i]=addition;
        }
    }
    for(int i=0; i<SIZE; i++){
        sum+=multi[i];
    }
    residue=sum%10;
    if(residue==0){
        result=residue;
    }
    else{
        result=10-residue;
    }
    if(idNumber[9]==result){
        validation=true;
    }
    else{
        validation=false;
    }
    return validation;
}

