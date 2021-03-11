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

        a dd 125
        b db 2
        c db 1,2,3,4
        d db '1234'
        e db '1,2,3,4'
        f db '1',',','2'
        g db 'a'
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        mov  ax, [a+2];
        mov bh, [a+4]
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

        
        