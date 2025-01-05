// Author: reDragonCoder
//Make a program in C, which captures two strings of characters (s1 and s2) and how result the number of times that string 
//s1 appears in string s2. May or may not use the functions contained in string.h or ctype.h.

//LIBRARIES
#include <stdio.h>

//MAIN
int main() {
    //VARIABLES
    char s1[]="si", s2[]="si y solo si, si?";
    int i=0, j=0, n=0;
    int c=0;
    while(s2[j]!='\0'){
        for (i=0; s1[i]!='\0';)
            if (s1[i++]==s2[j++])
               c=1;
            else{
               c=0;
               break; 
            } 
        n+=(c==1)?1:0;
    }
    printf("%d times\n", n);
    return 0;
}