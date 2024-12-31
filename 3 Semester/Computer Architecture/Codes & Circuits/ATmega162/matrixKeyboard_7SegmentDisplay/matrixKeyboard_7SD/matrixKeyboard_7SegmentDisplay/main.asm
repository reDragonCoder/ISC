;
; matrixKeyboard_7SegmentDisplay.asm
;
; Created: 07/12/2024 07:25:21 p. m.
; Author : darely
;

.include <m162def.inc>

; Configuración de puertos
LDI     R16, 0xFF       ; Configura todos los pines de PORTB como salidas
OUT     DDRB, R16

LDI     R16, 0b11110000 ; Configura PA4-PA7 como salidas y PA0-PA3 como entradas
OUT     DDRA, R16

LDI     R16, 0b00001111 ; Activamos resistencias Pull-Up en PA0-PA3
OUT     PORTA, R16

; Configure Stack Pointer
    LDI     R16, HIGH(RAMEND)
    OUT     SPH, R16
    LDI     R16, LOW(RAMEND)
    OUT     SPL, R16

; Inicializamos el Display con puros unos para que no aparezca nada antes de que comience a sondear filas y columnas
LDI     R19, 0xFF
OUT     PORTB, R19

CICLO:
    LDI     R17, 0x00        ; Usamos R17 como contador de posiciones para el KeyPad

; Ubicamos la dirección de la TABLA Z=HIGH:LOW (R31:R30) donde están almacenados los códigos del KeyPad
    LDI     R31, HIGH(TABLA<<1)
    LDI     R30, LOW(TABLA<<1)

; Comenzamos el recorrido de las Filas del KeyPad

; Fila 1 (F1)
F1:
    CBI     PORTA, 4         ; Comenzamos haciendo F1=0, es decir, PA.7=0 (colocamos fila 1 en 0)

F1_C1:
    RCALL   Rebote           ; Generamos un retardo de 20ms para evitar rebote al presionar cada tecla
    IN      R18, PINA        ; Leemos todo el dato del Puerto A y lo colocamos en R18
    BST     R18, 0           ; Enviamos el bit 0 (C1) al bit T del Registro de Estado (BST = BitStoreT T = Rr.b)
    SBI     PORTA, 4         ; Regresamos a 1 el bit de la fila (PA.7 = 1)
    BRTS    F1_C2            ; Si T = 1 (no presionada), saltamos a la siguiente columna
    RCALL   DatoTabla        ; Si T = 0 (presionada), llamamos la subrutina para mostrar el valor
    RJMP    CICLO            ; Regresamos al inicio del ciclo para volver a preguntar por cada tecla

F1_C2:
    CBI     PORTA, 4
    INC     R17              ; Aumentamos en 1 el conteo para la posición del dato de la tabla
    RCALL   Rebote           ; Generamos un retardo de 20ms para evitar rebote
    IN      R18, PINA        ; Leemos todo el dato del Puerto A
    BST     R18, 1           ; Enviamos el bit 1 (C2) al bit T del Registro de Estado
    SBI     PORTA, 4         ; Regresamos a 1 el bit de la fila
    BRTS    F1_C3            ; Si T = 1, saltamos a la siguiente columna
    RCALL   DatoTabla        ; Si T = 0, mostramos el valor
    RJMP    CICLO

F1_C3:
    CBI     PORTA, 4
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 2           ; Enviamos el bit 2 (C3) al bit T
    SBI     PORTA, 4         ; Regresamos a 1 el bit de la fila
    BRTS    F1_C4            ; Si T = 1, saltamos a la siguiente columna
    RCALL   DatoTabla        ; Si T = 0, mostramos el valor
    RJMP    CICLO

F1_C4:
    CBI     PORTA, 4
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 3           ; Enviamos el bit 3 (C4) al bit T
    SBI     PORTA, 4         ; Regresamos a 1 el bit de la fila
    BRTS    F2          ; Si T = 1, saltamos a la etiqueta intermedia
    RCALL   DatoTabla        ; Si T = 0, mostramos el valor
    RJMP    CICLO            ; Regresamos al inicio del ciclo

FinFila:
    RJMP    CICLO

