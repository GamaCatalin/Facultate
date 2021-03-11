bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose, fread, printf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db "input.txt", 0
    mode db "r", 0
    format dd "There are %d even numbers", 0
    file_nr dd -1
    len_current dd 0
    len equ 1
    buffer resb len
    even_nr db 0
    
    
    

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        push dword mode
        push dword file_name
        call [fopen]
        add esp, 4*2
    
    
        cmp eax,0
        je End
    
        mov [file_nr],eax
        
        
        loop:
            push dword [file_nr]
            push dword len
            push dword 1
            push dword buffer
            call [fread]
            add esp, 4*4
            
            cmp eax, 0
            je Close_f
            
            mov edx, [buffer]
            cmp edx, 0x20
            je Next_char
            jne Parity_check

            
            Parity_check:
            
            mov edx, [buffer]
            test edx, 01h
            jnp Next_char
                         
            inc dword [even_nr]
            
            Next_char:
            
            mov [len_current],eax
    
            jmp loop
    

    
        Close_f:
            push dword [file_nr]
            call [fclose]
            add esp, 4*1
            
            mov edx, [even_nr]
            push edx
            push format
            call [printf]
            add esp, 4*2
    
        End:
        
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
