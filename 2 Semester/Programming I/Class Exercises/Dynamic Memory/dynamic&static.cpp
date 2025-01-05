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
    char *phrase; //is the same as phrase[SIZE]
    float *gpa; //its the same as gpa[SIZE]
    int value;
};

//PROTOTYPES
void showData(Data);
void showData2(Data*);

//MAIN
int main(){
    Data staticData, *dynamicData;

    //static data
    staticData.phrase=new char[15];
    staticData.gpa=new float[5];
    
    staticData.value=30;
    strcpy(staticData.phrase, "hola mundo");
    for(int i=0; i<5; i++){
        staticData.gpa[i]=i*3;
    }

    showData(staticData);

    //dynamic data
    dynamicData=new Data;
    dynamicData->phrase=new char[15];
    dynamicData->gpa=new float[5];

    dynamicData->value=1;
    strcpy(dynamicData->phrase, "hola mundo");
    for(int i=0; i<5; i++){
        dynamicData->gpa[i]=i*3;
    }

    showData2(dynamicData);


    return 0;
}

//IMPLEMENTATIONS
void showData(Data staticData){
    cout<<staticData.phrase<<endl;
    cout<<staticData.value<<endl;
    for(int i=0; i<5; i++){
        cout<<staticData.gpa[i]<<"\t";
    }
}

void showData2(Data *dynamicData){
    cout<<dynamicData->phrase<<endl;
    cout<<dynamicData->value<<endl;
    for(int i=0; i<5; i++){
        cout<<dynamicData->gpa[i]<<"\t";
    }
}