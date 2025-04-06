;
; externalInterruption_Buttons.asm
;
; Created: 16/12/2024 10:56:02 a. m.
; Author : reDragonCoder
;

.include <m162def.inc>

; Start on MAIN
.org 0x000
    RJMP MAIN              

; Set IE0
.org 0x002
    RJMP INT_0             

; Set IE1
.org 0x004
    RJMP INT_1             

; Main Program
MAIN:
    ; Set input and outputs
    LDI R16, 0x00
    OUT DDRD, R16          ; PORT D as input (interruptions)
    LDI R16, 0xFF
    OUT DDRA, R16          ; PORT A as output (display 2)
    LDI R16, 0xFF
    OUT DDRB, R16          ; PORT B as output (display 1)

	; Configure Stack Pointer
    LDI     R16, HIGH(RAMEND)
    OUT     SPH, R16
    LDI     R16, LOW(RAMEND)
    OUT     SPL, R16

    ; Enable Pull-Up Resistors
    LDI R16, 0xFF
    OUT PORTD, R16          ; Enable pull-up on Port D
	
    ; Configure Interrupts
    LDI R16, 0b00001010     ; Falling edge trigger for INT0 and INT1
    OUT MCUCR, R16
    LDI R16, 0b11000000     ; Enable INT0 and INT1
    OUT GICR, R16
    SEI                     ; Enable INT0 and INT1

    ; Define R16 as an index for TENS in NUMBERS (Decenas)
    CLR R16                 ; R16 will behave as a pointer               
    ; Define R17 as an index for ONES in NUMBERS (Unidades)
    CLR R17                 ; R17 will behave as a pointer

    ; Initialize displays
    RCALL TENS
    RCALL ONES

WAIT:
    RJMP WAIT              ; Loop that waits for a button to be pressed

; Interruption IE0 = INCREASE  
INT_0:
    RCALL DEBOUNCE         ; Avoid debounce
    INC R16                ; Increase TENS index
    CPI R16, 0x0A          ; Check if TENS == 10
    BRNE INT_0_CONT        ; If FALSE, continue 
    CLR R16				   ; If TRUE, reset TENS to 0
    INC R17                ; Increase ONES index
    CPI R17, 0x0A          ; Check if ONES == 10
    BRNE INT_0_CONT        ; If FALSE, continue
    LDI R17, 0x09          ; If TRUE, reset ONES to 9 if it overflows
    LDI R16, 0x09          ; Reset TENS to 9

INT_0_CONT:		; Continue
    RCALL TENS             ; Update tens display
    RCALL ONES             ; Update ones display
    RETI

; Interruption IE1 = DECREASE 
INT_1:
    RCALL DEBOUNCE        ; Avoid debounce
    CPI R16, 0x00         ; Check if TENS = 0
    BRNE INT_1_DECR_TENS  ; If not zero, decrease TENS
    CPI R17, 0x00         ; If TENS = 0, check ONES = 0
    BRNE INT_1_DECR_ONES  ; If ONES != 0, decrease ONES
    LDI R16, 0x00         ; Reset TENS to 0
    LDI R17, 0x00         ; Reset ONES to 0 if both are already 0
    RJMP INT_1_EXIT       ; Exit the interrupt

INT_1_DECR_TENS:
    DEC R16               ; Decrease TENS
    RJMP INT_1_EXIT       ; Exit after updating TENS

INT_1_DECR_ONES:
    DEC R17               ; Decrease ONES
    LDI R16, 0x09         ; Reset TENS to 9 after ONES decrement
    RJMP INT_1_EXIT       ; Exit after updating ONES

INT_1_EXIT:
    RCALL TENS            ; Update TENS display
    RCALL ONES            ; Update ONES display
    RETI

; Display TENS (decenas) - Second display
TENS:
    LDI R31, HIGH(NUMBERS << 1)
    LDI R30, LOW(NUMBERS << 1)       ; Load NUMBERS table address
    ADD R30, R16                     ; Set index for NUMBERS table
    LPM R18, Z                       ; Load the corresponding value
    OUT PORTB, R18                   ; Send it to PORT B
	RCALL DEBOUNCE
    RET

; Display ONES (unidades) - First display
ONES:
    LDI R31, HIGH(NUMBERS << 1)
    LDI R30, LOW(NUMBERS << 1)
    ADD R30, R17                     ; Set index for NUMBERS table 
    LPM R18, Z                       ; Load the corresponding value
    OUT PORTA, R18                   ; Send it to PORT A
	RCALL DEBOUNCE
    RET

; Numbers from 0 to 9
NUMBERS:
    .db 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90

; Debounce
DEBOUNCE:
; Assembly code auto-generated
; by utility from Bret Mulvey
; Delay 160 000 cycles
; 20ms at 8.0 MHz

			LDI		R20, 4	; 208
			LDI		R21, 202
L1:			DEC		R21
			BRNE	L1
			DEC		R20
			BRNE	L1
			NOP
			RET
