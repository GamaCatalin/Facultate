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
        a dd 2
        b db 4
        c db 5
        d dq 0
        x dq 1
        y dq 0
        z dq 0
        t dq 0

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ; (a+b)/(2-b*b+b/c)-x
        
        mov eax,[a]
        adc eax,[b]
        mov [d], eax
        mov eax,[b]
        mul word [b]
        mov [y], eax
        mov eax,[b]
        div word [c]
        mov [z], eax
        mov eax, 2
        sbb eax,[y]
        add eax,[z]
        mov [t],eax
        mov eax,[d]
        div dword [t]
        sbb eax, [x]
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
