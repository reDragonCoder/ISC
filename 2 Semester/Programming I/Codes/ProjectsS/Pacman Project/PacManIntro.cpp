// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <windows.h>
#include <conio.h> 
#include <time.h>
#include <stdlib.h>

//Recibir flechas para el movimiento
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27

//Colores
#define BLUE "\x1B[34m"
#define RESET "\x1b[0m"
#define YELLOW "\x1b[33m"
#define WHITE "\x1B[37m"
#define ORANGE "\033[38;5;208m"
#define RED "\033[31m"
#define GREEN "\033[32m"

//CONSTANTS
#define FILAS 29 //Filas del tablero
#define COLUMNAS 64 //Columnas del tablero
#define X_GUARIDA 21 //Coordenada salida de fantasmas
#define Y_GUARIDA 11 //Coordenada salida de fantasmas
#define X_PACMAN 21 //Coordenada de inicio de pacman
#define Y_PACMAN 15 //Coordenada de inicio de pacman

//Variables globales
char tablero[FILAS][COLUMNAS] = {
     "AxxxxxxxxxxxxxxxxxxxB AxxxxxxxxxxxxxxxxxxxFxxxxxxxxxxxxxxxxxxxB",
     "I___________________I I___________________I                   I",
     "I_AxxxxxB_AxxxxxxxB_I I_AxxxxxxxB_AxxxxxB_I                   I",
     "I_I     I_I       I_I I_I       I_I     I_I                   I",
     "I_DxxxxxC_DxxxxxxxC_DxC_DxxxxxxxC_DxxxxxC_I     PPPPPPPPP     I",
     "I_________________________________________I                   I",
     "I_AxxxxxB_AxB_AxxxxxxxxxxxxxB_AxB_AxxxxxB_I                   I",
     "I_DxxxxxC_I I_DxxxxB   AxxxxC_I I_DxxxxxC_I                   I",
     "I_________I I______I   I______I I_________I                   I",
     "DxxxxxxxB_I DxxxxB I   I AxxxxC I_AxxxxxxxC                   I",
     "        I_I AxxxxC DxxxC DxxxxB I_I                           I",
     "        I_I I                 I I_I                           I",
     "AxxxxxxxC_DxC Axxxxxx*xxxxxxB DxC_DxxxxxxxB                   I",
     "         _    I             I    _         U                  I",
     "DxxxxxxxB_AxB DxxxxxxxxxxxxxC AxB_AxxxxxxxC                   I",
     "        I_I I                 I I_I                           I",
     "        I_I I AxxxxxxxxxxxxxB I I_I                           I",
     "AxxxxxxxC_DxC DxxxxB   AxxxxC DxC_DxxxxxxxB                   I",
     "I__________________I   I__________________I                   I",
     "I_AxxxxxB_AxxxxxxB_I   I_AxxxxxxB_AxxxxxB_I                   I",
     "I_DxxxB I_DxxxxxxC_DxxxC_DxxxxxxC_I AxxxC_I                   I",
     "I_____I I_________________________I I_____I                   I",
     "DxxxB_I I_AxB_AxxxxxxxxxxxxxB_AxB_I I_AxxxC                   I",
     "AxxxC_DxC_I I_DxxxxB   AxxxxC_I I_DxC_DxxxB                   I",
     "I_________I I______I   I______I I_________I                   I",
     "I_AxxxxxxxC DxxxxB_I   I_AxxxxC DxxxxxxxB_I                   I",
     "I_DxxxxxxxxxxxxxxC_DxxxC_DxxxxxxxxxxxxxxC_I                   I",
     "I_________________________________________I                   I",
     "DxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxKxxxxxxxxxxxxxxxxxxxC",
};
char tablero_esquinas[FILAS][COLUMNAS] = { //Tablero solo esquinas para que se muevan los fantasmas
     "AxxxxxxxxxxxxxxxxxxxB AxxxxxxxxxxxxxxxxxxxFxxxxxxxxxxxxxxxxxxxB", 
     "I1       2         3I I1         2       3I                   I",
     "I AxxxxxB AxxxxxxxB I I AxxxxxxxB AxxxxxB I                   I",
     "I I     I I       I I I I       I I     I I                   I",
     "I DxxxxxC DxxxxxxxC DxC DxxxxxxxC DxxxxxC I     PPPPPPPPP     I",
     "I4       5   2     6   6     2   5       7I                   I",
     "I AxxxxxB AxB AxxxxxxxxxxxxxB AxB AxxxxxB I                   I",
     "I DxxxxxC I I DxxxxB   AxxxxC I I DxxxxxC I                   I",
     "I8       7I I8    3I   I1    9I I8       9I                   I",
     "DxxxxxxxB I DxxxxB I   I AxxxxC I AxxxxxxxC                   I",
     "        I I AxxxxC DxxxC DxxxxB I I                           I",
     "        I I I1    6  .  6    3I I I                           I",
     "AxxxxxxxC DxC Axxxxxx*xxxxxxB DxC DxxxxxxxB                   I",
     "         5   7I             I4   5         U                  I",
     "DxxxxxxxB AxB DxxxxxxxxxxxxxC AxB AxxxxxxxC                   I",
     "        I I I4               7I I I                           I",
     "        I I I AxxxxxxxxxxxxxB I I I                           I",
     "AxxxxxxxC DxC DxxxxB   AxxxxC DxC DxxxxxxxB                   I",
     "I1       5   6    3I   I1    6   5       3I                   I",
     "I AxxxxxB AxxxxxxB I   I AxxxxxxB AxxxxxB I                   I",
     "I DxxxB I DxxxxxxC DxxxC DxxxxxxC I AxxxC I                   I",
     "I8   3I I4   2    6     6    2   7I I1   9I                   I",
     "DxxxB I I AxB AxxxxxxxxxxxxxB AxB I I AxxxC                   I",
     "AxxxC DxC I I DxxxxB   AxxxxC I I DxC DxxxB                   I",
     "I1   6   9I I8    3I   I1    9I I8   6   3I                   I",
     "I AxxxxxxxC DxxxxB I   I AxxxxC DxxxxxxxB I                   I",
     "I DxxxxxxxxxxxxxxC DxxxC DxxxxxxxxxxxxxxC I                   I",
     "I8                6     6                9I                   I",
     "DxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxKxxxxxxxxxxxxxxxxxxxC",
};
char mapa[FILAS][COLUMNAS]; //Copia del tablero

