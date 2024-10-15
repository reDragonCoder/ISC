// Author: reDragonCoder
//Static methods to obtain the cosine of two n-component arrays
//NOTE: static methods do not require an object to be called

//LIBRARIES
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

//NAMESPACE
using namespace std;

//CLASS
class Product{
    public:
        static void fill(int *v, int size);
        static void print(int *v, int size);
        static double scalarProduct(int *v1, int *v2, int size);
        static double norm(int *v, int size);
        static double cosine(double scalarProduct, double normv1, double normv2);
};

//METHODS
void Product::fill(int *v, int size){
    for(int i=0; i<size; i++){
        v[i]=10+rand()%(50-10+1);
    }
}

void Product::print(int *v, int size){
    for(int i=0; i<size; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

double Product::scalarProduct(int *v1, int *v2, int size){
    double scalarProduct=0.0;
    for(int i=0; i<size; i++){
        scalarProduct+=v1[i]*v2[i];
    }
    return scalarProduct;
}

double Product::norm(int *v, int size){
    double norm=0.0;
    for(int i=0; i<size; i++){
        norm+=v[i]*v[i];
    }
    return sqrt(norm);
}

double Product::cosine(double scalarProduct, double normv1, double normv2){
    double cosine;
    cosine=scalarProduct/(normv1*normv2);
    return cosine;
}

//MAIN
int main(){
    //random seed generator
    srand(time(0));

    //variables
    int vSize;
    double scalarProduct=0, normv1=0, normv2=0, cosine=0;

    //asking for the size
    cout<<"Enter the size of your arrays: ";
    cin>>vSize;

    //creating the dynamic arrays
    int *v1=new int[vSize];
    int *v2=new int[vSize];

    //using the static methods
    Product::fill(v1, vSize);
    Product::fill(v2, vSize);

    cout<<endl;
    Product::print(v1, vSize);
    Product::print(v2, vSize);
    cout<<endl;

    scalarProduct=Product::scalarProduct(v1, v2, vSize);
    cout<<"The scalar product of the two arrays is: "<<scalarProduct<<endl;

    normv1=Product::norm(v1, vSize);
    cout<<"The norm of the first array is: "<<normv1<<endl;
    normv2=Product::norm(v2, vSize);
    cout<<"The norm of the second array is: "<<normv2<<endl;

    cosine=Product::cosine(scalarProduct, normv1, normv2);
    cout<<"The cosine of the arrays is: "<<cosine<<endl;

    //freeing memory
    delete[] v1;
    delete[] v2;

    return 0;
}