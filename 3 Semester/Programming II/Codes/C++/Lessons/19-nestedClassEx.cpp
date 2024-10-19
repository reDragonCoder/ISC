#include <iostream>
#include <string>

using namespace std;

class Carro {
	private:
			// Clase anidada Motor <----------------------------------------------------------
			
			/*La clase Motor solo tiene sentido dentro de la clase Carro, 
			lo que es un buen ejemplo de como usar clases anidadas cuando 
			hay una fuerte relacion entre dos entidades*/
			
			class Motor {
			private:
				int cilindros;
		
			public:
				// Constructor de la clase Motor
				Motor(int c) : cilindros(c) { cout<<endl<<"constructor Motor";}
		
				// Metodo para mostrar detalles del motor
				int getCilindros(){
					return this->cilindros;
				}
					
			};//fin clase anidada <----------------------------------------------------------
		
		string marca;
		int anio;
		Motor *miMotor;

	public:
		// Constructor de la clase Carro
		Carro(string m, int a, int cilindros) : marca(m), anio(a), miMotor(  new Motor(cilindros) ) {
			cout<<endl<<"constructor Carro";
		
			
		}

		string getMarca(){
			return this->marca;
		}
		
		int getAnio(){
			return this->anio;
		}
		
		int muestraCilindros(){   
			return miMotor->getCilindros();
		}
  
};

int main() {
    // Crear un objeto de tipo Carro
    
    Carro carro("Toyota", 2020, 4);
    cout<<endl;
    cout<<endl<<"marca: "<<carro.getMarca(); 
    cout<<endl<<"anio: "<<carro.getAnio();
    cout<<endl<<"cilindros: "<<carro.muestraCilindros();
   return 0;
}

