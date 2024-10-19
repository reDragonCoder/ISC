#include <iostream>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string ciudad;

public:
	
	/*Al tener un constructor con argumentos implicitos
	  Ya incluye al constructor vacio*/
	
    // Constructor con argumentos implicitos
    Persona(string nombre = "Desconocido", int  edad = 0,  string ciudad = "No especificado"){ //no debe haber constructor vacío si hay constructor implicito
    	cout<<endl<<"\nconstructor con argumentos implicitos\n";
		this->nombre=nombre;
    	this->edad=edad;
    	this->ciudad=ciudad;
    }
        
    // Metodo para mostrar los detalles de la persona
    void mostrarDetalles() {
         cout << "Nombre: " << this->nombre << "\n";
         cout << "Edad: " << this->edad << "\n";
         cout << "Ciudad: " << this->ciudad << "\n";
         cout<<endl;
    }
};

int main() {
    // Crear objetos de la clase Persona usando diferentes combinaciones de argumentos
    
	Persona persona0;
    Persona persona1("lula");
    Persona persona2("Juan", 25);
    Persona persona3("Ana", 30, "Madrid");
    cout<<endl;

    // Mostrar detalles de cada persona
    cout << "Persona 0:\n";
    persona0.mostrarDetalles();
    
	cout << "Persona 1:\n";
    persona1.mostrarDetalles();
    
    cout << "\nPersona 2:\n";
    persona2.mostrarDetalles();
    
    cout << "\nPersona 3:\n";
    persona3.mostrarDetalles();

    return 0;
}
