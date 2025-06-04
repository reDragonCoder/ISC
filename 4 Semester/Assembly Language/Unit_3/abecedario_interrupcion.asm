
.model small

.stack

.data

.code 
main PROC
    MOV AH,06H
    MOV Al,00H
    MOV BH,81H
    MOV CX, 0000H
    MOV DX, 184FH
    INT 10H
    
    MOV BL,65
    MOV CL,26


PRINT:
    
    MOV AH,2
    MOV DL,BL
    INC BL
    DEC CL
    INT 21H

    MOV DL,0DH
    INT 21H
    MOV DL,0AH
    INT 21H

 JNZ PRINT

  MOV AH,4CH
  INT 21H

    
    
main ENDP                                                             

END main