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
    b dw 10
    c dd 3
    d dq 4
    
    aux1 dq 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;(b+c+a)-(d+c+a)
        
        mov EAX,0   ;clear all
        mov EBX,0
        mov ECX,0
        mov EDX,0
                
                                ;d = [d+4] [d] 
        mov EBX, dword [d]      ;ebx = [d] 
        mov EDX, dword [d+4]    ;edx = [d+4]
        
        adc EBX,[c]             ;ebx = ebx + c
        
        mov EAX, [a]
        cbw
        cwde
        adc EBX, EAX            ;ebx = ebx + eax
        
        mov [aux1],EBX          ;[aux1] = ebx
        mov [aux1+4],EDX        ;[aux1+4] = edx

        
        mov EDX, 0              ;edx = 0 
        mov AX, [b]             ;ax = b
        cwde                    ;eax = b
        mov EBX, EAX
        
        adc EBX, [c]            ;ebx = ebx + c
        
        mov AL, [a]             ;al = a
        cbw                     ;ax = a
        cwde                    ;eax = a
        
        adc EBX, EAX            ;ebx = ebx + a
        mov EAX, EBX
        
        
        sub EAX, dword [aux1]   ;eax = eax - [aux1]
        sub EDX, dword [aux1+4] ;edx = edx - [aux1+4]
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
