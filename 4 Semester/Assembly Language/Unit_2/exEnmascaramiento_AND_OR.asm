; Enmascaramiento con AND, OR y Rotaciones (Ejercicio)
; Author: reDragonCoder
; 08/04/2025
; Ensamblador

.model small

.stack 100h

.data

.code
main PROC
      MOV AX, @data ; Inicializacion del segmento de datos
      MOV DS, AX     
            
      ; Convertir 5Ah a D2h con rotaciones      
      MOV AL, 5Ah   
      ROL AL, 3     ; Rota 3 veces a la izquierda
      
      ; Limpieza de registros
      MOV AX, 0
      MOV BX, 0
      
      ; Convertir 0011 1100 a 1100 0011 con desplazamientos y enmascaramientos
      XOR AL, AL    ; Limpieza del registro y carga de 0011 1100 a AL
      MOV AL, 3Ch   ; 0
      SHL AL, 2     ; Dos desplazamientos a la izauierda
      AND AL, 0C0h  ; AND entre el numero contenido en AL con 0C0h
      OR AL, 0C3h    ; OR entre el numero contenido en AL con CCh
      
      
      TERMINAR:
      ; Terminar programa correctamente
      MOV AH, 4Ch
      INT 21h

MAIN ENDP
END MAIN








