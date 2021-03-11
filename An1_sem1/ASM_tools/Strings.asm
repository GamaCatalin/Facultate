bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit            ; tell nasm that exit exists even if we won't be defining it
extern printf
extern scanf
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    format dd "%d",0
    sir dd 0702090Ah, 0B0C0304h, 05060108h 
    len equ ($-sir)
    sir1 db 0
    len1 equ ($-sir1)

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
       ;turn double words from the string into bytes on another string
        
        
        
        mov esi, sir
        mov ecx, len
        mov edi, sir1
        
        cld
        
        
        Repeat:
            lodsb
            stosb 
        loop Repeat
        
    
        
        mov ecx, len1
        mov esi, sir1
        
        
        
        
        PrintLoop:
            
            lodsb
            cbw
            cwde
            
            
            push eax
            push format
            call [printf]
        loop PrintLoop
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
