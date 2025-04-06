; Numeros primos
; Author: reDragonCoder
; 01/04/2025
; Assembly Language  

.model small
.stack 100h
.data

    ; Arreglo original de �numeros
    array DB 13, 29, 17, 53, 61, 83, 97, 7, 9
    count DW 9      ; Cantidad de elementos en el arreglo
    
    ; Arreglo para lamacenar los numeros primos encontrados (capacidad maxima igual a count)
    Primos DB 9 DUP(?)
    numPrimos DW 0 

.code  
main PROC
    MOV AX, @data   ; Inicializar segmento de datos
    MOV DS, AX  
    
    MOV CX, count   ; CX = cantidad de elementos del arreglo
    MOV SI, 0       ; SI = indice del arreglo original
    XOR DI  , DI    ; DI = indice para el arreglo Primos (inicia en 0)

NEXTNUMBER:
    MOV AL, array[SI]   ; Cargar el numero actual en AL
    MOV BL, AL          ; BL conserva el numero para la verificacion
    
    ; Verificar si el numero es menor a 2 (no se consideran primos)
    CMP BL, 2
    JB NOTPRIME
    
    ; El numero 2 es primo
    CMP BL, 2
    JE STOREPRIME
    
    ; Para numeros mayores que 2, se prueba si tienen algun divisor entre 2 y (numero-1)
    MOV DL, 2       ; DL sera nuestro divisor, iniciamos en 2

PRIMELOOP:
    MOV AL, BL  ; Colocar el numero a verificar en AL
    XOR AH, AH  ; Limpiar AH para la division (AX = BL)
    DIV DL      ; Dividir BL (AL) entre DL; AL = cociente, AH = residuo
    CMP AH, 0
    JE NOTPRIME ; Si residuo es 0, BL es divisible por DL, por lo tanto no es primo
    INC DL      ; Incrementar divisor
    CMP DL, BL  ; Continuar mientras DL < BL
    JL PRIMELOOP
    
    ; Si se completa el ciclo sin encontrar divisor, el numero es primo
STOREPRIME:
    MOV AL, BL          ; AL = numero primo
    MOV Primos[DI], AL  ; Guardar el numero en el arreglo Primos
    INC DI              ; Incrementar indice para el siguiente primo
    JMP DONECHECK

NOTPRIME:
    ; Si no es primo, no se almacena y se continua con el siguiente numero
    NOP ; Esta instruccion no hace nada

DONECHECK:
    INC SI          ; Pasar al siguiente elemento del arreglo original
    LOOP NEXTNUMBER ; Repetir CX veces (count elementos) 
    
    ; Al finalizar, DI contiene la cantidad de numeros primos encontrados
    MOV numPrimos, DI
    
    
    ; Fin del programa
    MOV AH, 4Ch
    INT 21h
main ENDP
END main