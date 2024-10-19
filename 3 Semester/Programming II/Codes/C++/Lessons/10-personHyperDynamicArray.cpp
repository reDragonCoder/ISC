// AUthor: reDragonCoder

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
	
    // Constructor con argumentos impl�citos
    Persona(string nombre = "Desconocido", int  edad = 0,  string ciudad = "No especificado"){
    	cout<<endl<<"\nconstructor con argumentos implicitos\n";
		this->nombre=nombre;
    	this->edad=edad;
    	this->ciudad=ciudad;
    }
    
  
        
    // M�todo para mostrar los detalles de la persona
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
     
    Persona **migrupo; //no es una matriz dinamica
    int n;
    cout<<endl<<"Dame el tama�o del vector ";
    cin>>n;
    cin.ignore();
	migrupo = new Persona*[n]; 
	cout<<endl<<"\n*******************************************";
	for (int i=0; i<n; i++){
		//creando instancia para cada casilla
    	migrupo[i]=new Persona;//ejecuta constructor vacio
    }
    cout<<endl<<"\n*******************************************";
	for (int i=0; i<n; i++){
    	migrupo[i]->mostrarDetalles();
    }
    cout<<endl<<"\n*******************************************";
    for (int i=0; i<n; i++){
    	migrupo[i]->capturar();//llenando cada instancia
    }
    cout<<endl<<"\n*******************************************";
    for (int i=0; i<n; i++){
    	migrupo[i]->mostrarDetalles();
    }
    cout<<endl<<"\n*******************************************";
    float acum=0;
    for (int i=0; i<n; i++){
    	acum+=migrupo[i]->getEdad();
    }
    cout<<endl<<"El promedio de edad del  grupo es: "<<acum/n;
    cout<<endl<<"\n*******************************************";

     
     
    return 0;
}
