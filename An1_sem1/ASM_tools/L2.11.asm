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
    
    
        a db 2
        b db 2
        c db 3
        d db 8
        x dd 1
        y dd 1
        z dd 1
        l dd 1
        h db 2
        
        
        
; our code starts here
segment code use32 class=code
    start:
        ; ... [(d/2)*(c+b)-a*a]/b
    
        mov ax, [d]
        div word [h]
        mov [x],al 
        mov ax, [c]
        add ax, [b]
        mov [y],ax
        mov al, [a]
        mul word [a]
        mov [z], al
        mov al, [x]
        mul word [y]
        mov [l], al
        mov ax, [l]
        sub ax, [z]
        div word [b]
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
