//AUTOR: GSP ******************************************

/*APRENDER QUE CUANDO NO COLOCAMOS
NINGUN CONSTRUCTOR NI SOBRECARGA DE
OPERADORES, contamos de regalo o por
default con la sobrecarga de
operador de asignacion, siempre y cuando
en los atributos de la clase NO existan
punteros la asignacion entre objetos funciona*/ 
 

#include <iostream>
using namespace std;
class Coordenada{
	private:
		int x, y;

	public:
	 						
		int getX(){return this->x;}
		int getY(){return this->y;}
		void setX(int x){
			this->x=x;
		}
		void setY(int y){
			this->y=y;
		}
};

 
int main()
{

//AQUI VEMOS uso de funcion operator= IMPLICITO
cout<<endl<<endl<<"EJEMPLO#1***********************\n";
cout<<endl<<"Coordenada obj1; obj1.setX(3); obj1.setY(7); Coordenada otro = obj1; \n";
Coordenada obj1;
obj1.setX(3);
obj1.setY(7);
Coordenada otro;
otro = obj1;  // equivale otro.operator=(obj1)
cout<<endl<<"Direcciones de memoria de objeto otro y obj1";
cout<<endl<<&otro<<"<---otro";
cout<<endl<<&obj1<<"<---obj1\n";
cout<<endl<<"Llamadas a metodos get de objeto otro y obj1";
cout<<endl<<otro.getX()<<"<---otro.getX()";
cout<<endl<<obj1.getX()<<"<---obj1.getX()\n";
obj1.setX(5);
cout<<endl<<obj1.getX()<<"<---obj1.getX()\n";

 

cout<<endl<<endl<<"EJEMPLO#2***********************\n";

//FUNCIONA LA ASIGNACION EN CASCADA
Coordenada obj4, obj5, obj3;
obj3.setX(10);
obj3.setY(20);

cout<<endl<<"\nasignacion en cascada, uso de sobrecarga de asignacion implicita ";
cout<<endl<<"obj4=obj5=obj1=obj3;\n ";
obj4=obj5=obj1=obj3;
cout<<endl<<obj4.getX()<<"<-----obj4.getX() ";
cout<<endl<<obj5.getX()<<"<-----obj5.getX() ";
cout<<endl<<obj1.getX()<<"<-----obj1.getX() ";
cout<<endl<<obj3.getX()<<"<-----obj3.getX() ";
obj3.setX(19);
cout<<endl<<obj3.getX()<<"<-----obj3.getX() ";

return 0;
}
