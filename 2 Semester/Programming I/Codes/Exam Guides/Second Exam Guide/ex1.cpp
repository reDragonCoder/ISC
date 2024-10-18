// Author: reDragonCoder
//Utilizando notación de punteros y memoria dinámica se necesita crear una matriz cuadrada, la cual se llenará de forma aleatoria y el sistema
//deberá validar si es un cuadrado mágico o no. Al finalizar la ejecución, el programa deberá realizar la liberación de la memoria.
//(se califica matrices dinámicas, notación de punteros y correcto funcionamiento del programa).
//NOTA: un cuadrado mágico es aquel que contiene una serie de números enteros de forma tal que la suma de cualquier fila, columna o diagonal
//es la misma.

//LIBRARIES
#include <iostream>
#include <stdlib.h>
#include <time.h>

//GLOBAL CONSTANTS
#define SIZE 3

//NAMESPACE
using namespace std;

//PROTOTYPES
void fillMat(int**);
void showMat(int **);
bool validateMagicCube(int **);
void freeMemory(int **);

//MAIN
int main(){
    srand(time(NULL));
    //create the matrix
    int **mat;
    mat=new int*[SIZE]; 
    for(int i=0; i<SIZE; i++){
        mat[i]=new int[SIZE];
    }
    //fill and show the matrix
    fillMat(mat);
    showMat(mat);
    //validate the magic cube
    if(validateMagicCube(mat)==true){
        cout<<"\nThe matrix is a magic cube \n";
    }else{
        cout<<"\nThe matrix is not a magic cube! \n";
    }
    //free memory
    freeMemory(mat);
    return 0;
}

//IMPLEMENTATIONS
void fillMat(int **mat){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            *(*(mat+i)+j)=rand()%10; //equal to mat[i][j]=rand%10;
        }
    }
}

void showMat(int **mat){
    cout<<"\n";
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout<<*(*(mat+i)+j)<<"  ";
        }
        cout<<"\n";
    }
}

bool validateMagicCube(int **mat){
    int rowAdd=0, auxRow=0, c=0, auxCol=0;
    int columnsAdd[SIZE]={0}, diagonalAdd[2]={0};
    bool rows=false, columns=false, diagonal=false;
    //rows validation
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            rowAdd+=mat[i][j];
        }
        if(i==0){
            auxRow=rowAdd;
            rowAdd=0;
        }else{
            if(rowAdd==auxRow){
                rows=true;
            }
        }
    }
    //columns validation
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            columnsAdd[c]+=mat[i][j];
            c++;
        }
        c=0;
    }
    for(int i=0; i<SIZE; i++){
        auxCol=columnsAdd[i];
        if(i>0 && columnsAdd[i++]!=auxCol){
            columns=false;
            break;
        }else{
            columns=true;
        }
    }
    //diagonal validation
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(i==j){ //principal diagonal
                diagonalAdd[0]+=mat[i][j];
            }
            if(i+j==SIZE-1){//secondary diagonal
                diagonalAdd[1]+=mat[i][j];
            }
        }
    }
    for(int i=0; i<2; i++){
        if(diagonalAdd[0]==diagonalAdd[1]){
            diagonal=true;
        }else{
            diagonal=false;
        }
    }
    //return validation
    if(rows==true && columns==true && diagonal==true){
        return true;
    }else{
        return false;
    }
}

void freeMemory(int **mat){
    for(int i=0; i<SIZE; i++){
        delete[]mat[i];
    }
    delete[]mat;
}


