// Author: reDragonCoder
#include <cstdlib>
#include <iostream>

using namespace std;
/*Sobrecarga operadores de flujo
>> extraccion de flujo
<< insercion de flujo

Las funciones operator >> y operator << se declaran
como funciones friend.

Estos operadores deben ser no miembro debido a que el objeto
de la clase Coordenada aparece en cada caso como el operando
derecho del operador, el operando de la clase debe aparecer
a la izquierda del operador para permitirnos sobrecargar
dicho operador como una funcion miembro de la clase.

Por lo tanto los operadores sobrecargados en entrada y salida
no pueden ser funciones miembro y se declaran como friend
si necesitan acceder de manera directa a los miembros
de la clase no publicos. como es el caso de este programa*/

//el cin y el cout son objetos de tipo clase istream y ofstream respectivamente

class Coordenada{
	private:
		int x, y;
	public:
	Coordenada(){
		x = 0; y = 0;
	}
	
	Coordenada(int i, int j){
	x = i; y = j;
	}
	
	friend ostream &operator <<(ostream &, Coordenada & ); //la clase le esta otorgando su amistad
	friend istream &operator >>(istream &, Coordenada & );
	
};//fin de la clase

/*Las funciones amigas se pueden implementar antes del main para no
poner prototipos de funciones*/

//implementacion de la funcion amiga
ostream &operator <<(ostream &out,  Coordenada &obj){
	out << "(" << obj.x << "," << obj.y << ")";
	return out; //notar que manejar este return permite las llamadas en cascada
}

//implementacion de la funcion amiga
istream &operator >>(istream &in, Coordenada &obj){
	cout << "\nDame x:";
	in >> obj.x;
	fflush(stdin);
	cout << "\nDame y:";
	in >> obj.y;
	return in;//notar que manejar este return permite las llamadas en cascada
}

int main(){
	Coordenada obj,obj1;
	cout<<endl<<"Capturando objetos con dos lineas de cin independientes: ";
	
	cout<<endl<<"\nDame datos para obj:";
	cin >> obj;// operator>>(cin,obj);
	
	cout<<endl<<"\nDame datos para obj1:";
	cin >> obj1;
	
	//Imprimiendo
	//1a opcion
	cout<< "coordenadas de obj (x,y) " << obj << "\n";
	
	//2da opcion
	cout<< "coordenadas de obj1 (x,y) ";
	operator<<(cout,obj1) << "\n";
	
	/*Tambien es posible hacerlo en una sola linea: cin>>obj>>obj1;
	esto es llamadas en cascada*/
	cout<<endl<<"Capturando dos objetos en una linea de cin : ";
	cout<<endl<<"\nDame datos para obj y obj1:";
	cin>>obj>>obj1;
	
	//Imprimiendo objetos por separado
	
	cout<< "coordenadas de obj (x,y) "<<obj<<"\n";
	cout<< "coordenadas de obj1 (x,y) "<<obj1<<"\n";
	
	//Imprimiendo en cascada
	cout<<endl<<"imprimiendo ..."<<endl;
	cout<<obj<<obj1;
	
 
return 0;
}
