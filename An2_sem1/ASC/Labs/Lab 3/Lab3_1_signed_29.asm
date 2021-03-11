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
    d dq 2
    
    aux1 dw 0
    aux2 dq 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;(a+a)-(b+b)-(c+d)+(d+d)
        
        mov EAX,0   ;clear all
        mov EBX,0
        mov ECX,0
        mov EDX,0
                
        
        mov AX, word [b]        ;ax = b
        cwde                    ;eax = b
        

        clc                     ;clear CF
        adc EAX, EAX            ;get b+b in EAX
        mov EBX, EAX            ;move b+b into EBX
        mov AL, byte [a]        ;al = a
        cbw                     ;ax = a
        cwde                    ;eax = a
        clc
        adc EAX, EAX            ;get a+a in eax
        clc         
        sbb EAX, EBX            ;get (a+a)-(b+b) in eax
        cdq                     ;edx:eax = (a+b)-(b+b)
        mov ECX, dword [c]      ;ecx = c
        mov EBX, dword [d]      ;ebx = [d]
        clc
        adc ECX, EBX            ;ecx = c + [d] + CF           
        clc
        sbb EAX, ECX            ;eax = c + [d] - CF
        clc
        sbb EDX, [d+4]          ;edx = edx - [d+4] -CF
                                ;edx:eax = (a+a)-(b+b)-(c+d)
        mov EBX, [d]            ;ebx = [d]
        mov ECX, [d+4]          ;ecx = [d+4]
        clc
        adc EAX, EBX            ;eax = eax + [d] + CF
        clc
        adc EDX, ECX            ;edx = eax + [d+4] + CF
        clc
        adc EAX, EBX            ;eax = eax + [d] + CF
        clc
        adc EDX, ECX            ;edx = eax + [d+4] + CF
        
                                
                                ;edx:eax = (a+a)-(b+b)-(c+d)+(d+d)
                                
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
