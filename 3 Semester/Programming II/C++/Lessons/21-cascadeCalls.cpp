// Author: reDragonCoder

#include <iostream>
#include <string>
#include <iomanip>//uso de setfill y setw
//Autor gsp

/*Como utilizar el apuntador this para permitir
llamadas en cascada a funciones*/

/*Otro uso del apuntador this es permitir llamadas en 
cascada a funciones, en las cuales se invoca a funciones
en la misma instruccion*/

using namespace std;
class Tiempo{
	    private:
		int hora, minuto, segundo;
		
		public:
	    
	    /*En las siguientes funciones se retorna *this, entendiendo
	    que se esta retornando la direccion donde esta la instancia
		del propietario de la llamada*/
	    
	    /*Cuando se va a retornar *this se utiliza el operador de alias
	    en el tipo de retorno de la funcion*/
	    
		Tiempo &estableceHora(int h){
			this->hora= (h>=0 && h<24) ? h : 0;
			return *this;
		}
		
		Tiempo &estableceMinuto(int m){
			this->minuto = (m>=0 && m<=60) ? m : 0;
			return *this;
		}
		
		Tiempo &estableceSegundo(int s){
			this->segundo = (s>=0 && s<=60) ? s : 0;
			return *this;
		}

        //imprime tiempo en formato universal
        void imprimeUniversal() const{
        	cout<<endl<<"\nFormato Universal"<<endl;
		    cout<<setfill('0')<<setw(2)<<this->hora<<":"
		        <<setw(2) << this->minuto << ":"
		        <<setw(2) << this->segundo<<endl;
		}
		
		//imprime tiempo en formato estandar
		void imprimeEstandar() const{
		  cout<<endl<<"\nFormato estandar"<<endl;	
		  cout<<( (hora==0 || hora==12 )? 12 : hora % 12)
		      <<":"<<setfill('0')<<setw(2)<<this->minuto
			  <<":"<<setw(2) << this->segundo
			  <<(hora<12 ? " am" : " pm")<<endl;
		}
};

int main(int argc, char** argv) {
    Tiempo t;
    //llamando UNA x UNA cada funcion
    cout<<endl<<endl<<"Llamando las funciones una por una"<<endl;
    t.estableceHora(16);
    t.estableceMinuto(48);
    t.estableceSegundo(35);
    
	t.imprimeEstandar();
	t.imprimeUniversal();
	
	//PERO TAMBIEN FUNCIONA ASI CON LLAMADAS EN CASCADA
	cout<<endl<<endl<<"Usando las llamadas en cascada"<<endl;
	t.estableceHora(15).estableceMinuto(20).estableceSegundo(24).imprimeUniversal();
	t.estableceHora(12).estableceMinuto(8).estableceSegundo(30).imprimeEstandar();
	return 0;
}

/*Por que funciona la tecnica de devolver *this como una referencia?
  Porque el operador de punto se asocia de izquierda a derecha, de manera que al regresar
  de la llamada a establecerHora y sabiendo que esta funcion retorno la direccion del objeto
  que inicialmente hizo la llamada,  entonces con esa direccion se hace la llamada a la  
  funcion estableceMinuto y asi sucesivamente */
  
  
