// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

//NAMESPACE
using namespace std;

//STRUCT
struct Data{
    char *phrase; 
    float *gpa; 
    int value;
};

//PROTOTYPES
void fill(Data*);
void show(Data*);

//MAIN
int main(){
    Data *example=new Data[3]; //dynamic
    fill(example);
    show(example);
    return 0;
}

//IMPLEMENTATIONS
void fill(Data *example){ 
    for(int i=0; i<3; i++){
        example[i].phrase=new char[10];
        strcpy(example[i].phrase, "Thursday");
        example[i].gpa=new float[3];
        for(int j=0; j<3; j++){
            example[i].gpa[j]=4.5*j;
        }
        example[i].value=8;
    }
}

void show(Data *example){
    for(int i=0; i<3; i++){
        cout<<"Phrase: "<<example[i].phrase<<endl;
        cout<<"GPA: "<<endl;
        for(int j=0; j<3; j++){
            cout<<example[i].gpa[j]<<"\t";
        }
        cout<<endl;
        cout<<example[i].value<<endl;
    }
}

//The arrays by itself makes memory, so you need to use . instead of ->
