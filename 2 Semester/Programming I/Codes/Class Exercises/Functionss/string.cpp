// Author: reDragonCoder
//Simulate the operation of the instructions: strlen, strcpy, strcat, strrev, strcmp

//LIBRARIES
#include <stdio.h>
#include <iostream>

//GLOBAL CONSTANTS
const int MAX=50;

//PROTOTYPES                                         //Callback
void menu();                                         //menu();
void chainClean(char[]);                            //cleanChain(chain);
void chainCapture(char[]);                         //captureChain(chain);
int chainLength(char[]);                          //size=length(chain);
void chainCopy(char[], char[]);                  //chainCopy(chainDest, chainOrg);
bool chainCompare(char[], char[]);              //compare(chainOrg, chainDest);
void chainUnite(char[], char[], char[]);               //chainUnite(org,aux,chain)
void chainReverse(char[]);                    //chainReverse(chainOrg);

//MAIN
int main(){
    //CALLBACK
    menu();
    
    return 0;
}

//IMPLEMENTATIONS
void menu(){
    int option=0, size=0;
    char chain[MAX], chainOrg[MAX], chainDest[MAX];
    do{
        printf("\n");
        printf("OPTIONS \n");
        printf("1.... Length \n");
        printf("2.... Copy \n");
        printf("3.... Compare \n");
        printf("4.... Unite \n");
        printf("5.... Reverse \n");
        printf("6.... Exit \n");
        printf("Select one option: ");
        scanf("%d", &option);
        switch(option){
            case 1: //length
                size=0;
                chainClean(chain);
                chainCapture(chain);
                size=chainLength(chain);
                printf("\n");
                printf("The length of your chain: %d \n", size);
                break;
            case 2: //copy
                chainClean(chainOrg);
                chainClean(chainDest);
                chainCapture(chainOrg);
                chainCopy(chainOrg, chainDest);
                printf("\n");
                printf("Destination chain: %s \n", chainDest);
                break;
            case 3: //compare
                chainClean(chainOrg);
                chainClean(chainDest);
                chainCapture(chainOrg);
                chainCapture(chainDest);
                if(chainCompare(chainOrg, chainDest)==0){
                    printf("\n");
                    printf("Equal chains \n");
                }else{
                    printf("\n");
                    printf("Different chains \n");
                }
                break;
            case 4: //unite
                chainClean(chain);
                chainClean(chainOrg);
                chainClean(chainDest);
                chainCapture(chainOrg);
                fflush(stdin);
                chainCapture(chain);
                fflush(stdin);
                chainUnite(chainOrg, chain, chainDest);
                printf("\n");
                printf("Your final chain is: %s \n", chainDest);
                break;
            case 5: //reverse
                chainClean(chainOrg);
                chainCapture(chainOrg);
                chainReverse(chainOrg);
                break;
            default:
                break;
        }
    }while(option!=6);
}

int chainLength(char chain[]){
    int counter=0;
    for(int i=0; chain[i]!='\0'; i++){
        counter++;
    }
    return counter++;
}

void chainCopy(char chainOrg[], char chainDest[]){
    for(int i=0; chainOrg[i]!='\0'; i++){
        chainDest[i]=chainOrg[i];
    }
}

bool chainCompare(char chainA[], char chainB[]){
    bool different=false;
    for(int i=0; chainA[i]!='\0'; i++){
        if(chainA[i]==chainB[i]){
            continue;
        }
        else{
            different=true;
            break;
        }
    }
    return different;
}

void chainUnite(char chainOrg[], char chain[], char chainDest[]){
    int j=0;
    for(int i=0; chainOrg[i]!=('\0'); i++){
        chainDest[i]=chainOrg[i];
        j++;
    }
    int i=0;
    j++;
    for(int k=(j-1); chain[i]!=('\0'); k++){
        chainDest[k]=chain[i];
        i++;
    }
    j+=2;
    chainDest[(j+1)]='\0';
}

void chainReverse(char chainOrg[]){
    int size=0, i=0, j=0;
    char aux[MAX];
    chainClean(aux);
    size=chainLength(chainOrg);
    for (i=(size-1); i>=0; i--){
        aux[j]=chainOrg[i];
        j++;
    }
    printf("\n");
    printf("The reverse string is: %s\n", aux);
}

void chainClean(char chain[]){
    for (int i=0; i<MAX; i++) {
        chain[i]=0;
    }
}

void chainCapture(char chain[]){
    printf("String value: ");
    fflush(stdin);
    gets(chain);
}

