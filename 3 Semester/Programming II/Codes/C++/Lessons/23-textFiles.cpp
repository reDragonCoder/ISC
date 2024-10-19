// Author: reDragonCoder
//MANEJO DE ARCHIVOS CON POO

#include <iostream>
#include <windows.h> //<------------------ para uso del Sleep
#include <fstream> //<-------------------- IMPORTANTE

using namespace std;

class Datos{
    private:
        fstream file; //<------- IMPORTANTE
    public:
     //***********************************************

        bool abrir(char modo, char *nomArch){
            bool band=true; //Todo bien

            if(modo=='e')
                file.open(nomArch, ios::out | ios::app); //ABRE EL ARCHIVO DE ESCRITURA Y PARA AGREGAR
            else    
                file.open(nomArch, ios::in); //Abrimos el archivo de lectura
            if(!file) //verificar que el archivo se abrio con exito
                band=false; //mal
            return band;
        } //fin abrir

        //***********************************************

        void cerrar(){
            file.close(); //<------------- IMPORTANTE
        } //fin cerrar

        //***********************************************

        void leerCaracter(){
            char c; //para trabajar lectura caracter por caracter

            file.clear(); //<----------- IMPORTANTE
            file.seekg(0); //<----------- IMPORTANTE

            //<----------- IMPORTANTE lee caracter x caracter la informacion del archivo
            while(file.get(c)){ //obtiene un caracter del archivo lo asigna a la c, el ciclo da vueltas
                                //mientras existan caracteres que leer
                cout<<c; //imprime el caracter leido en pantalla
                Sleep(100);
            } //fin while
        }// fin leer

        //***********************************************

        void escribirCaracter(){
            char c; //para trabajar escritura caracter por caracter

            //Aqui se graba caracter por caracter en el archivo
            //Ciclo infinito se rompera hasta que se teclee un * (asterisco)
            for(;;){ //<----- IMPORTANTE
                c=cin.get();
                if(c=='*')
                    break;
                else
                    file.put(c); //escribe el caracter en el archivo
            }
        } //fin escribir

        //***********************************************

        void leerRenglon(){
            char linea[100]; //para trabajar lectura renglon por renglon

            file.clear(); //<---- IMPORTANTE
            file.seekg(0); //<---- IMPORTANTE
            while(file.getline(linea, 100)){ //recupera una linea de codigo y la almacena en la cadena linea
                cout<<linea<<endl; //imprime la linea a pantalla
                Sleep(1000);
            } //fin de while
        } //fin leerRenglon

        void leerPalabra(){
            char palabra[30];

            file.clear(); //<---- IMPORTANTE
            file.seekg(0); //<---- IMPORTANTE
            while(file>>palabra){ /*obtiene una palabra del archivo, el ciclo da vueltas mientras existan palabras que sacar*/
                cout<<palabra<<" ";
                Sleep(500);
            } //fin while
        } //fin leerPalabra
}; //fin de clase

int menu(){
    int op;
    cout<<endl;
    do{
        cout<<endl<<"Archivos de textos";
        cout<<endl<<"1. Escribir caracter por caracter";
        cout<<endl<<"2. Leer caracter por caracter";
        cout<<endl<<"3. Leer por renglon";
        cout<<endl<<"4. Leer palabra por palabra";
        cout<<endl<<"5. Fin";
        cout<<endl<<"Que vas a hacer: ";
        cin>>op;
        if(op<1 || op>5)
            cout<<endl<<"error en la entrada ";
    } while(op<1 || op>5);
    return op;
}

int main(){
    //NAME & DATA
    cout<<endl<<"\033[1;35mCESAR ANDRES ZULETA MALANCO  ID:300077\033[0m"<<endl;
    char nomArch[30];
    Datos obj;
    bool band;
    int op;

    cout<<endl<<"Dame el nombre del archivo con el que vas a trabajar xxxxx.txt: ";
    cin.getline(nomArch, 30);

    do{
        op=menu();
        switch(op){
            case 1: band=obj.abrir('e', nomArch);
                if(band==true){
                    cout<<endl<<"Escritura caracter por caracter \n";
                    cout<<endl<<"Tecle las lineas que quieras termina con * y un ENTER"<<endl;
                    obj.escribirCaracter();
                    obj.cerrar();
                }
                else
                    cout<<endl<<"Error al abrir el archivo";
                break;
            case 2: band=obj.abrir('l', nomArch);
                if(band==true){
                    cout<<endl<<"Lectura caracter por caracter\n";
                    obj.leerCaracter();
                    obj.cerrar();
                }
                else
                    cout<<endl<<"Error al abrir el archivo";
                break;
            case 3: band=obj.abrir('l', nomArch);
                if(band==true){
                    cout<<endl<<"Lectura renglon por renglon \n";
                    obj.leerRenglon();
                    obj.cerrar();
                }
                else
                    cout<<endl<<"Error al abrir el archivo";
                break;
            case 4: band=obj.abrir('l', nomArch);
                if(band==true){
                    cout<<endl<<"Lectura palabra por palabra\n";
                    obj.leerPalabra();
                    obj.cerrar();
                }
                else
                    cout<<endl<<"Error al abrir el archivo";
                break;
            case 5: cout<<endl<<"Fin de programa";
        } // fin switch
    }while(op!=5);
} //fin main