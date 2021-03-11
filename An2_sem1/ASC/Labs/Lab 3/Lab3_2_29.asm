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
    b db 2
    c db 4
    d dd 2
    x dq 1
    
    aux1 dw 0
    aux2 db 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;((a+b)/(c-2))-d+2-x
        
        mov EAX,0   ;clear all
        mov EBX,0
        mov ECX,0
        mov EDX,0
                
        
        mov AL, byte [c]    ;al = c
        cbw                 ;ax = c
        clc         
        sbb AX, 2           ;ax = c-2
        
        mov [aux1], AX      ;[aux1] = c-2
        
        mov AL, byte [a]    ;al = a
        clc 
        adc AL, byte [b]    ;al = a + b + CF
        cbw                 ;ax = a + b
        
        mov BX, [aux1]      ;bx = c-2
        idiv BX             ;ax = (a+b)/(c-2)
                            ;dx = (a+b)%(c-2)
        
        
        mov CX, DX          ;cx = (a+b)%(c-2)
        
        
        cwde                ;eax = (a+b)/(c-2)
        mov EBX, EAX
        
        mov AL, [d]         ;al = d
        cbw
        cwde                ;eax = d
        clc
        sbb EBX, EAX        ;eax = ((a+b)/(c-2)) - d
        clc
        mov EAX, EBX
        adc EAX, 2          ;eax = ((a+b)/(c-2)) - d + 2
        cdq                 ;edx:eax = ((a+b)/(c-2)) - d + 2
        
        clc                 
        sbb EAX, dword [x]  
        clc
        sbb EDX, dword [x+4]
        
        ;edx:eax = ((a+b)/(c-2)) - d + 2 - x
       
                
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
