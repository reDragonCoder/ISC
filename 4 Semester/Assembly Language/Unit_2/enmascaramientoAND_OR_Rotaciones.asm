; Enmascaramiento con AND, OR y Rotaciones
; Author: reDragonCoder
; 08/04/2025
; Ensamblador

.model small

.stack 100h

.data

.code
main PROC
      MOV AX, @data ; Inicialización del segmento de datos
      MOV DS, AX
      
      ; ENMASCARAMIENTO CON AND
      MOV AL, 0FFh ; AL = 1111 1111b
      AND AL, 0Fh ; 0Fh = 15 = 0000 1111b
      ; Al hacer la AND, solo se conserva el nibble bajo
      
      ; ENMASCARAMIENTO CON OR
      MOV BL, 0Fh ; bl = 0000 1111b
      OR BL, 0F0h ; Se activan los bits del nibble alto
      
      ; Limpieza de registros
      MOV AX, 0
      MOV BX, 0
      
      ; ROTACION A LA IZQUIERDA (ROL)
      MOV AL, 81h ; AL = 1000 0001b
      ROL AL, 1 ; AL se rota en 1 posicion a la izquierda
      ; AL = 0000 0011b
      
      ; Tambien podemos rotar registros completos
      MOV BX, 7FFFh
      ROL BX, 1
                
      ; --------------------          
      XOR AX, AX
      XOR BX, BX
      
      ; ROTACION A LA DERECHA (ROR)
      MOV AL, 81h ; AL = 1000 0001b
      ROR AL, 2 ; Se rota AL en dos posiciones a la derecha 
      
      ; DESPLAZAMIENTOS
      XOR AL, AL
      MOV AL, 255
      SHR AL, 2 ; Desplazamiento de dos posiciones a la derecha
      SHL AL, 3 ; Desplazamiento de tres posiciones a la izquierda
      
      
      TERMINAR:
      ; Terminar programa correctamente
      MOV AH, 4Ch
      INT 21h

MAIN ENDP
END MAIN




