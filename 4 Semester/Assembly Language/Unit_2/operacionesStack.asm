; Operaciones con stack
; Celia Fernanda Vela Uribe
; 20/03/2025
; Assembly Language   

.model

.stack

.data

.code
MAIN PROC
    MOV AX, 3   ; A = 3
    MOV BX, 6   ; B = 6
    MOV CX, 13  ; C = 13
    MOV DX, 2   ; D = 2
    
    ; Guardar valores en un orden distinto
    PUSH BX ; B = 6
    PUSH CX ; C = 13
    PUSH AX ; A = 3
    PUSH DX ; D = 2
    
    ; Extraer valores en un orden diferente
    POP AX  ; AX = D = 2
    POP DX  ; DX = A = 3 
    POP CX  ; CX = C = 13
    POP BX  ; BX = B = 6
    
    ; Realizar operaciones con el nuevo orden
    ADD AX, DX  ; AX = D + A = 2 + 3 = 5 
    SUB BX, CX  ; BX = B - C = 6 - 13 = -7 
    
    IMUL BX     ; AX = AX * BX = 5 * (-7) = -35
    
    ; AX ahora contiene el resultado (-35)
    
    MOV AH, 4CH ; Terminar programa correctamente
    INT 21H
MAIN ENDP
END MAIN




