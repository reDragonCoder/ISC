// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <windows.h>
#include <conio.h> 
#include <ctype.h>
#include <time.h>

//PROTOTYPES
void showTable(); 
void wallTable();
void pacmanTable();
void pacman(); 
bool hitWallUp(int[]);
bool hitWallDown(int[]);
bool hitWallLeft(int[]);
bool hitWallRight(int[]);
void gotoxy(int,int);
void hideCursor(); 
void iDontKnowWhatItDoesButItWorks(int[]);
void clearLine(int []);
void pacmanMov(int, int[]);
void clyde();


//Posicion inicial del pacman en el tablero
const int PACMANSTART_X=21;
const int PACMASTART_Y=16;

const int CLYDE_X=25;
const int CLYDE_Y=13;

//Numero de lineas para quitar el mensaje al final del programa
const int LINEJUMPS=30;

//MAIN
int main(){
    pacman(); //Aqui inicia lo chido >:v
}

//Functions implementation
void showTable(){

    //Caracteres del tablero
    char upper_left_corner=201; 
    char horizontal_wall=205; 
    char upper_right_corner=187; 
    char vertical_wall=186; 
    char lower_right_corner=188; 
    char lower_left_corner=200; 
    char power_points=248; 
    char food_points=250;
    char space=' '; 
    char alcove=196; 
    char ghost=190;

    //Matriz del tablero
    char table[29][44]={ 
     "AxxxxxxxxxxxxxxxxxxxB AxxxxxxxxxxxxxxxxxxxB",
     "I________+__________I I__________+________I",
     "I_AxxxxxB_AxxxxxxxB_I I_AxxxxxxxB_AxxxxxB_I",
     "I_I     I_I       I_I I_I       I_I     I_I",
     "I_DxxxxxC_DxxxxxxxC_DxC_DxxxxxxxC_DxxxxxC_I",
     "I_________________________________________I",
     "I_AxxxxxB_AxB_AxxxxxxxxxxxxxB_AxB_AxxxxxB_I",
     "I_DxxxxxC_I I_DxxxxB   AxxxxC_I I_DxxxxxC_I",
     "I_________I I______I   I______I I_________I",
     "DxxxxxxxB_I DxxxxB I   I AxxxxC I_AxxxxxxxC",
     "        I_I AxxxxC DxxxC DxxxxB I_I        ",
     "        I_I I                 I I_I        ",
     "xxxxxxxxC_DxC Axxxxx***xxxxxB DxC_Dxxxxxxxx",
     "         _    I F  F  F  F  I    _         ",
     "xxxxxxxxB_AxB DxxxxxxxxxxxxxC AxB_Axxxxxxxx",
     "        I_I I                 I I_I        ",
     "        I_I I AxxxxxxxxxxxxxB I I_I        ",
     "AxxxxxxxC_DxC DxxxxB   AxxxxC DxC_DxxxxxxxB",
     "I__________________I   I__________________I",
     "I_AxxxxxB_AxxxxxxB_I   I_AxxxxxxB_AxxxxxB_I",
     "I_DxxxB I_DxxxxxxC_DxxxC_DxxxxxxC_I AxxxC_I",
     "I_____I I_________________________I I_____I",
     "DxxxB_I I_AxB_AxxxxxxxxxxxxxB_AxB_I I_AxxxC",
     "AxxxC_DxC_I I_DxxxxB   AxxxxC_I I_DxC_DxxxB",
     "I_________I I______I   I______I I_________I",
     "I_AxxxxxxxC DxxxxB_I   I_AxxxxC DxxxxxxxB_I",
     "I_DxxxxxxxxxxxxxxC_DxxxC_DxxxxxxxxxxxxxxC_I",
     "I_________________+_____+_________________I",
     "DxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxC",
    };

    //Imprimir el tablero
    for(int i=0; i<29; i++){
        for (int j=0; j<44; j++){
            //Switch para ver el caso segun la letra de la matriz e imprimirlo
        	switch(table[i][j]){
        		case 'x':
        			printf("%c", horizontal_wall, table[i][j]);
        			break;
        		case 'A':
        			printf("%c", upper_left_corner, table[i][j]);
        			break;
        		case 'B':
                    printf("%c", upper_right_corner, table[i][j]);
                    break;
                case 'C':
                    printf("%c", lower_right_corner, table[i][j]);
                    break;
                case 'D':
                    printf("%c", lower_left_corner, table[i][j]);
                    break;
                case 'I':
                    printf("%c", vertical_wall, table[i][j]);
                    break;
                case '_':
                    printf("%c", power_points, table[i][j]);
                    break;
                case '+':
                    printf("%c", food_points, table[i][j]);
                    break;
                case '*':
                    printf("%c", alcove, table[i][j]);
                    break;
                case 'F':
                    printf("%c", ghost, table[i][j]);
                    break;               
        		default:
        			printf("%c", space, table[i][j]);
        			break;
			}
        }
        //Salto de linea entre cada renglon
        printf("\n");
    }
}


