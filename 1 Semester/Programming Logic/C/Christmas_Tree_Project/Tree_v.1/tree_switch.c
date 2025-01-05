// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include<stdlib.h>
#include<windows.h>

//COLOR PALETTE
#define CYAN "\x1b[36m"
#define PURPLE "\x1b[35m"
#define BLUE "\x1b[34m"
#define YELLOW "\x1b[33m"
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"

#define RESET "\x1b[0m"

//MAIN
int main(){
    system("cls");
    system("color 0F");

    //variables
    int height, tree_counter=0, space_counter=0, color_opt;

    //ask height
    printf("Star color menu: \n");
    printf("1) Yellow \n");
    printf("2) Cyan \n");
    printf("3) Red \n");
    printf("4) Blue \n");
    printf("5) Purple \n");
    printf("\nEnter the star color: ");
    scanf("%d", &color_opt);
    printf("Enter the tree height: ");
    scanf("%d", &height);

    printf("\n");

    //print tree
    for(int i=1; i<=height+1; i++){
        //calculates the number of "o"s that will be printed in the current row
        tree_counter=((i)*2)-1;
        //calculates the number of spaces that will be printed in the current row
        space_counter=height-i+1;
        //print spaces in current row
        for(int j=0; j<space_counter; j++){
            printf(" ");
        }
        //prints the first o of the row as a *
        if(i==1){
            switch(color_opt){
                case 1:
                    printf(YELLOW "*" RESET);
                break;
                case 2:
                    printf(CYAN "*" RESET);
                break;
                case 3:
                    printf(RED "*" RESET);
                break;
                case 4:
                    printf(BLUE "*" RESET);
                break;
                case 5:
                    printf(PURPLE "*" RESET);
                break;
            }
        }
        else{
        //print the "o's" in the current row
            for(int j=0; j<tree_counter; j++){
                printf(GREEN "o" RESET);
            }
        }
  
        printf("\n");
    }
    //print the trunk of the tree (always equal to 3)
    for(int i=0; i<3; i++){
        for(int j=0; j<height; j++){
            printf(" ");
        }
        printf(RED "*\n" RESET);
    }
    return 0;
}

