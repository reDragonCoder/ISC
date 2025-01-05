// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <stdlib.h>
#include <time.h>

//NAMESPACE
using namespace std;

//PROTOTYPES
void print(int *v, int size);
int *gun(int n);
int *deck(int n);
int *array_union(int *v1, int n1, int *v2, int n2);

//MAIN
int main(){
    //VARIABLES
    int n, n1=8, n2=9;
    int *v;
    int vec1[n1]={2,4,12,9,2,15,4,2}, vec2[n2]={5,7,63,4,15,7,5,3,15};

    //initialize the function for random numbers
    srand(time(NULL));

    //GUN
    do{
        //ask vector size (n) for the gun
        cout<<"Enter the number of spaces your gun will have: ";
        cin>>n;
    }while(n<10);

    //call "gun" function 
    v=gun(n);
    print(v, n);
    delete[] v; //release memory occupied by the array 

    //DECK
    do{
        //ask vector size (n) for the deck
        cout<<"Enter the number of cards you want to receive: ";
        cin>>n; 
    }while(n<10);

    //call "deck" function
    v=deck(n);
    print(v, n);
    delete[] v; //release memory occupied by the array 

    //UNION
    v=array_union(vec1, n1, vec2, n2);
    n=n1+n2;
    cout<<"Arrays union: "<<endl;
    print(v, n);
    delete[] v;

    return 0;
}

//IMPLEMENTATIONS 
void print(int *v, int size){
    //loop through the received vector and print its data
    for(int i=0; i<size; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
}

int *gun(int n){
    //VARIABLES
    int *v=new int[n];
    int percentage=n*0.3;
    int temp_pos=0, ones=0;

    //initialize the array
    for(int i=0; i<n; i++){
        v[i]=0;
    }

    //filling positions (ones)
    while(ones<=percentage){
        temp_pos=rand()%n;
        if(v[temp_pos]!=1){ //evaluate if the position is already occupied
            v[temp_pos]=1;
            ones++;
        }
    }

    //return array
    return v;
}

int *deck(int n){
    //VARIABLES
    int *v=new int[n];
    bool repeated=false;

    //initialize the array
    for(int i=0; i<n; i++){
        v[i]=0;
    }

    //card dealing
    for(int i=0; i<n; i++){
        do{
            v[i]=rand()%n+1;
            repeated=false;
            for(int j=0; j<i; j++){
                if(v[i]==v[j]){
                    repeated=true;
                    break;
                }
            }
        }while(repeated==true);
    }
    
    //return array
    return v;
}

int *array_union(int *v1, int n1, int *v2, int n2){
    //VARIABLES
    int union_size=n1+n2;
    int *v=new int[union_size];
    int i=0;

    //initialize the array
    for(int i=0; i<union_size; i++){
        v[i]=0;
    }

    //array's union
    do{
        for(int j=0; j<n1; j++){
            v[i]=v1[j];
            i++;
        }
        for(int k=0; k<n2; k++){
            v[i]=v2[k];
            i++;
        }
    }while(i<union_size);
    
    //return array
    return v;
}