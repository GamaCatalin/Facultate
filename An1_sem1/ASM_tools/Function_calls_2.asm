bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit
extern printf  
extern scanf            ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll   ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
   
    text1 dd "Enter the first number: ",0
    text2 dd "Enter the second number: ",0
    output dd "The quotient is %d, and the remainder is %d",0
    format dd "%d",0
   
    a db 0
    b db 0
   
    x dw 0
    y dw 0
   
; our code starts here
segment code use32 class=code
    start:
        ; ...
       
       
        ;divide 2 given numbers, a and b
       
       
        mov eax,0    
        push text1  
        call [printf]
        add esp, 4*1
        push a
        push format
        call [scanf]
        add esp, 4*1
       
       
        push text2
        call [printf]
        add esp, 4*1
        push b
        push format
        call [scanf]
        add esp, 4*1
       
        mov ax, [a] 
        mov ah, 0
        mov bl, [b]
        div bl
       
        mov [x], al
        mov [y], ah
       
       
        mov ax,[y]
        cwde
        push eax
        
        mov ax,[x]                                                              
        cwde
        push eax        
        push output
        call [printf]
        add esp, 4*3 
       
       
       
   
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program