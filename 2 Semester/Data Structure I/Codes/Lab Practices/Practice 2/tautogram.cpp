// Author: reDragonCoder
//Write a program that determines whether the inserted strings are tautograms or not. Each case of test is a string 
//containing a statement. A sentence consists of a sequence of at most 50 words separated by spaces. A word is a sequence 
//of no more than 20 contiguous characters of the English alphabet. A word consists of at least one letter and one sentence 
//contains at least one word. The program stops evaluating strings when inserting *.

//LIBRARIES
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//GLOBAL CONSTANT
#define SIZE 10000

//PROTOTYPE
int isTauto(char[]);

//MAIN
int main(){
    //VARIABLES
    char string[SIZE];
    int string_size=0, spaces=0, letters=0, result=0;

    printf("Enter your sentences: \n");
    while(1){
        fgets(string, sizeof(string), stdin);
        if(strchr(string, '*')!=NULL){
            break;
        }else{
            string_size=strlen(string);
            for(int i=0; i<string_size; i++){
                if(isblank(string[i])){
                    spaces++;
                }
            }
            if(spaces+1>50){
                printf("There are more than 50 words in the sentence");
                return 0;
            }
            else{
                for(int i=0; i<string_size; i++){
                    if(!isblank(string[i])){
                        letters++;
                        continue;
                    }else{
                        if(letters>20){
                            printf("You have a word with more than 20 letters");
                            return 0;
                        }else{
                            letters=0;
                            continue;
                        }
                    }
                }
                result=isTauto(string);
                if(result==1){
                    printf("Yes \n");
                }else{
                    printf("No \n");
                }
            }
        }
    }
    return 0;
}

//IMPLEMENTATIONS
int isTauto(char string[]){
    int size=strlen(string);
    char aux=tolower(string[0]);
    for(int i=0; i<size; i++){
        string[i]=tolower(string[i]);
    }
    for(int i=0; i<size; i++){
        if(isblank(string[i])){
            i++;
            if(string[i]==aux){
                continue;
            }else{
                return 0;
            }
        } 
    }
    return 1;
}