; Exam code
; Author: reDragonCoder
; 10/03/2025
; Assembly Language

.model
.stack
.data
    name1 db "Cesar Zuleta", "$" 
    char db " ", "$"
    endl db 10, 13, "$"
    name2 db "Fernanda Vela", "$"
.code

main PROC   
    ; PRINT NAMES
    MOV AX, SEG name1
    MOV DS, AX
    
    MOV BX, SEG name2
    MOV DS, BX   
    
    MOV AH, 09H
    LEA DX, name1
    INT 21H  
    
    MOV AH, 09H
    LEA DX, endl
    INT 21H
    
    MOV BH, 09H
    LEA DX, name2
    INT 21H
    
    ; INITIALIZATION
    MOV AX, @data
    MOV DS, AX
    
    ; ADD
    MOV AL, 74h
    ADD AL, 65h
    
    ; SUB
    MOV AL, 74h
    SUB AL, 65h
    
    ; MUL BYTE
    MOV AL, 74h
    MOV BL, 65h
    MUL BL
    
    ; MUL WORD - RESULT * 500
    MOV BX, 1F4h
    MUL BX
    
    ; DIV WORD/WORD
    MOV AX, 74h
    MOV BL, 65h
    DIV BL
    
    ; DIV DWORD/WORD
    MOV DX, 20h
    MOV AX, 65h    
    MOV BX, 74h
    DIV BX 
    
    MOV AL, 74h
    ;MOV BL, 65h
    CMP AL, 65h
    JNZ RESULT_IS_NOT_ZERO
    
    MOV AL, 1  
    
    RESULT_IS_NOT_ZERO: 
        MOV AL, 50
    
    
    .exit

main ENDP
END main