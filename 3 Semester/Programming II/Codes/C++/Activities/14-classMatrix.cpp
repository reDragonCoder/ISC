// Author: reDragonCoder
//HOMEWORK - CLASS MATRIX

//LIBRARIES
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

//NAMESPACE
using namespace std;

//CLASSES
class Matrix{
    private:
        int **m;
        int r, c;
    public:
        Matrix(int r, int c); 
        ~Matrix();
        void fill();
        void print();
        void rowSum();
        void columnSum();
        void multiples(int n);
};

//METHODS
Matrix::Matrix(int r, int c){
    cout<<endl<<endl<<"I'm the class constructor with parameters"<<endl<<endl;
    this->r=r;
    this->c=c;
    this->m=new int*[r];
    for(int i=0; i<r; i++){
        m[i]=new int[c];
    }
}

Matrix::~Matrix(){
    cout<<endl<<endl<<"I'm the class destructor"<<endl<<endl;
    for(int i=0; i<this->r; i++){
        delete[] m[i];
    }
    delete[] m;
}

void Matrix::fill(){
    srand(time(NULL));
    for(int i=0; i<this->r; i++){
        for(int j=0; j<this->c; j++){
            this->m[i][j]=1+rand()%(1000-1+1);
        }
    }
}

void Matrix::print(){
    for(int i=0; i<this->r; i++){
        for(int j=0; j<this->c; j++){
            cout<<setw(5)<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Matrix::rowSum(){
    unsigned int rowSum=0;
    for(int i=0; i<this->r; i++){
        rowSum=0;
        for(int j=0; j<this->c; j++){
            rowSum+=m[i][j];
        }
        cout<<"The summatory of the "<<i+1<<" row is: "<<rowSum<<endl;
    }
    cout<<endl;
}

void Matrix::columnSum(){
    unsigned int colSum=0;
    for(int i=0; i<this->r; i++){
        colSum=0;
        for(int j=0; j<this->c; j++){
            colSum+=m[j][i];
        }
        cout<<"The summatory of the "<<i+1<<" column is: "<<colSum<<endl;
    }
    cout<<endl;
}

void Matrix::multiples(int n){
    int counter=0;
    for(int i=0; i<this->r; i++){
        for(int j=0; j<this->c; j++){
            if(m[i][j]%n==0){
                cout<<m[i][j]<<" is multiple of the number "<<n<<endl;
                counter++;
            }
        }
    }
    cout<<"The total multiples of "<<n<<" in the matrix is: "<<counter;
}

//MAIN
int main(){
    //variables
    int r, c, n;
    
    //static object test
    {
    cout<<"---Static Object Test---"<<endl;
    cout<<endl<<"Enter the number of rows in your matrix: ";
    cin>>r;
    if(r<2){
        while(r<2){
            cout<<endl<<"Enter a valid number of rows: ";
            cin>>r;
        }
    }
    cout<<"Enter the number of columns in your matrix: ";
    cin>>c;
    if(c<2){
        while(c<2){
            cout<<endl<<"Enter a valid number of columns: ";
            cin>>c;
        }
    }
    Matrix staticMatrix(r, c);
    staticMatrix.fill();
    staticMatrix.print();
    staticMatrix.rowSum();
    staticMatrix.columnSum();
    cout<<"Enter the number of which you want to search for multiples: ";
    cin>>n;
    staticMatrix.multiples(n);
    }

    cout<<endl<<"*************************************************"<<endl;

    //dynamic object test
    cout<<"---Dynamic Object Test---"<<endl;
    cout<<endl<<"Enter the number of rows in your matrix: ";
    cin>>r;
    if(r<2){
        while(r<2){
            cout<<endl<<"Enter a valid number of rows: ";
            cin>>r;
        }
    }
    cout<<"Enter the number of columns in your matrix: ";
    cin>>c;
    if(c<2){
        while(c<2){
            cout<<endl<<"Enter a valid number of columns: ";
            cin>>c;
        }
    }
    Matrix *dynamicMatrix;
    dynamicMatrix=new Matrix(r, c);
    dynamicMatrix->fill();
    dynamicMatrix->print();
    dynamicMatrix->rowSum();
    dynamicMatrix->columnSum();
    cout<<"Enter the number of which you want to search for multiples: ";
    cin>>n;
    dynamicMatrix->multiples(n);

    delete dynamicMatrix;

    cout<<endl<<"*************************************************"<<endl;

    //matrix vector (hyper dynamic)
    cout<<"---Matrix Vector Test---"<<endl;
    Matrix **matArray;
    matArray=new Matrix*[3];
    for(int i=0; i<3; i++){
        {
        cout<<endl<<endl<<"Enter the number of rows in your matrix: ";
        cin>>r;
        if(r<2){
            while(r<2){
                cout<<"Enter a valid number of rows: ";
                cin>>r;
            }
        }
        cout<<"Enter the number of columns in your matrix: ";
        cin>>c;
        if(c<2){
            while(c<2){
                cout<<"Enter a valid number of columns: ";
                cin>>c;
            }
        }
        matArray[i]=new Matrix(r, c);
        matArray[i]->fill();
        matArray[i]->print();
        matArray[i]->rowSum();
        matArray[i]->columnSum();
        cout<<endl<<"Enter the number of which you want to search for multiples: ";
        cin>>n;
        matArray[i]->multiples(n);
        }
    }
    for(int i=0; i<r; i++){
        delete[] matArray[i];
    }
    delete[] matArray;
    
    return 0;
}