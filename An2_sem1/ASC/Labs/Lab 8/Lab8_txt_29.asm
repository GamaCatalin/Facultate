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
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    
    fileDescriptor dd 0
    accessMode db "a+",0
    fileName db "input29.txt",0
    space db " "
    readByte db "0",0
    maximumNumber db 0
    currentNumber db 0
    readDigit db 0
    spaceString db " ",0
    printFormat db " %d",0
    maxFormat db "Max: %d ",0
    testingFormat db "Read: '%c' ",0
    outputString db "",0
    

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;A text file is given. The text file contains numbers (in base 10) separated by spaces. Read the content of the file, determine the maximum number (from the numbers that have been read) and write the result at the end of file.
        
        
        
        push dword accessMode                           ;push into the stack the access mode for the file
        push dword fileName                             ;push the file name
        call [fopen]                                    ;open the file
        add ESP, 4*2                                    ;clear the stack
        
        
        cmp EAX, 0                                      ;check if fopen returned a file descriptor
        je endProgram                                   
        
        
        mov [fileDescriptor], EAX                       ;save the file descriptor
        
              
        
        
        mainLoop:
            push dword [fileDescriptor]                 ;push the file descriptor
            push dword 1                                ;push the number of characters to be read
            push dword 1                                ;push the size of one character
            push dword readByte                         ;push the buffer
            call [fread]                                ;call fread
            add ESP, 4*4                                ;clear the stack
            
            
            cmp EAX, 0                                  ;check if something has been read
            je cleanup
            
            
            ;test print
            
            mov AL, [readByte]
            cbw
            cwde
            
            push dword EAX
            push dword testingFormat
            call [printf]
            add ESP, 4*2
            ;test print
            
            
            mov DL, [readByte]                          ;check if the read character is space or not
            cmp DL, [space]
            
            je isSpace
            
                     
            sub DL, "0"                                 ;get the value of the read character
            
            
            mov [readDigit],DL                          ;save the value
                
            mov AL, [currentNumber]                     ;get into al the current number
            mov BL, 10                                  
            mul BL                                      ;multiply the current number by 10
            
            add AX, [readDigit]                         ;add the read digit
            
            mov [currentNumber], AX                     ;save the new number
            
            jmp endLoop
            
            isSpace:
                mov AL, [currentNumber]                 ;if the current read character is space, check if the current number is greater than the current max
                cmp AL, [maximumNumber]         
                
                jbe endSpace
                    
                    
                ;test print    
                mov AL, [currentNumber]    
                mov [maximumNumber],AL
                cbw
                cwde
                push EAX
                push dword maxFormat
                call [printf]
                add ESP, 4*2
                ;test print
                    
                
                    endSpace:                           ;reset the current number
                        mov DL, 0
                        mov [currentNumber],DL
        
            endLoop:
        
        jmp mainLoop
        

        
        
        cleanup:
        
        mov AL, [maximumNumber]                         ;push into the stack the maximum number
        cbw
        cwde
        push dword EAX
        push dword printFormat                          ;push the format
        push dword [fileDescriptor]                     ;push the file descriptor
        call [fprintf]                                  ;call fprintf
        add ESP, 4*3                                    ;clear the stack
        
        
        push dword [fileDescriptor]                     ;push the file descriptor
        call [fclose]                                   ;close the file
        add ESP, 4*1                                    ;clear the stack
        
        endProgram:
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