char opcion; //Variable para detectar el movimiento por tecla

int PacMan_x = 21; //Variable para las coordenadas x de pacman
int PacMan_y = 15; //Variable para las coordenadas y de pacman
int Clyde_x = 21; //Variable para las coordenadas x de Clyde el fantasma
int Clyde_y = 13; //Variable para las coordenadas y de Clyde el fantasma
int Blinky_x = 23; //Variable para las coordenadas x de Blinky el fantasma
int Blinky_y = 13; //Variable para las coordenadas y de Blinky el fantasma
int Inky_x = 25; //Variable para las coordenadas x de Inky el fantasma
int Inky_y = 13; //Variable para las coordenadas y de Inky el fantasma
int CasoComer = 0; //Ver que fantasma se comio a pacman

int puntos_totales = 329; //Puntos que se pueden comer en el tablero
int puntaje; //Puntaje que se va acumulando
int vidas = 3; //Vidas que tiene para completar el juego

bool BanderaChoqueClyde = false;
bool BanderaChoqueBlinky = false;
bool BanderaChoqueInky = false;

int numeroAleatorio = 0; //Parte del movimiento aleatorio de Clyde
int direccionBlinky = 0; //Movimiento segun la direccion de Blinky
int direccionInky = 0;  //Movimiento segun la direccion de Inky

//Prototipos de las funciones
void hideCursor();
void gotoxy(int,int);

void CopiarTablero(char[FILAS][COLUMNAS]);
void MostrarTablero(char[FILAS][COLUMNAS]);
void MusicaInicio();

void MenuInicial();
void MostrarPuntaje();
void MostrarVidas();
void Reiniciar();

void limpiar();
void LimpiarFantasma(int, int);
void LimpiarGuarida(int, int);

void MovimientoPacman();
void MovimientoClyde();
void MovimientoBlinky();
void MovimientoInky();

bool EvaluarColision(int, int);
bool EvaluarChoque(int, int);

void FantasmaClyde();
void FantasmaBlinky();
void FantasmaInky();

void ImprimirPunto(int, int, int);
void IniciarFantasma(int, int, int);

int main(){
    MenuInicial();
    srand(time(NULL)); //Iniciar numeros aleatorios
    system("cls"); //Limpiar pantalla al iniciar el programa
    CopiarTablero(tablero); 
    hideCursor();
    MostrarTablero(mapa);
    MusicaInicio();
    opcion = UP;    
    do {
        if (kbhit()){ //Detectar si se pulsa alguna tecla
            FantasmaClyde();
            FantasmaBlinky();
            FantasmaInky();
            MovimientoPacman();
        }
        else{
            FantasmaClyde();
            FantasmaBlinky();
            FantasmaInky();
            MovimientoPacman();
        }
        if (puntos_totales <= 0){ //Cuando se comen todos los puntos, se termina el ciclo
            //Limpiar por ultima vez la posicion en la que se encuentra el pacman
            limpiar();
            //Imprimir el pacman en la posicion en la que se quedo
            switch(opcion){
                case LEFT:
                    gotoxy(PacMan_x, PacMan_y);
                    printf(">");
                    break;
                case UP:
                    gotoxy(PacMan_x, PacMan_y);
                    printf("v");            
                    break;
                case DOWN:
                    gotoxy(PacMan_x, PacMan_y);
                    printf("%c", 94);            
                    break;  
                case RIGHT:
                    gotoxy(PacMan_x, PacMan_y);
                    printf("<");            
                    break;                  
            }
            //Imprimir el mensaje cuando se termina el juego hasta abajo del tablero    
            gotoxy(0, 0);
            for (int i = 0; i < 28; i++){
                printf("\n");   
            }
            break;
        }
        if (BanderaChoqueClyde == true || BanderaChoqueBlinky == true || BanderaChoqueInky == true){
            BanderaChoqueClyde = false;
            BanderaChoqueBlinky = false;
            BanderaChoqueInky = false;
            Reiniciar();
            CasoComer = 0;
        }
        MostrarPuntaje();
        MostrarVidas();        
    } while (vidas != 0);
    //Imprimir el mensaje cuando se termina el juego hasta abajo del tablero cuando se presiona ESC
    gotoxy(0, 0); 
    for (int i = 0; i < 28; i++){
        printf("\n");
    }

    return 0;
}

