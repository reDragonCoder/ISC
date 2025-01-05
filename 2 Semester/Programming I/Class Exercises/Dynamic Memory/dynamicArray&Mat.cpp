// Author: reDragonCoder
//Array & Matrix with dynamic memory

//LIBRARIES
#include <iostream>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

//GLOBAL CONSTANTS
#define SIZE 10

//NAMESPACE
using namespace std;

//STRUCT
struct Data{
    char *phrase; //is the same as phrase[SIZE]
    float *gpa; //its the same as gpa[SIZE]
    int value;
};

//PROTOTYPES
void fillAges(int*);
void fillMat(float**);
int show(int*,float**);

//MAIN
int main(){
    srand(time(NULL));
    int *ages, values=0; //its the same as ages[SIZE]
    float **mat; //mat=matrix
    //dynamic memory
    ages=new int[SIZE]; //create an array
    mat=new float*[SIZE]; //create a matrix
    for(int i=0; i<SIZE; i++){
        mat[i]=new float[SIZE];
    }

    fillAges(ages);
    fillMat(mat);
    values=show(ages, mat);
    cout<<"\n"<<"Total: "<<values<<endl;

    return 0;
}

//IMPLEMENTATIONS
void fillAges(int *ages){
    //pointers arithmetic
    for(int i=0; i<SIZE; i++){
        *(ages+i)=rand()%10;
        //ages[i]=rand()%10;
    }
}

void fillMat(float **mat){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            *(*(mat+i)+j)=rand()%10;
            //mat[i][j]=rand()%10;
        }
    }
}

int show(int*ages,float**mat){
    int values=0;
    for(int i=0; i<SIZE; i++){
        cout<< *(ages+i)<<"\t";
        values++;
    }
    cout<<endl<<endl;
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout<<*(*(mat+i)+j)<<"\t";
            values++;
        }
    }
    return values;
}