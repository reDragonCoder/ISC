// Author: reDragonCoder
//An ice cream company makes 7 types of ice cream and they work 3 shifts a day to make them. Write a program that allows: 
//capturing the name of each type of ice cream and the production in each shift, Print the name of the ice cream with the 
//highest production, print the shift that made the most production, print the lowest production of all the shifts.  
//Print the shift and the ice cream to which all cases in which the lowest production appears correspond.

//LIBRARIES
#include <stdio.h>
#include <string.h>

//GLOBAL CONSTANTS
#define ICECREAMTYPES 7
#define SHIFTS 3

//MAIN
int main(){
    //VARIABLES
    char iceCreamNames[ICECREAMTYPES][50];
    int iceCreamProduction[ICECREAMTYPES][SHIFTS];

    //ask the user for name and production data
    for(int i=0; i<ICECREAMTYPES; ++i){
        printf("Enter the name of ice cream #%d: ", i+1);
        scanf("%s", iceCreamNames[i]);
        for(int shift=0; shift<SHIFTS; ++shift){
            printf("Enter production for shift #%d: ", shift+1);
            scanf("%d", &iceCreamProduction[i][shift]);
        }
    }

    //determine the ice cream with the highest production
    int maxProduction=0;
    int maxIceCreamIndex=0;
    for(int i=0; i<ICECREAMTYPES; ++i){
        int totalProduction = 0;
        for(int shift=0; shift<SHIFTS; ++shift){
            totalProduction+=iceCreamProduction[i][shift];
        }
        if(totalProduction>maxProduction){
            maxProduction=totalProduction;
            maxIceCreamIndex=i;
        }
    }
    printf("\nIce cream with highest production: %s \n", iceCreamNames[maxIceCreamIndex]);

    //determine the shift with highest production
    int maxShiftProduction=0;
    int maxShiftIndex=0;
    for(int shift=0; shift<SHIFTS; ++shift){
        int totalShiftProduction = 0;
        for(int i=0; i<ICECREAMTYPES; ++i){
            totalShiftProduction+=iceCreamProduction[i][shift];
        }
        if(totalShiftProduction>maxShiftProduction){
            maxShiftProduction=totalShiftProduction;
            maxShiftIndex=shift;
        }
    }
    printf("Shift with highest production: Shift #%d \n", maxShiftIndex+1);

    //find lowest production across all shifts
    int minProduction = iceCreamProduction[0][0];
    for(int i=0; i<ICECREAMTYPES; ++i) {
        for(int shift=0; shift<SHIFTS; ++shift){
            if (iceCreamProduction[i][shift]<minProduction){
                minProduction = iceCreamProduction[i][shift];
            }
        }
    }
    printf("Lowest production across all shifts: %d\n", minProduction);

    //display shifts and ice creams with lowest production
    printf("Shifts and ice creams with lowest production: \n");
    for(int i=0; i<ICECREAMTYPES; ++i){
        for(int shift=0; shift<SHIFTS; ++shift){
            if(iceCreamProduction[i][shift]==minProduction){
                printf("Shift #%d: %s\n", shift+1, iceCreamNames[i]);
            }
        }
    }

    return 0;
}
