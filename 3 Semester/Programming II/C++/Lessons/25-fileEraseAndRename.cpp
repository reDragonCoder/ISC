#include <iostream>
#include <cstdlib>
//autor: Georgina Salazar Partida
/*Programa que ejemplifica la forma de borrar un archivo y renombrarlo
utilizando comandos del sistema operativo MS-DOS*/


using namespace std;
int main()
{
//Eliminamos archivo original
	system("cls");//Limpia pantalla linea opcional
	system("dir *.txt"); //Muestra todos los archivos del directorio actual con extension .txt
	
	cout<<"\n\n***** borrando archivo copia.txt*****\n\n";
	system("del copia.txt"); //del es un comando de DOS para borrar archivos
	system("pause");
	
	//renombramos la copia
	cout<<"\n\n*****Renombrando archivo origina.txt por fuente.txt *****\n\n";
	system("ren original.txt fuente.txt");//ren es un comando de DOS para renombrar archivos
	system("pause");
	return 0;
}//fin main

