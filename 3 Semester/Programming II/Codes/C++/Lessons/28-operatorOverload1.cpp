// Author: reDragonCoder
//sobrecarga operador + ejemplo1

#include <iostream>
using namespace std;
class Coordenada{
	private:
		int x, y;

	public:
		Coordenada (){ this->x = 0; this->y = 0; }
		Coordenada (int x, int y){ this->x = x; this->y = y; }
	 
		Coordenada operator+ ( Coordenada  ); //<--NOTAR AQUI
						
		int getX(){return this->x;}
		int getY(){return this->y;}
};

Coordenada  Coordenada::operator+ (Coordenada  obj) //<--NOTAR AQUI
{
	cout<<endl<<"Entre a sobrecarga del operador de +"<<endl;	
	Coordenada  temp ;//<--NOTAR AQUI
	temp.x = this->x + obj.x;//<--NOTAR AQUI
	temp.y = this->y + obj.y;//<--NOTAR AQUI
	return temp;//<--NOTAR AQUI
}

int main()
{
Coordenada obj1(8,4), obj2(10,3),obj3;
obj3 = obj1 + obj2; 

/*equivale obj1.operator+(obj2); 
   
  Y de una forma mas completa considerando la asignacion es
  
  obj3.operator=(obj1.operator+(obj2));
  
  Este programa no tiene sobrecarga de operador de =, al menos no
  implementado por nosotros, pero realmente se esta usando la sobrecarga del
  operador de asignacion de forma implicita, gracias a que no hay
  punteros en esta clase, si hubiera punteros involucrados, necesitariamos
  sobrecargar al operador de asignacion
  
*/
cout << "Suma de obj1 mas obj2\n";
cout << "obj3 x: "<<obj3.getX()<< " y: " << obj3.getY();
 


return 0;
}
