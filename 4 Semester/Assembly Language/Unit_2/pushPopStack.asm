; Push y Pop (Stack)
; CAuthor: reDragonCoder
; 20/03/2025
; Assembly Language
      
.model small

.stack 100h ; Reservamos 256 bytes de memoria para la pila 
      
.data

.code
main PROC
    MOV AX, @data   ; Inicializacion del segmento de datos
    MOV DS, AX
    
    ; Inicializar algunos valores (arbitrarios)
    MOV AX, 1
    MOV BX, 1024
    MOV CX, 100
    MOV DX, 15
    
    ; Poner los valores en la pila (Push)
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX 
    
    ; Sacar los valores de la pila y ponerlos en AX (Pop)
    POP AX
    POP AX
    POP AX
    POP AX
    
    ; Intercambio de valores usando la pila (Sin variable auxiliar) *****
    MOV AX, 10  ; AX = 10
    MOV BX, 20  ; BX = 20
    
    PUSH AX ; Guardar AX en la pila (10)
    PUSH BX ; Guardar BX en la pila (20)
    
    POP AX  ; Sacar el ultimo valor (20) y guardarlo en AX
    POP BX  ; Sacar el ultimo valor (10) y guardarlo en BX
    
    TERMINAR:
    ; Terminar programa correctamente
    MOV AH, 4Ch ; Funcion 4Ch: Terminar programa en DOS
    INT 21h ; Llamada a interrupcion DOS

main ENDP
END main
    