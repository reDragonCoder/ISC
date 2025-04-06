; Suma de dos numeros
; Author: reDragonCoder
; 27/02/2025
; Lenguaje Ensamblador

.model small
.stack
.data
.code
    
main PROC
    MOV AX, @data
    MOV DS, AX
    ; MOV ES, AX
    
    ; Suma
    MOV AL, 5
    ADD AL, 8 ;El limite maximo de AL es 255 -8 bits    
    
    ; Suma
    MOV AL, 5
    ADD AL, -5
    
    ; Suma
    MOV AL, 5
    ADD AL, -10
    
    ; Resta
    MOV AL, 5
    SUB AL, 1
    
    ; Resta
    MOV AL, 5
    SUB AL, -10
    
    ; Terminar programa correctamente
    MOV AH, 4Ch ; Funcion 4Ch: Terminar programa en DOS
    INT 21h     ; Llamada a interrupcion DOS
main ENDP
END main