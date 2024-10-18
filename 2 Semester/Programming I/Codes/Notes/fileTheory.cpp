// Author: reDragonCoder
//Files (with C++) -> inside iostream library

/*--Secuenciales (texto) -> .txt -> variables normales--
    //1. Declarar variable de tipo FILE *varArch;
    //2. Abrir archivo y crear (lectura, lectura/escritura, escritura)
    //3. Realizar operaciones de Altas, Bajas, Cambios y Consultas (grabar/leer/buscar, ordenar...)
    //4. Cerrar archivo

*/
/*--Aleatorios (binarios) -> .dat o .bin -> structs--
    //1. Declarar variable de tipo FILE *varArch;

    //4. Cerrar archivo

*/


//COMANDOS PARA ARCHIVOS DE TEXTO
/*
    FILE *archivo -> variable lógica

    FILE *fopen(char*nombre, char*modo) -> puntero (linkea variable lógica a física -> memoria a disco duro)
    archivo=fopen("c:\\autoexec.bat", "r"); -> r(lectura), w(escritura o sobreescribe si ya existe), a(abre el programa o lo crea si no existe) //devuelve nulo si no hay espacio en el disco
    
    int fclose(FILE *archivo);
    fclose(archivo);

    int fgetc(FILE *archivo); 
    fgetc(archivo); -> lee desde el archivo un caracter

    int fputc(int caracter, FILE *archivo); 
    fputc('a', archivo); -> escribe en el archivo un caracter

    char *fgets(char *cadena, int n, FILE *archivo);
    fgets(linea, 128, archivo); -> lee desde el archivo una cadena (128 toma todo el primer renglón)

    fputs(linea, archivo); -> escribe en el archivo una cadena

    feof(archivo); -> fin de archivo

    void rewind(FILE *archivo);
    rewind(archivo); --> rebobina en archivo para seguir buscando

    int fprint(FILE *archivo, const char *formato, ...);
    fprint(archivo, "x\tx\tx\tx\tx\n\n"); -> función con formato

    fscanf(archivo, "%d\t%d\t%d\n", t1, t2, t3);

*/

//COMANDOS PARA ARCHIVOS BINARIOS
/*
    FILE *archivo -> variable lógica

    FILE *fopen(char*nombre, char*modo) -> puntero (linkea variable lógica a física -> memoria a disco duro)
    archivo=fopen("c:\\autoexec.bat", "rb"); -> rb(lectura), wb(escritura o sobreescribe si ya existe), ab(abre el programa o lo crea si no existe) //devuelve nulo si no hay espacio en el disco

    r+=rb
    w+=wb
    a+=ab

    rb+ abrir un archivo binario (lectura/escritura)
    wb+ crear un archivo binario (lectura/escritura)
    ab+ abrir un archivo binario (lectura/escritura)

    fread(&reg, sizeof(stRegistro, 1, archivo); -> lee de un archivo (referencia de la estructura a grabar, tamaño que ocupa la estructura [reserva esa memoria], 1 porque graba solo una estructura, lugar a guardar)

    fwrite(&reg, sizeof(stRegistro, 1, archivo); -> escribe en un archivo

    fseek(archivo, 0, SEEK_END);
    
*/



//Note: el cursor es un puntor dentro de un archivo. Al final del renglón , el cursor o apuntador apunta a Null, lo que
//      quiere decir que el archivo llegó a su fin. (archivos secuenciales)