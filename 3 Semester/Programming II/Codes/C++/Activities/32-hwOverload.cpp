// Author: reDragonCoder
//stream extraction and insertion operator overload >> << and operator[] overload

//LIBRARIES
#include <iostream>
#include <ctime>
#include <cstdlib>

//NAMESPACE
using namespace std;

//CLASS
class Numbers{
	private:
		int *x;
		int size;

	public:
		Numbers(){}

		Numbers(int size){
			this->size=size;
			this->x=new int[size];
		}
		
		int getSize(){return this->size;}
		
		void print(){
			cout<<endl<<"Array size: "<<this->size;
			cout<<endl;
			for(int i=0; i<size; i++){
				cout<<this->x[i]<<" ";
			}
			cout<<endl;
		}
		
		void changeValue(int index){
			this->x[index]=9999;
		}
		
		void fill(){
			for(int i=0; i<this->size; i++){
				this->x[i]=10+rand()%39;
			}
		}
		
		Numbers &operator=(const Numbers &c){
			cout<<"\n*Entering to = operator*"<<endl;
			//verify that it is not a self-assignment
			if(this!=&c){
				this->size=c.size;
				this->x=new int[size];
				for(int i=0; i<this->size; i++){
					this->x[i]=c.x[i];
				}
			}else
				cout<<endl<<"Autoassignment attempt error"<<endl;
			return *this; //cascade
		}
		/*We must take into account the possibility of assigning an object to itself.
		That's why we compare the this pointer with the address of the parameter,
		If they are the same, it is the same object, and we should not do anything.
		This is one of the situations where the this pointer is essential*/

		friend ostream &operator<<(ostream &, Numbers&);
		friend istream &operator>>(istream &, Numbers&);

		int &operator[](int index){
			cout<<"\n*Entering to [] operator*"<<endl;
			return this->x[index];
		}

		void operator--(int z){
			cout<<"\n*Entering to -- operator*"<<endl;
			for(int i=0; i<this->size; i++){
				x[i]--;
			}
		}
};

//friend functions
ostream &operator<<(ostream &out, Numbers &obj){
	cout<<"\n*Entering to << operator*"<<endl;
	out<<endl<<"Array size: "<<obj.getSize()<<endl;
	for(int i=0; i<obj.getSize(); i++){
		out<<obj.x[i]<<" ";
	}
	out<<endl;
	return out; //for cascade
}

istream &operator>>(istream &in, Numbers&obj){
	cout<<"\n*Entering to >> operator*"<<endl;
	for(int i=0; i<obj.getSize(); i++){
		cout<<"Enter the value in the "<<i+1<<" position: ";
		in>>obj.x[i];
	}
	return in; //for cascade
}

//MAIN
int main(){
	srand(time(0));

	cout<<"Filling and printing obj1 and obj2...";
	Numbers obj1(10),obj2(5);

	obj1.fill();
	cout<<endl<<"\nPrinting obj1";obj1.print();

	obj2.fill();
	cout<<endl<<"\nPrinting obj2";obj2.print();

	cout<<endl<<"************************************************************"<<endl<<endl;

	cout<<"Printing obj1, then printing in cascade obj1 and obj2..."<<endl;
	cout<<endl<<"Printing obj1";
	cout<<obj1;

	cout<<endl<<"Printing in cascade obj1<<obj2";
	cout<<obj1<<obj2;

	cout<<"************************************************************"<<endl<<endl;

	cout<<"Using >> and << with one object, then using >> and << in cascade..."<<endl;
	Numbers obj3(4), obj4(5), obj5(3);
	cout<<"Obtaining and printing obj3"<<endl;
	cin>>obj3;
	cout<<obj3;

	cout<<endl<<"Obtaining and printing obj4 and obj5 in cascade..."<<endl;
	cin>>obj4>>obj5;
	cout<<obj4<<obj5;
	
	cout<<"************************************************************"<<endl<<endl;

	cout<<endl<<"Printing obj3 using [] overload"<<endl;
	for(int i=0; i<obj3.getSize(); i++)
		cout<<obj3[i]<<" "; //printing the position i of the vector that is inside obj3
	cout<<endl;

	cout<<"************************************************************"<<endl<<endl;

	cout<<endl<<"Decreasing in 1 each value of obj3..."<<endl;
	obj3--;
	cout<<obj3;

	return 0;
}
