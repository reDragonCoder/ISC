;
; ex3.asm
;
; Created: 02/12/2024 08:38:23 p. m.
; Author : andre
;

.include <m162def.inc>

.org 0x000
    RJMP RESET

.org 0x020

RESET:
    ; Configuración de puertos
    LDI R16, 0xFF         ; Configurar todos los pines de PORTA como salida (para los displays)
    OUT DDRA, R16
    
    LDI R16, 0xFF         ; Configurar todos los pines de PORTB como salida (para selección de displays)
    OUT DDRB, R16

    ; Configuración del Stack Pointer
    LDI R16, HIGH(RAMEND)
    OUT SPH, R16
    LDI R16, LOW(RAMEND)
    OUT SPL, R16

INICIO:
    LDI R20, 0xF8         ; Valor que representa el número "7" en display de 7 segmentos 
    LDI R21, 0xFF         ; Valor que apaga el display
    LDI R22, 0xFE         ; Valor del primer display (0xFE selecciona el primer display)

; INCISO A
/*
CICLO:
    ; Primer Display
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el primer display
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al display apagado)
	RCALL TIME
    OUT PORTA, R20        ; Mostrar el número "7"
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al "7" en el display)
	RCALL TIME
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME            ; Retardo adicional si es necesario
	RCALL TIME

    ; Segundo Display
    LDI R22, 0xFD         ; Cambiar a 0xFD para seleccionar el segundo display
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el segundo display
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al display apagado)
	RCALL TIME
    OUT PORTA, R20        ; Mostrar el número "7"
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al "7" en el display)
	RCALL TIME
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME            ; Retardo adicional si es necesario
	RCALL TIME

	; Tercer Display
    LDI R22, 0xFB         ; Cambiar a 0xFB para seleccionar el tercer display
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el tercer display
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al display apagado)
	RCALL TIME
    OUT PORTA, R20        ; Mostrar el número "7"
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al "7" en el display)
	RCALL TIME
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME            ; Retardo adicional si es necesario
	RCALL TIME

	; Tercer Display
    LDI R22, 0xF7         ; Cambiar a 0xF7 para seleccionar el cuarto display
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el cuarto display
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al display apagado)
	RCALL TIME
    OUT PORTA, R20        ; Mostrar el número "7"
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al "7" en el display)
	RCALL TIME
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME            ; Retardo adicional si es necesario
	RCALL TIME

    RJMP INICIO           ; Repetir el ciclo
*/

; INCISO B
/*
CICLO:
	; Primer Display
	LDI R20, 0x89
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el primer display
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al display apagado)
	RCALL TIME
    OUT PORTA, R20        ; Mostrar la letra "H"
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al "7" en el display)
	RCALL TIME
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME            ; Retardo adicional si es necesario
	RCALL TIME

    ; Segundo Display
	LDI R20, 0xC0
    LDI R22, 0xFD         ; Cambiar a 0xFD para seleccionar el segundo display
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el segundo display
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al display apagado)
	RCALL TIME
    OUT PORTA, R20        ; Mostrar la letra "O"
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al "7" en el display)
	RCALL TIME
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME            ; Retardo adicional si es necesario
	RCALL TIME

	; Tercer Display
	LDI R20, 0xC7
    LDI R22, 0xFB         ; Cambiar a 0xFB para seleccionar el tercer display
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el tercer display
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al display apagado)
	RCALL TIME
    OUT PORTA, R20        ; Mostrar la letra "L"
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al "7" en el display)
	RCALL TIME
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME            ; Retardo adicional si es necesario
	RCALL TIME

	; Tercer Display
	LDI R20, 0x88
    LDI R22, 0xF7         ; Cambiar a 0xF7 para seleccionar el cuarto display
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el cuarto display
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al display apagado)
	RCALL TIME
    OUT PORTA, R20        ; Mostrar la letra "A"
    RCALL TIME            ; Llamar a retardo (esto le da tiempo al "7" en el display)
	RCALL TIME
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME            ; Retardo adicional si es necesario
	RCALL TIME

    RJMP INICIO           ; Repetir el ciclo
*/

; INCISO C
CICLO:
	; Primer Display
	LDI R20, 0x89
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el primer display
    RCALL TIME2            ; Llamar a retardo (esto le da tiempo al display apagado)
    OUT PORTA, R20       ; Mostrar la letra "H"
    RCALL TIME2            ; Llamar a retardo (esto le da tiempo al "7" en el display)
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME2           ; Retardo adicional si es necesario

    ; Segundo Display
	LDI R20, 0xC0
    LDI R22, 0xFD         ; Cambiar a 0xFD para seleccionar el segundo display
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el segundo display
    RCALL TIME2            ; Llamar a retardo (esto le da tiempo al display apagado)
    OUT PORTA, R20        ; Mostrar la letra "O"
    RCALL TIME2            ; Llamar a retardo (esto le da tiempo al "7" en el display)
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME2            ; Retardo adicional si es necesario

	; Tercer Display
	LDI R20, 0xC7
    LDI R22, 0xFB         ; Cambiar a 0xFB para seleccionar el tercer display
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el tercer display
    RCALL TIME2            ; Llamar a retardo (esto le da tiempo al display apagado)
    OUT PORTA, R20        ; Mostrar la letra "L"
    RCALL TIME2            ; Llamar a retardo (esto le da tiempo al "7" en el display)
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME2            ; Retardo adicional si es necesario

	; Tercer Display
	LDI R20, 0x88
    LDI R22, 0xF7         ; Cambiar a 0xF7 para seleccionar el cuarto display
    OUT PORTA, R21        ; Apagar display (esto apagará todos los segmentos)
    OUT PORTB, R22        ; Seleccionar el cuarto display
    RCALL TIME2            ; Llamar a retardo (esto le da tiempo al display apagado)
    OUT PORTA, R20        ; Mostrar la letra "A"
    RCALL TIME2            ; Llamar a retardo (esto le da tiempo al "7" en el display)
    OUT PORTA, R21        ; Apagar el display permanentemente
    OUT PORTB, R22        ; Des-seleccionar el display
    RCALL TIME2            ; Retardo adicional si es necesario

    RJMP INICIO           ; Repetir el ciclo

; Tiempo de .5 seg
TIME:
    ; Subrutina de retardo simple
    LDI R18, 200         
    LDI R19, 200
L1: DEC R19
    BRNE L1
    DEC R18
    BRNE L1
    RET

; Tiempo de 5 ms
TIME2:
    ; Subrutina de retardo simple
    LDI R18, 100      
    LDI R19, 25       
L2:
    DEC R19          
    BRNE L1           
    DEC R18           
    BRNE L1           
    RET              
