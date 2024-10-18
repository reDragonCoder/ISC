// Author: reDragonCoder
//fputc - fgetc

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//PROTOTYPES
void capture(FILE*);
void show(FILE*);

//MAIN
int main(){
    FILE *fileL=NULL;
    capture(fileL);
    show(fileL);
}

//IMPLEMENTATIONS
void capture(FILE *fileL){
    char letter;
    //open file
    fileL=fopen("letters.txt", "w");
    if(fileL==NULL){
        cout<<"Error type: open/create file! \n";
        exit(1);
    }
    cout<<"Character capture: \n";
    while(letter!='.'){ //with the while is going to save the '.'
        letter=getchar();
        fputc(letter, fileL);
    }
    fclose(fileL); //it's important to close the file beacuse otherwise is not going to save correctly
}

void show(FILE *fileL){
    char letter;
    int tot=0;
    fileL=fopen("letters.txt", "r"); //it will overwrite everytime it opens
    if (fileL==NULL) {
        cout<<"There appears to have been an error while opening/creating your file";
        exit (1);
    }
    while (!feof(fileL)) {
        letter=fgetc(fileL);
        tot++;
        cout<<letter;
    }
    fclose(fileL);
}