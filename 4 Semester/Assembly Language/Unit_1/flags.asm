; Zero Flag & Compare Flag
; Author: reDragonCoder
; 06/03/2025
; Ensamblador

.model small

.stack

.data 

.code
main PROC
    MOV AX, @data ; Inicializacion del segmento de datos
    MOV DS, AX
    
    ; Compare (CMP): sirve para hacer comparaciones. Implicitament rest el segundo operando menos el primero 
    ; pero solo se refleja en las banderas (FLAGS)
    
    ; Zero Flags(ZF): Se enciende (se pone en 1) cuando el resultado es 0
    ; Se apaga (se pone en 0) cuando el resultado no es 0
    
    ;Ejemplo de uso
    MOV AL, 7
    MOV BL, 7
    CMP AL, BL
    
    MOV AL, 5
    CMP AL, 6
    
    MOV AX, 256
    CMP AX, 256
    
    MOV AL, 10
    CMP AL, 50
    
    ;SALTOS
    ;Jump if Zero (JZ): Salta si el resultado es cero, es decir, si ZF es activa 
    MOV AL, 20
    CMP AL, 20
    JZ  RESULT_IS_ZERO
    
    MOV BH, 20 
    
    RESULT_IS_ZERO:
        MOV BL, 45
    
    MOV AL, 6 
    CMP AL, 9
    JNZ RESULT_IS_NOT_ZERO
    
    MOV BH, 20
    
    RESULT_IS_NOT_ZERO:
        MOV BL, 1
    
    MOV AL, 4
    CMP AL, 4
    JNZ ET1
    
    ET1:
        MOV AH, 40
    
    MOV AL, 5
    CMP AL, 5
    JNZ ET2 
    
    JMP TERMINATE
    
    ET2:
        MOV AH, 55
    
    TERMINATE:
    MOV AH, 4Ch
    INT 21h
main ENDP
END main