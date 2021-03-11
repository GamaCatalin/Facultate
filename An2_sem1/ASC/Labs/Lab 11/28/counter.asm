bits 32 ; assembling for the 32 bits architecture


global counter


; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
extern printf
import printf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    format db '%d',0
    buffer db '',0
    
    
; our code starts here
segment code use32 class=code
    counter:
        ; ...
        
        
        
        mov EAX,[ESP]
        mov [buffer],EAX
        
        mov ECX,0
        
        
        loopChars:
            cmp byte [buffer+ECX],''
            je endLoop
            add ECX, 1
        endLoop:    
      
        
        push dword ECX
        push dword format
        call [printf]
        add ESP, 4*2
        
        
        
        ret
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
