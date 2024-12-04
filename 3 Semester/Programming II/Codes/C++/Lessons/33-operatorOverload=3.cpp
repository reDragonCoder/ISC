// Author: reDragonCoder
//sobrecarga operador de asignacion = 
//Cuando alguno de los atributos es un puntero
 

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
		
    Numeros &operator=(const Numeros &c){
			cout<<"\nEntre a la sobrecarga del operador de asignacion"<<endl; 
			//verifica que no se trate de una autoasignacion
			if(this !=  &c) {
			     this->tam=c.tam;
			     this->x=new int[tam];
			     for (int i=0; i<this->tam; i++){
			     	this->x[i]=c.x[i];
			     }
			}
			else
				  cout<<endl<<"Error de intento de autoasignacion"<<endl;			
			return *this; //esto permitira la autoasignacion en cascada
		}
		
		/*Hay que tener en cuenta la posibilidad de que se asigne un objeto a si mismo.
		  Por eso comparamos el puntero this con la direcci�n del par�metro, 
		  si son iguales es que se trata del mismo objeto, y no debemos hacer nada.
	 	  Esta es una de las situaciones en las que el puntero this es imprescindible*/			
};

 
int main()
{
	srand(time(0));
	Numeros obj1(10), obj2, obj3(9),obj4, obj5(12);
	cout<<endl<<"\nSobrecargando operador de asignacion";
	obj5.llenar();
	cout<<endl<<"\nEJEMPLO#1************************************\n";
	
	obj1.llenar();
	
    cout<<endl<<"\nimprimiendo obj1";obj1.imprimir();    
    cout<<endl<<endl<<"obj2=obj1";	
    cout<<endl<<"\nTanto obj1 como obj2 tienen su propio vector";
 	obj2=obj1; //obj2.operator=(obj1);
 	cout<<endl<<"\nimprimiendo obj2";obj2.imprimir();
 	
 	cout<<endl<<endl;
	cout<<endl<<"Cambiando el contenido de la  posicion 2 con 9999 en obj1";
	obj1.cambiarvalor(2);
	cout<<endl<<"\nimprimiendo obj1";obj1.imprimir();
	cout<<endl<<"\nimprimiendo obj2";obj2.imprimir();
	
	cout<<endl<<"\nNotar que el cambio solo se hico en obj1";
	
	cout<<endl<<"\nEJEMPLO#2************************************\n"; 	
 	
	cout<<endl<<endl<<"Checando asignacion en cascada obj4=obj3=obj2=obj5";
	obj4=obj3=obj2;
	
	cout<<endl<<"\nimprimiendo obj4"; obj4.imprimir();
	cout<<endl<<"\nimprimiendo obj3";obj3.imprimir();
	cout<<endl<<"\nimprimiendo obj2";obj2.imprimir();
	
	cout<<endl<<"\nobj4, obj3 y obj2 tienen su propio vector";
 
	cout<<endl<<"\nLlamando a llenar con obj3 para cambiar todos sus valores";
	//que pase si obj3 manda llamar a llenar?
	obj3.llenar();
	cout<<endl<<"\nimprimiendo obj4"; obj4.imprimir();
	cout<<endl<<"\nimprimiendo obj3";obj3.imprimir();
	cout<<endl<<"\nimprimiendo obj2";obj2.imprimir();
	cout<<endl<<"\nNotar que solo cambio el vector de obj3";
     
	cout<<endl<<"\nEJEMPLO#3************************************\n";
	cout<<endl<<endl<<"Checando autoasignacion";
	obj4=obj4;
	cout<<endl<<"imprimiendo obj4"; obj4.imprimir();
	cout<<endl<<"\nEsta validado que la autoasignacion no proceda";
    
	
	return 0;
}
