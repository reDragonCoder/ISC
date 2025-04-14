; Carga de valores
; Author: reDragonCoder
; 11/04/2025
; Assembly Language  
        
.model small        
.stack 100h

.data
    value1 DB 10
    value2 DB 20
    result DB 0

.code
main PROC
    MOV AX, @data
    MOV DS, AX

    ; 1. MODO INMEDIATO
    ; Se carga un valor directamente 
    MOV AL, 5

    ; 2. MODO DIRECTO
    ; Se carga un valor de una direccion fija (variable)
    MOV BL, value1
    MOV BH, value2

    ; 3. MODO DE REGISTRO
    ; Se hace una operacion entre registros
    ADD BL, BH

    ; Guardemos el resultado en memoria (modo directo de nuevo)
    MOV result, BL 

    ; 4. MODO INDIRECTO POR REGISTRO
    ; Usamos un registro (como SI) para apuntar a memoria
    LEA SI, value1  ; SI apunta a valor1
    MOV AL, [SI]    ; AL = contenido [SI] = 10

    ; 5. MODO CON  DESPLAZAMIENTO
    ; Accedemos a valor2 usando SI + DESPLAZAMIENTO
    ; valor2 esta 1 byte despues de valor1
    MOV AH, [SI+1]

    TERMINAR: 
    MOV AH, 4Ch
    INT 21h
main ENDP
END main