//Funcion para poder movernos en coordenadas x/y
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

//Funcion para ocultar el cursor
void hideCursor(){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize =100;
    cci.bVisible= FALSE; //False para que no se muestre
    SetConsoleCursorInfo(hcon,&cci);
}

void pacman(){
    int lives=1; //Numero de vidas
    int dude[2]={PACMANSTART_X, PACMASTART_Y}; //Posicion inicial del pacman
    gotoxy(dude[0], dude[1]); //Poner el pacman en esa posicion
    //printf("c"); ¿Esto era necesario?
    for(int i=0; i<LINEJUMPS; i++){ //Mover el mensaje de fin de programa, y que no se vea empalmado
        printf("\n");
    }

    pacmanMov(lives, dude); //Llamar funcion para el movimiento del pacman
}

void pacmanMov(int lives, int dude[]){
    char key;
    char pacman_down = 94; //Caracter para el movimiento de pacman hacia abajo
    bool flag=false;
    iDontKnowWhatItDoesButItWorks(dude); //Llamar funcion para poner el pacman y el tablero
    hideCursor(); //No se muestra el cursor
    while(lives!=0){
        if(kbhit){ //Condicion para la colision
            key=getch(); //Obtener movimiento
            key=tolower(key); //Pasarlo a minuscula
            switch(key){
                case 'w': //En caso de que sea w
                    clearLine(dude); //Se limpia la posicion en la que se encontraba pacman
                    flag=hitWallUp(dude);
                    if (flag==false){
                        dude[1]--; //Cambia la posicion de pacman, en las y menos 1
                        gotoxy(dude[0], dude[1]); //Se pone el cursor en la nueva posicion
                        printf("v"); //Se imprime ahora el pacman
                    }
                    else if (flag==true){
                        gotoxy(dude[0], dude[1]); //Se pone el cursor en la nueva posicion
                        printf("v"); //Se imprime ahora el pacman
                    }
                    break;
                case 'a': //En caso de que sea a
                    clearLine(dude); //Se limpia la posicion en la que se encontraba pacman
                    flag=hitWallLeft(dude);
                    if (flag==false){
                       dude[0]--; //Cambia la posicion de pacman, en las x menos 1
                        gotoxy(dude[0], dude[1]); //Se pone el cursor en la nueva posicion
                        printf(">"); //Se imprime ahora el pacman
                    }
                    else if (flag==true){
                        gotoxy(dude[0], dude[1]); //Se pone el cursor en la nueva posicion
                        printf(">"); //Se imprime ahora el pacman
                    }
                    break;
                case 's': //En caso de que sea a
                    clearLine(dude); //Se limpia la posicion en la que se encontraba pacman
                    flag=hitWallDown(dude);
                    if (flag==false){
                        dude[1]++; //Cambia la posicion de pacman, en las y mas 1
                        gotoxy(dude[0], dude[1]); //Se pone el cursor en la nueva posicion
                        printf("%c", pacman_down); //Se imprime ahora el pacman
                    }
                    else if (flag==true){
                        gotoxy(dude[0], dude[1]); //Se pone el cursor en la nueva posicion
                        printf("%c", pacman_down); //Se imprime ahora el pacman
                    }
                    break;
                case 'd': //En caso de que sea d
                    clearLine(dude); //Se limpia la posicion en la que se encontraba pacman
                    flag=hitWallRight(dude);
                    if (flag==false){
                       dude[0]++; //Cambia la posicion de pacman, en las x mas 1
                       gotoxy(dude[0], dude[1]);//Se pone el cursor en la nueva posicion
                       printf("<"); //Se imprime ahora el pacman
                    }
                    else if (flag==true){
                        gotoxy(dude[0], dude[1]);//Se pone el cursor en la nueva posicion
                        printf("<"); //Se imprime ahora el pacman
                    }
                    break;
                case 'k':
                    lives = 0;
                    break;
            }
        }
    }
}

