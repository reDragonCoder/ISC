; Lectura de una Cadena
; Celia Fernanda Vela Uribe y César Andrés Zuleta Malanco
; 26/02/2025
; Ensamblador 

.model small

.stack  

.data 

    msg DB "Enter a string: $" ;The character $ indicates the end of the string
    msg2 DB 10,13,"String entered: $" ;Includes end of line, the return to the beginning and a new string
    string DB 20 ;Maximum size of the string
    count DB ? ;Number of the actual characters added
    buffer DB 20 DUP('$') ;Storage space for up to 20 characters 
    salto DB 10,13,"$" ;End of line
    
.code
MAIN PROC
    MOV AX, @data ;Start the segment of data
    MOV DS, AX
    
    ;Print the message asking for the string
    MOV AH, 09h 
    LEA DX, msg
    INT 21h
    
    ;Read the string from user input
    MOV AH, 0Ah ;DOS function for entry to the buffer
    LEA DX, string ;LOad buffer's address
    INT 21h
    
    ;The amount of characters is stored in count
    MOV AL, count   ;AL= number of charcters entered
    MOV AH, 0   ;Clean high part of AX
    MOV SI, OFFSET buffer ;Add SI at the beginning of the buffer
    ADD SI, AX ;Move SI to the position where the string ends
    
    ;Add the ending term '$' for printing with the 09h function
    MOV BYTE PTR [SI],'$'
    
    ;Print an end of line
    MOV AH, 09h
    LEA DX, salto
    INT 21h 
    
    ;Print the message announcing that now the string will be shown
    MOV AH, 09h
    LEA DX, msg2
    INT 21h
    
    ;Print the string
    MOV AH, 09h
    LEA DX, buffer
    INT 21h
    
    ;End the program correctly
    MOV AH,4Ch
    INT 21h
    
MAIN ENDP
END MAIN
  