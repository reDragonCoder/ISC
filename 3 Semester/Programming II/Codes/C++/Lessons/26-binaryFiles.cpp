//CESAR ANDRES ZULETA MALANCO - ID: 300077
// ARCHIVOS BINARIOS CON ACCESO SECUENCIAL EN POO (Clases)

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Clientes{
    private:
        int cuenta;
        char nombre[50];
        float monto;

        fstream file; //<----- IMPORTANTE
    
    public:
        Clientes(){}

        Clientes(int cuenta, char *nombre, float monto){
            this->cuenta=cuenta;
            strcpy(this->nombre, nombre);
            this->monto=monto;
        }

        ~Clientes(){}

        bool openEscritura(char *nomArch){
            bool band=true;
            file.open(nomArch, ios::binary | ios::out | ios::app); //<---- IMPORTANTE
            if(!file)
                band=false;
            return band;
        }

        bool openLectura(char *nomArch){
            bool band=true;
            file.open(nomArch, ios::binary | ios::in); //<----- IMPORTANTE
            if(!file)
                band=false;
            return band;
        }

        void escribirRegistro(Clientes *cte){
            cout<<endl<<"Grabando registro en el archivo...";
            cout<<endl<<cte->cuenta;
            cout<<endl<<cte->nombre;
            cout<<endl<<cte->monto;
            file.write(reinterpret_cast<const char*>(cte), sizeof(Clientes)); //<---- IMPORTANTE
        }

        void leerArchivo(){
            Clientes cte;
            int c=0;
            while(file.read(reinterpret_cast<char*>(&cte), sizeof(Clientes))){ //<---- IMPORTANTE
                cout<<endl;
                cout<<endl<<"Cuenta: "<<cte.getCuenta();
                cout<<endl<<"Nombre: "<<cte.getNombre();
                cout<<endl<<"Monto: "<<cte.getMonto();
                c++;
            }
            cout<<endl<<endl<<"Total de registros: "<<c;
        }

        void cerrarArchivo(){
            file.close(); //<----- IMPORTANTE
        }

        int getCuenta(){
            return this->cuenta;
        }

        char *getNombre(){ //<---- IMPORTANTE
            char *aux=new char[strlen(this->nombre)+2];
            strcpy(aux, this->nombre); //No se debe regresar un vector estatico
            return aux;
        }

        float getMonto(){
            return this->monto;
        }

        void setCuenta(int cuenta){
            this->cuenta=cuenta;
        }

        void setNombre(char *nombre){
            strcpy(this->nombre, nombre);
        }

        void setMonto(float monto){
            this->monto=monto;
        }

};

int main(){
    //NAME & DATA
    cout<<endl<<"\033[1;35mCESAR ANDRES ZULETA MALANCO  ID:300077\033[0m"<<endl;
    
    int cuenta;
    char nombre[40];
    float monto;
    char *nomArch=new char[40];
    strcpy(nomArch, "banco.bin");

    Clientes *obj;
    string resp="si";
    while(resp=="si"){
        cout<<endl<<"Dame la cuenta: ";
        cin>>cuenta;
        cin.ignore();
        cout<<endl<<"Dame el nombre: ";
        //se puede capturar nombre con apellidos y espacios en blanco
        cin.getline(nombre, 40);
        cout<<endl<<"Dame el monto: ";
        cin>>monto;

        obj=new Clientes(cuenta, nombre, monto); //constructor con parametros

        if(obj->openEscritura(nomArch)){
            obj->escribirRegistro(obj);
            obj->cerrarArchivo();
        }else
            cout<<endl<<"No se pudo abrir el archivo";

        cout<<endl<<endl<<"Desea ingresar mas datos si/no: ";
        cin.ignore();
        getline(cin, resp);
    }//fin while

    cout<<endl<<"Leyendo el archivo binario";
    Clientes *objL=new Clientes; //constructor vacio

    if(objL->openLectura(nomArch)){
        objL->leerArchivo();
        objL->cerrarArchivo();
    }else
        cout<<endl<<"No se pudo abrir el archivo";

    return 0;
}
