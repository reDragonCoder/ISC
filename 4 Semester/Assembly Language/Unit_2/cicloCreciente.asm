; Ciclo creciente
; Author: reDragonCoder
; 18/03/2025
; Assembly Language  

.model small

.stack

.data
    arreglo_1 DB 1,2,3,4,5,6,7,8,9,10
    arreglo_2 DB 10 dup(0)
    
.code
main PROC
    MOV AX, @data   ; Inicializacion del segmento de datos
    MOV DS, AX
    
    ; SI: Source Index
    MOV si, 0   
    ; DI: Destination Index
    MOV DI, 0
    
    BUCLE:
    MOV AL, arreglo_1[SI]
    MOV arreglo_2[DI], AL
    INC SI  ; Incrementar SI
    INC DI  ; Incrementar DI
    CMP DI, 10
    JL BUCLE    ; JL: Jump if Less
    JMP TERMINAR
    
    TERMINAR:
    ; Terminar programa correctamente
    MOV AH, 4Ch ; Funcion 4Ch: Terminar programa en DOS
    INT 21h ; Llamada a interrupcion DOS

main ENDP
END main



