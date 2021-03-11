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

        
        a dw 2
        b dw 3
        c dw 10
        d dw 1
        x dw 1
        y dw 1
        z dw 1
        
        
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        
        mov ax, [a]
        add ax, [d]
        mov [x], ax
        mov ax, [b]
        add ax, [d]
        mov [y], ax
        mov ax, [c]
        sub ax, [x]
        add ax, [y]
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