void iDontKnowWhatItDoesButItWorks(int dude[]){
    system("cls"); //Limpiar espacios de la pantalla 
    showTable(); //Se muestra en la pantalla el tablero
    dude[1]--; //Se mueve en y la posicion 
    gotoxy(dude[0], dude[1]); //Poner el cursor en la nueva posicion
    printf(">"); //Imprimir el pacman
}

void clearLine(int dude[]){
   gotoxy(dude[0], dude[1]); //Posicion actual de pacman
   printf(" ");  //Espacio en blanco
}

bool hitWallUp(int dude[]){
    bool wall=false;
    //w
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=13&&dude[0]!=29&&dude[0]!=9&&dude[0]!=33)&&dude[1]==15){//wall bellow the alcove
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=29&&dude[0]!=9&&dude[0]!=13&&dude[0]!=33)&&dude[1]==13){//teleportation
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=18&&dude[0]!=24&&dude[0]!=9&&dude[0]!=33)&&dude[1]==11){//fork avobe the alcove
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=13&&dude[0]!=29&&dude[0]!=9&&dude[0]!=33&&dude[0]!=1&&dude[0]!=41)&&dude[1]==8){//Top T and Friends
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=9&&dude[0]!=19&&dude[0]!=23&&dude[0]!=33&&dude[0]!=1&&dude[0]!=41)&&dude[1]==5){ //the bottom of then squares at the top and their alleys
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0)&&dude[1]==1){ //THE LITERAL TOP
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=13&&dude[0]!=29&&dude[0]!=9&&dude[0]!=33)&&dude[1]==18){ //the bottom t 
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=9&&dude[0]!=33&&dude[0]!=3&&dude[0]!=40&&dude[0]!=18&&dude[0]!=24&&dude[0]!=1&&dude[0]!=41)&&dude[1]==21){ //inverted L's
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=13&&dude[0]!=29&&dude[0]!=9&&dude[0]!=33&&dude[0]!=5&&dude[0]!=37)&&dude[1]==24){ //the most bottom t 
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=18&&dude[0]!=24&&dude[0]!=1&&dude[0]!=41)&&dude[1]==27){ //THE LITERAL BOTTOM
        wall = true;
    }
    return wall;
}

bool hitWallDown(int dude[]){
    bool wall=false;
    //s
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=13&&dude[0]!=29&&dude[0]!=9&&dude[0]!=33)&&dude[1]==15){//wall bellow the alcove
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=29&&dude[0]!=9&&dude[0]!=13&&dude[0]!=33)&&dude[1]==13){//teleportation
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=9&&dude[0]!=33&&dude[0]!=1&&dude[0]!=41&&dude[0]!=18&&dude[0]!=24)&&dude[1]==18){ //the bottom t 
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=13&&dude[0]!=29&&dude[0]!=9&&dude[0]!=33&&dude[0]!=5&&dude[0]!=37)&&dude[1]==21){ //inverted L's
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=18&&dude[0]!=24&&dude[0]!=1&&dude[0]!=41)&&dude[1]==24){ //inverted L's
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=18&&dude[0]!=24&&dude[0]!=1&&dude[0]!=41)&&dude[1]==27){ //THE ALMOST BOTTOM
        wall = true;
    }
     if((dude[0]<=42&&dude[0]>=0)&&dude[1]==27){ //THE LITERAL BOTTOM
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=9&&dude[0]!=33&&dude[0]!=18&&dude[0]!=24)&&dude[1]==8){//Top T and Friends
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=13&&dude[0]!=29&&dude[0]!=9&&dude[0]!=33)&&dude[1]==11){//fork avobe the alcove
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=9&&dude[0]!=13&&dude[0]!=29&&dude[0]!=33&&dude[0]!=1&&dude[0]!=41)&&dude[1]==5){ //the bottom of then squares at the top and their alleys
        wall = true;
    }
    if((dude[0]<=42&&dude[0]>=0&&dude[0]!=9&&dude[0]!=19&&dude[0]!=23&&dude[0]!=33&&dude[0]!=1&&dude[0]!=41)&&dude[1]==1){ //the TOP of then squares at the top and their alleys
        wall = true;
    }
    return wall;
}

