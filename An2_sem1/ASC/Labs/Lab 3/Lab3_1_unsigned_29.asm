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

    
    a db 1
    b dw 2
    c dd 3
    d dq 4
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;d+c-b+(a-c)

        
        mov EAX,0   ;clear all
        mov EBX,0
        mov ECX,0
        mov EDX,0
                
                
                
                
                                ;d = [d+4] [d] 
        mov EBX, dword [d]      ;ebx = [d] 
        mov EDX, dword [d+4]    ;edx = [d+4]
        
        adc EBX, [c]            ;eax = eax+c
        
        mov AX, [b]             ;ax = b
        cwde                    ;eax = b
        sbb EBX, EAX            ;ebx = ebx-eax
                        
        
        mov AL, [a]             ;al = a
        cbw                     ;ax = a
        cwde                    ;eax = a
        adc EBX, EAX            ;ebx = ebx+eax
        
        sbb EBX, [c]            ;eax = eax-c
        
        mov EAX, EBX
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
