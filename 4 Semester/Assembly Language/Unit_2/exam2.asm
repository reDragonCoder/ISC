; Exam
; Author: reDragonCoder
; 14/04/2025
; Assembly Language  
          
.model small          
.stack 100h

.data 
; === Option 1 - Prime numbers ===      
array_prime   DB 7, 3, 6, 2, 5, 5, 13, 7, 4, 10  
count         DW 10 
primeNums     DB 0   
divisor       DB 10 
; This array converts and stores the current number that is to be printed
; 3 bytes are reserved: two for the digits and one for the end signal '$'
numStr  DB 3 DUP(?) 

; === Option 2 - Bubble sort ===
bubbleSort_array   DB 14, 7, 22, 5, 4, 13, 1, 10    

; Endl
jump   DB 13,10,'$'

; Main menu title and options
menu    DB 13,10,'=== Option Menu ===',13,10
        DB '1 - Add prime numbers',13,10
        DB '2 - Bubble sort',13,10
        DB '3 - AX swap',13,10  
        DB '4 - Exit',13,10
        DB 'Select an option: $'

; Submenu title and options
submenu DB 13,10,'--- Bubble Sort Submenu ---',13,10
        DB 'A - Ascending',13,10
        DB 'D - Descending',13,10 
        DB 'Select an option: $'             
        

; Stores selected option for the main menu
option_menu      DB ?

buffer1 DB 20
        DB ?    
        DB 20 dup('$')  

; Stores selected option for the main menu        
option_submenu  DB ?    

buffer2 DB 20
        DB ?    
        DB 20 dup('$')
                                 
                                
                                 
; Extra messages                    
bubbleSuccess_msg   DB 13, 10, 'Your sorted array is ready in the vars section!$' 
swapAX_msg          DB 13, 10, 'Your values have switched places! Check the registers$'
goodbye_msg         DB 13,10,'See you later!$'
error_msg           DB 13,10,'Non-valid option.$'

.code
main PROC
    ; Data segment
    MOV AX, @data
    MOV DS, AX  

start_menu:
    MOV AH, 09h
    LEA DX, menu
    INT 21h

read_option1:

    MOV AH, 01h
    INT 21h

    CMP AL, 13
    JE read_option1

    MOV option_menu, AL

    MOV AH, 09h
    LEA DX, jump
    INT 21h

    CMP option_menu, '1'
    JE option_1

    CMP option_menu, '2'
    JE option_2  
    
    CMP option_menu, '3'
    JE option_3

    CMP option_menu, '4'
    JE exit

    MOV AH, 09h
    LEA Dx, error_msg

option_1: 
    MOV CX, count       ; CX = elements that will be evaluated
    MOV SI, 0           ; SI = array index
    XOR DI, DI          ; DI = array index for the prime numbers (starts in 0)     

NEXTNUMBER:
    MOV AL, array_prime[SI]   
    MOV BL, AL          
    
    ; Verifies if the number is less then 2 and thus not a prime number
    CMP BL, 2
    JB NOTPRIME
    
    ; If the number is 2 then it is a prime number
    CMP BL, 2
    JE ADDPRIME
    
    ; If the number is greater then two then we check if there is a number that it can be divided by.
    MOV DL, 2

PRIMELOOP:
    MOV AL, BL  
    XOR AH, AH  
    DIV DL      
    CMP AH, 0
    JE NOTPRIME ; If the residue is equal to 0 then it is not a prime number.
    INC DL
    CMP DL, BL
    JL PRIMELOOP
    
    ; If the cycle is completed without finding a divisor then the number is a prime number.
ADDPRIME:
    ADD primeNums, BL   ; primeNums = the total sum of the found prime numbers
    INC DI              
    JMP DONECHECK

NOTPRIME:
    NOP

