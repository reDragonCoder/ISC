// Author: reDragonCoder
//ASSIGNMENT OPERATOR OVERLOAD

//LIBRARIES
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

//NAMESPACE
using namespace std;

//CLASS
class Matrix{
    private:
        int r, c, **mat;
    public:
        //constructors
        Matrix(){}
        
        Matrix(int r, int c){
            this->r=r;
            this->c=c;
            this->mat=new int*[r];
            for(int i=0; i<r; i++){
                mat[i]=new int[c];
                for(int j=0; j<c; j++){
                    mat[i][j]=0;
                }
            }
        }

        Matrix(const Matrix &obj){
            cout<<"*Entering to copy constructor*"<<endl;
            this->r=obj.r;
            this->c=obj.c;
            this->mat=new int*[obj.r];
            for(int i=0; i<obj.r; i++){
                mat[i]=new int[obj.c];
                for(int j=0; j<c; j++){
                    this->mat[i][j]=obj.mat[i][j];
                }
            }
        }

        //destructor
        ~Matrix(){
            for(int i=0; i<this->r; i++){
                delete[] mat[i];
            }
            delete[] mat;
        }

        //set methods
        void setRow(int r){this->r=r;}

        void setColumn(int c){this->c=c;}

        void setMat(int **mat){this->mat=mat;}

        //get methods
        int getRow(){return this->r;}

        int getCol(){return this->c;}

        int** getMat(){return this->mat;}

        //other methods
        void fill(){
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    this->mat[i][j]=10+rand()%90;
                }
            }
        }

        void print(){
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    cout<<setw(5)<<this->mat[i][j];
                }
                cout<<endl;
            }
            cout<<endl;
        }

        //operators overload
        Matrix& operator=(const Matrix &tempMat){
            cout<<"*Entering to = operator*"<<endl;
            if(this!=&tempMat){
                this->r=tempMat.r;
                this->c=tempMat.c;
                this->mat=new int*[this->r];
                for(int i=0; i<r; i++){
                    mat[i]=new int[this->c];
                    for(int j=0; j<c; j++){
                        mat[i][j]=tempMat.mat[i][j];
                    }
                }
            }else
                cout<<endl<<"Autoassignment attempt error"<<endl;
            return *this; //for cascade utility
        }

        Matrix operator+(const Matrix &tempMat) const{
            cout<<"*Entering to + operator*"<<endl;
            Matrix temp(this->r, this->c);
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    temp.mat[i][j]=this->mat[i][j]+tempMat.mat[i][j];
                }
            }
            return temp;
        }
};

//MAIN
int main(){
    srand(time(0));

    int r=0, c=0;

    while(r<2){
        cout<<"Enter the number of rows: ";
        cin>>r;
        if(r<2){
            cout<<"Error: enter a value equal or greater than 2"<<endl;
        }
    }
    while(c<2){
        cout<<"Enter the number of columns: ";
        cin>>c;
        if(c<2){
            cout<<"Error: enter a value equal or greater than 2"<<endl;
        }
    }

    cout<<endl;

    cout<<"Filling and printing m1..."<<endl;
    Matrix m1(r, c);
    m1.fill();
    cout<<"Matrix #1: "<<endl;
    m1.print();

    cout<<"************************************************************"<<endl<<endl;

    cout<<"Copying m3=m1..."<<endl;
    Matrix m3;
    m3=m1;
    cout<<"Matrix #3: "<<endl;
    m3.print();

    cout<<"************************************************************"<<endl<<endl; 

    cout<<"Filling and printing m1 again and printing m3 again..."<<endl;
    m1.fill(); 
    cout<<"Matrix #1: "<<endl;
    m1.print();
    cout<<"Matrix #3: "<<endl;
    m3.print(); 

    cout<<"************************************************************"<<endl<<endl;

    cout<<"Using the copy constructor to copy m3 to m4..."<<endl;
    Matrix m4(m3);
    cout<<"Matrix #4: "<<endl;
    m4.print();

    cout<<"************************************************************"<<endl<<endl;

    cout<<"Adding m5=m3+m4 if rows & columns are the same in each matrix, then printing m5..."<<endl;
    if(m3.getRow()==m4.getRow() && m3.getCol()==m4.getCol()){
        Matrix m5=m3+m4;
        cout<<"Matrix #5: "<<endl;
        m5.print();
    }else
        cout<<endl<<"Invalid matrix sum";
    
    cout<<"************************************************************"<<endl<<endl;

    cout<<"Using cascade method with m3=m4=m6..."<<endl;
    Matrix m6(10, 10);
    m6.fill();
    m3=m4=m6;
    cout<<"Matrix #3: "<<endl;
    m3.print();
    cout<<"Matrix #4: "<<endl;
    m4.print();
    cout<<"Matrix #6: "<<endl;
    m6.print();

    return 0;
}