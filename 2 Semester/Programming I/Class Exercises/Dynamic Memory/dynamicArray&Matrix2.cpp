// Author: reDragonCoder
//dynamic memory

// int *vec=new int[TAM]; CREATES A VEC
// int *(ren)*(col)mat=new int*[REN];
/*for (int i=0; i<REN; i++){
   mat[i]=new in [COL]
}*/

//LIBRARIES
#include <iostream>
#include <stdlib.h>
#include <time.h>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANTS
#define SIZE 10
#define ROW 4
#define COL 3

//PROTOTYPES
void fill(float*, int**);
void show(float*, int**);

//MAIN
int main(){
    srand(time(NULL));
    //VARIABLES
    float *vec=new float[SIZE]; //declare the array
    int **mat=new int*[ROW]; //declare and initialize the pointer matrix
    for(int i=0; i<ROW; i++){ //create columns by row
        mat[i]=new int[COL];
    }
    fill(vec, mat);
    show(vec, mat);
    show(vec,mat);

    return 0;
}

//IMPLEMENTATIONS
void fill(float*vec, int**mat){
    for(int i=0; i<SIZE; i++){
        *(vec+i)=rand()%31; //vec[i]=rand()%31;
    }
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            *(*(mat+i)+j)=rand()%51; //mat[i][j]=rand()%51;
        }
    }
}

void show(float*vec, int**mat){
    for (int i=0; i<SIZE; i++) {
        cout<<*(vec+i)<<"\t";
        
    }
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            cout<<*(*(mat+i)+j)<<"\t";
        }
        cout<<endl;
    }
}

