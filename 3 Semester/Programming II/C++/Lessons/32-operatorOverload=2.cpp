//Autor: GSP

/*Cuando No sobrecargamos operador de asignacion =
y trabajamos con la sobrecarga de asignacion implicita 
y  alguno de los atributos es un puntero*/
 

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Numeros{
	private:
		int *x;
		int tam;

	public:
		Numeros (int tam){ 
		  this->x = new int[tam]; 
		  this->tam = tam;
		}
		
		Numeros(){
		}
		
		void imprimir(){
			cout<<endl<<"tamano del vector: "<<this->tam;
			cout<<endl;
			for (int i=0; i<tam; i++){
				cout<<this->x[i]<<" ";
			}
			cout<<endl;
		}
		
		void cambiarvalor(int indice){
			this->x[indice]=9999;
		}
		
		void llenar(){
			for (int i=0; i<this->tam; i++){
				this->x[i]=10+rand()%39;
			}
		}
};

 
int main(){
	srand(time(0));
	Numeros obj1(10), obj2, obj3(9),obj4, obj5(12);
	cout<<endl<<"\nSin sobrecargar operador de asignacion";
	obj5.llenar();
	cout<<endl<<"\nEJEMPLO#1************************************\n";
	
	obj1.llenar();
	
    cout<<endl<<"\nimprimiendo obj1";obj1.imprimir();    
    cout<<endl<<endl<<"obj2=obj1";	
    cout<<endl<<"\nAparentemente tanto obj1 como obj2 tienen su propio vector";
 	obj2=obj1;
 	cout<<endl<<"\nimprimiendo obj2";obj2.imprimir();
 	
 	cout<<endl<<endl;
	cout<<endl<<"Cambiando el contenido de la  posicion 2 con 9999 en obj1";
	obj1.cambiarvalor(2);
	cout<<endl<<"\nimprimiendo obj1";obj1.imprimir();
	cout<<endl<<"\nimprimiendo obj2";obj2.imprimir();
	
	cout<<endl<<"\nPodemos notar que ambos objetos en realidad comparten el mismo vector";
	
	cout<<endl<<"\nEJEMPLO#2************************************\n"; 	
 	
	cout<<endl<<endl<<"Checando asignacion en cascada obj4=obj3=obj2=obj5";
	obj4=obj3=obj2;
	
	cout<<endl<<"\nimprimiendo obj4"; obj4.imprimir();
	cout<<endl<<"\nimprimiendo obj3";obj3.imprimir();
	cout<<endl<<"\nimprimiendo obj2";obj2.imprimir();
	
	cout<<endl<<"\nAparentemente tanto obj4, obj3 y obj2 tienen su propio vector";
 
	cout<<endl<<"\nLlamando a llenar con obj3 para cambiar todos sus valores";
	//que pase si obj3 manda llamar a llenar?
	obj3.llenar();
	cout<<endl<<"\nimprimiendo obj4"; obj4.imprimir();
	cout<<endl<<"\nimprimiendo obj3";obj3.imprimir();
	cout<<endl<<"\nimprimiendo obj2";obj2.imprimir();
	cout<<endl<<"\nNotamos que se modificaron todos los vectores y solo se debio modificar el de obj3";
     
	cout<<endl<<"\nEJEMPLO#3************************************\n";
	cout<<endl<<endl<<"Checando autoasignacion";
	obj4=obj4;
	cout<<endl<<"imprimiendo obj4"; obj4.imprimir();
	cout<<endl<<"\nDeberiamos validar que cuando fuera autoasignacion no se haga";
    
	
	return 0;
}
