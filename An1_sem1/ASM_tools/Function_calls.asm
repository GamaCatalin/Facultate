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
    outputtext dd "The product is %d",0 ; am modificat tipul variabileleor- trebuie sa fie dd si nu db
    format dd "%d", 0
   
    a db 0
    b db 0
   

; our code starts here
segment code use32 class=code
    start:
        ; ...
       
       
        ;multiply 2 given numbers, a and b
       
       
        mov eax,0    
        push text1  
        call [printf]
        add esp, 4*1
        push a
        push format
        call [scanf]
        add esp, 4*2
       
       
        push text2
        call [printf]
        add esp, 4*1
        push b
        push format
        call [scanf]
        add esp, 4*2
       
        mov ax, [a] ; pentru ca a este byte, iar in ax incape un word, va incarca in ah -rumatoarea pozitie din memorie (care este b de fapt). In memoria variabilele apar in ordinea definirii lor
        mov ah, 0
        mov bl, [b]
        mul bl
       
        cwd
        push eax ; aici pui pe stiva pt print doar un word. trebuie pus un double word. solutii: 1. pui alt word initializat cu 0 inainte (adica mov dx,0, push dx, ori faci conversie la double word si asa pui pe stiva)
        push outputtext
        call [printf]
        add esp, 4*2 ; aici pt ca ai pus 2 dublu cuvinte (eax si outputext), trebuie sa add 4*2      
       
       
       
   
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program