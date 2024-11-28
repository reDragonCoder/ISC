;
; 4Bits_7SegmentDisplay.asm
;
; Created: 28/11/2024 07:31:23 a. m.
; Author : reDragonCoder
;


.INCLUDE <M162DEF.INC>

; Configurar los puertos
ldi r16, 0x00            
out DDRB, r16            ; Entrada: puerto B

ldi r16, 0xFF            
out DDRD, r16            ; Salida: Puerto D

out PORTB, r16           ; resistencias Pull-Up en el puerto B

CICLO:
    in r16, PINB         ; leer datos
    andi r16, 0x0F       ; 4 bits menos significativos

    ; direccion de la TABLA Z = HIGH:LOW (r31:r30)
    ldi r31, HIGH(TABLA << 1)
    ldi r30, LOW(TABLA << 1)
    
    ; una vez definido el apuntador del inicio de la tabla
    add r30, r16         ; ajustar el desplazamiento del valor que se lee
    BRCC SIGUE           ; Saltar si no hay acarreo
    inc r31              ; Aumenta el registro alto si hay acarreo

SIGUE:
    LPM r17, Z           ; dato de la tabla al registro r17
    out PORTD, r17       ; mostrar el valor en el puerto D
    rjmp CICLO           ; repetir

TABLA:
    ; Tabla de patrones para catodo comun
    .db 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07
    .db 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71

