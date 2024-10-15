// Author: reDragonCoder
//ACTIVITY: USING CLASSES FOR A TRIANGLE 

//NOTE: INLINE IS TO DECLARE THE METHOD'S TASKS INSIDE THE CLASS INSTEAD OF OUTSIDE OF IT

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//CLASSES
class Triangle{
    private:
        float base, height, side1, side2, side3;
    public:
        //empty constructor
        Triangle(){
            cout<<endl<<"I'm the class constructor"<<endl;
        }

        //destructor
        ~Triangle(){
            cout<<endl<<"I'm the class destructor"<<endl;
        }

        //set methods
        float setBase(float base){
            this->base=base;
        }
        float setHeight(float height){
            this->height=height;
        }
        float setSide1(float side1){
            this->side1=side1;
        }
        float setSide2(float side2){
            this->side2=side2;
        }
        float setSide3(float side3){
            this->side3=side3;
        }

        //get methods
        float getBase(){
            return this->base;
        }
        float getHeight(){
            return this->height;
        }
        float getSide1(){
            return this->side1;
        }
        float getSide2(){
            return this->side2;
        }
        float getSide3(){
            return this->side3;
        }

        //other methods
        float calculateArea(){
            float area=0;
            area=(this->base*this->height)/2;
            return area;
        }
        float calculatePerimeter(){
            float perimeter=0;
            perimeter=this->side1+this->side2+this->side3;
            return perimeter;
        }
};

//MAIN
int main(){
    Triangle triangle;
    int op=0;
    float var=0;

    do{
        cout<<endl<<"----------MENU----------"<<endl;
        cout<<"1. Triangle area"<<endl;
        cout<<"2. Triangle perimeter"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<endl<<"Please select your option: ";
        cin>>op;
        switch(op){
            case 1:
                cout<<endl<<"OPTION 1: AREA"<<endl;
                cout<<"Please enter the base: ";
                cin>>var;
                triangle.setBase(var);
                cout<<"Please enter the height: ";
                cin>>var;
                triangle.setHeight(var);
                cout<<endl<<"Triangle"<<endl;
                cout<<"Base: "<<triangle.getBase()<<endl;
                cout<<"Height: "<<triangle.getHeight()<<endl;
                cout<<"Area: "<<triangle.calculateArea()<<endl;
                break;
            case 2:
                cout<<endl<<"OPTION 2: PERIMETER";
                cout<<endl<<"Please enter the side 1: ";
                cin>>var;
                triangle.setSide1(var);
                cout<<"Please enter the side 2: ";
                cin>>var;
                triangle.setSide2(var);
                cout<<"Please enter the side 3: ";
                cin>>var;
                triangle.setSide3(var);
                cout<<endl<<"Triangle"<<endl;
                cout<<"Side 1: "<<triangle.getSide1()<<endl;
                cout<<"Side 2: "<<triangle.getSide2()<<endl;
                cout<<"Side 3: "<<triangle.getSide3()<<endl;
                cout<<"Perimeter: "<<triangle.calculatePerimeter()<<endl;
                break;
        }   
    }while(op!=3);

    return 0;
}