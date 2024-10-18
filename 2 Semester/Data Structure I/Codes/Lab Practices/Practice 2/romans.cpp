// Author: reDragonCoder
//Build a program that captures a number and outputs the value of the number in Roman. Roman numbering uses capital 
//letters to which the numbers correspond following values ​​the highest possible value will be 3999, you can use strcat 
//(string.h) for its solution

//LIBRARIES
#include <stdio.h>
#include <string.h>

//STRUCT DECLARATION
struct roman {
    char letter[3];
    int number;
};

//MAIN
int main() {
    //VARIABLES
    struct roman values[] = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9},
                             {"V", 5}, {"IV", 4}, {"I", 1}};
    int val=0, i=0;
    char withLetter[30] = ""; 

    printf("Enter your arabic number: ");
    scanf("%d", &val);
    do{
        if(val>=values[i].number){
            strcat(withLetter, values[i].letter);
            val-=values[i].number;
        }else{
            i++;
        }
    }while(val>0);
    printf("Your roman number is: %s \n", withLetter);
    
    return 0;
}
