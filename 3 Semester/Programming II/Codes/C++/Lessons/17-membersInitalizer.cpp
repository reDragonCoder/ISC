#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor con lista de inicializacion de miembros  <----------------------------------------------------
    Persona(string n, int e) : nombre(n), edad(e) {    }  //<----------------------------------------------------

    // Metodo para mostrar los detalles de la persona
    void mostrar() {
        cout << endl << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

int main() {
    // Crear un objeto de tipo Persona
    Persona p("Juan", 30);
    
    // Mostrar los detalles de la persona
    p.mostrar();

    return 0;
}

