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

    
    a db 4
    b dw 2
    c dd 1
    d dq 10
    
    aux1 dw 0
    aux2 dq 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;d-a+c+c-b+a
        
        mov EAX,0   ;clear all  
        mov EBX,0
        mov ECX,0
        mov EDX,0
                
        mov EBX, dword [c]      ;ebx = [c]
        mov AL, byte [a]        ;al = [a]
        cbw                     ;ax = [a]
        cwde                    ;eax = [a]
        clc         
        adc EBX, EBX            ;ebx = c + c
        clc
        sbb EBX, EAX            ;ebx = c + c - a
        clc
        adc EBX, EAX            ;ebx = c + c - a + a
        mov AX, word [b]        ;ax = b
        cwde                    ;eax = b
        clc
        sbb EBX, EAX            ;ebx = c + c - a + a - b = -a +c +c - b + a       
        mov EAX, dword [d]      ;eax = [d]
        mov EDX, dword [d+4]    ;edx = [d+4]
                                ;edx:eax = d
        clc
        adc EAX, EBX            ;eax = [d] + (-a +c +c - b + a)
        
        ;edx:eax = d-a+c+c-b+a
        
             
                
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
