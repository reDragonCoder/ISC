#include <iostream>
#include <fstream>
#include <cstring>
//autor GSP

using namespace std;



class Clientes{
	private:
		int cuenta; // campo llave
		char  nombre[50];
		float monto;
		
		fstream file;  //<--------------------------------------------
		
	public:
		Clientes();	 
		bool abrir(char *nomArch);		 
		void cerrarArchivo();  		
		void crearCascaron(char *nomArch);
		void escribirRegistro();
		void leerRegistro();
		int capturaCuenta();
		void muestra();
	    ~Clientes(){}
	    
	
};

    Clientes::Clientes(){  //<-------------I M P O R T A N T E
     
    	this->cuenta=0; // campo llave
		strcpy(this->nombre,"");
		this->monto=0;
	}
	
 
	
    bool Clientes::abrir(char *nomArch){
			cout<<endl<<"abriendo archivo de lectura/escritura";
			file.open(nomArch,ios::binary|ios::out|ios::in);//<-------------I M P O R T A N T E
			if (!file)
			  return false;
			else
			  return true;  
	}	
			
 
			 
	void Clientes::cerrarArchivo(){
		        cout<<endl<<"cerrando el archivo ";
				file.close();//<------I M P O R T A N T E
	} 	
	
	void Clientes::crearCascaron(char *nomArch){
	    file.open(nomArch,ios::binary|ios::out  );//abrir de escritura
	 	Clientes blank;// registro en blanco
	 	
		//crear el cascaron con 10 registros en blanco
		cout<<endl;
		for(int i = 0; i < 10; i++){
			file.write( (char*)(&blank),sizeof(Clientes));
		}
		cout <<endl<< "cascaron de archivo creado exitosamente para 10 registros!!!\n"<<endl; 
        file.close();
	} 
	
	int Clientes::capturaCuenta(){
		//ingrese solo cuentas validas entre 1 y 10
		//validacion para ingresar cuenta entre 1 y 10
		int cuenta;	
		do{
				cout <<endl<<"Ingresa cuenta: ";
				fflush(stdin);
				cin >>cuenta;
				if (cuenta<1 || cuenta>10)
						cout<<endl<<"ERROR, cuentas validas del 1 al 10 ";
		}while(cuenta<1 || cuenta>10);	

		return cuenta;   
	}
	
	
	void Clientes::escribirRegistro(){
		Clientes *registro=new Clientes; //<------I M P O R T A N T E
		
	    cout<<endl<<"Registro de Datos"<<endl;
	    int cta=capturaCuenta();
	    fflush(stdin);	 
		cout << "Dame un Nombre: ";
		cin.getline(registro->nombre,50);
		cout << "Dame el Monto: ";
		cin >> registro->monto;
	    registro->cuenta=cta;
	     
		/* seekp busca el registro solicitado a partir del inicio
		del archivo */
		file.seekp((registro->cuenta -1) * sizeof(Clientes), ios::beg);//<------I M P O R T A N T E
		
		// write escribe el registro 
	    file.write(reinterpret_cast<char*>(registro), sizeof(Clientes));//<------I M P O R T A N T E (el apuntador se queda en la sig posicion)
		cout<<endl<<endl<<"Registro guardado exitosamente"<<endl<<endl;  
		delete registro;
		
	}
	
	void Clientes::leerRegistro(){
	   Clientes *registro=new Clientes;
	   //colocamos el puntero al inicio de archivo
		file.clear();   //<-----I M P O R T A N T E
		file.seekg( 0 );  //<-----I M P O R T A N T E
	  	       
	   cout<<endl<<"Consulta de cuentas"<<endl; 
	   int cta=capturaCuenta();	  
	   cout<<endl<<"cuenta: "<<cta;
	   
	   /* se desplaza a una localidad especificada por cuenta */
		file.seekg( (cta - 1) * sizeof(Clientes) ); //<------I M P O R T A N T E
		
		/* extrae la cantidad de bytes de sizeof y los coloca
		en registro */
		file.read(reinterpret_cast<char*>( registro), sizeof(Clientes));//<------I M P O R T A N T E
		    
		if ( strlen(registro->nombre) == 0){
		     cout<<endl<<endl<<"Registro en blanco"<<endl;
		}
		else{
			cout <<endl<<endl<<"Datos del cliente...\n";
			cout << "Nombre:"<<registro->nombre<<endl<< "Monto: "<< registro->monto<< endl;		
		}   
	 
		 
	}
	
	
	void Clientes::muestra(){
		
		Clientes *registro; //usaremos un objeto dinamico
		 
		cout<<endl<<endl<<"Leyendo SECUENCIALMENTE el archivo binario binario";
	 
		int c=0;
		//colocamos el puntero al inicio de archivo
		file.clear();   //<-----I M P O R T A N T E
		file.seekg( 0 );  //<-----I M P O R T A N T E
		
		cout<<endl;
	
		for (int i=1; i<=10; i++){  //el cascaron solo tiene 10 lugares
		   registro=new Clientes;
		   file.read( reinterpret_cast<char*>(registro),sizeof(Clientes));   //  <-----------------IMPORTANTE
			if (strcmp(registro->nombre,"")!=0){
				 c++;
				cout<<endl;
				cout <<endl<<"Cuenta: "<<registro->cuenta;	     
				cout <<endl<<"Nombre: "<<registro->nombre;
				cout <<endl<<"Monto: "<<registro->monto;
			}
				 	 
		}
		if (c==0){
			cout<<endl<<"Todos los registros estan en blanco";
		}
		 
	}
	
	
	int menu()
	{
		int op;
		cout<<endl<<endl;
		
		cout<<endl<<"Menu para probar archivos binarios de acceso directo o aleatorio\n";
		cout<<endl<<"1. Escribir un registro";
		cout<<endl<<"2. Leer un registro";
		cout<<endl<<"3. Mostrar registros que tienen informacion";
		cout<<endl<<"4. Salir";
		cout<<endl<<"Cual opcion ?  ";
		fflush(stdin);
	    cin >> op;
	    return op;
	}
	
	
int main ()
{
	int op;
	char resp;
	char nomArch[]="bancomer.dat";
	Clientes cte;
	    
	cout<<endl<<"quieres crear el cascaron s/n: ";
	cin>>resp;
	if (resp=='s'){
		cte.crearCascaron(nomArch);
    }
    if (cte.abrir(nomArch)){ //el archivo se mantiene abierto en modo lectura/escritura
		do{
		    op=menu();
		    
		    switch(op){
		    	case 1: cte.escribirRegistro();
		    	        break;
		    	case 2: cte.leerRegistro();
				        break;  
				case 3: cte.muestra();	        
		    	        break;   
				case 4: cout<<endl<<"fin programa";
				        break;
				default: cout<<endl<<"Error en la opcion";				      
		    	        
			}//fin switch
		   
    	}while (op!=4);
    	cte.cerrarArchivo();//<------I M P O R T A N T E
    }else
	   cout<<endl<<"No se pudo abrir el archivo";		
 
 
    return 0;
} //fin main

//despues de cambiar unos datos, poner de nuevo seekp a la posicion anterior para evitar errores 