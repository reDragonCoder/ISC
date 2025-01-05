/*POO Sobrecarga de Funciones miembro en una clase

La sobrecarga de metodos o funciones se refiere a
multiples funciones con el mismo nombre dentro de una clase,
diferenciadas por su firma, donde el tipo de retorno de cada funcion
puede ser diferente.

Por firma se entiende el total de parametros y/o el tipo
de dato de los parametros
*/

#include <iostream>
using namespace std;

class Operaciones{
	public:
		//-------> Notar que para las funciones inline puede usarse o NO la sentencia inline 
		
		inline int mayor(int a, int b) { //parametros
			cout<<endl<<"Entre a mayor que recibe dos enteros";
			return a > b ? a : b;    /*<------------ operador ternario utilizado para representar una condicion simple 
									indicando lo que hacer en la parte verdadera y falsa, es decir equivale a
									if (a>b)
										return a;
									else
										return b;   
									*/   
		}
		
		inline char mayor(char a, char b) {
			cout<<endl<<"Entre a mayor que recibe dos char";
			return a > b ? a : b;
		}
		
		inline double mayor(double a, double b) {
			cout<<endl<<"Entre a mayor que recibe dos double";
			return a > b ? a : b;
		}

};

int main(){
	Operaciones obj;
	
	cout<<endl<<obj.mayor(45, 20); //argumentos
	cout<<endl<<obj.mayor('x', 'a');
	cout<<endl<<obj.mayor(16.3, 14.15);

  	return 0;
}
