// Author: reDragonCoder

#include <iostream>
using namespace std;

/*La clase le otorga su amistad a una funcion ajena a sus funciones miembro,
para que pueda utilizar atributos y metodos privados*/

//La clase decide quienes seran sus funciones amigas 

class Numeros {

private:
  int a, b;
  
  void metodoPrivado(){cout<<"\n metodo privado";}

public:
  friend Numeros sumaAmiga(Numeros &, Numeros &); //puede tener acceso a la seccion privada de la clase
  void metodoPublico(){
    cout<<"\nSoy un metodo publico, llamando a un ... ";
	metodoPrivado();
  }

  Numeros(){   }
  
  Numeros(int a, int b) {
      this->a=a;
      this->b= b;
  }

  void setA(int a){this->a=a;}
  void setB(int b){this->b=b;}
  int getA(){return this->a;}
  int getB(){return this->b;}

  void mostrar(){
      cout << this->a << " "<< this->b <<endl;
	   
	  }
};//fin de la clase

/*Una funcion amiga puede utilizar los atributos y metodos
privados y publicos de la clase siempre y cuando sea a traves
de un objeto de la clase*/

Numeros sumaAmiga(Numeros &obj1, Numeros &obj2){  //NOTAR QUE NO SE USO el operador de alcance ::
    cout<<"\nSoy la funcion amiga";
    /*una funcion amiga no puede llamar DIRECTAMENTE metodos de la 
     clase, necesita un objeto para poder hacerlo*/
    //metodoPrivado(); 
    //metodoPublico();
    obj1.metodoPrivado();
    obj1.metodoPublico();//Lo publico de todos modos si se puede mandar llamar
    Numeros aux;
    aux.a = obj1.a + obj2.a;//notar que se utiliza directo el nombre del atributo sin usar los gets
    aux.b = obj1.b + obj2.b;
    
    return aux;
}

int main(){
	Numeros a(3,3),b(4,4);
	a.mostrar();
	b.mostrar();
	
	Numeros res1=sumaAmiga(a,b); //no se necesita un objeto para mandar llamar a la funcion Amiga
	cout<<"\n\n Usando la funcion amiga"<<endl;
	res1.mostrar();
	
	
	cin.get();
  return 0;
}
