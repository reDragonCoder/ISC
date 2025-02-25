; Impresion de caracter
; Celia Fernanda Vela Uribe - Cesar Andres Zuleta Malanco
; 25/02/2025
; Lenguaje Ensamblador

.model small

.stack

.data
    char DB " ", "$"
    salto DB 10, 13, "$" ; 10 ->LF (similar a \n) ...; 13 -> CR Regresa el cursor al inicio de la linea

.code

MAIN PROC
    MOV AX, @data
    MOV DS, AX
    ; MOV ES, AX
    
    ; Lectura del caracter
    MOV AH, 01H
    INT 21H
    MOV char, AL
    
    ; Impresion del salto de linea
    MOV AH, 09H
    LEA DX, salto
    INT 21H 
    
    ; Impresion del valor de la variable
    MOV AH, 09H
    LEA DX, char
    INT 21H
    
    .exit
MAIN ENDP
END
    