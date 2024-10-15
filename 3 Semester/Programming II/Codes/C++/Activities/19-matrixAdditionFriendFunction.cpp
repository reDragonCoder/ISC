// Author: reDragonCoder
//Friend funtion for matrix addition

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//CLASSES
class Matrix{
    private:
        int mat[2][2];
    public:
        //empty constructor
        Matrix(){}

        void input(){
            cout<<"Enter 4 matrix elements: "<<endl;
            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++)
                    cin>>mat[i][j];
        }

        //friend function for matrix addition
        friend Matrix addMatrices(const Matrix& m1, const Matrix& m2);

        //method to display the matrix
        void display() const{
            cout<<"Matrix:"<<endl;
            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++)
                    cout<<mat[i][j]<<" ";
                cout<<endl;
            }
        }
};

//definition of friend function
Matrix addMatrices(const Matrix& m1, const Matrix& m2){
    Matrix result;
    for(int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            result.mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
    return result;
}

// MAIN
int main(){
    //variables
    Matrix m1, m2, sum;

    //input for the first matrix
    cout<<"Input for first matrix: "<<endl;
    m1.input();

    //input for the second matrix
    cout<<"Input for second matrix: "<<endl;
    m2.input();

    //calculate the sum of matrices
    sum=addMatrices(m1, m2);

    //display the result
    cout<<"Resultant Matrix after addition: "<<endl;
    sum.display();

    return 0;
}
