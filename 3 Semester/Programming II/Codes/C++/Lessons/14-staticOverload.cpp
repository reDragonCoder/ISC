//POO  funciones miembro static y sobrecarga de funciones static

#include<iostream>
#include<cstdlib>


using namespace std;
//la funcion static cuadrado esta sobrecargada tres veces, una inline y dos fuera de la clase

class Cuadrado{
    public:
        static int cuadrado(int i);
        static double cuadrado(double d);
        static long cuadrado(long l){ //tambien se puede inline
          cout<<"Funcion cuadrado() que utiliza un argumento long: ";
          return l*l;
        }   
    };
    
  int Cuadrado::cuadrado(int i) //<---------------NOTAR que en la implementacion SE OMITE static
  {
	  cout<<"Funcion cuadrado() que utiliza un argumento entero: ";
	  return i*i;
  }
  
  double Cuadrado::cuadrado(double d)
  {
	   cout<<"Funcion cuadrado() que utiliza un argumento double: ";
	   return d*d;
  }

int main()
{
  //Los metodos  static no necesitan un objeto para llamarlos es a 
  //traves del nombre de la clase
  cout<<Cuadrado::cuadrado(10)<<"\n";
  cout<<Cuadrado::cuadrado(11.0)<<"\n";
  cout<<Cuadrado::cuadrado(9L)<<"\n";
  cout<<"\n";
  system("pause");
  return 0;
}
