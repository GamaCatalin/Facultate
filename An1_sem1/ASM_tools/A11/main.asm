bits 32 


global start        

import printf msvcrt.dll
extern printf
extern exit               
import exit msvcrt.dll  
import scanf msvcrt.dll
extern scanf  



%include "module.asm"


segment data use32 class=data
    ; ...

    
    text1 dd "Enter the first number: ",0
    text2 dd "Enter the second number: ",0
    format dd "%d",0
    output dd "The sum is %d",0
    a dd 0
    b dd 0
    
    

segment code use32 class=code
    start:
        ; ...
    
    
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
    
    
    
        
        mov eax,[a]
        push dword eax
        mov eax,[b]
        push dword eax
        call sum
        
        
        push eax
        push output
        call [printf]
        add esp, 4*2
    
    
    
    
    
        ; exit(0)
        push    dword 0      
        call    [exit]       
