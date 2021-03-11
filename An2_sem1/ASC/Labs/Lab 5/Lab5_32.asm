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

    S db 1, 6, 3, 1
    lenghtS equ $-S
    control1 db -1
    D times lenghtS-1 db 0
    control2 db -1
    R times lenghtS-1 db 0
    control3 db -1

    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;A byte string S of length l is given. Obtain the string D of length l-1, such that each element of D is the quotient of two consecutive elements of S, i.e. D(i) = S(i) / S(i+1)
    
        mov ECX, lenghtS-1                  ;get the number of times we have to do the loop
        mov ESI, 0                          ;clear ESI

       
        jecxz End                           ;check if ECX is 0
            stringLoop:
                mov BL,byte [S+ESI+1]       ;get the element on index ESI+1 in BL
                mov AL,byte [S+ESI]         ;get the element on index ESI in AL
                cbw                         ;convert AL to a word
                
                div BL                      ;divide the two elements
                
                mov [D+ESI],AL              ;put the result in the second string
                inc ESI                     ;increase ESI
            loop stringLoop                 ;loop ECX times
        End:
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