//Implementaciones
//SI NOS CAMBIAN EL MENU, NOS SALIMOS DEL EQUIPO
void MenuInicial(){ //Menu que se desplega al inicio del programa
    int x=29;
  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	gotoxy(25, 13);
    printf("P A C M A N");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	gotoxy(25, 15);
    printf("PRESS START");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	gotoxy(5, 27);
    system("pause");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    hideCursor();
    gotoxy(x, 13);
    printf("<");
    gotoxy(25,15);
    printf("                   ");
    Sleep(1000);
    do{  
        gotoxy(x,13);
        printf(" ");   
        x++;
        gotoxy(x,13);
        printf("<");
        Sleep(500);
        if(x==36){
            gotoxy(36,13);
            printf(" ");
        }
    }while(x!=36);
    if(x==36){
        int x=25;
        gotoxy(x,13);
        printf("<");
        do{
            gotoxy(x,13);
            printf(" ");   
            x++;
            gotoxy(x,13);
            printf("<");
            Sleep(500);
        }while(x!=29);
    }
    printf(RESET);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(25,11);
    printf("P A C M A N");
    printf(RESET);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(25,15);
    printf("HOW TO PLAY \n");
    printf(RESET);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(20,16);
    printf("Use the arrows to move");
    gotoxy(26,18);
    printf("%c  Up     %c", 219, 94);
    gotoxy(26,20);
    printf("%c  Down   v", 219);
    gotoxy(26,22);
    printf("%c  Left   %c", 219, 60);
    gotoxy(26,24);
    printf("%c  Right  %c", 219, 62);
    Sleep(2500);
    printf(RESET);
	system("cls");
}

void CopiarTablero(char tablero[FILAS][COLUMNAS]){ //Copiar el tablero en otra variable
    for (int i = 0; i < FILAS; i++){
        for (int j = 0; j < COLUMNAS; j++){
            mapa[i][j] = tablero[i][j]; 
        }
    }   
}

void MostrarTablero(char mapa[FILAS][COLUMNAS]){ //Imprimir el tablero segun los caracteres de la matriz, ya con colores
    for (int i = 0; i < FILAS; i++){
        for (int j = 0; j < COLUMNAS; j++){
            switch(mapa[i][j]){
        		case 'x':
                    gotoxy(j,i);
        			printf(BLUE "%c", 205, mapa[i][j]);
                    printf(RESET);
        			break;
        		case 'A':
                    gotoxy(j,i);
        			printf(BLUE "%c", 201, mapa[i][j]);
                    printf(RESET);
        			break;
        		case 'B':
                    gotoxy(j,i);
                    printf(BLUE "%c", 187, mapa[i][j]);
                    printf(RESET);
                    break;
                case 'C':
                    gotoxy(j,i);
                    printf(BLUE "%c", 188, mapa[i][j]);
                    printf(RESET);
                    break;
                case 'D':
                    gotoxy(j,i);
                    printf(BLUE "%c", 200, mapa[i][j]);
                    printf(RESET);
                    break;
                case 'I':
                    gotoxy(j,i);
                    printf(BLUE "%c", 186, mapa[i][j]);
                    printf(RESET);
                    break;
                case '_':
                    gotoxy(j,i);
                    printf(YELLOW "%c", 250, mapa[i][j]);
                    printf(RESET);
                    break;
                case '+':
                    gotoxy(j,i);
                    printf(YELLOW "%c", 250, mapa[i][j]);
                    printf(RESET);
                    break;
                case '*':
                    gotoxy(j,i);
                    printf(WHITE "%c", 196, mapa[i][j]);
                    printf(RESET);
                    break;        
                case 'F':
                    gotoxy(j,i);
                    printf(BLUE "%c", 203, mapa[i][j]);
                    printf(RESET);                
                    break;    
                case 'K':                       
                    gotoxy(j,i);
                    printf(BLUE "%c", 202, mapa[i][j]);
                    printf(RESET);   
                    break;        
                case 'P':                       
                    gotoxy(j,i);
                    printf(WHITE "%c", 196, mapa[i][j]);
                    printf(RESET);                
                    break;     
        		default:
                    gotoxy(j,i);
        			printf(" ", mapa[i][j]);
                    printf(RESET);
        			break;                
            }
        }
    }
}

void MusicaInicio(){
    Beep(523, 250); // Do
    Beep(1047, 250); // DO
    Beep(784, 250); // Sol
    Beep(659, 125); // Mi
    Beep(784, 125); // Sol
    Beep(659, 125); // Mi

    // Segunda línea
    Beep(554, 250); // Do#
    Beep(1109, 250); // DO#
    Beep(830, 250); // Sol#
    Beep(698, 125); // Fa
    Beep(830, 125); // Sol#
    Beep(698, 125); // Fa

    // Tercera línea
    Beep(523, 250); // Do
    Beep(1047, 250); // DO
    Beep(784, 250); // Sol
    Beep(659, 125); // Mi
    Beep(784, 125); // Sol
    Beep(659, 125); // Mi

    // Cuarta línea
    Beep(698, 125); // Fa
    Beep(740, 125); // Fa#
    Beep(784, 125); // Sol
    Beep(830, 125); // Sol#
    Beep(880, 125); // La
    Beep(987, 250); // Si
}

void hideCursor(){ //Para que no se vea el cursor durante el programa
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize =100;
    cci.bVisible= FALSE; //False para que no se muestre
    SetConsoleCursorInfo(hcon,&cci);
}

