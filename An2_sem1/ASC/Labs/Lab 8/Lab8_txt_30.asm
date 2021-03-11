bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
extern fopen
import fopen msvcrt.dll
extern fclose
import fclose msvcrt.dll
extern fprintf
import fprintf msvcrt.dll
extern fread
import fread msvcrt.dll
extern printf
import printf msvcrt.dll
extern scanf
import scanf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    
    fileName db "output30.txt",0
    fileFormat db "a",0
    stopChar db "$"
    fileDescriptor dd 0
    scanFormat db "%s",0
    outputFormat db "%s ",0
    charFormat db "%c", 0
    index db 0
    buffer dd "",0
    lenWord equ 132
    
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;A file name (defined in data segment) is given. Create a file with the given name, then read words from the keyboard until character '$' is read from the keyboard. Write only the words that contain at least one digit to file.
        
        
        
        push dword fileFormat               ;push the file format
        push dword fileName                 ;push the file name
        call [fopen]                        ;open the file
        add ESP, 4*2                        ;clear the stack
        
        mov [fileDescriptor],EAX            ;save the file descriptor
        
        cmp EAX,0                           ;check if the file has been open
        je endProgram
        
        
        mov ECX, 1                          ;initialize ecx
        
        
        mainLoop:       
        push dword buffer                   ;push the buffer
        push dword scanFormat               ;push the format
        call [scanf]                        ;read from keyboard
        add ESP, 4*2                        ;clear the stack

        
        mov AL, [stopChar]                  ;check if the read word is the stopping word
        cmp [buffer], AL
        je cleanup
            
        
        mov ESI, 0                          ;clear esi
        
        wordLoop:
           
            mov AL, [buffer+ESI]            ;get the current char from the word
            cbw
            cwde
        
            cmp EAX, '0'                    ;check if it is a digit
            jge possibleNumber
            jmp nextIteration
        
            possibleNumber:
            cmp EAX,'9'
            jg notNumber
            
            jbe containsDigit
        
            notNumber:
            nextIteration:
                inc ESI                     ;increment ESI
            
                cmp ESI, lenWord            ;check if it is less than the max lenght of the word
                jbe wordLoop
      
        jmp nextWord                        ;if the word didn't contain a digit, read the next one
      
        containsDigit:                      
            push dword buffer               ;push the word 
            push dword outputFormat         ;push the format
            push dword [fileDescriptor]     ;push the file descriptor
            call [fprintf]                  ;write to file
            add ESP, 4*3                    ;clear the stack
        
        nextWord:
        
        loop mainLoop
        
        
        
        
        cleanup:
            push dword [fileDescriptor]     ;push the file descriptor
            call [fclose]                   ;close the file
            add ESP, 4*1                    ;clear the stack
        
        
        
        endProgram:
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
