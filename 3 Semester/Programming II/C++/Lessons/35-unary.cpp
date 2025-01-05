// Author: reDragonCoder
#include <cstdlib>
#include <iostream>

using namespace std;

//Sobrecarga de los operadores unarios ++ --
//CON FUNCIONES MIEMBRO

/*Las versiones prefijas se sobrecargan de la misma maneraG que un operador unario,
en cuyo caso no sera necesario colocar argumento alguno. Por otro lado las
versiones postfijas necesitan un argumento de entrada que es declarado,
pero generalmente nunca utilizado, solo para que el compilador ubique que
se pide un postincremento o postdecremento.
*/

class Coordenada{
private:
	int x, y;
public:
	Coordenada(){
		x = 0; y = 0; 
	}
	Coordenada(int i, int j) { x = i; y = j; }
	
	int getX(){
		return this->x;
	}
	
	int getY(){
		return this->y;
	}

	void operator++(); // ++ prefijo
	void operator++( int ); // postfijo ++


};

void Coordenada::operator++() // ++ objeto preincremento
{
	cout<<endl<<"entre sobrecarga de preincremento";
	++this->x; //incremento prefijo
	++this->y;
	 

}

void Coordenada::operator++( int z) // objeto ++ postincremento
// notar que no se usa z (solo para diferenciar las funciones)
{

	cout<<endl<<"entre sobrecarga de postincremento";
	this->x++; // incremento postfijo
	this->y++;
	
}

int main(){
	/*int a=4, b=2, c;
	c = a++ + b;
	cout<<endl<<"a="<<a<<" b="<<b<<" c="<<c;
	*/
	
	Coordenada objeto1(5,4);
	cout<<endl<<endl<<"objeto1"<<endl;
	cout<<endl<<"x="<<objeto1.getX();
	cout<<endl<<"y="<<objeto1.getY();
	
	cout<<endl<<endl<<"objeto1++"<<endl;
	objeto1++; // tambien puede ser objeto1.operator++(2); Mando lo que sea como parametro,
	//solo es para que durante la ejecucion se diferencie el postincremento de preincremento
	cout<<endl<<"x="<<objeto1.getX();
	cout<<endl<<"y="<<objeto1.getY();
	cout<<endl;
	
	cout<<endl<<endl<<"++objeto1"<<endl;
	++objeto1; //objeto1.operator++();
	cout<<endl<<"x="<<objeto1.getX();
	cout<<endl<<"y="<<objeto1.getY();
	cout<<endl;
	
	cout<<"\n*****************************************************";
	 
	cout<<endl;
 
return 0;
}
