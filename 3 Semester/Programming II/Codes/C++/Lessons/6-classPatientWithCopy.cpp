// AUthor: reDragonCoder
#include <iostream>

using namespace std;

class Paciente{
	private:
		string nombre;
		int edad;
		string padecimiento;
		
	public:
			string getNombre(){
				return this->nombre;
			}	
	      
	      int getEdad(){
	      	return this->edad;
	      }
	      
	      string getPadecimiento(){
	      	return this->padecimiento;
	      }
	      
	      // los metodos set establecen o colocan un valor en el atributo
	      
	      void setNombre(string nombre){
	      	  this->nombre = nombre;
	      }
	      void setEdad(int edad){
	      	 this->edad = edad;
	      }
	      
	      void setPadecimiento(string padecimiento){
	      	this->padecimiento = padecimiento;
	      }
	      
	      //constructor vacio
	      Paciente(){
	      	cout<<endl<<"Soy el constructor vacio\n ";
	      }
	      
	      ~Paciente(){
	      	cout<<endl<<"Soy el destructor";
	      }
	      
	      //constructor con parametros
	      
	      Paciente(string nombre, int edad, string padecimiento){
	      	cout<<endl<<"Constructor con parametros\n";
	      	this->nombre = nombre;
	      	this->edad = edad;
	      	this->padecimiento = padecimiento;
	      }
	      
	      Paciente(const Paciente &obj){
	      	cout<<endl<<"Constructor copia\n";
	      	this->nombre = obj.nombre;
	      	this->edad = obj.edad;
	      	this->padecimiento = obj.padecimiento;
	      }
	
	
	   void recetar(){
        	
        	if(this->padecimiento == "gripe")
        	  cout<<"Para la gripa toma un parasetamol";
          	else if(this->padecimiento == "dolor de panza")
            	     cout<<"Para el dolor de panza toma hierbabuena";
        	     else if(this->padecimiento == "tos")
                      cout<<"Para la tos toma jarabe";
        	        else 
                    	cout<<"Para "<<this->padecimiento<<" Ve a descansar";	
}

}; //fin de la clase

 
int main(){
    	cout<<endl<<"*********************************"<<endl;
    	// declarar un objeto
       	cout<<endl<<"obj1:";   
    	Paciente obj1;  //constructor vacio
    	obj1.setNombre("liliana");
    	obj1.setPadecimiento("dolor de cabeza");
    	obj1.setEdad(18);
    	cout<<endl<<obj1.getNombre()<<" ";
	    obj1.recetar();
	    
	     
    	cout<<endl<<"\n*********************************"<<endl;
    	cout<<endl<<"obj2:";  
    	Paciente obj2("luis enrique", 24, "tos"); //constructor con parametros
    	cout<<endl<<"Nombre: "<<obj2.getNombre();
    	cout<<endl<<"Edad: "<<obj2.getEdad();
    	cout<<endl<<"Padecimiento: "<<obj2.getPadecimiento();
    	cout<<endl<<obj2.getNombre()<<" ";
    	obj2.recetar();
    	
    	cout<<endl<<"\n*********************************"<<endl;
    	cout<<endl<<"obj3:";  
        Paciente obj3(obj2); //constructor copia
    	cout<<endl<<"Nombre: "<<obj3.getNombre();
    	cout<<endl<<"Edad: "<<obj3.getEdad();
    	cout<<endl<<"Padecimiento: "<<obj3.getPadecimiento();
    	cout<<endl<<obj3.getNombre()<<" ";
    	obj3.recetar();
    	
    	cout<<endl<<"\n*********************************"<<endl;
    	cout<<endl<<"obj4:"; 
    	Paciente *obj4 = new Paciente(obj1); //constructor con parametros
         
    	cout<<endl<<"Nombre: "<<obj4->getNombre();
    	cout<<endl<<"Edad: "<<obj4->getEdad();
    	cout<<endl<<"Padecimiento: "<<obj4->getPadecimiento();
    	cout<<endl<<obj4->getNombre()<<" ";
    	obj2.recetar();
	
		
    	cout<<endl<<endl<<endl;
    	return 0;
    }
