// Author: reDragonCoder
//Punteros a estructuras

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCT DECLARATION
struct Data{
    int id;
    double gpa;
    char group;
};

int main(){
    //VARIABLES
    Data *student=new Data[3], *ptr=&*student; //when you declare *ptr in the declaration, you SHOULD use & (not in the arrays)

    cout<<"Id: ";
    cin>>ptr->id;  //student.id;
    cout<<"GPA: ";
    cin>>ptr->gpa; //student.gpa;
    ptr->group='C'; //student.group='C';
    cout<<ptr->id<<"\t"<<ptr->gpa<<"\t"<<ptr->group<<endl;

    return 0;
}