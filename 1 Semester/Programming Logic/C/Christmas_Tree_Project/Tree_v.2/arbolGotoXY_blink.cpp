// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

//COLOR PALETTE
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define PURPLE "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define ORANGE "\033[33m"

//CHARACTER OPTIONS
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define DIM "\x1b[2m"

//FUNCTIONS
void gotoxy(int x, int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize=100;
    cursorInfo.bVisible=FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//MAIN
int main() {
	//variables
    int height=0, opc_color=0, aux_height=0, remaining=0, remaining2=0, remaining3=0;
    int i=0, j=0;
	int x=40;
	int y=10;
	int stars=1;
	int starX=0, starY=0; 

	//ask height
    printf("\nEnter the height of the tree (remember that the height must be in a range of 1 to 39): ");
    scanf("%d", &height);

    //validate height
    if(height>0 && height<40){
    	//print star menu
	    printf("1) RED \n");
	    printf("2) YELLOW \n");
	    printf("3) BLUE \n");
	    printf("4) PURPLE \n");
	    printf("5) Cyan \n");
	    //ask start color
	    printf("Enter the color of your star: ");
	    scanf("%d", &opc_color);
	    /*remind the user to use the _kbhit function*/
	    printf("To stop the star from flashing, press any key");
	    /*tree=n+1*/
	    height++;

	    //print tree
	    for(i=0; i<height; i++) {
	    	/*print tree (GREEN content of tree)*/
	    	/*do you mean leafs? --> inside joke*/
	        gotoxy(x, y);
	        for(j=0; j<stars; j++){
	            printf(GREEN "o" RESET);
	        }
	        printf("\n");
	        x--;
	        y++;
	        stars += 2;
	        //print main star
	        if(i==0){
	        	switch(opc_color){
	        		case 1:
	        			starX = x + 1; 
	            		starY = y - 1; 
	            		printf(RED "Merry Christmas!" RESET);
	            		gotoxy(starX, starY);
	            		printf(RED BOLD"*" RESET);
	        			break;
	        		case 2:
	        			starX = x + 1; 
	            		starY = y - 1; 
	            		printf(YELLOW "Merry Christmas!" RESET);
	            		gotoxy(starX, starY);
	            		printf(YELLOW BOLD"*" RESET);
	        			break;
	        		case 3:
	        			starX = x + 1; 
	            		starY = y - 1; 
	            		printf(BLUE "Merry Christmas!" RESET);
	            		gotoxy(starX, starY);
	            		printf(BLUE BOLD"*" RESET);
	        			break;
	        		case 4:
	        			starX = x + 1; 
	            		starY = y - 1; 
	            		printf(PURPLE "Merry Christmas!" RESET);
	            		gotoxy(starX, starY);
	            		printf(PURPLE BOLD"*" RESET);
	        			break;
	        		case 5:
	        			starX = x + 1; 
	            		starY = y - 1; 
	            		printf(CYAN "Merry Christmas!" RESET);
	            		gotoxy(starX, starY);
	            		printf(CYAN BOLD"*" RESET);
	        			break;
				}
	        }
	    }
		
		//print trunk
	    gotoxy(39, y);
	    printf(ORANGE "|||\n" RESET);
		
		//return height to its original value
	    height-=1;
	    
	    /*the star blinks only if height is less than 27*/
	    /*The secondary and tertiary star are calculated only if the height is greater than 27*/
	    /*calculate secondary and tertiary star coordinates*/
	    if(height>10 && height<=27){
	    	aux_height=(height/10)*10;
	        remaining=height-aux_height;
	        remaining2=height-aux_height;
	        if(remaining>=9){
		        remaining2-=1;
			}
			if(aux_height>=20 && aux_height<28){
				aux_height=height/10;
				remaining3=height-20;
				aux_height+=remaining3;
				remaining2-=aux_height;
			}
	        starY-=remaining-remaining2;
	    }
		
		/*print secondary and tertiary star with the color chosen by the user (flicker effect)*/
		if(height<=27){
			switch(opc_color){
		        case 1:
		        	do{
						hideCursor();
		    			for(i=0; i<10; i++) {
				        	gotoxy(starX, starY);
				        	_cputs(RED DIM"*" RESET);
				        	gotoxy(starX, starY);
				        	_cputs(RED BOLD"*" RESET);
						}	
					}while(!_kbhit());
		        	break;
		        case 2:
		        	do{
						hideCursor();
		    			for(i=0; i<10; i++) {
				        	gotoxy(starX, starY);
				        	_cputs(YELLOW DIM"*" RESET);
				        	gotoxy(starX, starY);
				        	_cputs(YELLOW BOLD"*" RESET);
						}	
					}while(!_kbhit());
		        	break;
		        case 3:
		        	do{
						hideCursor();
		    			for (i=0; i<10; i++) {
				        	gotoxy(starX, starY);
				        	_cputs(BLUE DIM"*" RESET);
				        	gotoxy(starX, starY);
				        	_cputs(BLUE BOLD"*" RESET);
						}	
					}while(!_kbhit());
		        	break;
		        case 4:
		        	do{
						hideCursor();
		    			for(i=0; i<10; i++) {
				        	gotoxy(starX, starY);
				        	_cputs(PURPLE DIM"*" RESET);
				        	gotoxy(starX, starY);
				        	_cputs(PURPLE BOLD"*" RESET);
						}	
					}while(!_kbhit());
		        	break;
		        case 5:
		        	do{
						hideCursor();
		    			for(i=0; i<10; i++) {
				        	gotoxy(starX, starY);
				        	_cputs(CYAN DIM"*" RESET);
				        	gotoxy(starX, starY);
				        	_cputs(CYAN BOLD"*" RESET);
						}	
					}while(!_kbhit());
		        	break;
			}
		}
		
		//return to the end of the program line
		gotoxy(0, y + 2);
		printf("\033[0m"); 
	}
	//print error if the height of the tree is greater than 39
	else{
		printf(ORANGE "Please enter a valid height!!" RESET);
	}
    return 0;
}



