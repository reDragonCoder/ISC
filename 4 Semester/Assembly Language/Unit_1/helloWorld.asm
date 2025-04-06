; Hello World en ensamblador
; Author: reDragonCoder
; 24/02/2025   
; Ensamblador

.model small    ; Se usa el modelo de memoria "small <Codigo y Datos = 64 kb>"
.stack          ; Segmento de pila (stack), no se especifica tamano
.data
    msg db "Hello World, this is my first assembly program", "$"
.code           ; Inicio del segmento de codigo

main PROC           ; Inicio del procedimiento principal
    MOV AX, SEG msg ; Obtiene el segmento donde esta almacenado msg y lo guarda en AX
    MOV DS, AX      ; Mueve el valor de AX al registro DS (Data Segment)                                                               
                    ; Ahora DS apunta al segmento donde esta msg  
                    
    MOV AH, 09H     ; Cargar la funcion 09H en AH (Imprimir cadena en DOS)
    LEA DX, msg     ; Carga la direccion de msg en DX
    INT 21H         ; Llama a la interrupcion 21H para imprimir la cadena en pantalla
    
    .exit           ; Indica el final del program
main ENDP           ; Fin del procedimiento "main"
END                 ; Fin del codigo fuente