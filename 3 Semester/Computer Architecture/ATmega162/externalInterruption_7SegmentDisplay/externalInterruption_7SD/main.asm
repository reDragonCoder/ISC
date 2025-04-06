;
; externalInterruption_7SegmentDisplay.asm
;
; Created: 16/12/2024 10:50:01 a. m.
; Author : reDragonCoder
;

.include <m162def.inc>
.org 0x000                 ; Reset vector
    RJMP PRINCIPAL         ; Jump to main program

.org 0x002                 ; INT0 External Interrupt vector
    RJMP INT_EXT_0


; Main Program
PRINCIPAL:
    ; Configure Ports
    LDI     R16, 0
    OUT     DDRD, R16        ; Port D as input
    LDI     R16, 0xFF
    OUT     DDRA, R16        ; Port A as output

    ; Configure Stack Pointer
    LDI     R16, HIGH(RAMEND)
    OUT     SPH, R16
    LDI     R16, LOW(RAMEND)
    OUT     SPL, R16

    ; Enable Pull-Up Resistors
    LDI     R16, 0xFF
    OUT     PORTD, R16       ; Enable pull-up on Port D

    ; Configure Interrupts
    LDI     R16, 0b00000010  ; Falling edge trigger for INT0
    OUT     MCUCR, R16
    LDI     R16, 0b01000000  ; Enable INT0
    OUT     GICR, R16
    SEI                      ; Enable global interrupts

    ; Initialize Variables
  
INICIO:
    LDI     R16, 0           ; Initialize index

CICLO:
    LDI     R31, HIGH(TABLANUM << 1)   ; Default to TABLANUM
    LDI     R30, LOW(TABLANUM << 1)
    ADD     R30, R16                   ; Update table index
    BRCC    SIGUE                      ; Skip carry adjustment if no carry
    INC     R31                        ; Increment high byte if carry occurred
SIGUE:
    LPM     R17, Z                     ; Load table data to R17
    OUT     PORTA, R17                 ; Output to PORTA
    RCALL   TIEMPO                     ; Delay
    INC     R16                        ; Increment index
    CPI     R16, 0x0A                  ; Check if index reaches 10
    BREQ    INICIO                     ; Restart if index reaches 10
    RJMP    CICLO

TABLANUM:
.db 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8
.db 0x80,0x98

TIEMPO:
; Delay 1 second
    LDI     R25, 4
    LDI     R26, 150
    LDI     R27, 128
L1: DEC     R27
    BRNE    L1
    DEC     R26
    BRNE    L1
    DEC     R25
    BRNE    L1
    RET


INT_EXT_0:
    PUSH    R25                  ; Save temporary registers save what number it left off on
    LDI		R18, 0x88
	OUT		PORTA, R18
	RCALL	TIEMPO
	LDI		R18, 0x83
	OUT		PORTA, R18
	RCALL	TIEMPO
	LDI		R18, 0xc6
	OUT		PORTA, R18
	RCALL	TIEMPO
	LDI		R18, 0xa1
	OUT		PORTA, R18
	RCALL	TIEMPO
	LDI		R18, 0x86
	OUT		PORTA, R18
	RCALL	TIEMPO
	LDI		R18, 0x8e
	OUT		PORTA, R18
	RCALL	TIEMPO
    POP     R25                  ; Restore temporary register
    RETI                          ; Return from Interrupt
