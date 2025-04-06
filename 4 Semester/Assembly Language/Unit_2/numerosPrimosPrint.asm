; Numeros primos Print
; Author: reDragonCoder
; 02/04/2025
; Assembly Language

.model small
.stack 100h

.data
    ; Arreglo de numeros
    array   DB 7, 3, 4, 2, 5, 5, 13, 7, 4
    count   DW 9      ; Cantidad de elementos en el arreglo
    
    ; Arreglo para almacenar los numeros primos encontrados
    Primos  DB 9 DUP(?)
    numPrimos DW 0     
    
    ; Array para convertir y almacenar el numero actual a imprimir.
    ; Se reserva 3 bytes: dos para el digito (o digitos) y uno para el terminador '$'
    numStr  DB 3 DUP(?)

    ; Definir constante para el divisor (valor 10)
    ten DB 10
    
    ; Saltos y mensajes
    salto   DB 13, 10, "$"    ; 10 -> LF, 13 -> CR
    msg1    DB "Numero: ", "$"     
    msg2    DB "Es primo", "$"
    msg3    DB "No es primo", "$"
    
.code  
main PROC 
    ; Inicializar el segmento de datos
    MOV AX, @data
    MOV DS, AX  
    
    ; Inicializar indices:
    MOV CX, count       ; CX = cantidad de elementos a evaluar
    MOV SI, 0           ; SI = indice del arreglo 
    XOR DI, DI          ; DI = indice para el arreglo Primos (inicia en 0)

NEXTNUMBER:
    ; Cargar el numero actual del arreglo
    MOV AL, array[SI]
    ; Guardar el valor original en BL para la verificacion de primo
    MOV BL, AL         

    ; Realizar la conversion a cadena en el buffer numStr:
    ; Si el numero es menor que 10, se convierte a 1 digito;
    ; si es 10 o mayor, se convierte a 2 digitos.
    CMP BL, 10          
    JB ONE_DIGIT_CONVERSION  ; Si BL < 10, saltar a conversion de 1 digito

    ; Conversion para numeros de 2 digitos
    MOV AL, BL          ; Cargar el numero en AL
    XOR AH, AH          ; Limpiar AH (AX = BL)
    DIV ten             ; Dividir AX entre 10 usando la constante ten
                        ; AL <- digito de las decenas, AH <- digito de las unidades
    ADD AL, '0'         ; Convertir el digito de las decenas a ASCII
    MOV numStr, AL      ; Almacenar en numStr[0]
    MOV AL, AH          ; Recuperar el digito de las unidades
    ADD AL, '0'         ; Convertir a ASCII
    MOV numStr+1, AL    ; Almacenar en numStr[1]
    MOV BYTE PTR numStr+2, '$'  ; Terminar la cadena
    JMP PRINT_NUMBER

ONE_DIGIT_CONVERSION:
    ; Conversion para numeros de 1 digito 
    MOV AL, BL                  ; El numero es de un digito
    ADD AL, '0'                 ; Convertir a ASCII
    MOV BYTE PTR numStr, AL     ; Almacenar en numStr[0]
    MOV BYTE PTR numStr+1, '$'  ; Agregar el terminador de cadena
    JMP PRINT_NUMBER            ; Saltar a imprimir

PRINT_NUMBER:
    MOV AH, 09h
    LEA DX, salto
    INT 21h
    ; Imprimir el mensaje "Numero: "
    MOV AH, 09h
    LEA DX, msg1
    INT 21h

    ; Imprimir el numero convertido (cadena en numStr)
    MOV AH, 09h
    LEA DX, numStr
    INT 21h

    ; Imprimir salto de linea
    MOV AH, 09h
    LEA DX, salto
    INT 21h

    ; Verificar si el numero es primo
    ; Caso base (numero 2)
    CMP BL, 2
    JB NOTPRIME

    ; El numero 2 es primo
    CMP BL, 2
    JE STOREPRIME

    ; Para numeros mayores que 2, verificar divisibilidad (desde 2 hasta BL-1)
    MOV DL, 2           ; Iniciar divisor en 2

PRIMELOOP:
    MOV AL, BL          ; Cargar el numero en AL
    XOR AH, AH          ; Limpiar AH para la division
    DIV DL              ; Dividir BL entre DL; AL = cociente, AH = residuo
    CMP AH, 0
    JE NOTPRIME         ; Si el residuo es 0, el numero no es primo
    INC DL              ; Incrementar divisor
    CMP DL, BL          ; Repetir mientras DL < BL
    JL PRIMELOOP

    ; Si no se encuentra divisor exacto, se considera primo
STOREPRIME: 
    MOV AH, 09h
    LEA DX, msg2
    INT 21h
    MOV AH, 09h
    LEA DX, salto
    INT 21h 
    ; Almacenar el numero primo en el arreglo Primos
    MOV Primos[DI], BL
    INC DI
    JMP DONECHECK

NOTPRIME:       
    ; Imprimir mensaje "No es primo" 
    MOV AH, 09h
    LEA DX, msg3
    INT 21h
    MOV AH, 09h
    LEA DX, salto
    INT 21h      

DONECHECK:
    INC SI              ; Pasar al siguiente elemento del arreglo original
    LOOP NEXTNUMBER     ; Repetir CX veces

    ; Guardar la cantidad de numeros primos encontrados
    MOV numPrimos, DI
    
    ; Finalizar el programa (retorno a DOS)
    MOV AH, 4Ch
    INT 21h 
main ENDP
END main

