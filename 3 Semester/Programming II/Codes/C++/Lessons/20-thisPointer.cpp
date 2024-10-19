#include <iostream>

/*Uso implicito y explicito del apuntador this
para acceder a los datos miembro de un objeto*/

/*Cada objeto tiene acceso a su propia direccion 
a traves de un apuntador llamado this*/

using namespace std;
class Prueba{
	private:
		int x;
		float y;
	public:
	    Prueba(int x=3, int y=6){
		  this->x=x;
		  this->y=y;
		}
	    void imprimir1(){
	    	//USO EXPLICITO DEL APUNTADOR this
	    	cout<<endl<<"Usando apuntador this explicito";
	    	cout<<endl<<this->x;
	    	cout<<endl<<this->y;
	    	cout<<endl;
	    }
	    void imprimir2(){
	    	//USO IMPLICITO DEL APUNTADOR this
	    	cout<<endl<<"Usando apuntador this implicito";
	    	cout<<endl<< x;
	    	cout<<endl<< y;
	    	cout<<endl;
	    }
	    void imprimir3(){
	    	/*USO explicito DEL APUNTADOR this desreferenciado y 
	    	el operador de . para acceder al dato miembro*/
	    	cout<<endl<<"USO explicito DEL APUNTADOR this desreferenciado";
	    	cout<<endl<< (*this).x;
	    	cout<<endl<< (*this).y;
	    }
};

int main(int argc, char** argv) {
	Prueba obj;
	obj.imprimir1();
	obj.imprimir2();
	obj.imprimir3();
	return 0;
}
