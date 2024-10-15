// Author: reDragonCoder
//A class declares its friendship to a function

//LIBRARIES
#include <iostream>
#include <conio.h>

//NAMESPACE
using namespace std;

//CLASS
class MyClass{
    private:
        int n, d;
    public:
        MyClass(int i, int j){
            n=i;
            d=j;
        }
        //MyClass friend function declaration
        friend int isFactor(MyClass obj);
};

//FUNCTION
int isFactor(MyClass obj){
    if(!(obj.n%obj.d))
        return 1;
    else
        return 0;
}

//MAIN
int main(){
    //variables
    MyClass obj1(10, 2), obj2(13, 3);

    if(isFactor(obj1))
        cout<<"2 is a factor of 10 \n";
    else    
        cout<<"2 is not a factor of 10 \n";
    if(isFactor(obj2))
        cout<<"3 is a factor of 13 \n";
    else    
        cout<<"3 is not a factor of 13 \n";
    char ch=getch();
    
    return 0;
}