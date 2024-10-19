
//POO Uso de una constante static como atributo de una clase
//Autor GSP
#include <iostream>
using namespace std;

/*Un atributo static sea constante o NO es un dato com�n a todas
 las instancias que se hagan de la clase, es decir  NO FORMAN 
 PARTE DE LA instancia*/
 
class Circulo{
	private:
	  double radio;
	  static int contador; //<----------ATENCION AQUI
	  /*cuando se declara un dato miembro o atributo static en la clase, NOO es posible
	    darle su valor de manera directa !!!!!!  */
	   
	public:
	   Circulo(double radio) {
	   	 cout<<endl<<"contructor con parametros";
	     this->radio=radio;
	     
	     Circulo::contador++; //o simplemente contador++
	         //No aplica el uso de this-> con atributos static
	   }
	   
	   static int getContador(){
	   	  return Circulo::contador; // o simplemente return contador
	   	     //No aplica el uso de this-> con atributos static
	   }
	   
	  
	   double calcularArea(){
	      return 3.1416 * this->radio * this->radio; 
	  }
};

int Circulo::contador=3; //un atributo static se inicializa fuera de la clase.
 
int main()
{
                                             
 cout<<endl<<"******************************************************"; 	
 Circulo circulo1(6);
 cout<<endl<<"El area es: "<<circulo1.calcularArea();
 cout<<endl<<"******************************************************";
  	
 Circulo circulo2(8);
 cout<<endl<<"El area es: "<<circulo2.calcularArea();
 cout<<endl<<"******************************************************"; 	
 
 Circulo circulo3(9);
 cout<<endl<<"El area es: "<<circulo3.calcularArea();
 cout<<endl<<"******************************************************"; 
 	
 Circulo circulo4(3.4); 
 cout<<endl<<"El area es: "<<circulo4.calcularArea();
 
 cout<<endl<<"******************************************************";  	
 cout<<endl<<"contador de objetos: "<<Circulo::getContador();
 
 
 
 
return 0;
} 