bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    
    S db '+', '4', '2', 'a', '8', '4', 'X', '5'
    lenghtS equ $-S
    control1 db -1
    D times lenghtS db 0
    control2 db -1
    dIndex dd 0
    sIndex dd 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;A character string S is given. Obtain the string D which contains all the digit characters of S.
        
       mov ECX, lenghtS                 ;get the number of times we have to do the loop
       mov ESI, 0                       ;clear ESI
       
       jecxz End                        ;check if ECX is empty
       stringLoop:
            mov AL,[S+ESI]              ;get the curent element in AL
            cmp AL, '0'                 ;check if the ascii code is at least that of '0'
            jb isNotDigit               ;jump to the end of the loop otherwise
            
            checkDigit:                 
                cmp AL, '9'             ;check if the ascii code is at most that of '9'
                jbe isDigit             ;go tho the next operation if so
            isNotDigit:
                jmp endLoop             ;otherwise go to the end
            isDigit:
                mov [sIndex],ESI        ;save the index of the first string 
                mov ESI, [dIndex]       ;get the index of the second string
                mov [D+ESI],AL          ;put the digit in the second string
                inc ESI                 ;increment the second string's index
                mov [dIndex],ESI        ;save the second string index
                mov ESI, [sIndex]       ;get the first string's index           
            endLoop:    
                inc ESI                 ;increment the first string's index
        loop stringLoop                 ;loop ECX times
        End:
   
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
