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
    Data *example=new Data; //dynamic
    fill(example);
    show(example);
    return 0;
}

//IMPLEMENTATIONS
void fill(Data *example){ 
    example->phrase=new char[10];
    strcpy(example->phrase, "Thursday");
    example->gpa=new float[3];
    for(int i=0; i<3; i++){
        example->gpa[i]=4.5*i;
    }
    example->value=8;
}

void show(Data *example){
    cout<<"Phrase: "<<example->phrase<<endl;
    cout<<"GPA: "<<endl;
    for(int i=0; i<3; i++){
        cout<<example->gpa[i]<<"\t";
    }
    cout<<endl;
    cout<<example->value<<endl;
}
