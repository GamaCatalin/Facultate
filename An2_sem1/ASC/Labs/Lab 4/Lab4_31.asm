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

    A dw 132
    B dw 1412
    C dw 523
    D dw 0
        
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;Given the words A, B si C, obtain the word D as the sum of the integers represented by:
        ;-the bits 1-5 of A
        ;-the bits 6-10 of B
        ;-the bits 11-15 of C
        
        
        
        ;A -> [________|__-----_]
        ;B -> [_____---|--______]
        ;C -> [-----___|________]
        ;                           +
        ;D =  [                 ]
        
        
        ;    15                0
        ;    [________|________]
        
    
        mov EAX,0   ;clear all
        mov EBX,0
        mov ECX,0
        mov EDX,0
    
        
        MOV AX, [A]                     ;move A into ax
        MOV BX, [B]                     ;move B into bx
        MOV CX, [C]                     ;move C into cx
    
    
        AND AX, 00000000_00111110b      ;get the integer from the bits 1-5 of A
        AND BX, 00000111_11000000b      ;get the integer from the bits 6-10 of B
        AND CX, 11111000_00000000b      ;get the integer from the bits 11-15 of C
        
        ADD DX, AX                      ;get into DX the sum of all integers
        ADD DX, BX
        ADD DX, CX
        
        MOV [D], DX
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
