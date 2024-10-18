// Author: reDragonCoder
//fputs - fgets

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//PROTOTYPES
void capture(FILE*);
void show(FILE*);

//MAIN
int main(){
    FILE *fileP=NULL;
    capture(fileP);
    show(fileP);
}

void capture(FILE*fileP){
    char *word=new char[30]; //it is not necessary to be dynamic
    int answ=0;
    fileP=fopen("words.txt", "a");
    if(fileP==NULL){
        cout<<"Error type: open/create file! \n";
        exit(1);
    }
    do{
        cout<<"Word: ";
        cin>>word;
        fputs(word, fileP);
        cout<<"Another one? y=1/n=0: ";
        cin>>answ;
        fflush(stdin);
    }while(answ!=0);
    fclose(fileP);
    delete word;
}

void show(FILE*fileP){
    char word[30];
    fileP=fopen("words.txt", "r");
    if(fileP==NULL){
        cout<<"Error type: open/create file! \n";
        exit(1);
    }
    while(!feof(fileP)){
        fgets(word,30,fileP);
        cout<<word<<endl;
    }
    fclose(fileP);
}