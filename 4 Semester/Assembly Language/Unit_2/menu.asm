; Menu
; Author: reDragonCoder
; 10/04/2025
; Assembly Language  
          
.model small          
.stack 100h

.data
; Cadena para salto de linea (CR y LF) y para finalizar con '$'
salto   DB 13,10,'$'

; Menu y opciones (se utilizan CR y LF para saltos de linea)
menu    DB 13,10,'===== MENU =====',13,10
        DB '1. Say hello',13,10
        DB '2. Write your name and say hello',13,10
        DB '3. Exit',13,10
        DB 'Select an option: $'

; Variables para guardar la opcion leida
option  DB ?

; Buffer para entrada de cadena con funcion 0Ah
; Estructura:
;   - Byte 0: Capacidad maxima (en este caso 20)
;   - Byte 1: Numero de caracteres leidos
;   - A partir del Byte 2: Texto ingresado
buffer  DB 20   ; Capacidad maxima permitida
        DB ?    ; Capacidad de caracteres efectivamente leidos
        DB 20 dup('$')  ;Espacio para la cadena

;Mensajes adicionales
name_msg        DB 13,10,'Write your name: $'
hello_msg       DB 13,10,'Hello!$'
greeting_msg    DB 13,10,'Hello, $'
goodbye_msg     DB 13,10,'See you later!$'
error_msg       DB 13,10,'Non-valid option.$'

.code
main PROC
    ; Inicializa el segmento de datos para acceder a las variables
    MOV AX, @data
    MOV DS, AX

start_menu:
    MOV AH, 09h
    LEA DX, menu
    INT 21h

read_option:
    ; Funcion 01h: Lee un caracter y lo almacena en AL
    MOV AH, 01h
    INT 21h

    CMP AL, 13
    JE read_option

    MOV option, AL

    MOV AH, 09h
    LEA DX, salto
    INT 21h

    CMP option, '1'
    JE opcion_1

    CMP option, '2'
    JE opcion_2

    CMP option, '3'
    JE exit

    MOV AH, 09h
    LEA Dx, error_msg

opcion_1:
    MOV AH, 09h
    LEA DX, hello_msg
    INT 21h
    JMP start_menu

opcion_2:
    MOV AH, 09h
    LEA DX, name_msg
    INT 21h

    ; Leer la cadena de entrada con funcion 0Ah
    ; La funcion 0Ah utiliza el buffer definido para almacenar:
    ;   - En buffer[0]: Capacidad maxima
    ;   - En buffer[1]: Numero de caracteres leidos
    ;   -A partir de buffer+2: Cadena ingresada
    MOV AH, 0Ah
    LEA DX, buffer
    INT 21h

    MOV AH, 09h
    LEA DX, greeting_msg
    INT 21h

    LEA DX, buffer + 2
    MOV AH, 09h
    INT 21h

    JMP start_menu

exit:
    MOV AH, 09h
    LEA DX, goodbye_msg
    INT 21h

    MOV AH, 4Ch
    INT 21h

main ENDP
END main