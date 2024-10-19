#include <iostream>
 

using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string ciudad;

public:
	
	/*Al tener un constructor con argumentos implicitos
	  este incluye YA el constructor vacio*/
	
    // Constructor con argumentos implicitos
    Persona(string nombre = "Desconocido", int  edad = 0,  string ciudad = "No especificado"){
    	cout<<endl<<"\nconstructor con argumentos implicitos\n";
		this->nombre=nombre;
    	this->edad=edad;
    	this->ciudad=ciudad;
    }
        
    // Metodo para mostrar los detalles de la persona
    void mostrarDetalles() {
    	 cout<<endl<<"Mostrando detalles\n";
         cout << "\nNombre: " << this->nombre;
         cout << "\nEdad: " << this->edad;
         cout << "\nCiudad: " << this->ciudad;
         cout<<endl;
    }
    
    void capturar(){
    	cout<<endl<<"Capturando datos\n";
    	cout<<endl<<"Dame nombre: ";
    	getline(cin,this->nombre);
    	cout<<endl<<"Dame edad: ";
    	cin>>this->edad;
    	cin.ignore();
    	cout<<endl<<"Dame ciudad: ";
    	getline(cin,this->ciudad);
    	
    }
    
    int getEdad(){
    	return this->edad;
    }
};

int main() {
     
    Persona *gpo;
    int n;
    cout<<endl<<"Dame el tamanio del vector ";
    cin>>n;
    cin.ignore();
	gpo = new Persona[n];//Este tipo de crear un vector de objetos requiere el constructor vacio (usa el . en vez de ->)
    
    cout<<endl<<"\n*******************************************";
	for (int i=0; i<n; i++){
    	gpo[i].mostrarDetalles();
    }
    cout<<endl<<"\n*******************************************";
    for (int i=0; i<n; i++){
    	gpo[i].capturar();
    }
    cout<<endl<<"\n*******************************************";
     for (int i=0; i<n; i++){
    	gpo[i].mostrarDetalles();
    }
    cout<<endl<<"\n*******************************************";
    float acum=0;
    for (int i=0; i<n; i++){
    	acum+=gpo[i].getEdad();
    }
    cout<<endl<<"El promedio de edad del  grupo es: "<<acum/n;
    cout<<endl<<"\n*******************************************";


    return 0;
}
