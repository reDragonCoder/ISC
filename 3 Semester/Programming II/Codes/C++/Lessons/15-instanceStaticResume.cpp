#include <iostream>
//POO Reglas y uso de atributos y metodos static
//Autor GSP

using namespace std;
/*Una variable (atributo)  y/o constante estatica de una clase es un dato comun a todas
 las instancias que se hagan de esa clase, es decir este tipo de miembros NO FORMAN 
 PARTE DE LA instancia*/
 
  /*La manera mas correcta de llamar a miembros estaticos de una clase, estando dentro
  de la clase o FUERA de ella (main) es utilizando el nombre de la clase y el operador
  de alcance ::
  Ejemplo Foo::numFoos=8;*/
  
class Foo {
	
private:
  static int numFoos;//<------ ATENCION AQUI   contador de instancias Y no es const
  static int n;
  int num;
	
public:
  Foo() {
  	cout<<endl<<"constructor vacio";
    Foo::numFoos = Foo::numFoos + 1; //Cada que se crea una instancia se incrementa el contador
    //++numFoos;  //tambien funciona asi sin el Foo:: PERO ESTO solo dentro de la clase
  }
  
    static int getNumFoos() {  //<-- ATENCION AQUI, si el el atributo es static entonces
	    						//tambien su get es static
		return Foo::numFoos; //correcto
		//return numFoos; // correcto          
		//return this->numFoos; //<-- ERROR el apuntador this No funciona con miembros static
    }
  
  /*Hay una restriccion importante que saber, los metodos static no tienen derecho
    a utilizar atributos ni metodos de instancia, solo tienen acceso a atributos 
	y metodos que tambien sean static*/
	
  static void prueba1(){ //Este es un metodo static
         cout<<endl<<"Soy el metodo static ";
         cout<<endl<<"valor del atributo static numFoos: "<< getNumFoos(); //ok esta llamando a un metodo tambien static
         numFoos=0; //ok esta utilizando un atributo static
         //num=9; //<--error num no es static
         //prueba2();//<--error prueba2 no es static
   
   }
  	
  /*sin embargo constructores y metodos de instancia (no son static) 
    pueden usar todo de la clase*/
    
  void prueba2(){
  	     cout<<endl<<"valor del atributo static numFoos: "<< getNumFoos(); //static
         Foo::n=5;
         num=9; //no es static , es atributo de instancia
         prueba3(); //no es static, es metodo de instancia  	
  }
  
  void prueba3(){
  	  cout<<endl<<"son prueba3 soy metodo de instancia";
  	  cout<<endl<<"valor del atributo static numFoos: "<< Foo::n; //static
  }
	 
};

int Foo::numFoos = 0;  //<-- ATENCION AQUI esta la Forma de inicializar un 
                       //atributo  static, se hace fuera de la clase
int Foo::n = 0; 

int main() {
  Foo f1;
  Foo f2;
  Foo f3;
  Foo f4;
  
  f3.prueba2(); //llamando a metodo de instancia
  
  //LOS METODOS static NO REQUIEREN DE UNA INSTANCIA para poder  llamarlos
  //Se llaman utilizando el NOMBRE DE LA CLASE :: NOMBRE DEL METODO static
  
  cout << "\nTotal de instancias creadas: " << Foo::getNumFoos();
  Foo::prueba1();
  //prueba1(); //<--- ESTA MAL se tiene que indicar que esta en la clase Foo
}
