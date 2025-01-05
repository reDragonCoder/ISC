//POO Uso de una constante static como atributo de una clase

#include <iostream>
using namespace std;

/*Un atributo static sea constante o NO es un dato com�n a todas
 las instancias que se hagan de la clase, es decir  NO FORMAN 
 PARTE DE LA instancia*/
 
class Circulo{
	private:
	  double radio;
	  static const double PI; //<----------ATENCION AQUI
	  /*cuando se declara un dato miembro o atributo static const en la clase, es posible
	    darle su valor de manera directa !!!!!!  */
	   
	public:
	   Circulo(double radio) {
	   	 cout<<endl<<"contructor con parametros";
	     this->radio=radio;
	     }
	   
	   static const double getPI(){//<-- ATENCION AQUI, su get es static const
	      return Circulo::PI;//<-- ATENCION AQUI tambien puede ser solo PI
	      //Un atributo static NO usa NUNCAAAAAAAAAAAAA el this-> esto esta reservado para atributos de instancia
	   }
	   double calcularArea(){
	      return Circulo::PI * this->radio * this->radio; //<-- ATENCION AQUI tambien puede ser solo PI
	         //Un atributo static NO usa NUNCAAAAAAAAAAAAA el this-> esto esta reservado para atributos de instancia
	   }
};
const double Circulo::PI=3.1416;
 
int main()
{
 cout<<endl<<"Valor de PI: "<< Circulo::getPI();//Notar la sintaxis cambia !!!!! NO se usa objeto, sino el nombre de la clase
                                              
 cout<<endl<<"******************************************************"; 	
 Circulo circulo1(6);
 cout<<endl<<"PI="<<circulo1.getPI(); //Tambien se puede obtener PI con un objeto PERO NO ES BUENA PRACTICA
 cout<<endl<<"El area es: "<<circulo1.calcularArea();
 cout<<endl<<"******************************************************"; 	
 Circulo circulo2(8);
 cout<<endl<<"PI="<<circulo2.getPI();//Tambien se puede obtener PI con un objeto PERO NO ES BUENA PRACTICA
 cout<<endl<<"El area es: "<<circulo2.calcularArea();
 cout<<endl<<"******************************************************"; 	
 Circulo circulo3(9);
 cout<<endl<<"PI="<<circulo3.getPI();//Tambien se puede obtener PI con un objeto PERO NO ES BUENA PRACTICA
 cout<<endl<<"El area es: "<<circulo3.calcularArea();
 
 
return 0;
} 


// Los :: son operadores de clase
