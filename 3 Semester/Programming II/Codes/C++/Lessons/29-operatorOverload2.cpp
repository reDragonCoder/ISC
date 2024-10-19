//sobrecarga operador + ejemplo2
//No hay punteros entre los atributos de la clase

#include <iostream>
#include <cstdlib>

//Sobrecarga del operador binario + Programa Ejemplo Tiempo

using namespace std;

class Tiempo {
public:
	Tiempo(int h=0, int m=0) : hora( h ), minuto(m) {}//inicializacion de miembros
	void mostrar();
	Tiempo operator+(Tiempo h);//<--NOTAR AQUI
private:
	int hora;
	int minuto;
};

Tiempo Tiempo::operator+(Tiempo h){//<--NOTAR AQUI
	cout<<endl<<"Entre a sobrecarga del operador de +"<<endl;
    Tiempo temp;
	temp.minuto = this->minuto + h.minuto;
	temp.hora = this->hora + h.hora;
	if(temp.minuto >= 60) {
		temp.minuto -= 60;
		temp.hora++;
	}
	return temp;
}

void Tiempo::mostrar(){
	cout << hora << ":" << minuto << endl;
}

int main(){	
	Tiempo ahora(12,24), t1(4,45);
	t1 = ahora + t1; // equivale a ahora.operator+(t1);
	t1.mostrar();
	
	(ahora + Tiempo(1,10)).mostrar(); /* Objeto Anonimo manda llamar
	a la funcion mostrar, un objeto anonimo
    es creado en un instante sin un nombre*/
	 
	return 0;
}
