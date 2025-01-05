// Author: reDragonCoder
//MANEJO DE ARCHIVOS DE TEXTO POR CAMPO

#include <iostream>
#include <fstream> //<--------- IMPORTANTE
#include <string>

using namespace std;

class Datos{
    private:
        fstream file; //<------- IMPORTANTE
    public:
        //**************************************

        bool abrir(char modo, char *nomArch){
            bool band=true; //Todo bien

            if(modo=='e')
                file.open(nomArch, ios::out | ios::app); //ABRE EL ARCHIVO DE TEXTO DE ESCRITURA Y PARA AGREGAR
            else
                file.open(nomArch, ios::in); //Abrimos el archivo de lectura
            if(!file) //verifica que el archivo se abrio con exito
                band=false; //mal
            return band;
        } //fin abrir

        //**************************************

        void cerrar(){
            file.close(); //<-------- IMPORTANTE
        } //fin cerrar

        //**************************************

        void escribirCampos(){
            int cuenta;
            string nombre;
            float monto;
            char resp='s';

            cout<<endl;
            while(resp=='s'){ //mientras resp=='s'
                cout<<"Dame un numero de cuenta: ";
                cin>>cuenta;
                cout<<"Dame un nombre (solo una palabra): ";
                fflush(stdin);
                getline(cin, nombre);
                cout<<"Dame el monto: ";
                cin>>monto;

                //Escribe o guarda la informacion en el archivo de texto
                file<<cuenta<<" "<<nombre<<" "<<monto<<endl; //<--------- IMPORTANTE

                cout<<"\nDeseas seguir ingresando datos? s/n: ";
                fflush(stdin);
                cin>>resp;
            } //fin while
        } //fin escribir

        //**************************************

        void leerCampos(){
            int cuenta;
            string nombre;
            float monto;
            cout<<endl<<endl<<"Imprimiendo la informacion desde el archivo";
            //<-------------- IMPORTANTE aqui recorre el archivo para recuperar la informacion
            while(file>>cuenta>>nombre>>monto){ /*obtiene un registro del archivo, el ciclo da vueltas mientras no se acabe el archivo*/
                cout<<endl;
                cout<<"\nCuenta: "<<cuenta;
                cout<<"\nNombre: "<<nombre;
                cout<<"\nMonto: "<<monto;
            } //fin while
        } //fin leer

        //**************************************
}; //fin de clase

int menu(){
    int op;
    cout<<endl;
    do{
        cout<<endl<<"Clientes (registros fijos)";
        cout<<endl<<"1. Escribir clientes";
        cout<<endl<<"2. Leer clientes";
        cout<<endl<<"3. Salir";
        cout<<endl<<"Que vas a hacer?: ";
        cin>>op;
        if(op<1 || op>3)
            cout<<endl<<"error en la entrada ";
    }while(op<1 || op>3);
    return op;
}

int main(){
    //NAME & DATA
    cout<<endl<<"\033[1;35mCESAR ANDRES ZULETA MALANCO  ID:300077\033[0m"<<endl;
    
    char nomArch[]="datos.txt";
    Datos obj;
    bool band;
    int op;

    do{
        op=menu();
        switch(op){
            case 1: band=obj.abrir('e', nomArch);
                if(band==true){
                    obj.escribirCampos();
                    obj.cerrar();
                }else
                    cout<<endl<<"Error al abrir el archivo";
                break;
            case 2: band=obj.abrir('l', nomArch);
                if(band==true){
                    obj.leerCampos();
                    obj.cerrar();
                }else
                    cout<<endl<<"Error al abrir el archivo";
                break;
            case 3: cout<<endl<<"Fin de programa";
        } //fin switch
    } while(op!=3);

    return 0;
} //fin main