bool hitWallLeft(int dude[]){
    bool wall=false;
    //a
    if (dude[0]==1){ //LEFT MOST WALL
        wall = true;
    }
    if (dude[0]==9&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=13&&dude[1]!=8&&dude[1]!=18&&dude[1]!=27&&dude[1]!=24)){ //LEFT ALMOST MOST WALL
        wall = true;
    }
    if (dude[0]==13&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=13&&dude[1]!=18&&dude[1]!=21&&dude[1]!=27)){ //before entering teleportatiom
        wall = true;
    }
    if (dude[0]==18&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=8&&dude[1]!=15&&dude[1]!=11&&dude[1]!=18&&dude[1]!=24&&dude[1]!=21&&dude[1]!=27)){ //IDK, T'S I GUESS
        wall = true;
    }
    if (dude[0]==19&&(dude[1]>=2&&dude[1]<=4)){
            wall = true;
    }
    if (dude[0]==29&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=15&&dude[1]!=11&&dude[1]!=8&&dude[1]!=18&&dude[1]!=21&&dude[1]!=27&&dude[1]!=24)){ //IDK, T'S I GUESS X2
        wall = true;
    }
    if (dude[0]==23&&(dude[1]>=0&&dude[1]<=4)){//THE lID BIT AT THE TOP
        wall = true;
    }
    if (dude[0]==5&&(dude[1]>=22&&dude[1]<=23)){//THE lID BIT AT THE TOP
        wall = true;
    }
    if (dude[0]==24&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=15&&dude[1]!=11&&dude[1]!=27&&dude[1]!=21)){//THE lID BIT AT THE TOP
        wall = true;
    }
    if (dude[0]==33&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=13&&dude[1]!=27&&dude[1]!=21&&dude[1]!=18)){
        wall = true; //THE ALMOST MOST RIGHT WALLS
    }
    if (dude[0]==41&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=8&&dude[1]!=13&&dude[1]!=18&&dude[1]!=21&&dude[1]!=27&&dude[1]!=24)){// the basically end
        wall = true;
    }
    if (dude[0]==37&&(dude[1]>=21&&dude[1]<=23)){ //BIG SQUARE UPPER LEFT
        wall = true;
    }
    return wall;
}

bool hitWallRight(int dude[]){
    bool wall=false;
    if (dude[0]==1&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=13&&dude[1]!=8&&dude[1]!=18&&dude[1]!=27&&dude[1]!=24&&dude[1]!=21)){ //RIGHT MOST WALL
        wall = true;
    }
    if (dude[0]==9&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=13&&dude[1]!=27&&dude[1]!=21&&dude[1]!=18)){
        wall = true; //THE ALMOST MOST RIGHT WALLS
    }
    if (dude[0]==13&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=15&&dude[1]!=11&&dude[1]!=8&&dude[1]!=18&&dude[1]!=21&&dude[1]!=27&&dude[1]!=24)){ //IDK, T'S I GUESS X2
        wall = true;
    }
    if (dude[0]==18&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=15&&dude[1]!=11&&dude[1]!=27&&dude[1]!=21)){//THE lID BIT AT THE TOP
        wall = true;
    }
    if (dude[0]==19&&(dude[1]>=0&&dude[1]<=4)){ //LID UP
        wall = true;
    }
    if (dude[0]==23&&(dude[1]>=2&&dude[1]<=4)){//THE lID BIT AT THE TOP
        wall = true;
    }
    if (dude[0]==29&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=13&&dude[1]!=18&&dude[1]!=21&&dude[1]!=27)){ //before entering teleportatiom
        wall = true;
    }
    if (dude[0]==24&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=8&&dude[1]!=15&&dude[1]!=11&&dude[1]!=18&&dude[1]!=24&&dude[1]!=21&&dude[1]!=27)){ //IDK, T'S I GUESS
        wall = true;
    }
    if (dude[0]==33&&(dude[1]!=1&&dude[1]!=5&&dude[1]!=13&&dude[1]!=8&&dude[1]!=18&&dude[1]!=27&&dude[1]!=24)){ //LEFT ALMOST MOST WALL
        wall = true;
    }
    return wall;
}

