; Suma con variables
; Celia Fernanda Vela Uribe - Cesar Andres Zuleta Malanco
; 05/03/2025
; Ensamblador

.model small

.stack

.data         

; Variable BYTE       
var1 DB 255

; Variable WORD
var2 DW 65535

; Arreglos
arreglo DB 1,1,1,1,1,1
arreglo2 DW 1, 10, 100, 1000, 10000
arreglo3 DB 5 dup(2)

; Variables no inicializadas
num1 DW ?
num2 DW ?
resul DW ? 

.code
main PROC
    MOV AX, @data   ; Inicializacion del segmento de datos
    MOV DS, AX
    
    ; Suma de las variables num1 + num2
    MOV AX, num1
    ADD AX, num2
    MOV resul, AX
    
    ; Si quiero sumar 255 + 255, que cambios debo hacer?
    
    ; Para multiplicar, que cambio debo hacer?
    MOV AX, num1
    MUL num2
    
    ; Terminar programa correctamente
    MOV AH, 4Ch ; Funcion 4Ch: Terminar programa en DOS
    INT 21h     ; Llamada a interrupcion DOS
main ENDP
END main