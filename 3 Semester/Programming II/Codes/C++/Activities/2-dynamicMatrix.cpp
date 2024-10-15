// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <stdlib.h>
#include <time.h>

//NAMESPACE
using namespace std;

//CONSTANTS
#define ROW1 3
#define COL1 3
#define ROW2 3
#define COL2 2

//PROTOTYPES
void print(int **mat, int row, int col);
int **board(int n);
int **bakery(int mat1[ROW1][COL1], int mat2[ROW2][COL2]);   

//MAIN
int main(){
    //VARIABLES
    int n=0;
    int **mat;
    int mat1[ROW1][COL1]={5,7,1,
                          11,9,4,
                          3,14,8};
    int mat2[ROW2][COL2]={12,6,
                          4,5,
                          8,3};
    bool valid=false;

    //initialize the function for random numbers
    srand(time(NULL));

    //MEMORY GAME BOARD 
    do{ 
        //ask vector size (n) for the board
        cout<<"Enter the desire size of your board: ";
        cin>>n;
        if(n>1){
            if(n%2==0){
                valid=true;
            }else{
                valid=false;
            }
        }else{
            valid=false;
        }
    }while(valid==false);

    //call "board" function 
    mat=board(n);
    print(mat, n, n);
    //release memory occupied by the matrix 
    for(int i=0; i<n; i++){
        delete[]mat[i];
    }
    delete[] mat; 
    cout<<endl;

    //BAKERY
    //Note: (3x3)(3x2)=3x2 & 3=3 so it's ok
    cout<<"Bakery info: "<<endl;
    //evaluate if the multiplication is possible
    if(COL1==ROW2){
        mat=bakery(mat1, mat2);
        print(mat, ROW1, COL2);
        //release memory occupied by the matrix 
        for(int i=0; i<n; i++){
            delete[]mat[i];
        }
        delete[] mat;
    }else{
        cout<<"The multiplication is not valid, try again"<<endl;
    }

    return 0;
}

//IMPLEMENTATIONS
void print(int **mat, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int **board(int n){
    //VARIABLES
    int **mat=new int*[n];
    int total=n*n/2;
    int total2=total*2;
    int *aux=new int[total2]; //It is good practice to use dynamic memory for the array if it is used for the matrix within the same function
    int auxCounter=0, totalCounter=0, auxNum=1, auxPos=0;
    int temp_pos=0;

    //column creation
    for(int i=0; i<n; i++){
        mat[i]=new int[n];
    }

    //initialize the matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mat[i][j]=0;
        }
    }

    //initialize the auxiliar array
    for(int i=0; i<total2; i++){
        aux[i]=0;
    }

    //filling the auxiliar array with the desired numbers
    do{
        aux[auxPos]=auxNum;
        auxPos++;
        auxCounter++;
        if(auxCounter==2){
            auxNum++;
            auxCounter=0;
        }
        totalCounter++;
    }while(totalCounter<total2);

    //filling the board with the array numbers
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            do{
                temp_pos=rand()%total2;
            }while(aux[temp_pos]==0);

            mat[i][j]=aux[temp_pos];
            aux[temp_pos]=0;
        }     
    }

    //release memory occupied by the array 
    delete[] aux;

    //return matrix
    return mat;
}

int **bakery(int mat1[ROW1][COL1], int mat2[ROW2][COL2]){
    //VARIABLES
    int n=ROW1, m=COL2;
    int sum=0;
    int **mat=new int*[n];

    //column creation
    for(int i=0; i<n; i++){
        mat[i]=new int[m];
    }

    //initialize the matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mat[i][j]=0;
        }
    }

    //filling the matrix with the resultant multiplications
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            sum=0;
            for(int k=0; k<COL1; k++){
                sum+=mat1[i][k]*mat2[k][j]; 
            }
            mat[i][j]=sum;
        }
    }

    //return matrix
    return mat;
}