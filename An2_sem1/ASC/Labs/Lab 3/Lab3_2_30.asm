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

    
    a dw 4
    b db 2
    c db 4
    e dd 2
    x dq 1
    
    aux1 dd 0
    aux2 dq 0
    remainder dd 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;a*b-(100-c)/(b*b)+e+x 
        
        mov EAX,0   ;clear all
        mov EBX,0
        mov ECX,0
        mov EDX,0
                
        mov AL, byte [c]        ;al = c
        cbw                     ;ax = c
        cwde                    ;eax = c
        clc
        mov ECX, 100            ;ecx = 100
        sbb ECX, EAX            ;ecx = 100-c
        
        mov AL, byte [b]        ;al = b
        mul AL                  ;ax = b*b
        cwde                    ;eax = b*b
        mov EDX, EAX            ;edx = b*b
        mov EAX, ECX            ;eax = 100-c
        mov ECX, EDX            ;ecx = b*b
        mov EDX, 0              ;edx = 0
        idiv ECX                ;eax = (100-c)/(b*b)
                                ;edx = (100-c)%(b*b)
        mov [remainder], EDX    ;[remainder] = edx
        mov [aux1], EAX         ;[aux1] = eax
        
        mov EAX, 0              ;eax = 0
        mov AL, byte [b]        ;al = b
        cbw                     ;ax = b
        cwde                    ;eax = b
        mov EBX, EAX            ;ebx = b
        mov AX, word [a]        ;ax = a
        cwde                    ;eax = a
        imul EBX                ;edx:eax = a*b
        
        clc                     
        sbb EAX, dword [aux1]   ;edx:eax = a*b - (100-c)/(b*b)
        clc                     
        adc EAX, dword [e]      ;edx:eax = a*b - (100-c)/(b*b) + e
        
        clc                     
        adc EAX, dword [x]      
        clc
        adc EDX, dword [x+4]
        
        
        ;edx:eax = a*b - (100-c)/(b*b) + e + x
        
        
        
        
       
                
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
