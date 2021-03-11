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

    a db 11
    b db 5
    c db 9
    d db 24
    
    aux1 db 0
    aux2 db 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        mov EAX, 0
        mov EDX, 0
        mov EBX, 0
        mov ECX, 0
        
        
        mov AL, [b]
        mov BL, [c]
        
        ADD AL,BL
        
        
        mov [aux1],AL
        
        mov AL, [a]
        mov BL, [b]
        
        ADD AL,BL
        mov BL, [d]
        
        SUB AL,BL
        
        mov [aux2],AL
        
        mov AL, [aux1]
        mov BL, [aux2]
        
        ADD AL, BL
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
