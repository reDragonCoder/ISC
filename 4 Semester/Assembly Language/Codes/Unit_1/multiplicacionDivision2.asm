; Multiplicacion y division
; Celia Fernanda Vela Uribe - Cesar Andres Zuleta Malanco
; 03/03/2025
; Lenguaje Ensamblador

.model small

.stack 

.data

.code   

main PROC
    MOV AX, @DATA 
    MOV DS, AX
    
    ; MULTIPLICACION BYTE    
    MOV AL, 10     ; A - hexadecimal
    MOV BL, 7      ; 7 - hexadecimal
    MUL BL         ; Resultado en AX 46 (hexadecimal)
    
    
    ; MULTIPLICACION WORD 
    MOV AX, 550    ; 226 - hexadecimal
    MOV BX, 233    ; E9 - hexadecimal
    MUL BX         ; Resultado en AX y DX 1F496 (hexadecimal)
    
    
    ; DIVISION WORD / WORD  
    MOV AX, 777    ; 309 - hexadecimal
    MOV BL, 43     ; 2B - hexadecimal
    DIV BL
    ;AH guarda el residuo 3 (hexadecimal)
    ;AL guarda el resultado 12 (hexadecimal)
    
    
    
    ; DIVISION DWORD / WORD    
    MOV DX, 0098h   ; 152 (decimal)
    MOV AX, 4563h   ; 17763(decimal)
    ; 9,979,235 en decimal (dividendo)
    
    MOV BX, 21F1h
    ; 8689 en decimal (divisor)
    
    DIV BX
    ; 9,979,235 / 8689 =  121 (47C)
    ;DX guarda el residuo 10A7 (hexadecimal)
    ;AX guarda el resultado 47C (hexadecimal)
    
 
    
    ;---------------------------------------------------
    ; Terminar programa correctamente
    MOV AH, 4Ch ; Funcion 4Ch: Terminar programa en DOS
    INT 21h     ; Llamada a interrupcion DOS
    
main ENDP
END