; Q4.4 - Exercise
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
     
    ; -2.75 + 1.50 = -1.25 --> Q4.4   
    MOV AL, 11010100b ; -2.75 | -44    
    MOV BL, 00011000b ; 1.50 | 24 
    ADD AL, BL
    
    MOV AH, 4Ch
    INT 21h

main ENDP
END main