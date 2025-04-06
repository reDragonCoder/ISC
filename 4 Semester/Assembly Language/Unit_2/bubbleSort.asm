; Bubble Sort
; Author: reDragonCoder
; 31/03/2025
; Assembly Language 
.stack 100h

.data
    array DB 1, 15, 12, 20, 4, 2, 8, 35, 30

.code
main PROC
    MOV AX, @data
    MOV DS, AX
    
    MOV CX, 8 ;COUNTER REGISTER STORES THE NUMBER OF COMPARISONS (SIZE OF ARRAY - 1) 
       
    LOOP_1:
    PUSH CX
    MOV  SI, 0
    MOV  DI, 0
    
    LOOP_2:
    INC DI
    MOV AL, array[SI]
    CMP AL, array[DI]
    JB SWAP ;SALTA A SWAP SI ES MAYOR (ABOVE)
    JA LESS ;SALTA A LESS SI ES MENOR (BELOW)
    
    SWAP:
    MOV AH, array[DI]
    MOV array[DI], AL
    MOV array[SI], AH
    
    LESS:
    INC SI
    LOOP LOOP_2 ;Decrepenta CX en 1 y salta a LOOP_2 si es diferente de 0
    POP CX                                       
    LOOP LOOP_1 ;Decrementa CX en 1 y salta a LOOP_1 si es diferente de 0
    
    TERMINAR:
    MOV AH, 4Ch
    INT 21h

main ENDP
END main