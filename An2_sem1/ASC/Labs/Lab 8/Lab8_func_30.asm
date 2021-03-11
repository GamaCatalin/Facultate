bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
extern printf
import printf msvcrt.dll
extern scanf
import scanf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    
    scanFormat db "%d",0
    printFormat db "Smallest numer: %d",0
    number dd 0
    smallestNumber dd 0xFFFFFFFF
    
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;Read numbers (in base 10) in a loop until the digit '0' is read from the keyboard. Determine and display the smallest number from those that have been read.
        
        
        mov ECX, 1                              ;initialize ECX
        
        mainLoop:
            push dword number                   ;read the number from the keyboard
            push dword scanFormat
            call [scanf]
            add ESP, 4*2
            
            mov EAX, [number]                   ;move the number into EAX
            cmp EAX, 0                          ;check if the number is equal to 0
            
            je afterLoop                        ;end the loop if the number is equal to 0
            
            cmp dword [smallestNumber], EAX     ;check if the read number is smaller than the current smallest number
            jb endLoop                          
                        
            mov [smallestNumber],EAX            ;save the new smallest number
                           
              
            mov ECX, 2
        
            endLoop:
        
        loop mainLoop                           ;loop until 0 is read
        
        
        afterLoop:
        
        push dword [smallestNumber]             ;print the smallest number
        push dword printFormat
        call [printf]
        add ESP, 4*2
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
