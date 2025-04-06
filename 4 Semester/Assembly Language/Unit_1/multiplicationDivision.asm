; Multiplication & Division
; Author: reDragonCoder
; 03/03/2025
; Lenguaje Ensamblador

.model small

.stack

.data

.code
main PROC
    MOV AX, @data ; Initialization of the data segment
    MOV DS, AX
    
    ; MULTIPLICATION
    ; There are two types, one for BYTE and one for WORD
    
    ; For BYTE, the result is stored in AX (Maximum value is 255)
    MOV AL, 150
    MOV BL, 2                        
    MUL BL  ; This is implicitly by AL
    ; The result is 300 (12Ch)
    
    ;Another example
    MOV AL, 14
    MOV BL, 55
    MUL BL
    ; The result is 770(302h)
    
    ;Multiplying the maximum values
    MOV AL, 255
    MOV BL, 255
    MUL BL
    ; The result is 65,025 (FE01h)
    
    ; For WORD, the result is stores in DX and AX (Maximum value is 65,535)
    MOV AX, 300 ; The 300 goes over the allowed 8 bits (1 byte), thus we must loaded into the AX register  
    MOV BX, 500 ; The same thing happens with the 500, but it is now stored in BX
    MUL BX ; Implicit multiplication with AX
    ; The result is 150,000 (249f0h) 
    
    ;Another example, using DX
    MOV AX, 270 
    MOV DX, 1000
    MUL DX
    ; The result is 270,000 (41EB0h)
    
    ; The maximum multiplication that can be done with word: 65,535 * 65,535
    MOV AX, 65535
    MOV BX, 65535
    MUL BX
    ; The result is 4,924,836,225 (FFFE0001h)
    
    
    ; DIVISION
    ; It can be done with:
    ; - WORD / WORD (16 bits/16 bits) 
    ; - DWORD / WORD (32 bits/16 bits)
    MOV AX, 505
    MOV BL, 3
    DIV BL ; Implicitly divided by the AX
    ; As a result, AH stored the residue, while Al stores the quotient
    ; 505/3= 168 with a residue of 1
    ; AL = 168 (48h)
    ; AH = 1 (1h)
    
    ;Another example
    MOV AX, 10
    MOV BL, 5
    DIV BL
    ; AL = 2
    ; AH = 0
    
    ; DWORD / WORD 
    MOV DX, 003Fh
    MOV AX, 5555h
    ; 3F5555h
    
    MOV BX, 0CCC4h
    DIV BX
    
   ; AX = 79 (4Fh)
   ; DX = 9,433 (24D9)
   
   ;Another example
   MOV DX, 00FFh 
   MOV AX, 0FFFFh
   
   MOV BX, 0AAAh
   DIV BX
   ; AX = 6,145 (1,801h)
   ; DX = 1,365 (555h)
   
   MOV AH, 4Ch
   INT 21h
   
main ENDP
   
    