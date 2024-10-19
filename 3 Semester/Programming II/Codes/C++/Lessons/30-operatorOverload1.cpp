//Sobrecarga del operador relacional == y !=

#include <iostream>

using namespace std;

class Coordenada{
private:
	int x,y;
public:
	Coordenada (){
	   this->x = 0; 
	   this->y = 0;
	}
	Coordenada (int x, int y){
	   this->x = x; 
	   this->y = y;
	}

	bool operator== ( Coordenada );
	bool operator!= (Coordenada obj);

}; //fin de la clase

bool Coordenada::operator== (Coordenada obj)
{
cout<<"\nEntre a la sobrecarga del operator == ";
	if( this->x == obj.x && this->y == obj.y )
        return true;  
    else
        return false;
}


bool Coordenada::operator!= (Coordenada obj)
{
cout<<"\nEntre a la sobrecarga del operator != ";
	if( this->x != obj.x || this->y != obj.y )
        return true;  
    else
        return false;
}

int main()
{
Coordenada obj1(10,5), obj2(10,10);
if( obj1 == obj2 ) // puede quedar if ( obj1.operator==(obj2) )
  cout << "\nValores de los atributos de Objeto 1 y Objeto 2  IGUALES";
else
  cout << "\nValores de los atributos de Objeto 1 y Objeto 2  NO IGUALES";
cout<<"\n\n";

if( obj1 != obj2 ) // puede quedar if ( obj1.operator!=(obj2) )
  cout << "\nValores de los atributos de de Objeto 1 y Objeto 2 SON DIFERENTES";
else
  cout << "\nValores de los atributos de de Objeto 1 y Objeto 2 NO SON DIFERENTES";

return 0;
}