DONECHECK:
    INC SI          
    LOOP NEXTNUMBER
    CMP primeNums, 10          
    JB ONE_DIGIT_CONVERSION 
    
    ; 2 digit number conversion
    MOV AL, primeNums   
    XOR AH, AH          
    DIV divisor             
    ADD AL, '0'         
    MOV numStr, AL      
    MOV AL, AH          
    ADD AL, '0'         
    MOV numStr+1, AL    
    MOV BYTE PTR numStr+2, '$'  
    JMP PRINT_NUMBER 
    
ONE_DIGIT_CONVERSION:
    ; One digit conversions 
    MOV AL, primeNums           
    ADD AL, '0'                 
    MOV BYTE PTR numStr, AL     
    MOV BYTE PTR numStr+1, '$'  
    JMP PRINT_NUMBER            

PRINT_NUMBER:
    MOV AH, 09h
    LEA DX, jump
    INT 21h

    ; Print sum of the prime numbers (numStr)
    MOV AH, 09h
    LEA DX, numStr
    INT 21h

    MOV AH, 09h
    LEA DX, jump
    INT 21h  
    
    MOV BL, 0
    MOV primeNums, BL
    
    JMP start_menu

option_2:
start_submenu:
    MOV AH, 09h
    LEA DX, submenu
    INT 21h

read_option2:
    MOV AH, 01h
    INT 21h

    CMP AL, 13
    JE read_option2

    MOV option_submenu, AL

    MOV AH, 09h
    LEA DX, jump
    INT 21h

    CMP option_submenu, 'A'
    JE option_A

    CMP option_submenu, 'D'
    JE option_D  

    MOV AH, 09h
    LEA Dx, error_msg 
    INT 21h

option_A: 
    MOV CX, 7 ;COUNTER REGISTER STORES THE NUMBER OF COMPARISONS (SIZE OF ARRAY - 1) 
       
    LOOP_1A:
    PUSH CX
    MOV  SI, 0
    MOV  DI, 0
    
    LOOP_2A:
    INC DI
    MOV AL, bubbleSort_array[SI]
    CMP AL, bubbleSort_array[DI]
    JA SWAP_A 
    JB LESS_A 
    
    SWAP_A:
    MOV AH, bubbleSort_array[DI]
    MOV bubbleSort_array[DI], AL
    MOV bubbleSort_array[SI], AH
    
    LESS_A:
    INC SI
    LOOP LOOP_2A 
    POP CX                                       
    LOOP LOOP_1A 
    
    FINISH_A:  
    MOV AH, 09h
    LEA DX, bubbleSuccess_msg
    INT 21h      
    MOV AH, 09h
    LEA DX, jump
    INT 21h 
    
    JMP start_menu    
    
option_D: 
    MOV CX, 7 ;COUNTER REGISTER STORES THE NUMBER OF COMPARISONS (SIZE OF ARRAY - 1) 
       
    LOOP_1D:
    PUSH CX
    MOV  SI, 0
    MOV  DI, 0
    
    LOOP_2D:
    INC DI
    MOV AL, bubbleSort_array[SI]
    CMP AL, bubbleSort_array[DI]
    JB SWAP_D 
    JA LESS_D 
    
    SWAP_D:
    MOV AH, bubbleSort_array[DI]
    MOV bubbleSort_array[DI], AL
    MOV bubbleSort_array[SI], AH
    
    LESS_D:
    INC SI
    LOOP LOOP_2D 
    POP CX                                       
    LOOP LOOP_1D 
    
    FINISH_D:  
    MOV AH, 09h
    LEA DX, bubbleSuccess_msg
    INT 21h      
    MOV AH, 09h
    LEA DX, jump
    INT 21h 
    
    JMP start_menu
          
option_3:
    MOV AH, 26h
    MOV AL, 13h 
    SHR AH, 1   ; Shift to the right one place (26 --> 13)
    SHL AL, 1   ; Shift to the left one place (13 --> 26)
    
    MOV AH, 09h
    LEA DX, swapAX_msg
    INT 21h      
    MOV AH, 09h
    LEA DX, jump
    INT 21h 

    JMP start_menu

exit:
    MOV AH, 09h
    LEA DX, goodbye_msg
    INT 21h

    MOV AH, 4Ch
    INT 21h

main ENDP
END main