void gotoxy(int x,int y){ //Mover el cursor en unas coordenadas exactas
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

void MostrarPuntaje(){ //Muestra el puntaje que cambia en una coordenada exacta
    gotoxy(47, 3);
    printf("Puntaje: %d", puntaje);
}

void MostrarVidas(){
    gotoxy(48, 5);
    printf("Vidas: %d", vidas);
}

bool EvaluarColision(int x, int y){ //Checa si el movimiento se puede realizar
    if (mapa[y][x] == '_' || mapa[y][x] == '+' || mapa[y][x] == ' '){ //Si en la matriz existen esos elementos, entonces el movimiento se puede realizar
        return true;
    }
    else{
        return false;
    }
}

void limpiar(){ //Limpia la posicion actual del pacman
    gotoxy(PacMan_x, PacMan_y);
    printf(" ");
}

void MovimientoPacman(){ //Para el movimiento de pacman
    //Se imprime el pacman segun la ultima entrada del teclado
    switch(opcion){
        case LEFT:
            gotoxy(PacMan_x, PacMan_y);
            printf(">"); //Pacman hacia la izquierda
            break;
        case UP:
            gotoxy(PacMan_x, PacMan_y);
            printf("v"); //Pacman hacia arriba
            break;
        case DOWN:
            gotoxy(PacMan_x, PacMan_y);
            printf("%c", 94); //Pacman hacia abajo        
            break;  
        case RIGHT:
            gotoxy(PacMan_x, PacMan_y);
            printf("<"); //Pacman hacia la derecha   
            break;                  
    }

    if (kbhit()){ //Detectar si se pulsa una tecla
        opcion = getch();
    }
    Sleep(10); //Tiempo en el que se tarda en imprimir el pacman
    
    switch(opcion){ //Segun la entrada del teclado
        case UP:
            if (EvaluarColision(PacMan_x, PacMan_y - 1)){ 
                limpiar(); 
                if (mapa[PacMan_y - 1][PacMan_x] == '_'){ //Si hay un punto en la matriz
                    Beep(500, 100);
                    puntos_totales--; //Se resta los puntos totales que hay para comer
                    mapa[PacMan_y - 1][PacMan_x] = ' '; //Se vacia la matriz en ese espacio
                    puntaje += 10; //Aumenta el puntaje 
                }
                PacMan_y--; //Cambia la posicion de pacman
            }
            break;
        case DOWN:
            if (EvaluarColision(PacMan_x, PacMan_y + 1)){
                limpiar();
                if (mapa[PacMan_y + 1][PacMan_x] == '_'){ //Si hay un punto en la matriz
                    Beep(500, 100);
                    puntos_totales--; //Se resta los puntos totales que hay para comer
                    mapa[PacMan_y + 1][PacMan_x] = ' '; //Se vacia la matriz en ese espacio
                    puntaje += 10; //Aumenta el puntaje 
                }
                PacMan_y++; //Cambia la posicion de pacman      
            }
            break;
        case RIGHT:
            if (EvaluarColision(PacMan_x + 1, PacMan_y)){ 
                limpiar();
                if (mapa[PacMan_y][PacMan_x + 1] == '_'){ //Si hay un punto en la matriz
                    Beep(500, 100);
                    puntos_totales--; //Se resta los puntos totales que hay para comer
                    mapa[PacMan_y][PacMan_x + 1] = ' '; //Se vacia la matriz en ese espacio   
                    puntaje += 10; //Aumenta el puntaje 
                }
                PacMan_x++; //Cambia la posicion de pacman
            }
            else{
                if (PacMan_y == 13 && PacMan_x == 42){ //Si el pacman se encuentra en la posicion del portal
                    limpiar();
                    PacMan_x = COLUMNAS - 64; //Se cambia la posicion del pacman
                }
            }        
            break;
        case LEFT:
            if (EvaluarColision(PacMan_x - 1, PacMan_y)){
                limpiar();
                if (mapa[PacMan_y][PacMan_x - 1] == '_'){ //Si hay un punto en la matriz
                    Beep(500, 100);
                    puntos_totales--; //Se resta los puntos totales que hay para comer
                    mapa[PacMan_y][PacMan_x - 1] = ' '; //Se vacia la matriz en ese espacio     
                    puntaje += 10; //Aumenta el puntaje 
                }
                PacMan_x--; //Se cambia la posicion del pacman
            }
            else{
                if (PacMan_y == 13 && PacMan_x == 0){ //Si el pacman se encuentra en la posicion del portal
                    limpiar();
                    PacMan_x = COLUMNAS - 22; //Se cambia la posicion del pacman
                }
            }
            break;
    }
}

void LimpiarFantasma(int x, int y){ //Limpiar la posicion en la que se encuentra cada fantasma
    if (mapa[y][x] == '_' || mapa[y][x] == '+'){
        gotoxy(x, y);
        printf(" ");
    }
    else{
        gotoxy(x, y);
        printf(" ");
    }
}

void ImprimirPunto(int x, int y, int direccion){ //Imprimir de nuevo el punto que se borro al pasar el fantasma
    if (mapa[y][x] == '_' || mapa[y][x] == '+'){
        switch(direccion){
            case 0:
                gotoxy(x, y - 1);
                printf(YELLOW "%c", 250);
                printf(RESET);
                break;
            case 1:
                gotoxy(x, y + 1);    
                printf(YELLOW "%c", 250);
                printf(RESET);
                break;
            case 2:
                gotoxy(x + 1, y);    
                printf(YELLOW "%c", 250);
                printf(RESET);
                break;
            case 3:
                gotoxy(x - 1, y);    
                printf(YELLOW "%c", 250);
                printf(RESET); 
                break;                                  
        }
    }
}

void LimpiarGuarida(int x, int y){ //Se limpa la posicion de la guarida donde se encontraba el fantasma
    gotoxy(x, y);
    printf(" ");    
}

void IniciarFantasma(int aux_x, int aux_y, int caso){
    //Segun el fantasma que toca iniciar
    switch(caso){
        case 1: //Fantasma clyde
            //Se limpia la posicion en donde se encontraba el fantasma
            LimpiarGuarida(Clyde_x, Clyde_y);        
            //Se imprime al fantasma afuera de la guarida
            gotoxy(aux_x, aux_y);
            printf(ORANGE "%c", 219);
            printf(RESET);
            //Cambia la posicion del fantasma
            Clyde_x = aux_x;
            Clyde_y = aux_y;
            break;
        case 2: //Fantasma Blinky
            //Se limpia la posicion en donde se encontraba el fantasma
            LimpiarGuarida(Blinky_x, Blinky_y);
            //Se imprime al fantasma afuera de la guarida
            gotoxy(aux_x, aux_y);
            printf(RED "%c", 219);
            printf(RESET);     
            //Cambia la posicion del fantasma
            Blinky_x = aux_x;
            Blinky_y = aux_y;
            break;       
        case 3:
            //Se limpia la posicion en donde se encontraba el fantasma
            LimpiarGuarida(Inky_x, Inky_y);
            //Se imprime al fantasma afuera de la guarida
            gotoxy(aux_x, aux_y);
            printf(GREEN "%c", 219);
            printf(RESET);     
            //Cambia la posicion del fantasma
            Inky_x = aux_x;
            Inky_y = aux_y;
            break;              
    }
}

void FantasmaClyde(){ //Funcion para el fantasma Clyde
    int id = 1; //id unico del fantasma      

    if (puntaje == 200){ //Momento en el que sale Clyde
        IniciarFantasma(X_GUARIDA, Y_GUARIDA, id); 
    }
    MovimientoClyde(); //Inicia el movimiento del fantasma
}

void MovimientoClyde(){

    //Segun la esquina en la que se encuentra Clyde
    switch(tablero_esquinas[Clyde_y][Clyde_x]){ 
        case '1':
            //Solo 2 opciones en ese tipo de esquina
            numeroAleatorio = rand() % 2;
            if (numeroAleatorio == 0){ 
                numeroAleatorio = 0; //Movimiento hacia abajo
            }
            else{ 
                numeroAleatorio = 3; //Movimiento hacia la derecha
            }
            break;
        case '2':
            //Solo 3 opciones en ese tipo de esquina
            numeroAleatorio = rand() % 3;
            if (numeroAleatorio == 0){ 
                numeroAleatorio = 2; //Movimiento hacia la izquierda
            }
            else if (numeroAleatorio == 1){ 
                numeroAleatorio = 3; //Movimiento hacia la derecha
            }
            else{
                numeroAleatorio = 0; //Movimiento hacia abajo
            }
            break;
        case '3':
            //Solo 2 opciones en ese tipo de esquina
            numeroAleatorio = rand() % 2;
            if (numeroAleatorio == 0){ 
                numeroAleatorio = 0; //Movimiento hacia abajo
            }
            else{ 
                numeroAleatorio = 2; //Movimiento hacia la izquierda
            }        
            break;    
        case '4':
            //Solo 3 opciones en ese tipo de esquina
            numeroAleatorio = rand() % 3;        
            if (numeroAleatorio == 0){ 
                numeroAleatorio = 2; //Movimiento hacia la izquierda
            }
            else if (numeroAleatorio == 1){ 
                numeroAleatorio = 3; //Movimiento hacia arriba
            }
            else{
                numeroAleatorio = 3; //Movimiento hacia la derecha
            }
            break;
        case '5':
            //Solo 4 opciones en ese tipo de esquina
            numeroAleatorio = rand() % 4;
            if (numeroAleatorio == 0){ 
                numeroAleatorio = 2; //Movimiento hacia la izquierda
            }
            else if (numeroAleatorio == 1){ 
                numeroAleatorio = 3; //Movimiento hacia la derecha
            }
            else if (numeroAleatorio == 2){ 
                numeroAleatorio = 0; //Movimiento hacia abajo
            }                    
            else{
                numeroAleatorio = 1; //Movimiento hacia arriba
            }          
            break; 
        case '6':
            //Solo 3 tipos de opciones en ese tipo de esquina
            numeroAleatorio = rand() % 3;        
            if (numeroAleatorio == 0){ 
                numeroAleatorio = 2; //Movimiento hacia la izquierda
            }
            else if (numeroAleatorio == 1){ 
                numeroAleatorio = 3; //Movimiento hacia la derecha
            }
            else{
                numeroAleatorio = 1; //Movimiento hacia arriba
            }     
            break;  
        case '7':
            //Solo 3 opciones en ese tipo de esquina
            numeroAleatorio = rand() % 3;        
            if (numeroAleatorio == 0){ //Movimiento hacia la izquierda
                numeroAleatorio = 2;
            }
            else if (numeroAleatorio == 1){ //Movimiento hacia arriba
                numeroAleatorio = 1;
            }
            else{
                numeroAleatorio = 0; //Movimiento hacia abajo
            }
            break;
        case '8':
            //Solo 2 opciones en ese tipo de esquina
            numeroAleatorio = rand() % 2;
            if (numeroAleatorio == 0){ //Movimiento hacia abajo
                numeroAleatorio = 1;
            }
            else{ 
                numeroAleatorio = 3; //Movimiento hacia la derecha
            }   
            break;
        case '9':
            //Solo 2 tipos de opciones en esa esquina
            numeroAleatorio = rand() % 2;
            if (numeroAleatorio == 0){ //Movimiento hacia abajo
                numeroAleatorio = 1;
            }
            else{ //Derecha
                numeroAleatorio = 2; //Movimiento hacia la izquierda
            }         
            break;
        case '.': //Punto de partida de Clyde
            //Aleatoriamente puede ir hacia dos lados al salir
            numeroAleatorio = rand() % 2;
            if (numeroAleatorio == 0){ 
                numeroAleatorio = 2; //Movimiento hacia la izquierda
            }
            else{ 
                numeroAleatorio = 3; //Movimiento hacia la derecha
            }            
            break;
    }

    //Se imprime Clyde
    gotoxy(Clyde_x, Clyde_y);
    printf(ORANGE "%c", 219);
    printf(RESET);  

    Sleep(10); //Tiempo que se tarda en imprimir a Clyde

    //Segun el numero aleatorio que se obtiene al verificar la esquina
    switch(numeroAleatorio){
        case 0: //Movimiento hacia abajo
            if (EvaluarColision(Clyde_x, Clyde_y + 1)){
                LimpiarFantasma(Clyde_x, Clyde_y);
                Clyde_y++;
                ImprimirPunto(Clyde_x, Clyde_y, 0);
            }    
            BanderaChoqueClyde = EvaluarChoque(Clyde_x, Clyde_y);
            if (BanderaChoqueClyde){
                CasoComer = 1;
            }
            break;
        case 1: //Movimiento hacia arriba
            if (EvaluarColision(Clyde_x, Clyde_y - 1)){
                LimpiarFantasma(Clyde_x, Clyde_y);
                Clyde_y--;
                ImprimirPunto(Clyde_x, Clyde_y, 1);
            }           
            BanderaChoqueClyde = EvaluarChoque(Clyde_x, Clyde_y); 
            if (BanderaChoqueClyde){
                CasoComer = 1;
            }
            break;
        case 2: //Movimiento hacia la izquierda
            if (EvaluarColision(Clyde_x - 1, Clyde_y)){
                LimpiarFantasma(Clyde_x, Clyde_y);
                Clyde_x--;
                ImprimirPunto(Clyde_x, Clyde_y, 2);
            }      
            else{
                if (Clyde_y == 13 && Clyde_x == 0){ //Si Clyde se encuentra en la posicion del porta
                    LimpiarFantasma(Clyde_x, Clyde_y);
                    Clyde_x = COLUMNAS - 22; //Se cambia la posicion de Clyde
                }                
            }                
            BanderaChoqueClyde = EvaluarChoque(Clyde_x, Clyde_y);
            if (BanderaChoqueClyde){
                CasoComer = 1;
            }
            break; 
        case 3: //Movimiento hacia la derecha
            if (EvaluarColision(Clyde_x + 1, Clyde_y)){
                LimpiarFantasma(Clyde_x, Clyde_y);
                Clyde_x++;
                ImprimirPunto(Clyde_x, Clyde_y, 3);
            }
            else{
                if (Clyde_y == 13 && Clyde_x == 42){ //Si Clyde se encuentra en la posicion del portal
                    LimpiarFantasma(Clyde_x, Clyde_y);
                    Clyde_x = COLUMNAS - 64; //Se cambia la posicion de Clyde
                }
            }     
            BanderaChoqueClyde = EvaluarChoque(Clyde_x, Clyde_y);    
            if (BanderaChoqueClyde){
                CasoComer = 1;
            }              
            break;                                    
    }
}

void FantasmaBlinky(){
    int id = 2; //id unico del fantasma

    if (puntaje == 1200){
        IniciarFantasma(X_GUARIDA, Y_GUARIDA, id); //Momento en el que sale Blinky
    }
    MovimientoBlinky(); //Inicia el movimiento del fantasma
}

void MovimientoBlinky(){
    //Segun la posicion en la que se encuentra Blinky
    switch(tablero_esquinas[Blinky_y][Blinky_x]){
        case '1': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Blinky, para asi seguirlo
            if (PacMan_y == Blinky_y){
                direccionBlinky = 3;
            }
            else if (PacMan_y > Blinky_y){
                direccionBlinky = 0;
            }
            else if (PacMan_y < Blinky_y){
                direccionBlinky = 3;
            }
            else if (PacMan_x < Blinky_x){
                direccionBlinky = 0;
            }
            else if (PacMan_x > Blinky_x){
                direccionBlinky = 3;
            }
            break;
        case '2': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Blinky, para asi seguirlo
            if (PacMan_x < Blinky_x){
                direccionBlinky = 2;
            }
            else if (PacMan_x > Blinky_x){
                direccionBlinky = 3;
            }
            else if (PacMan_y > Blinky_y){
                direccionBlinky = 0;
            }
            else if (PacMan_y < Blinky_y){
                direccionBlinky = 3;
            }
            break;
        case '3': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Blinky, para asi seguirlo
            if (PacMan_y == Blinky_y){
                direccionBlinky = 2;
            }
            else if (PacMan_y > Blinky_y){
                direccionBlinky = 0;
            }
            else if (PacMan_y < Blinky_y){
                direccionBlinky = 2;
            }
            else if (PacMan_x < Blinky_x){
                direccionBlinky = 2;
            }
            else if (PacMan_x > Blinky_x){
                direccionBlinky = 0;
            }
            break;
        case '4': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Blinky, para asi seguirlo
            if (PacMan_y == Blinky_y){
                direccionBlinky = 3;
            }
            else if (PacMan_y > Blinky_y){
                direccionBlinky = 0;
            }
            else if (PacMan_y < Blinky_y){
                direccionBlinky = 1;
            }
            break;
        case '5': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Blinky, para asi seguirlo
            if (PacMan_x > Blinky_x){
                direccionBlinky = 3;
            }else if (PacMan_x < Blinky_x){
                direccionBlinky = 2;
            }
            else{
                if (PacMan_y < Blinky_y){
                    direccionBlinky = 1;
                }
                else {
                    direccionBlinky = 0;
                }
            } 
            break;
        case '6': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Blinky, para asi seguirlo
            if (PacMan_x < Blinky_x){
                direccionBlinky = 2;
            }
            else if (PacMan_x > Blinky_x){
                direccionBlinky =  3;
            }
            else if (PacMan_y < Blinky_y){
                direccionBlinky = 1;
            }
            else if (PacMan_y > Blinky_y){
                direccionBlinky = 2;
            } 
            break;    
        case '7': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Blinky, para asi seguirlo
            if (PacMan_y > Blinky_y){
                direccionBlinky = 0;
            }
            else if (PacMan_y < Blinky_y){
                direccionBlinky = 1;
            }
            else if (PacMan_x < Blinky_x){
                direccionBlinky = 2;
            }
            else if (PacMan_x > Blinky_x){
                direccionBlinky = 1;
            }        
            break;
        case '8': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Blinky, para asi seguirlo
            if (PacMan_y == Blinky_y){
                direccionBlinky = 3;
            }
            else if (PacMan_y > Blinky_y){
                direccionBlinky = 0;
            }
            else if (PacMan_y < Blinky_y){
                direccionBlinky = 1;
            }
            else if (PacMan_x < Blinky_x){
                direccionBlinky = 1;
            }
            else if (PacMan_x > Blinky_x){
                direccionBlinky = 3;
            }            
            break;
        case '9': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Blinky, para asi seguirlo
            if (PacMan_y == Blinky_y){
                direccionBlinky = 2;
            }
            else if (PacMan_y > Blinky_y){
                direccionBlinky = 2;
            }
            else if (PacMan_y < Blinky_y){
                direccionBlinky = 1;
            }
            else if (PacMan_x < Blinky_x){
                direccionBlinky = 2;
            }
            else if (PacMan_x > Blinky_x){
                direccionBlinky = 1;
            }     
            break;
        case '.': //Segun al salir de la guarida
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Blinky, para asi seguirlo
            if (PacMan_x > Blinky_x){
                direccionBlinky = 3;
            }
            else{
                direccionBlinky = 2;
            }
            break;
    }

    //Se imprime Blinky
    gotoxy(Blinky_x, Blinky_y);
    printf(RED "%c", 219);
    printf(RESET);  

    Sleep(10); //Tiempo que se tarda en que se imprima a Blinky

    //Segun la salida de direccion
    switch(direccionBlinky){
        case 0: //Abajo
            if (EvaluarColision(Blinky_x, Blinky_y + 1)){
                LimpiarFantasma(Blinky_x, Blinky_y);
                Blinky_y++;
                ImprimirPunto(Blinky_x, Blinky_y, 0);
            }
            BanderaChoqueBlinky = EvaluarChoque(Blinky_x, Blinky_y);
            if (BanderaChoqueBlinky){
                CasoComer = 2;
            }
            break;
        case 1: //Arriba
            if (EvaluarColision(Blinky_x, Blinky_y - 1)){
                LimpiarFantasma(Blinky_x, Blinky_y);
                Blinky_y--;
                ImprimirPunto(Blinky_x, Blinky_y, 1);
            }        
            BanderaChoqueBlinky = EvaluarChoque(Blinky_x, Blinky_y);
            if (BanderaChoqueBlinky){
                CasoComer = 2;
            }
            break;
        case 2: //Izquierda
            if (EvaluarColision(Blinky_x - 1, Blinky_y)){
                LimpiarFantasma(Blinky_x, Blinky_y);
                Blinky_x--;
                ImprimirPunto(Blinky_x, Blinky_y, 2);
            }      
            else{
                if (Blinky_y == 13 && Blinky_x == 0){
                    LimpiarFantasma(Blinky_x, Blinky_y);
                    Blinky_x = COLUMNAS - 22;
                }                
            }   
            BanderaChoqueBlinky = EvaluarChoque(Blinky_x, Blinky_y);  
            if (BanderaChoqueBlinky){
                CasoComer = 2;
            }     
            break; 
        case 3: //Derecha
            if (EvaluarColision(Blinky_x + 1, Blinky_y)){
                LimpiarFantasma(Blinky_x, Blinky_y);
                Blinky_x++;
                ImprimirPunto(Blinky_x, Blinky_y, 3);
            }
            else{
                if (Blinky_y == 13 && Blinky_x == 42){
                    LimpiarFantasma(Blinky_x, Blinky_y);
                    Blinky_x = COLUMNAS - 64;
                }
            }    
            BanderaChoqueBlinky = EvaluarChoque(Blinky_x, Blinky_y);   
            if (BanderaChoqueBlinky){
                CasoComer = 2;
            }            
            break;          
    }
}

void FantasmaInky(){
    int id = 3; //id unico del fantasma
   
    if (puntaje == 700){ //Momento en el que sale Inky
        IniciarFantasma(X_GUARIDA, Y_GUARIDA, id);
    }
    MovimientoInky();
}

void MovimientoInky(){
    //Segun la posicion en la que se encuentra Inky
    switch(tablero_esquinas[Inky_y][Inky_x]){
        case '1': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Inky, para asi alejarse
            if (PacMan_y == Inky_y){
                direccionInky = 0;
            }
            else if (PacMan_y > Inky_y){
                direccionInky = 3;
            }
            else if (PacMan_y < Inky_y){
                direccionInky = 0;
            }
            else if (PacMan_x < Inky_x){
                direccionInky = 3;
            }
            else if (PacMan_x > Inky_x){
                direccionInky = 0;
            }
            break;
        case '2': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Inky, para asi alejarse
            if (PacMan_x < Inky_x){
                direccionInky = 3;
            }
            else if (PacMan_x > Inky_x){
                direccionInky = 2;
            }
            else if (PacMan_y > Inky_y){
                direccionInky = 3;
            }
            else if (PacMan_y < Inky_y){
                direccionInky = 0;
            }
            break;
        case '3': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Inky, para asi alejarse
            if (PacMan_y == Inky_y){
                direccionInky = 0;
            }
            else if (PacMan_y > Inky_y){
                direccionInky = 2;
            }
            else if (PacMan_y < Inky_y){
                direccionInky = 2;
            }
            else if (PacMan_x < Inky_x){
                direccionInky = 3;
            }
            else if (PacMan_x > Inky_x){
                direccionInky = 2;
            }
            break;
        case '4': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Inky, para asi alejarse
            if (PacMan_y == Inky_y){
                direccionInky = 1;
            }
            else if (PacMan_y > Inky_y){
                direccionInky = 1;
            }
            else if (PacMan_y < Inky_y){
                direccionInky = 0;
            }
            break;
        case '5': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Inky, para asi alejarse
            if (PacMan_x > Inky_x){
                direccionInky = 2;
            }else if (PacMan_x < Inky_x){
                direccionInky = 3;
            }
            else{
                if (PacMan_y < Inky_y){
                    direccionInky = 0;
                }
                else {
                    direccionInky = 1;
                }
            } 
            break;
        case '6': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Inky, para asi alejarse
            if (PacMan_x < Inky_x){
                direccionInky = 3;
            }
            else if (PacMan_x > Inky_x){
                direccionInky =  2;
            }
            else if (PacMan_y < Inky_y){
                direccionInky = 3;
            }
            else if (PacMan_y > Inky_y){
                direccionInky = 3;
            } 
            break;    
        case '7': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Inky, para asi alejarse
            if (PacMan_y > Inky_y){
                direccionInky = 1;
            }
            else if (PacMan_y < Inky_y){
                direccionInky = 0;
            }
            else if (PacMan_x < Inky_x){
                direccionInky = 0;
            }
            else if (PacMan_x > Inky_x){
                direccionInky = 2;
            }        
            break;
        case '8': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Inky, para asi alejarse
            if (PacMan_y == Inky_y){
                direccionInky = 1;
            }
            else if (PacMan_y > Inky_y){
                direccionInky = 1;
            }
            else if (PacMan_y < Inky_y){
                direccionInky = 3;
            }
            else if (PacMan_x < Inky_x){
                direccionInky = 3;
            }
            else if (PacMan_x > Inky_x){
                direccionInky = 1;
            }            
            break;
        case '9': //Segun la esquina
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Inky, para asi alejarse
            if (PacMan_y == Inky_y){
                direccionInky = 1;
            }
            else if (PacMan_y > Inky_y){
                direccionInky = 1;
            }
            else if (PacMan_y < Inky_y){
                direccionInky = 2;
            }
            else if (PacMan_x < Inky_x){
                direccionInky = 1;
            }
            else if (PacMan_x > Inky_x){
                direccionInky = 2;
            }     
            break;
        case '.': //Segun al salir de la guarida
            //Movimientos comparando la posicion del pacman actualmente y la posicion de Inky, para asi alejarse
            if (PacMan_x > Inky_x){
                direccionInky = 2;
            }
            else{
                direccionInky = 3;
            }
            break;
    }

    //Se imprime Inky
    gotoxy(Inky_x, Inky_y);
    printf(GREEN "%c", 219);
    printf(RESET);  

    Sleep(10); //Tiempo que se tarda en que se imprima a Inky    

    //Segun la salida de direccion
    switch(direccionInky){
        case 0: //Abajo
            if (EvaluarColision(Inky_x, Inky_y + 1)){
                LimpiarFantasma(Inky_x, Inky_y);
                Inky_y++;
                ImprimirPunto(Inky_x, Inky_y, 0);
            }
            BanderaChoqueInky = EvaluarChoque(Inky_x, Inky_y);
            if (BanderaChoqueInky){
                CasoComer = 3;
            }            
            break;
        case 1: //Arriba
            if (EvaluarColision(Inky_x, Inky_y - 1)){
                LimpiarFantasma(Inky_x, Inky_y);
                Inky_y--;
                ImprimirPunto(Inky_x, Inky_y, 1);
            }   
            BanderaChoqueInky = EvaluarChoque(Inky_x, Inky_y);
            if (BanderaChoqueInky){
                CasoComer = 3;
            }                    
            break;
        case 2: //Izquierda
            if (EvaluarColision(Inky_x - 1, Inky_y)){
                LimpiarFantasma(Inky_x, Inky_y);
                Inky_x--;
                ImprimirPunto(Inky_x, Inky_y, 2);
            }      
            else{
                if (Inky_y == 13 && Inky_x == 0){
                    LimpiarFantasma(Inky_x, Inky_y);
                    Inky_x = COLUMNAS - 22;
                }                
            }    
            BanderaChoqueInky = EvaluarChoque(Inky_x, Inky_y);
            if (BanderaChoqueInky){
                CasoComer = 3;
            }                       
            break; 
        case 3: //Derecha
            if (EvaluarColision(Inky_x + 1, Inky_y)){
                LimpiarFantasma(Inky_x, Inky_y);
                Inky_x++;
                ImprimirPunto(Inky_x, Inky_y, 3);
            }
            else{
                if (Inky_y == 13 && Inky_x == 42){
                    LimpiarFantasma(Inky_x, Inky_y);
                    Blinky_x = COLUMNAS - 64;
                }
            }    
            BanderaChoqueInky = EvaluarChoque(Inky_x, Inky_y);
            if (BanderaChoqueInky){
                CasoComer = 3;
            }                                
            break;          
    }    
}

bool EvaluarChoque(int Fantasma_x, int Fantasma_y){
    if (PacMan_x == Fantasma_x){
        if (PacMan_y == Fantasma_y){
            return true; //Cuando ambas coordenadas tanto de pacman como del fantasma son iguales, entonces regresa un verdadero
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void Reiniciar(){
    limpiar(); 
    vidas--; //Se resta una vida al perder
    Beep(200, 1000); //Sonido al perder
    gotoxy(X_PACMAN, Y_PACMAN); //Pacman vuelve al lugar de inicio
    printf("V");
    opcion = UP;
    PacMan_x = X_PACMAN; //Cambian las coordenadas de pacman
    PacMan_y = Y_PACMAN;
    switch(CasoComer){ //Segun el fantasma que se comio a pacman, se regresa a su lugar
        case 1:
            Clyde_x = X_GUARIDA;
            Clyde_y = Y_GUARIDA;    
            break;    
        case 2:
            Blinky_x = X_GUARIDA;
            Blinky_y = Y_GUARIDA;
            break;
        case 3:
            Inky_x = X_GUARIDA;
            Inky_y = Y_GUARIDA;
            break;
    }
}