; Fila 2 (F2)
F2:
    INC     R17
    CBI     PORTA, 5         ; Comenzamos haciendo F2=0 (colocamos fila 2 en 0)

F2_C1:
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 0
    SBI     PORTA, 5
    BRTS    F2_C2
    RCALL   DatoTabla
    RJMP    CICLO

F2_C2:
    CBI     PORTA, 5
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 1
    SBI     PORTA, 5
    BRTS    F2_C3
    RCALL   DatoTabla
    RJMP    CICLO

F2_C3:
    CBI     PORTA, 5
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 2
    SBI     PORTA, 5
    BRTS    F2_C4
    RCALL   DatoTabla
    RJMP    CICLO

F2_C4:
    CBI     PORTA, 5
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 3
    SBI     PORTA, 5
    BRTS    F3
    RCALL   DatoTabla
    RJMP    CICLO

; Fila 3 (F3)
F3:
    INC     R17
    CBI     PORTA, 6         ; Comenzamos haciendo F3=0 (colocamos fila 3 en 0)

F3_C1:
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 0
    SBI     PORTA, 6
    BRTS    F3_C2
    RCALL   DatoTabla
    RJMP    CICLO

F3_C2:
    CBI     PORTA, 6
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 1
    SBI     PORTA, 6
    BRTS    F3_C3
    RCALL   DatoTabla
    RJMP    CICLO

F3_C3:
    CBI     PORTA, 6
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 2
    SBI     PORTA, 6
    BRTS    F3_C4
    RCALL   DatoTabla
    RJMP    CICLO

F3_C4:
    CBI     PORTA, 6
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 3
    SBI     PORTA,6
    BRTS    F4
    RCALL   DatoTabla
    RJMP    CICLO

; Fila 4 (F4)
F4:
    INC     R17
    CBI     PORTA, 7         ; Comenzamos haciendo F4=0 (colocamos fila 4 en 0)

F4_C1:
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 0
    SBI     PORTA, 7
    BRTS    F4_C2
    RCALL   DatoTabla
    RJMP    CICLO

F4_C2:
    CBI     PORTA, 7
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 1
    SBI     PORTA, 7
    BRTS    F4_C3
    RCALL   DatoTabla
    RJMP    CICLO

F4_C3:
    CBI     PORTA, 7
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 2
    SBI     PORTA, 7
    BRTS    F4_C4
    RCALL   DatoTabla
    RJMP    CICLO

F4_C4:
    CBI     PORTA, 7
    INC     R17
    RCALL   Rebote
    IN      R18, PINA
    BST     R18, 3
    SBI     PORTA, 7
    BRTS    FinFilaF4
    RCALL   DatoTabla

FinFilaF4:
    RJMP    CICLO            ; Salto intermedio para evitar salto largo

; Subrutina para mostrar el valor en el display de 7 segmentos
DatoTabla:
    ; R17 contiene la posición de la tecla en el teclado (fila * 4 + columna)
    ; El índice de la tabla se calcula como R17

    ADD     R30, R17         ; Sumamos la posición de la tecla a la parte baja del registro Z
    BRCC    SIGUE            ; Saltamos si no hubo overflow (sin acarreo)
    INC     R31              ; Si hubo acarreo, incrementamos R31
SIGUE:
    LPM     R19, Z           ; Traemos el valor de la tabla a R19
    OUT     PORTB, R19       ; Mostramos el valor en el display de 7 segmentos
    RET

; Subrutina de rebote
Rebote:
    LDI     R18, 0xFF
DElay:
	DEC		R18
	BRNE	DELAY
	RET
   

; Tabla de códigos para el display 7 segmentos (hexadecimal)
TABLA:
    .DB     0xF9, 0x99, 0xF8, 0x8E   ; Fila 1: 1, 2, 3, A
    .DB     0xA4, 0x92, 0x80, 0xC0   ; Fila 2: 4, 5, 6, B
    .DB     0xB0, 0x82, 0x98, 0x86   ; Fila 3: 7, 8, 9, C
    .DB     0x88, 0x83, 0xC6, 0xA1   ; Fila 4: F, 0, D, E