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
    D db 0
    E db 0
    F db 0   
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
    
        
        ;Given the words A, B si C, obtain the byte D as the sum of the integers represented by:
        ;-the bits 0-4 of A
        ;-the bits 5-9 of B
        ;The byte E is the integer represented by 
        ;-the bits 10-14 of C. 
        ;Obtain the byte F by 
        ;-computing the subtraction D-E.
        
        
        
        ;A -> [________|___-----]
        ;B -> [______--|---_____]
        ;C -> [_-----__|________]

        
        
        ;    15                0
        ;    [________|________]
        
        ;D =          [________]
        ;E =          [________]
        ;F =          [________]                
        
        
        mov EAX,0   ;clear all
        mov EBX,0
        mov ECX,0
        mov EDX,0
    
        
        MOV AX, [A]                     ;move A into ax
        MOV BX, [B]                     ;move B into bx
        MOV CX, [C]                     ;move C into cx
        
        
        
        AND AX, 00000000_00011111b      ;get the integer from the bits 0-4 of A
        AND BX, 00000011_11100000b      ;get the integer from the bits 5-9 of B
        
        ADD AX, BX                      ;get the sum of the integers 
                                        ;the sum of the integers will be stored in AH:AL
        MOV [D], AL                     ;as [D] is a byte we can only move AL
        
        
        AND CX, 01111100_00000000b      ;get the integer from the bits 10-14 of C
                                        ;the integer is stored in CH:CL
        MOV [E], CL                     ;as [E] is a byte we can only move CL
        
        MOV AL,[E]
        MOV BL,[D]
        
        SUB AL,BL  
        MOV [F], AL
    
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
