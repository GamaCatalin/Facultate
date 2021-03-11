bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
extern scanf
import scanf msvcrt.dll
extern printf
import printf msvcrt.dll
extern fgets
import fgets msvcrt.dll
extern counter
;extern read
;import read msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    
    
    aux dd 1
    format db '%s',0
    format1 db '%d',0
    buffer resb 200  
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;Read a sentence from the keyboard. Count the letters from each word and print the numbers on the screen.
        
               
        
        
        Repeta:
        
        
        
        
        push dword buffer
        push dword format
        call [scanf]
        add ESP, 4*2

        
        
        
        cmp EAX, 1
        jne exitLoop
        

        
        push dword buffer
        call counter
        add ESP, 4*1
        
        
        push dword buffer
        push dword format
        call [printf]
        add ESP, 4*2
        
        
        cmp EAX, 4
        je exitLoop
        
        
        
        jmp Repeta
        
        
        
        
        exitLoop:
        
        
            
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
