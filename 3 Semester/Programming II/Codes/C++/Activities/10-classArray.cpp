// Author: reDragonCoder
//ACTIVITY: USING CLASSES FOR AN ARRAY 

//LIBRARIES
#include <iostream>
#include <time.h>
#include <cstdlib>

//NAMESPACE
using namespace std;

//CLASSES
class Array{
    private:
        int *v, size;
    public:
        //constructor with parameters
        Array(int size); //it receives the size of the array and it creates the dynamic array
        ~Array(); //use the delete function to erase the dynamic array

        //set methods for the *v atributes & size
        void fillRandom(); //fill the aray with random numbers 
        void print(); //print the array content
        int sumatory(); //it returns the sumatory inside the vector
        int smallest(); //it returns the smaller number in the array
        float average(); //it returns de array average
        
        //get methods
        int *getV(); //to get the array
        int getSize(); //to get the array size
}; //end of class

//METHODS
//constructor with parameters
Array::Array(int size){
  cout<<endl<<endl<<"I'm the class constructor with parameters"<<endl<<endl;
  this->size=size;
  this->v=new int[size];
}

//destructor
Array::~Array(){
  cout<<endl<<endl<<"I'm the class destructor"<<endl<<endl;
  delete[] v;
}

//functionality methods
void Array::fillRandom(){
  srand(time(NULL));
  for(int i=0; i<this->size; i++){
    this->v[i]=1+rand()%(100-1+1);
  }
}

void Array::print(){
  for(int i=0; i<this->size; i++){
    cout<<this->v[i]<<" ";
  }
}

int Array::sumatory(){
    int sumatory=0;
    for(int i=0; i<this->size; i++){
      sumatory+=this->v[i];
    }
    return sumatory;
}

int Array::smallest(){
    int smallest=0;
    smallest=this->v[0];
    for(int i=0; i<this->size; i++){
      if(this->v[i]<smallest){
        smallest=this->v[i];
      }
    }
    return smallest;
}

float Array::average(){
    float average=0, sumatory;
    sumatory=this->sumatory();
    average=sumatory/this->size;
    return average;
}

//get methods
int* Array::getV(){ 
  return this->v;
}

int Array::getSize(){
  return this->size;
}

//MAIN
int main(){
  //implementations for testing the class
  int n=0, sumatory=0, smallest=0;
  float average=0;

  //static object test
  cout<<endl<<"Please enter the size of the array: ";
  cin>>n;
  if(n<10 || n>30){
    while(n<10 || n>30){
      cout<<endl<<"Non-valid number, enter another size: ";
      cin>>n;
    }
  }
  Array staticArray(n);
  staticArray.fillRandom();
  staticArray.print();
  sumatory=staticArray.sumatory();
  cout<<endl<<"The sumatory of the values in the array is: "<<sumatory<<endl;
  smallest=staticArray.smallest();
  cout<<"The smallest number in the array is: "<<smallest<<endl;
  average=staticArray.average();
  cout<<"The average of the values in the array is: "<<average<<endl;


  cout<<endl<<"-----------------------------------------"<<endl;
  n=0;
  sumatory=0;
  smallest=0;
  average=0;

  //dynamic object test    
  cout<<"Please enter the size of the array: ";
  cin>>n;
  if(n<10 || n>30){
    while(n<10 || n>30){
      cout<<endl<<"Non-valid number, enter another size: ";
      cin>>n;
    }
  }
  Array *dynamicArray;
  dynamicArray=new Array(n);
  dynamicArray->fillRandom();
  dynamicArray->print();
  sumatory=dynamicArray->sumatory();
  cout<<endl<<"The sumatory of the values in the array is: "<<sumatory<<endl;
  smallest=dynamicArray->smallest();
  cout<<"The smallest number in the array is: "<<smallest<<endl;
  average=dynamicArray->average();
  cout<<"The average of the values in the array is: "<<average<<endl;
  delete dynamicArray;

  cout<<endl<<"-----------------------------------------"<<endl;
  n=0;
  sumatory=0;
  smallest=0;
  average=0;

  //get methods test
  cout<<"Please enter the size of the array: ";
  cin>>n;
  if(n<10 || n>30){
    while(n<10 || n>30){
      cout<<endl<<"Non-valid number, enter another size: ";
      cin>>n;
    }
  }
  Array arrayForGet(n);
  arrayForGet.fillRandom();
  arrayForGet.print();
  cout<<endl;
  int *aux;
  aux=arrayForGet.getV();
  int total=arrayForGet.getSize();
  for(int i=0; i<total; i++){
    cout<<aux[i]<<" ";
  }
  cout<<endl<<"The size of the array is: "<<total;
  delete[] aux;

  return 0;
}