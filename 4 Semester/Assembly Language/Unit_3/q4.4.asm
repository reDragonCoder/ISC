; Q4.4
; Author: Celia Fernanda Vela Uribe & Cesar Andres Zuleta Malanco
; 13/05/2025
; Assembly Language
                    
.model small
.stack 

.data

.code    

main PROC
    MOV AX, @data
    MOV DS, AX
    
    ; 00111100 --> 60
    ; 0011.1100 --> 3.75    
    MOV AL, 24 
    MOV BL, 36
    ADD AL, BL
    
    MOV AH, 4Ch
    INT 21h

main ENDP
END main